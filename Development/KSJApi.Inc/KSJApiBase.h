#ifndef __KSJ_API_BASE_H__
#define __KSJ_API_BASE_H__

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
	
	/// ����������KSJApi��������֧�ֵ��������
	enum KSJ_DEVICETYPE
	{
		KSJ_UC130C_MRNN = 0,   ///< 0 Guass2
		KSJ_UC130M_MRNN,       ///< 1 Guass2
		KSJ_RESERVED0,         ///< 2 Not Support
		KSJ_UC320C_MRNN,       ///< 3 Guass2
		KSJ_UC130C_MRYN,       ///< 4 Guass2
		KSJ_UC130M_MRYN,       ///< 5 Guass2
		KSJ_RESERVED1,         ///< 6 Not Support
		KSJ_UC320C_MRYN,       ///< 7 Guass2
		KSJ_UC500C_MRNN,       ///< 8 Guass2
		KSJ_UC500M_MRNN,       ///< 9 Guass2
		KSJ_UC500C_MRYN,       ///< 10 Guass2
		KSJ_UC500M_MRYN,       ///< 11 Guass2
		KSJ_UC320_OCR,         ///< 12 Not Support
		KSJ_UC900C_MRNN,       ///< 13 Not Support
		KSJ_UC1000C_MRNN,      ///< 14 Not Support
		KSJ_UC900C_MRYN,       ///< 15 Not Support
		KSJ_UC1000C_MRYN,      ///< 16 Not Support
		KSJ_MUC120C_MRYYO,     ///< 17 Jelly2 V6.0.121.16
		KSJ_MUC120M_MRYYO,     ///< 18 Jelly2 V6.0.121.16
		KSJ_UD140C_SRNN,       ///< 19 Not Support
		KSJ_UD140M_SRNN,       ///< 20 Not Support
		KSJ_UC36C_MGNN,        ///< 21 Elanus2 Not Support
		KSJ_UC36M_MGNN,        ///< 22 Elanus2 Not Support
		KSJ_UC36C_MGYN,        ///< 23 Elanus2 Not Support
		KSJ_UC36M_MGYN,        ///< 24 Elanus2 Not Support
		KSJ_UC900C_MRYY,       ///< 25 Elanus2
		KSJ_UC1000C_MRYY,      ///< 26 Elanus2
		KSJ_UC1400C_MRYY,      ///< 27 Elanus2
		KSJ_UC36C_MGYY,        ///< 28 Elanus2 Not Support
		KSJ_UC36M_MGYY,        ///< 29 Elanus2 Not Support
		KSJ_UC320C_MRYY,       ///< 30 Elanus2 Not Support
		KSJ_UC500C_MRYY,       ///< 31 Elanus2 Not Support
		KSJ_UC500M_MRYY,       ///< 32 Elanus2 Not Support
		KSJ_MUC130C_MRYN,      ///< 33 OEM
		KSJ_MUC130M_MRYN,      ///< 34 OEM.		 
		KSJ_MUC320C_MRYN,      ///< 35 OEM
		KSJ_MUC36C_MGYYO,      ///< 36 Jelly2
		KSJ_MUC36M_MGYYO,      ///< 37 Jelly2 
		KSJ_MUC130C_MRYY,      ///< 38 Not Support
		KSJ_MUC130M_MRYY,      ///< 39 Not Support
		KSJ_MUC320C_MRYY,      ///< 40 Not Support
		KSJ_MUC500C_MRYYO,     ///< 41 Jelly2
		KSJ_MUC500M_MRYYO,     ///< 42 Jelly2
		KSJ_MUC900C_MRYY,      ///< 43 Not Support
		KSJ_MUC1000C_MRYY,     ///< 44 Not Support
		KSJ_MUC1400C_MRYY,     ///< 45 Not Support
		KSJ_UD205C_SGYY,       ///< 46 Elanus2
		KSJ_UD205M_SGYY,       ///< 47 Elanus2
		KSJ_UD274C_SGYY,       ///< 48 Elanus2
		KSJ_UD274M_SGYY,       ///< 49 Elanus2
		KSJ_UD285C_SGYY,       ///< 50 Elanus2
		KSJ_UD285M_SGYY,       ///< 51 Elanus2
		KSJ_MU3C500C_MRYYO,    ///< 52 Jelly3 
		KSJ_MU3C500M_MRYYO,    ///< 53 Jelly3
		KSJ_MU3C1000C_MRYYO,   ///< 54 Jelly3
		KSJ_MU3C1400C_MRYYO,   ///< 55 Jelly3
		KSJ_MU3V130C_CGYYO,    ///< 56 Jelly3
		KSJ_MU3V130M_CGYYO,    ///< 57 Jelly3
		KSJ_MU3E130C_EGYYO,    ///< 58 Jelly3
		KSJ_MU3E130M_EGYYO,    ///< 59 Jelly3
		KSJ_MUC36C_MGYFO,      ///< 60 Jelly1
		KSJ_MUC36M_MGYFO,      ///< 61 Jelly1
		KSJ_MU3C120C_MGYYO,    ///< 62 Jelly3
		KSJ_MU3C120M_MGYYO,    ///< 63 Jelly3
		KSJ_MU3E200C_EGYYO,    ///< 64 Jelly3
		KSJ_MU3E200M_EGYYO,    ///< 65 Jelly3
		KSJ_MUC130C_MRYNO,     ///< 66 Jelly1
		KSJ_MUC130M_MRYNO,     ///< 67 Jelly1
		KSJ_MUC320C_MRYNO,     ///< 68 Jelly1
		KSJ_U3C130C_MRYNO,     ///< 69 Not Support
		KSJ_U3C130M_MRYNO,     ///< 70 Not Support
		KSJ_U3C320C_MRYNO,     ///< 71 Not Support
		KSJ_U3C500C_MRYNO,     ///< 72 Guass3
		KSJ_U3C500M_MRYNO,     ///< 73 Guass3
		KSJ_MU3C1401C_MRYYO,   ///< 74 DELETE Not Support 
		KSJ_MU3C1001C_MRYYO,   ///< 75 DELETE Not Support
		KSJ_MUC131M_MRYN,      ///< 76 OEM Device
		KSJ_MU3C501C_MRYYO,    ///< 77 DELETE Not Support
		KSJ_MU3C501M_MRYYO,    ///< 78 DELETE Not Support
		KSJ_MUC120C_MGYYO,     ///< 79 Jelly2
		KSJ_MUC120M_MGYYO,     ///< 80 Jelly2
		KSJ_MU3E131C_EGYYO,    ///< 81 DELETE Not Support
		KSJ_MU3E131M_EGYYO,    ///< 82 DELETE Not Support
		KSJ_MU3E201C_EGYYO,    ///< 83 DELETE Not Support
		KSJ_MU3E201M_EGYYO,    ///< 84 DELETE Not Support   
		KSJ_MISSING_DEVICE,	   ///< 85 Device Lost Program
		KSJ_MU3S230C_SGYYO,    ///< 86 Jelly3 Sony IMX174
		KSJ_MU3S230M_SGYYO,    ///< 87 Jelly3 Sony IMX174
		KSJ_MU3S640C_SRYYO,    ///< 88 Jelly3 Sony IMX178
		KSJ_MU3S640M_SRYYO,    ///< 89 Jelly3 Sony IMX178
		KSJ_CUD285C_SGYYO,     ///< 90
		KSJ_CUD285M_SGYYO,     ///< 91
		KSJ_MU3S231C_SGYYO,    ///< 92 Jelly3 Sony IMX249
		KSJ_MU3S231M_SGYYO,    ///< 93 Jelly3 Sony IMX249
		KSJ_MU3S500C_SGYYO,    ///< 94
		KSJ_MU3S500M_SGYYO,    ///< 95
		KSJ_MU3S1200C_SRYYO,   ///< 96
		KSJ_MU3S1200M_SRYYO,   ///< 97
		KSJ_MU3L2K7C_AGYYO,    ///< 98
		KSJ_MU3L2K7M_AGYYO,    ///< 99
		KSJ_MU3L4K3C_AGYYO,    ///< 100
		KSJ_MU3L4K3M_AGYYO,    ///< 101
		KSJ_MU3HS2000C_SRYYO,  ///< 102
		KSJ_MU3HS2000M_SRYYO,  ///< 103
		KSJ_MU3HS500C_SGYYO,   ///< 104
		KSJ_MU3HS500M_SGYYO,   ///< 105
		KSJ_MU3HS230C_SGYYO,   ///< 106 imx174 
		KSJ_MU3HS230M_SGYYO,   ///< 107
		KSJ_MU3HI400C_IGYYO,   ///< 108
		KSJ_MU3HI400M_IGYYO,   ///< 109
		KSJ_TEST_CAMERA,       ///< 110
		KSJ_MU3HI401C_IGYYO, 
		KSJ_MU3HI401M_IGYYO,
		KSJ_MU3S40C_SGYYO, 
		KSJ_MU3S40M_SGYYO,     ///< 114
		KSJ_MU3S210C_SRYYO,    ///< 115
		KSJ_MU3S210M_SRYYO,    ///< 116
		KSJ_MU3I130C_IGYYO,    ///< 117
		KSJ_MU3I130M_IGYYO,    ///< 118
		KSJ_MU3S321C_SGYYO,    ///< 119
		KSJ_MU3S321M_SGYYO,    ///< 120
		KSJ_MU3S641M_SRYYO,    ///< 121
		KSJ_MU3S1201M_SRYYO,   ///< 122
		KSJ_MU3HS2001M_SRYYO,  ///< 123
		KSJ_MU3S211M_SRYYO,    ///< 124
		KSJ_MU3C36C_MGYY,      ///< 125
		KSJ_MU3C36M_MGYY,      ///< 126
		KSJ_MU3HS1200C_SRYYO,  ///< 127
		KSJ_MU3HS1200M_SRYYO,  ///< 128
		KSJ_MU3S160C_SGYYO,    ///< 129
		KSJ_MU3S160M_SGYYO,    ///< 130
		KSJ_MU3S641C_SRYYO     ///< 131
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_Init
	/// @brief     ��ʼ��KSJApi��̬�⣬�ú������������������ڼ�ֻ��Ҫ����һ�Ρ�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention һ���ڳ����ʼ��ʱ����
	///          \li ��������ִ���������֮ǰ��������Ӻ�
	///          \li �����Ҫ�����豸����ִ�з���ʼ��KSJ_UnInit()����ִ��KSJ_Init()����Ҫ�ر�ע����ǣ��������������Ժ󣬾��������������Ӧ�������ſ��ܻ�ı䡣
	///          \li �����Ҫ����ָ�����������Ҫ������������䲻ͬ�����Serials��KSJ_SetSerials()�������ݲ�ͬ����Ź�������ǰ��������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_Init(void);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_UnInit
	/// @brief     ����ʼ��KSJApi��̬��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�����ͷŷ�����Դ���رձ������������Ѿ��򿪵��豸
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_UnInit(void);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_DeviceGetCount
	/// @brief     �õ��豸��Ŀ
	/// @return    ���ӵ������ϵ�KSJ�豸��Ŀ
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetCount(void);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_DeviceGetInformation
	/// @brief     �õ��豸��Ϣ���ͺţ���ţ��̼��汾�ţ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pusDeviceType[out] �����豸���͵ĵ�ַָ��
	/// @param     pnSerials[out] �����豸��ŵĵ�ַָ�룬ͨ�������ſ�������ͬ����������������ſ���ͨ��KSJ_SetSerials()�޸�
	/// @param     pusFirmwareVersion[out] �����豸�̼��汾�ŵĵ�ַָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformation(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_DeviceGetInformationEx
	/// @brief     �õ��豸��Ϣ���ͺţ���ţ��̼��汾�ţ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pusDeviceType[out] �����豸���͵ĵ�ַָ��
	/// @param     pnSerials[out] �����豸��ŵĵ�ַָ�룬ͨ�������ſ�������ͬ����������������ſ���ͨ��KSJ_SetSerials()�޸�
	/// @param     pusFirmwareVersion[out] �����豸�̼��汾�ŵĵ�ַָ��
	/// @param     pusFpgaVersion[out] �����豸FPGA�汾�ŵĵ�ַָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformationEx(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion, OUT unsigned short *pwFpgaVersion);

	/// �����������
	enum KSJ_PARAM
	{
		KSJ_EXPOSURE = 0,        ///< Exposure Time (ms)
		KSJ_RED,                 ///< Red Gain, for line scan sensor map to seg0, for ccd map to KSJ_VGAGAIN
		KSJ_GREEN,               ///< Green Gain, for line scan sensor map to seg1, for ccd map to KSJ_LAMPLEVEL
		KSJ_BLUE,                ///< Blue Gain, for CCD map to KSJ_CDSGAIN
		KSJ_GAMMA,               ///< Gamma
		KSJ_PREVIEW_COLUMNSTART, ///< Preview Col Start
		KSJ_PREVIEW_ROWSTART,    ///< Preview Row Start
		KSJ_CAPTURE_COLUMNSTART, ///< Capture Col Start
		KSJ_CAPTURE_ROWSTART,    ///< Capture Row Start
		KSJ_HORIZONTALBLANK,     ///< Horizontal Blank
		KSJ_VERTICALBLANK,       ///< Vertical Blank
		KSJ_FLIP,                ///< Flip
		KSJ_BIN,                 ///< Binning
		KSJ_MIRROR,              ///< Mirror
		KSJ_CONTRAST,            ///< Contrast
		KSJ_BRIGHTNESS,          ///< Brightness
		KSJ_VGAGAIN,             ///< VGA Gain(CCD)
		KSJ_CLAMPLEVEL,          ///< Clamp Level(CCD)
		KSJ_CDSGAIN,             ///< CDS Gain(CCD)
		KSJ_RED_SHIFT,           ///< Not Use
		KSJ_GREEN_SHIFT,         ///< Not Use
		KSJ_BLUE_SHIFT,          ///< Not Use
		KSJ_COMPANDING,          ///< Companding
		KSJ_EXPOSURE_LINES,      ///< Exposure Lines
		KSJ_SATURATION,          ///< Saturation
		KSJ_TRIGGERDELAY,        ///< Trigger Delay Step = 100uS
		KSJ_STROBEDELAY,         ///< Not Use
		KSJ_TRIGGER_MODE,        ///< Trigger Mode
		KSJ_TRIGGER_METHOD,      ///< Trigger Method
		KSJ_BLACKLEVEL,          ///< Black Level
		KSJ_BLACKLEVEL_THRESHOLD_AUTO, ///< Black Level Threshold Auto
		KSJ_BLACKLEVEL_THRESHOLD_LO,   ///< Black Level Low Threshold
		KSJ_BLACKLEVEL_THRESHOLD_HI    ///< Black Level High Threshold
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetParamRange
	/// @brief     ��ȡָ��������ȡֵ��Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     Param [in] ָ���Ĳ������ο�KSJ_PARAM���壩
	/// @param     pnMinValue[out] ȡ��ָ����������Сֵ
	/// @param     pnMaxValue[out] ȡ��ָ�����������ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParamRange(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnMinValue, OUT int *pnMaxValue);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetParam
	/// @brief     �����������ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     Param [in] ָ���Ĳ������ο�KSJ_PARAM���壩
	/// @param     nValue [in] �������õ�ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetParam(IN int nIndex, IN KSJ_PARAM Param, IN  int nValue);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetParam
	/// @brief     ��ȡ�������ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     Param [in] ָ���Ĳ������ο�KSJ_PARAM���壩
	/// @param     pnValue[out] ����ֵ�ĵ�ַָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParam(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ExposureTimeSet
	/// @brief     �����ع�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fExposureTimeMs [in] ���õ��ع�ʱ�䣬��λ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeSet(int nIndex, float fExposureTimeMs);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ExposureTimeGet
	/// @brief     ��ȡ�ع�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfExpTimeMs [out] �����ع�ʱ���ָ�룬��λ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeGet(int nIndex, float *pfExpTimeMs);

	///< ö�����Ϳ��Ӽѳ��ģʽ���壨��Ϊ�г����г�㣩
	enum KSJ_ADDRESSMODE
	{ 
		KSJ_SKIPNONE = 0, ///< ������������ӳ����÷�Χ�ڵ����ص�
		KSJ_SKIP2,        ///< ������Ϊ��ʱ�����col0, col2, col4, col6, col8, col10�ȣ�   ������Ϊ��ʱ�����row0, row2, row4, row6, row8, row10��
		KSJ_SKIP3,        ///< ������Ϊ��ʱ�����col0, col3, col6, col9, col12, col15�ȣ�  ������Ϊ��ʱ�����row0, row3, row6, row9, row12, row15��
		KSJ_SKIP4,        ///< ������Ϊ��ʱ�����col0, col4, col8, col12, col16, col20�ȣ� ������Ϊ��ʱ�����row0, row4, row8, row12, row16, row20��
		KSJ_SKIP8         ///< ������Ϊ��ʱ�����col0, col8, col16, col24, col32, col40�ȣ�������Ϊ��ʱ�����row0, row8, row16, row24, row32, row40��
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetDefaultFieldOfView
	/// @brief     ��ȡ�豸��Ĭ�ϲɼ��ӳ���С��Ҳ�����豸��֧�ֵ�����ӳ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnRowStart[out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnColSize [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч����ˮƽ������
	/// @param     pnRowSize [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч����ֱ����
	/// @param     pAmCol [out] ����ͼ��й�оƬ�ɼ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pAmRow [out] ����ͼ��й�оƬ�ɼ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureSetFieldOfView
	/// @brief     ���òɼ��ӳ���С
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [in] �ɼ�ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
	/// @param     pnRowStart [in] �ɼ�ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [in] �ɼ�ʱ��Ч���������ˮƽ������
	/// @param     pnRowSize [in] �ɼ�ʱ��Ч��������Ĵ�ֱ����
	/// @param     ColAddressMode [in] �ɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     RowAddressMode [in] �ɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li ������õĲ��������������FOVҪ��������һЩ���Ҫ��Startλ�ñ�������2�ı�����Size��������4�ı�������������ĳ�����ģʽ���������ڲ������Զ�ʹ����ӽ��Ĳ����������ã�������RET_SUCCESS(0)
	///           \li ���������Ժ���Ҫ���»�ȡ��ǰʵ����Ч�Ĳ�����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetFieldOfView
	/// @brief     ��ȡ�ɼ��ӳ���ʵ�ʴ�С
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [out] ���زɼ�ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
	/// @param     pnRowStart[out] ���زɼ�ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [out] ���زɼ�ʱ��Ч���������ˮƽ������
	/// @param     pnRowSize [out] �����زɼ�ʱ��Ч��������Ĵ�ֱ����
	/// @param     pAmCol [out] ���زɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pAmRow [out] ���زɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetSize
	/// @brief     ��ȡ�ɼ�ͼ��Ŀ�Ⱥ͸߶�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnWidth [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ؿ��
	/// @param     pnHeight [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ظ߶�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li ʵ�ʲɼ�ͼ������ؿ����ɼ��ӳ��д�С�����ģʽ�й�
	///           \li ʵ�ʲɼ�ͼ������ظ߶���ɼ��ӳ��д�С�����ģʽ����֡�ɼ����й�
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSize(int nIndex, int *pnWidth, int *pnHeight);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetSizeEx
	/// @brief     ��ȡ�ɼ�ͼ��Ŀ�Ⱥ͸߶ȣ���λ�����أ���λͼ��ȣ�8��24��32��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnWidth [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ؿ��
	/// @param     pnHeight [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ظ߶�
	/// @param     pnBitCount [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li ʵ�ʲɼ�ͼ������ؿ����ɼ��ӳ��д�С�����ģʽ�й�
	///           \li ʵ�ʲɼ�ͼ������ظ߶���ɼ��ӳ��д�С�����ģʽ����֡�ɼ����й�
	///           \li ʵ�ʲɼ�ͼ���λͼ����뵱ǰ��������Լ�Bayerģʽ�й�
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureRawData
	/// @brief     �ɼ�һ֡ԭʼ��ڰ�ͼ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRawData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize��KSJ_CaptureGetSizeEx�������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li pRawData����ʹ������ǰ���䣬����Ĵ�СӦΪKSJ_CaptureGetSize�õ���ͼ����*ͼ��߶ȣ������16bit����Ӧ�����ٳ���2��
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawData(int nIndex, unsigned char *pRawData);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureRgbData
	/// @brief     �ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRgbData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li pRgbData����ʹ������ǰ���䣬����Ĵ�СӦΪKSJ_CaptureGetSizeEx�õ���ͼ����*ͼ��߶�*λͼ���/8��
	///           \li ����Ǻڰ�������ú���ȡ�õ�ͼ���ԭʼ�Ҷ�ͼ����KSJ_CaptureRawData�õ���ͼ������һ����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbData(int nIndex, unsigned char *pRgbData);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureRgbDataEx
	/// @brief     �ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRgbData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
	/// @param     pnHeight [out] ����ͼ��ĸ߶ȣ����أ�
	/// @param     pnBitCount [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataEx(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetDefaultFieldOfView
	/// @brief     ��ȡ�豸��Ĭ��Ԥ���ӳ���С��Ҳ�����豸��֧�ֵ�����ӳ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnRowStart[out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnColSize [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч����ˮƽ������
	/// @param     pnRowSize [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч����ֱ����
	/// @param     pAmCol [out] ����ͼ��й�оƬ�ɼ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pAmRow [out] ����ͼ��й�оƬ�ɼ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewSetFieldOfView
	/// @brief     ����Ԥ���ӳ���С
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [in] Ԥ��ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
	/// @param     pnRowStart [in] Ԥ��ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [in] Ԥ��ʱ��Ч���������ˮƽ������
	/// @param     pnRowSize [in] Ԥ��ʱ��Ч��������Ĵ�ֱ����
	/// @param     ColAddressMode [in] Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     RowAddressMode [in] Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li ������õĲ��������������FOVҪ��������һЩ���Ҫ��Startλ�ñ�������2�ı�����Size��������4�ı�������������ĳ�����ģʽ���������ڲ������Զ�ʹ����ӽ��Ĳ����������ã�������RET_SUCCESS(0)
	///           \li ���������Ժ���Ҫ���»�ȡ��ǰʵ����Ч�Ĳ�����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetFieldOfView
	/// @brief     ��ȡԤ���ӳ���ʵ�ʴ�С
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [out] ���زɼ�ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
	/// @param     pnRowStart[out] ���زɼ�ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [out] ���زɼ�ʱ��Ч���������ˮƽ������
	/// @param     pnRowSize [out] �����زɼ�ʱ��Ч��������Ĵ�ֱ����
	/// @param     pAmCol [out] ���زɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pAmRow [out] ���زɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetSize
	/// @brief     ��ȡԤ��ͼ��Ŀ�Ⱥ͸߶�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnWidth [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ������ؿ��
	/// @param     pnHeight [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ������ظ߶�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li ʵ��Ԥ��ͼ������ؿ����ɼ��ӳ��д�С�����ģʽ�й�
	///           \li ʵ��Ԥ��ͼ������ظ߶���ɼ��ӳ��д�С�����ģʽ����֡�ɼ����й�
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSize(int nIndex, int *pnWidth, int *pnHeight);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetSizeEx
	/// @brief     ��ȡԤ��ͼ��Ŀ�Ⱥ͸߶ȣ���λ�����أ���λͼ��ȣ�8��24��32��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnWidth [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ������ؿ��
	/// @param     pnHeight [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ������ظ߶�
	/// @param     pnBitCount [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ���λͼ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li ʵ��Ԥ��ͼ������ؿ����ɼ��ӳ��д�С�����ģʽ�й�
	///           \li ʵ��Ԥ��ͼ������ظ߶���ɼ��ӳ��д�С�����ģʽ����֡�ɼ����й�
	///           \li ʵ��Ԥ��ͼ���λͼ����뵱ǰ��������Լ�Bayerģʽ�й�
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
    ///
	/// @brief     KSJ_PreviewSetPos
    /// @brief     ������Ƶͼ���ڴ����ϵ���ʾλ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     hWnd [in] ��ʾ���ڵľ��
    /// @param     x [in] ��ʾλ����Դ������Ͻ�ˮƽƫ�ƣ����أ�
	/// @param     y [in] ��ʾλ����Դ������ϽǴ�ֱƫ�ƣ����أ�
	/// @param     nWidth [in] ��ʾ�Ŀ�ȣ��������������Ԥ��ͼ��Ŀ�ȣ�ͼ���ˮƽ�Ŵ󣬷�֮��С
	/// @param     nHeight [in] ��ʾͼ��ĸ߶ȣ��������������Ԥ��ͼ��ĸ߶ȣ�ͼ��ᴹֱ�Ŵ󣬷�֮��С
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetPos(int nIndex, HWND hWnd, int x, int y, int nWidth, int nHeight);
	
	///-----------------------------------------------------------------------------
    ///
	/// @brief     KSJ_PreviewGetPos
    /// @brief     �õ���ǰ��ƵԤ��ͼ�����ʾλ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     px [out] ������ʾλ����Դ������Ͻ�ˮƽƫ�ƣ����أ�
	/// @param     py [out] ������ʾλ����Դ������ϽǴ�ֱƫ�ƣ����أ�
	/// @param     pnWidth [out] ������ʾ�Ŀ��
	/// @param     pnHeight [out] ������ʾͼ��ĸ߶�
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPos(int nIndex, int *px, int *py, int *pnWidth, int *pnHeight);
   
    ///-----------------------------------------------------------------------------
    ///
	/// @brief     KSJ_PreviewStart
    /// @brief     ������Ƶ�����û�������ͨ��KSJ_PreviewSetPos��������Ƶ��ʾ�Ĵ��ڼ�λ�ô���һ��Ԥ�����ڣ����򽫿�����Ԥ����Ƶ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bStart [in] true ����Ƶ������ʾ�ڴ���ָ��λ�ã��ο�KSJ_PreviewSetPos��������false �ر���Ƶ�� 
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStart(int nIndex, bool bStart);
	
	/// Ԥ����Ƶ����״̬
	enum KSJ_PREVIEWSTATUS 
	{
		PS_STOP,   ///< ��Ƶ��ֹͣ
		PS_START,  ///< ��Ƶ������
		PS_PAUSE   ///< ��Ƶ����ͣ
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_PreviewGetStatus
    /// @brief     ��ȡ��ƵԤ����״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pPreviewStatus [out] ����Ԥ��״̬
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatus(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_PreviewStartEx
    /// @brief     �ò���ģʽ������Ƶ�����û�������ͨ��KSJ_PreviewSetPos��������Ƶ��ʾ�Ĵ��ڼ�λ�ô���һ��Ԥ�����ڣ����򽫿�����Ԥ����Ƶ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bStart [in] true ������Ƶ����false �ر���Ƶ�� 
	/// @param     bParallel [in] true �ò���ģʽ����Ƶ����false ʹ�ô���ģʽ 
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStartEx(int nIndex, bool bStart, bool bParallel );

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_PreviewGetStatusEx
    /// @brief     ��ȡ��ƵԤ���Ͳ��е�״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pPreviewStatus [out] ����Ԥ��״̬ 
	/// @param     pbParallel [out] ���ز���״̬
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatusEx(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus, bool *pbParallel);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_PreviewGetFrameRateEx
    /// @brief     Ԥ��ʱ����ȡ�ɼ�����ʾ��֡��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fFrameRateCapture [out] ���ص�ǰ�ɼ���֡�� 
	/// @param     fFrameRateShow [out] ���ص�ǰ��Ƶ����֡��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRateEx(int nIndex, float *fFrameRateCapture, float *fFrameRateShow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_GetPreviewFrameCount
    /// @brief     ��ȡԤ���ɼ�����ʾ��ͼ����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnCaptureFrameCount [out] ���ص�ǰԤ��һ���ɼ���ͼ���� 
	/// @param     pnShowFrameCount [out] ���ص�ǰԤ��һ����ʾ��ͼ��ͼ����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetPreviewFrameCount(int nIndex, int *pnCaptureFrameCount, int *pnShowFrameCount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SendPktEnd
	/// @brief     ����������ǰ��������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li ��ʹ��KSJ_CaptureRgbData�Ⱥ����ɼ�ͼ��ʱ�����һֱû��ͼ�񴫻أ������ⴥ��ģʽ�£���ǰû���ⴥ���źţ�����Ҫ�ڳ�ʱʱ���ڽ����ɼ�������ִ�иò�����Capture�����������ء�
	///           \li Capture�������������п�������֡��RET_ZEROFRAME�����߰�֡��RET_INVALIDFRAME�����ݴ���һ�뱻�жϣ�
	///           \li �����ǰû��ִ�вɼ�������ִ���˸ò�����һ�λ��߶�Σ�����ô��һ�ν���ɼ���һ����֡��RET_ZEROFRAME��
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SendPktEnd(int nIndex);

	///-----------------------------------------------------------------------------
    ///
	/// @brief     KSJ_RebootDevice
    /// @brief     �����������������������������º���������USB����
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RebootDevice(int nIndex);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LogSet
	/// @brief     ����Log��־�Ƿ����������ı���Ŀ¼
	/// @param     bEnable [in] �Ƿ��Log��־���������
	/// @param     pszFolder [in] �����Log��־�������Ŀ¼������ΪNULL����ַ�����
	///				\li ���ΪNULL����ַ�������Log���Ŀ¼���Զ�������Ŀ¼λ����KSJAPI������Ŀ¼�´�������ΪKSJApiLog��Ŀ¼
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogSet(bool bEnable, const TCHAR *pszFolder);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LogGet
	/// @brief     �����־�����Ϣ
	/// @param     bEnable [out] �����Ƿ��Ѿ���Log��־���������
	/// @param     pszFolder[out] ���������Log��־�������Ŀ¼������ΪNULL����ʾ�����ȡ����Ϣ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����������ʱ�̵���
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogGet(bool *bEnable, TCHAR *pszFolder);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetVersion
	/// @brief     ��ȡKSJAPI��İ汾��
	/// @param     pnMaj1[out] �������汾��1��һ������Ҫ����ṹ����ʱ��ı䣬����1�����汾��1��ͬ��API�ⲻ����
	/// @param     pnMaj2[out] �������汾��2��һ������Ҫ��������ʱ��ı䣬����1
	/// @param     pnMin1[out] ���شΰ汾��1��һ������Ҫ����ṹ���������޸���Ҫ�߼�ʱ��ı䣬����1
	/// @param     pnMin2[out] ���شΰ汾��2��һ����С�ĸĶ����޸�Bugʱ��ı䣬����1
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetVersion(OUT int *pnMaj1, OUT int *pnMaj2, OUT int *pnMin1, OUT int *pnMin2);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HelperSaveToBmp
	/// @brief     ��ͼ�����ݱ���ΪBMP�ļ�
	/// @param     pData [in] ָ��ͼ�����ݵ��׵�ַָ��
	/// @param     nWidth [in] ͼ��Ŀ�ȣ����أ�
	/// @param     nHeight [in] ͼ��ĸ߶ȣ����أ�
	/// @param     nBitCount [in] 8Ϊ�Ҷ�ͼ�����ݣ�24Ϊ24λ��ɫͼ�����ݣ�����ֵ��֧��
	/// @param     pszFileName [in] �����ļ���ȫ·����������·��Ŀ¼������ڣ�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, const TCHAR *pszFileName);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HelperSaveToJpg
	/// @brief     ��ͼ�����ݱ���ΪJPG�ļ�
	/// @param     pData [in] ָ��ͼ�����ݵ��׵�ַָ��
	/// @param     nWidth [in] ͼ��Ŀ�ȣ����أ�
	/// @param     nHeight [in] ͼ��ĸ߶ȣ����أ�
	/// @param     nBitCount [in] 8Ϊ�Ҷ�ͼ�����ݣ�24Ϊ24λ��ɫͼ�����ݣ�����ֵ��֧��
	/// @param     pszFileName [in] �����ļ���ȫ·����������·��Ŀ¼������ڣ�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToJpg(unsigned char *pData, int nWidth, int nHeight, int nBitCount, int nQulity, const TCHAR *pszFileName);


#ifdef __cplusplus
}
#endif

#endif
