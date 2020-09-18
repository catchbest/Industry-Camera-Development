#ifndef __KSJ_API_16BITS_H__
#define __KSJ_API_16BITS_H__

// #pragma message("Include KSJApi16Bits.h") 

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
    /// @brief     获取图像传感器的ADC转换精度（比特位数）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnADCResolution [out] 返回ADC时的比特位数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetADCResolution(int nIndex, int *pnADCResolution);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置相机以16bit每个像素传输数据（部分相机是以10bit或者12bit采样，但是传输必须以16bit进行传输）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnADCResolution [in] 为true时设置16bit原始数据传输, false时不设置，恢复8bit原始数据传输
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetData16Bits(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     函数用于获取设备是否以16bit原始数据传输
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [out] 返回为true时为16bit原始数据传输, false时为默认8bit原始数据传输
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetData16Bits(int nIndex, bool *bEnable);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     该函数得到采集图像的宽度和高度（单位：像素）及位图深度（8，24，32）及每个采样的比特位数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnWidth [out] 返回当前视场模式设置下的实际采集图像的像素宽度
    /// @param     pnHeight [out] 返回当前视场模式设置下的实际采集图像的像素高度
    /// @param     pnBitCount [out] 返回当前视场模式设置下的实际采集图像的位图深度
	/// @param     nBitsPerSample [out] 采样位数，nBitPerSample = 8 或16，分别为8bit和16bit采样
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSizeExEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount, int *nBitsPerSample);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取图像传感器的ADC转换精度（比特位数）
    /// @param     pData [in] 指向图像数据的首地址指针
	/// @param     nWidth [in] 图像的宽度（像素）
    /// @param     nHeight [in] 图像的高度（像素）
    /// @param     nBitPerSample [in] 采样位数，nBitPerSample = 8 或16，分别为8bit和16bit采样
	/// @param     nSamplesPerPixel [in] 表示每个像素有几个采样点，nSamplesPerPixel = 1或3或4(分别对应BitCount=8,24,32)
    /// @param     pszFileName [in] 保存文件的全路径名（路径必须存在）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToTiff(unsigned char *pData, int nWidth, int nHeight, int nBitPerSample, int nSamplesPerPixel, const TCHAR *pszFileName);

#ifdef __cplusplus
}
#endif

#endif