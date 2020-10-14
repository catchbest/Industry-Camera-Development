#ifndef __KSJ_API_STRING_H__
#define __KSJ_API_STRING_H__

#include "KSJApi.h"

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
	
	/// 语言类型枚举 
	enum KSJ_LANGUAGE
	{
		L_ENG,     ///< 英文
		L_CHS,     ///< 中文
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetLanguage
	/// @brief     设置语言
	/// @param     lang [in] 传入语言类型
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetLanguage(IN KSJ_LANGUAGE Language);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetLanguage
	/// @brief     获得错误的详细信息
	/// @param     pLang [out] 输出语言类型
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetLanguage(OUT KSJ_LANGUAGE* pLanguage);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获得语言名称
	/// @param     Language [in] 传入语言类型，请参考参考KSJ_LANGUAGE
	/// @return    字符串信息地址指针
	/// @attention 调可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetLanguageString(IN KSJ_LANGUAGE Language);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获得错误的详细信息
	/// @param     nErrorNo [in] 传入错误代码，参考返回状态码（KSJCode.H）
	/// @return    字符串信息地址指针
	/// @attention 调可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  PTCHAR __stdcall KSJ_GetReturnCodeString(IN int nErrorNo);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetDeviceName
	/// @brief     获得相机名称字符串
	/// @param     usDeviceType [in] 传入相机型号, 参考KSJ_DEVICETYPE的定义，可以通过KSJ_DeviceGetInformation/KSJ_DeviceGetInformationEx获得。
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  PTCHAR __stdcall KSJ_GetDeviceName(KSJ_DEVICETYPE usDeviceType);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetParamString
	/// @brief     获得设置参数名称字符串
	/// @param     Param [in] 传入参数类型, 参考KSJ_PARAM的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  PTCHAR __stdcall KSJ_GetParamString(KSJ_PARAM Param);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetEEPROMTypeString
	/// @brief     获得存储器芯片类型字符串
	/// @param     Type [in] 传入参数类型, 参考KSJ_EEPROM_TYPE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  PTCHAR __stdcall KSJ_GetEEPROMTypeString(KSJ_EEPROM_TYPE Type);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetAddressModeString
	/// @brief     获得抽点模式字符串
	/// @param     AddressMode [in] 传入抽点模式类型, 参考KSJ_ADDRESSMODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetAddressModeString(KSJ_ADDRESSMODE AddressMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetTriggerModeString
	/// @brief     获得触发模式字符串
	/// @param     TriggerMode [in] 传入触发模式类型, 参考KSJ_TRIGGERMODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetTriggerModeString(KSJ_TRIGGERMODE TriggerMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetTriggerMethod
	/// @brief     获得触发信号条件字符串
	/// @param     TriggerMethod [in] 传入触发信号条件类型, 参考KSJ_TRIGGERMETHOD的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetTriggerMethod(KSJ_TRIGGERMETHOD TriggerMethod);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetStartEndModeString
	/// @brief     获得起始结束模式字符串
	/// @param     StartEndMode [in] 传入起始结束模式类型, 参考KSJ_STARTENDMODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetStartEndModeString(KSJ_STARTENDMODE StartEndMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetTriggerStatusString
	/// @brief     获得相机缓存状态字符串
	/// @param     TriggerStatus [in] 传入相机缓存状态类型, 参考KSJ_TRIGGERSTATUS的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetTriggerStatusString(KSJ_TRIGGERSTATUS TriggerStatus);


	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetFunctionEnumString
	/// @brief     获得功能枚举类型字符串
	/// @param     TriggerStatus [in] 传入功能描述类型, 参考KSJ_FUNCTION的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetFunctionEnumString(KSJ_FUNCTION Function);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetFunctionDescString
	/// @brief     获得功能描述字符串
	/// @param     TriggerStatus [in] 传入功能描述类型, 参考KSJ_FUNCTION的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetFunctionDescString(KSJ_FUNCTION Function);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetGpioInModeString
	/// @brief     获得外触发输入引脚类型字符串
	/// @param     Mode [in] 传入外触发输入引脚类型, 参考KSJ_GPIOIN_MODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetGpioInModeString(KSJ_GPIOIN_MODE Mode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetGpioOutModeString
	/// @brief     获得闪光灯输出引脚类型字符串
	/// @param     Mode [in] 传入闪光灯输出引脚类型, 参考KSJ_GPIOOUT_MODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetGpioOutModeString(KSJ_GPIOOUT_MODE Mode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetAutoExposureStatusString
	/// @brief     获得自动曝光状态字符串
	/// @param     Mode [in] 传入自动曝光状态类型, 参考KSJ_AE_STATUS的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetAutoExposureStatusString(KSJ_AE_STATUS AutoExposureStatus);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetBayerModeString
	/// @brief     获得Bayer模式类型字符串
	/// @param     BayerMode [in] 传入Bayer模式类型, 参考KSJ_BAYERMODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetBayerModeString(KSJ_BAYERMODE BayerMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetBayerFilterModeString
	/// @brief     获得Bayer滤波模式类型字符串
	/// @param     FilterMode [in] 传入Bayer滤波模式类型, 参考KSJ_FILTERMODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetBayerFilterModeString(KSJ_FILTERMODE FilterMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetSensitivityModeString
	/// @brief     获得灵敏度类型字符串
	/// @param     SensitivityMode [in] 传入灵敏度类型, 参考KSJ_SENSITIVITYMODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetSensitivityModeString(KSJ_SENSITIVITYMODE SensitivityMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetHueChannelString
	/// @brief     获得颜色分量通道枚举类型字符串
	/// @param     SensitivityMode [in] 传入颜色分量通道枚举类型, 参考KSJHueRange的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetHueChannelString(KSJHueRange HueChannel);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetWhiteBalanceModeString
	/// @brief     获得白平衡模式枚举类型字符串
	/// @param     SensitivityMode [in] 传入白平衡模式枚举类型, 参考KSJ_WB_MODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetWhiteBalanceModeString(KSJ_WB_MODE WhiteBalanceMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetColorTemperatureString
	/// @brief     获得色温枚举类型字符串
	/// @param     SensitivityMode [in] 传入色温枚举类型, 参考KSJ_WB_MODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetColorTemperatureString(KSJ_COLOR_TEMPRATURE ColorTemperature);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetColorCorrectionModeString
	/// @brief     获得颜色校正矩阵类型字符串
	/// @param     SensitivityMode [in] 传入颜色校正矩阵类型, 参考KSJ_CCM_MODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetColorCorrectionModeString(KSJ_CCM_MODE ColorCorrectionMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetDeviceStatusString
	/// @brief     获得设备状态字符串
	/// @param     DeviceStatus [in] 传入设备状态类型, 参考KSJ_DEVICESTATUS的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetDeviceStatusString(KSJ_DEVICESTATUS DeviceStatus);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetCalibrationMapModeString
	/// @brief     获得校正模式字符串
	/// @param     MapMode [in] 传入校正模式类型, 参考KSJ_MAPMODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetCalibrationMapModeString(KSJ_MAPMODE MapMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetBadPixelThresholdModeString
	/// @brief     获得坏点阈值模式字符串
	/// @param     ThresholdMode [in] 传入坏点阈值模式类型, 参考KSJ_THRESHOLD的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetBadPixelThresholdModeString(KSJ_THRESHOLD ThresholdMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetIoDirectionString
	/// @brief     获得IO方向字符串
	/// @param     Direction [in] 传入IO方向, 1表示此GPIO输出，0表示此GPIO输入
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetIoDirectionString(int Direction);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetFlashModeString
	/// @brief     获得闪光灯模式字符串
	/// @param     FlashMode [in] 传入闪光灯模式类型, 参考KSJ_FLASHMODE的定义
	/// @return    字符串信息地址指针
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetFlashModeString(KSJ_FLASHMODE FlashMode);


#ifdef __cplusplus
}
#endif

#endif
