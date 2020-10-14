#ifndef __KSJ_API_CALLBACK_H__
#define __KSJ_API_CALLBACK_H__

// #pragma message("Include KSJApiCallback.h") 

#ifdef KSJAPI_EXPORTS
    #define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
	#define KSJ_API
#else
    #define KSJ_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"{
#endif

	///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_PREVIEWCALLBACK
    /// @brief     回调函数指针的声明
    /// @param     pImageData [out] 预览图像的数据指针
	/// @param     pnWidth [out] 返回图像的宽度（像素）
    /// @param     pnHeight [out] 返回图像的高度（像素）
    /// @param     pnBitCount [out] 返回当前视场模式设置下的实际采集图像的位图深度
	/// @param     lpContext [out] 用户传入的上下文指针，这个指针就是用户调用KSJ_PreviewSetCallback函数时传给lpContext的指针
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	///
	///-----------------------------------------------------------------------------
	typedef void(CALLBACK *KSJ_PREVIEWCALLBACK)(unsigned char *pImageData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_PreviewSetCallback
    /// @brief     设置预览回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfPreviewCallback [in] 回调函数指针
	/// @param     lpContext [out] 用户传入的上下文指针
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用。
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_PreviewSetCallback( int nIndex, KSJ_PREVIEWCALLBACK pfPreviewCallback, void *lpContext );

    ///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_PREVIEWCALLBACKEX
    /// @brief     回调函数指针的声明
	/// @param     hDC [out] KSJApi库创建的内存DC，预览图像已经作为设备无关位图被选入此DC（设备环境句柄）中，用户可以使用此DC并调用GDI函数在此DC（设备环境句柄）上绘制需要添加显示的内容
    /// @param     pImageData [out] 预览图像的数据指针
	/// @param     pnWidth [out] 返回图像的宽度（像素）
    /// @param     pnHeight [out] 返回图像的高度（像素）
    /// @param     pnBitCount [out] 返回当前视场模式设置下的实际采集图像的位图深度
	/// @param     lpContext [out] 用户传入的上下文指针，这个指针就是用户调用KSJ_PreviewSetCallback函数时传给lpContext的指针
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	///
	///-----------------------------------------------------------------------------
    typedef void(CALLBACK *KSJ_PREVIEWCALLBACKEX)(HDC  hDC, unsigned char *pImageData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_PreviewSetCallbackEx
    /// @brief     设置预览回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfPreviewCallbackEx [in] 回调函数指针
	/// @param     lpContext [out] 用户传入的上下文指针
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_PreviewSetCallbackEx( int nIndex, KSJ_PREVIEWCALLBACKEX pfPreviewCallbackEx, void *lpContext );


#ifdef __cplusplus
}
#endif

#endif