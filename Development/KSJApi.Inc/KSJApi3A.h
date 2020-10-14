#ifndef __KSJ_API_3A_H__
#define __KSJ_API_3A_H__

// #pragma message("Include KSJApi3A.h") 

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
	/// @brief     KSJ_AESetRegion
	/// @brief     设置自动曝光的参考区域，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nX [in] 相对于无缩放预览图像的左上角水平像素偏移
	/// @param     nY [in] 相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     nW [in] 相对于无缩放预览图像的自动曝光区域的宽度，以像素为单位
	/// @param     nH [in] 相对于无缩放预览图像的自动曝光区域的高度，以像素为单位
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetRegion(int nIndex, int nX, int nY, int nW, int nH);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEGetRegion
	/// @brief     获取自动曝光的参考区域及显示状态，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnX [out] 返回相对于无缩放预览图像的左上角水平像素偏移
	/// @param     pnY [out] 返回相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     pnW [out] 返回相对于无缩放预览图像的自动曝光区域的宽度以像素为单位
	/// @param     pnH [out] 返回相对于无缩放预览图像的自动曝光区域的高度以像素为单位
	/// @param     pbShow [out] 参考区域是否显示
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// 
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEShowRegion
    /// @brief     设置是否预览时显示自动曝光的参考区域
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bShow [in] 是否显示自动曝光参考区域
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEShowRegion(int nIndex, bool bShow);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetPeakAveRatio
	/// @brief     设置自动曝光峰值像素的统计比率
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fRatio [in] 设置的峰值比率，范围0到1
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码，请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 自动曝光统计像素亮度值的时候，遇到峰值像素（255），该像素值将以（1+fRatio）的倍率参与统计
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetPeakAveRatio(int nIndex, float fRatio);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEGetPeakAveRatio
	/// @brief     获取自动曝光峰值像素的统计比率
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfRatio [out] 返回自动曝光峰值像素的统计比率
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetPeakAveRatio(int nIndex, float *pfRatio);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetExposureTimeRange
	/// @brief     设置自动曝光的调节范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fMinExpMs [in] 设置自动曝光调节下限，单位：毫秒
	/// @param     fMaxExpMs [in] 设置自动曝光调节上限，单位：毫秒
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 开启自动曝光时，曝光值将仅限于这个范围进行调节
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetExposureTimeRange(int nIndex, float fMinExpMs,   float fMaxExpMs);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEGetExposureTimeRange
	/// @brief     获取自动曝光的调节范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfMinExpMs [in] 返回自动曝光调节下限，单位：毫秒
	/// @param     pfMaxExpMs [in] 返回自动曝光调节上限，单位：毫秒
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetExposureTimeRange(int nIndex, float *pfMinExpMs, float *pfMaxExpMs);

	/// 自动曝光运算返回状态
	enum KSJ_AE_STATUS
	{
		KSJ_AE_ONCE_SUCCESS = 0, 			///< 单次调节成功
		KSJ_AE_ONCE_FAIL_MAX_COUNT, 		///< 单次调节失败，失败原因达到最大调节次数
		KSJ_AE_ONCE_FAIL_WAVE, 				///< 单次调节失败，失败原因调节上下振动
		KSJ_AE_ONCE_FAIL_OVER_RANGE, 		///< 单次调节失败，失败原因曝光超出设置范围
		KSJ_AE_DOING, 						///< 单次调节完成，设置了新的曝光时间
		KSJ_AE_CONTINUE_SUCCESS,			///< 连续调节成功，当前达到了目标值
		KSJ_AE_CONTINUE_FAIL_WAVE, 			///< 连续调节失败，失败原因调节上下振动
		KSJ_AE_CONTINUE_FAIL_OVER_RANGE 	///< 连续调节失败，失败原因曝光超出设置范围
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AECALLBACKEX
	/// @brief     自动曝光回调函数定义
	/// @param     Status [out] 当前自动曝光操作的状态（参考KSJ_AE_STATUS说明）
	/// @param     nExpsoureTimeMs [out] 在自动曝光调节结束后，当前的曝光值，单位：毫秒
	/// @param     lpContext [out] 用户上下文指针，这个指针是用户调用KSJ_AESetCallbackEx时传入的上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AECALLBACKEX)( KSJ_AE_STATUS Status, int nExpsoureTimeMs, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetCallbackEx
	/// @brief     设置自动曝光操作的回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfAECallbackEx [in] 用户定义的自动曝光回调函数指针
	/// @param     lpContext [in] 回调函数的上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 自动曝光完成一次曝光运行并调节时，会自动调用pfAECallbackEx用户指定的回调函数
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetCallbackEx(int nIndex, KSJ_AECALLBACKEX pfAECallbackEx, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetMaxCount
	/// @brief     设置自动曝光调节最大次数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nMaxCount [in] 设置自动曝光调节最大次数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 自动曝光最多进行nMaxCount指定的运算次数
	///          \li 如果需要自动曝光连续运行，请设置nMaxCount为-1
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetMaxCount(int nIndex, int  nMaxCount);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEStartEx
	/// @brief     启动或结束自动曝光操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bStart [in] true 开始自动曝光调节，false 终止或结束自动曝光调节
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetTarget(int nIndex, int  nTarget);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEGetStatusEx
	/// @brief     得到自动曝光的设置状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbStart [out] 得到自动曝光当前是否启动
	/// @param     pnMaxCount [out] 得到自动曝光的最大调节次数
	/// @param     pnTarget [out] 得到自动曝光调节的目标值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEStartEx(int nIndex, bool bStart);

	///-----------------------------------------------------------------------------
	///
    /// @brief     得到自动曝光的设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbStart [out] 得到KSJ_AEStartEx是否启动
	/// @param     pnMaxCount [out] 得到自动曝光的最大调节次数
	/// @param     pnTarget [out] 得到自动曝光调节的目标值
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetStatusEx(int nIndex, bool *pbStart, int *pnMaxCount, int *pnTarget);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AWBSetRegion
	/// @brief     设置自动白平衡的参考区域，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nX [in] 相对于无缩放预览图像的左上角水平像素偏移
	/// @param     nY [in] 相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     nW [in] 相对于无缩放预览图像的自动曝光区域的宽度，以像素为单位
	/// @param     nH [in] 相对于无缩放预览图像的自动曝光区域的高度，以像素为单位
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AECALLBACK)(bool bSuccess, int nResult, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AWBSetRegion
	/// @brief     设置自动白平衡的参考区域，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nX [in] 相对于无缩放预览图像的左上角水平像素偏移
	/// @param     nY [in] 相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     nW [in] 相对于无缩放预览图像的自动曝光区域的宽度，以像素为单位
	/// @param     nH [in] 相对于无缩放预览图像的自动曝光区域的高度，以像素为单位
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBSetRegion(int nIndex, int nX, int nY, int nW, int nH);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_AWBShowRegion
    /// @brief     设置预览时是否显示自动白平衡的参考区域
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bShow [in] 是否显示自动白平衡参考区域
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBShowRegion(int nIndex, bool bShow);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AWBGetRegion
	/// @brief     获取自动白平衡的参考区域及显示状态，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnX [out] 返回相对于无缩放预览图像的左上角水平像素偏移
	/// @param     pnY [out] 返回相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     pnW [out] 返回相对于无缩放预览图像的自动曝光区域的宽度，以像素为单位
	/// @param     pnH [out] 返回相对于无缩放预览图像的自动曝光区域的高度，以像素为单位
	/// @param     pbShow [out] 参考区域是否显示
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);

#ifdef __cplusplus
}
#endif

#endif