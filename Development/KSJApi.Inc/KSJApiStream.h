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

	//-----------------------------------------------------------------------------
    // 函数：KSJ_IsSupportStreamMode
    // 功能：查看相机是否支持流模式
    // 参数：
	//       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbSupport： 输出，是否支持流模式，true支持，false不支持
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_IsSupportStreamMode(int nIndex, bool* pbSupport);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_StreamIsStart
    // 功能：查看相机是否开启流模式
    // 参数：
	//       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbStart： 输出，是否启动流模式，true启动，false未启动
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamIsStart(int nIndex, bool* pbStart);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_StreamStart
    // 功能：开启流模式
    // 参数：
	//       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamStart(int nIndex);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_StreamStop
    // 功能：关闭流模式
    // 参数：
	//       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamStop(int nIndex);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_StreamReadRawData
    // 功能：相机工作在流模式时，采集一帧原始或黑白图像数据
    // 参数：
    //       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pRawData：输出，由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRawData(int nIndex, unsigned char *pRawData);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_StreamReadRawData
    // 功能：相机工作在流模式时，采集一帧8位原始或灰度图像或24，32位彩色数据图像
    // 参数：
    //       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pRgbData：输出，由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRgbData(int nIndex, unsigned char *pRgbData);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_StreamReadRawDataEx
    // 功能：相机工作在流模式时，采集一帧原始或黑白图像数据
    // 参数：
    //       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pRawData：输出，由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
	//       pDataSize： 输出，返回实际图像数据的大小
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRawDataEx(int nIndex, unsigned char *pRawData, unsigned int* pDataSize);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_StreamReadRgbDataEx
    // 功能：相机工作在流模式时，采集一帧8位原始或灰度图像或24，32位彩色数据图像
    // 参数：
    //       nIndex： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pRgbData：输出，由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
	//       pDataSize： 输出，返回实际图像数据的大小
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRgbDataEx(int nIndex, unsigned char *pRgbData, unsigned int* pDataSize);

#ifdef __cplusplus
}
#endif

#endif
