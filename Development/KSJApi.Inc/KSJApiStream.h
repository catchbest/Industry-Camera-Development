#ifndef __KSJ_API_STREAM_H__
#define __KSJ_API_STREAM_H__

// #pragma message("Include KSJApiBase.h") 

#ifdef KSJAPI_EXPORTS
#define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
#define KSJ_API
#else
#define KSJ_API __declspec(dllimport)
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifdef __cplusplus
extern "C"{
#endif

	///-----------------------------------------------------------------------------
    ///
    /// @brief     查看相机是否支持流模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbSupport [out] 是否支持流模式，true支持，false不支持
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_IsSupportStreamMode(int nIndex, bool* pbSupport);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     查看相机是否开启流模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbStart [out] 是否启动流模式，true启动，false未启动
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamIsStart(int nIndex, bool* pbStart);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     开启流模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamStart(int nIndex);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     关闭流模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamStop(int nIndex);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     相机工作在流模式时，采集一帧原始或黑白图像数据
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pRawData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRawData(int nIndex, unsigned char *pRawData);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     相机工作在流模式时，采集一帧8位原始或灰度图像或24，32位彩色数据图像
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRgbData(int nIndex, unsigned char *pRgbData);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     相机工作在流模式时，采集一帧原始或黑白图像数据
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pRawData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
	/// @param     pDataSize [out] 返回实际图像数据的大小
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRawDataEx(int nIndex, unsigned char *pRawData, unsigned int* pDataSize);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     相机工作在流模式时，采集一帧8位原始或灰度图像或24，32位彩色数据图像
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
	/// @param     pDataSize [out] 返回实际图像数据的大小
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRgbDataEx(int nIndex, unsigned char *pRgbData, unsigned int* pDataSize);

#ifdef __cplusplus
}
#endif

#endif
