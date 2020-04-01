#ifndef __KSJ_API_WATER_MARK__H__
#define __KSJ_API_WATER_MARK__H__

// #pragma message("Include KSJApiWaterMark.h") 

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

	enum KSJ_WATERMARKMODE //水印模式
	{ 
		KSJ_WMM_TIMESTAMP, 
		KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, 
		KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER 
	};

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WaterMarkSetMode
    // 功能：设置水印模式（新版本水印已经不支持水印模式设置，默认KSJ_WMM_TIMESTAMP）
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       WaterMarkMode：输入，设置水印模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetMode(int nChannel, KSJ_WATERMARKMODE WaterMarkMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WaterMarkGetMode
    // 功能：获取水印模式（新版本水印已经不支持水印模式设置，默认KSJ_WMM_TIMESTAMP）
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pWaterMarkMode：输出，获取当前水印模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetMode(int nChannel, KSJ_WATERMARKMODE *pWaterMarkMode);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WaterMarkSetEnable
    // 功能：设置是否开启水印
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，是否开启水印功能，true表示开启，false表示不开启
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetEnable(int nChannel, bool bEnable);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WaterMarkGetEnable
    // 功能：获取是否开启水印
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pWaterMarkMode：输出，获取当前水印模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetEnable(int nChannel, bool *pbEnable);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WaterMarkGetInfo
    // 功能：获取水印信息
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pwId：输出，获取当前水印号
	//       pdwTimestampLowPart：输出，获取时间戳的低4字节值
	//       pdwTimestampHighPart：输出，获取时间戳的高4字节位值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetInfo(int nChannel, unsigned short *pwId, unsigned long *pdwTimestampLowPart, unsigned long *pdwTimestampHighPart);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_WaterMarkGetInfoEx
    // 功能：获取水印信息和增益曝光
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pwId：输出，获取当前水印号
	//       pdwTimestampLowPart：输出，获取时间戳的低4字节值
	//       pdwTimestampHighPart：输出，获取时间戳的高4字节位值
	//       pnExposure：输出，获取当前图像的曝光值
	//       pwGain：输出，获取当前图像的增益值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetInfoEx(int nChannel, unsigned int *pnId, unsigned long *pdwTimestampLowPart, unsigned long *pdwTimestampHighPart, unsigned int* pnExposure, unsigned short* pwGain);

#ifdef __cplusplus
}
#endif

#endif
