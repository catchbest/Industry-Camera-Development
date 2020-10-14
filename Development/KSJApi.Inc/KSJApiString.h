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
	
	/// ��������ö�� 
	enum KSJ_LANGUAGE
	{
		L_ENG,     ///< Ӣ��
		L_CHS,     ///< ����
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetLanguage
	/// @brief     ��������
	/// @param     lang [in] ������������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetLanguage(IN KSJ_LANGUAGE Language);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetLanguage
	/// @brief     ��ô������ϸ��Ϣ
	/// @param     pLang [out] �����������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetLanguage(OUT KSJ_LANGUAGE* pLanguage);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �����������
	/// @param     Language [in] �����������ͣ���ο��ο�KSJ_LANGUAGE
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ������������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetLanguageString(IN KSJ_LANGUAGE Language);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ô������ϸ��Ϣ
	/// @param     nErrorNo [in] ���������룬�ο�����״̬�루KSJCode.H��
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ������������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  PTCHAR __stdcall KSJ_GetReturnCodeString(IN int nErrorNo);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetDeviceName
	/// @brief     �����������ַ���
	/// @param     usDeviceType [in] ��������ͺ�, �ο�KSJ_DEVICETYPE�Ķ��壬����ͨ��KSJ_DeviceGetInformation/KSJ_DeviceGetInformationEx��á�
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  PTCHAR __stdcall KSJ_GetDeviceName(KSJ_DEVICETYPE usDeviceType);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetParamString
	/// @brief     ������ò��������ַ���
	/// @param     Param [in] �����������, �ο�KSJ_PARAM�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  PTCHAR __stdcall KSJ_GetParamString(KSJ_PARAM Param);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetEEPROMTypeString
	/// @brief     ��ô洢��оƬ�����ַ���
	/// @param     Type [in] �����������, �ο�KSJ_EEPROM_TYPE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  PTCHAR __stdcall KSJ_GetEEPROMTypeString(KSJ_EEPROM_TYPE Type);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetAddressModeString
	/// @brief     ��ó��ģʽ�ַ���
	/// @param     AddressMode [in] ������ģʽ����, �ο�KSJ_ADDRESSMODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetAddressModeString(KSJ_ADDRESSMODE AddressMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetTriggerModeString
	/// @brief     ��ô���ģʽ�ַ���
	/// @param     TriggerMode [in] ���봥��ģʽ����, �ο�KSJ_TRIGGERMODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetTriggerModeString(KSJ_TRIGGERMODE TriggerMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetTriggerMethod
	/// @brief     ��ô����ź������ַ���
	/// @param     TriggerMethod [in] ���봥���ź���������, �ο�KSJ_TRIGGERMETHOD�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetTriggerMethod(KSJ_TRIGGERMETHOD TriggerMethod);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetStartEndModeString
	/// @brief     �����ʼ����ģʽ�ַ���
	/// @param     StartEndMode [in] ������ʼ����ģʽ����, �ο�KSJ_STARTENDMODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetStartEndModeString(KSJ_STARTENDMODE StartEndMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetTriggerStatusString
	/// @brief     ����������״̬�ַ���
	/// @param     TriggerStatus [in] �����������״̬����, �ο�KSJ_TRIGGERSTATUS�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetTriggerStatusString(KSJ_TRIGGERSTATUS TriggerStatus);


	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetFunctionEnumString
	/// @brief     ��ù���ö�������ַ���
	/// @param     TriggerStatus [in] ���빦����������, �ο�KSJ_FUNCTION�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetFunctionEnumString(KSJ_FUNCTION Function);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetFunctionDescString
	/// @brief     ��ù��������ַ���
	/// @param     TriggerStatus [in] ���빦����������, �ο�KSJ_FUNCTION�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetFunctionDescString(KSJ_FUNCTION Function);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetGpioInModeString
	/// @brief     ����ⴥ���������������ַ���
	/// @param     Mode [in] �����ⴥ��������������, �ο�KSJ_GPIOIN_MODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetGpioInModeString(KSJ_GPIOIN_MODE Mode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetGpioOutModeString
	/// @brief     ��������������������ַ���
	/// @param     Mode [in] ��������������������, �ο�KSJ_GPIOOUT_MODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetGpioOutModeString(KSJ_GPIOOUT_MODE Mode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetAutoExposureStatusString
	/// @brief     ����Զ��ع�״̬�ַ���
	/// @param     Mode [in] �����Զ��ع�״̬����, �ο�KSJ_AE_STATUS�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetAutoExposureStatusString(KSJ_AE_STATUS AutoExposureStatus);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetBayerModeString
	/// @brief     ���Bayerģʽ�����ַ���
	/// @param     BayerMode [in] ����Bayerģʽ����, �ο�KSJ_BAYERMODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetBayerModeString(KSJ_BAYERMODE BayerMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetBayerFilterModeString
	/// @brief     ���Bayer�˲�ģʽ�����ַ���
	/// @param     FilterMode [in] ����Bayer�˲�ģʽ����, �ο�KSJ_FILTERMODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetBayerFilterModeString(KSJ_FILTERMODE FilterMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetSensitivityModeString
	/// @brief     ��������������ַ���
	/// @param     SensitivityMode [in] ��������������, �ο�KSJ_SENSITIVITYMODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetSensitivityModeString(KSJ_SENSITIVITYMODE SensitivityMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetHueChannelString
	/// @brief     �����ɫ����ͨ��ö�������ַ���
	/// @param     SensitivityMode [in] ������ɫ����ͨ��ö������, �ο�KSJHueRange�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetHueChannelString(KSJHueRange HueChannel);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetWhiteBalanceModeString
	/// @brief     ��ð�ƽ��ģʽö�������ַ���
	/// @param     SensitivityMode [in] �����ƽ��ģʽö������, �ο�KSJ_WB_MODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetWhiteBalanceModeString(KSJ_WB_MODE WhiteBalanceMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetColorTemperatureString
	/// @brief     ���ɫ��ö�������ַ���
	/// @param     SensitivityMode [in] ����ɫ��ö������, �ο�KSJ_WB_MODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetColorTemperatureString(KSJ_COLOR_TEMPRATURE ColorTemperature);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetColorCorrectionModeString
	/// @brief     �����ɫУ�����������ַ���
	/// @param     SensitivityMode [in] ������ɫУ����������, �ο�KSJ_CCM_MODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetColorCorrectionModeString(KSJ_CCM_MODE ColorCorrectionMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     GetDeviceStatusString
	/// @brief     ����豸״̬�ַ���
	/// @param     DeviceStatus [in] �����豸״̬����, �ο�KSJ_DEVICESTATUS�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetDeviceStatusString(KSJ_DEVICESTATUS DeviceStatus);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetCalibrationMapModeString
	/// @brief     ���У��ģʽ�ַ���
	/// @param     MapMode [in] ����У��ģʽ����, �ο�KSJ_MAPMODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetCalibrationMapModeString(KSJ_MAPMODE MapMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetBadPixelThresholdModeString
	/// @brief     ��û�����ֵģʽ�ַ���
	/// @param     ThresholdMode [in] ���뻵����ֵģʽ����, �ο�KSJ_THRESHOLD�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetBadPixelThresholdModeString(KSJ_THRESHOLD ThresholdMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetIoDirectionString
	/// @brief     ���IO�����ַ���
	/// @param     Direction [in] ����IO����, 1��ʾ��GPIO�����0��ʾ��GPIO����
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetIoDirectionString(int Direction);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetFlashModeString
	/// @brief     ��������ģʽ�ַ���
	/// @param     FlashMode [in] ���������ģʽ����, �ο�KSJ_FLASHMODE�Ķ���
	/// @return    �ַ�����Ϣ��ַָ��
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API PTCHAR __stdcall KSJ_GetFlashModeString(KSJ_FLASHMODE FlashMode);


#ifdef __cplusplus
}
#endif

#endif
