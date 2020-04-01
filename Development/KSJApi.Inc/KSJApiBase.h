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
	enum KSJ_DEVICETYPE// ����������KSJApi��������֧�ֵ��������
	{
		KSJ_UC130C_MRNN = 0,   // 0 Guass2
		KSJ_UC130M_MRNN,       // 1 Guass2
		KSJ_RESERVED0,         // 2 Not Support
		KSJ_UC320C_MRNN,       // 3 Guass2
		KSJ_UC130C_MRYN,       // 4 Guass2
		KSJ_UC130M_MRYN,       // 5 Guass2
		KSJ_RESERVED1,         // 6 Not Support
		KSJ_UC320C_MRYN,       // 7 Guass2
		KSJ_UC500C_MRNN,       // 8 Guass2
		KSJ_UC500M_MRNN,       // 9 Guass2
		KSJ_UC500C_MRYN,       // 10 Guass2
		KSJ_UC500M_MRYN,       // 11 Guass2
		KSJ_UC320_OCR,         // 12 Not Support
		KSJ_UC900C_MRNN,       // 13 Not Support
		KSJ_UC1000C_MRNN,      // 14 Not Support
		KSJ_UC900C_MRYN,       // 15 Not Support
		KSJ_UC1000C_MRYN,      // 16 Not Support
		KSJ_MUC120C_MRYYO,     // 17 Jelly2 V6.0.121.16
		KSJ_MUC120M_MRYYO,     // 18 Jelly2 V6.0.121.16
		KSJ_UD140C_SRNN,       // 19 Not Support
		KSJ_UD140M_SRNN,       // 20 Not Support
		KSJ_UC36C_MGNN,        // 21 Elanus2 Not Support
		KSJ_UC36M_MGNN,        // 22 Elanus2 Not Support
		KSJ_UC36C_MGYN,        // 23 Elanus2 Not Support
		KSJ_UC36M_MGYN,        // 24 Elanus2 Not Support
		KSJ_UC900C_MRYY,       // 25 Elanus2
		KSJ_UC1000C_MRYY,      // 26 Elanus2
		KSJ_UC1400C_MRYY,      // 27 Elanus2
		KSJ_UC36C_MGYY,        // 28 Elanus2 Not Support
		KSJ_UC36M_MGYY,        // 29 Elanus2 Not Support
		KSJ_UC320C_MRYY,       // 30 Elanus2 Not Support
		KSJ_UC500C_MRYY,       // 31 Elanus2 Not Support
		KSJ_UC500M_MRYY,       // 32 Elanus2 Not Support
		KSJ_MUC130C_MRYN,      // 33 OEM
		KSJ_MUC130M_MRYN,      // 34 OEM.
		 
		KSJ_MUC320C_MRYN,      // 35 OEM
		KSJ_MUC36C_MGYYO,      // 36 Jelly2
		KSJ_MUC36M_MGYYO,      // 37 Jelly2 
		KSJ_MUC130C_MRYY,      // 38 Not Support
		KSJ_MUC130M_MRYY,      // 39 Not Support
		KSJ_MUC320C_MRYY,      // 40 Not Support
		KSJ_MUC500C_MRYYO,     // 41 Jelly2
		KSJ_MUC500M_MRYYO,     // 42 Jelly2
		KSJ_MUC900C_MRYY,      // 43 Not Support
		KSJ_MUC1000C_MRYY,     // 44 Not Support
		KSJ_MUC1400C_MRYY,     // 45 Not Support
		KSJ_UD205C_SGYY,       // 46 Elanus2
		KSJ_UD205M_SGYY,       // 47 Elanus2
		KSJ_UD274C_SGYY,       // 48 Elanus2
		KSJ_UD274M_SGYY,       // 49 Elanus2
		KSJ_UD285C_SGYY,       // 50 Elanus2
		KSJ_UD285M_SGYY,       // 51 Elanus2
		KSJ_MU3C500C_MRYYO,    // 52 Jelly3 
		KSJ_MU3C500M_MRYYO,    // 53 Jelly3
		KSJ_MU3C1000C_MRYYO,   // 54 Jelly3
		KSJ_MU3C1400C_MRYYO,   // 55 Jelly3
		KSJ_MU3V130C_CGYYO,    // 56 Jelly3
		KSJ_MU3V130M_CGYYO,    // 57 Jelly3
		KSJ_MU3E130C_EGYYO,    // 58 Jelly3
		KSJ_MU3E130M_EGYYO,    // 59 Jelly3
		KSJ_MUC36C_MGYFO,      // 60 Jelly1
		KSJ_MUC36M_MGYFO,      // 61 Jelly1
		KSJ_MU3C120C_MGYYO,    // 62 Jelly3
		KSJ_MU3C120M_MGYYO,    // 63 Jelly3
		KSJ_MU3E200C_EGYYO,    // 64 Jelly3
		KSJ_MU3E200M_EGYYO,    // 65 Jelly3
		KSJ_MUC130C_MRYNO,     // 66 Jelly1
		KSJ_MUC130M_MRYNO,     // 67 Jelly1
		KSJ_MUC320C_MRYNO,     // 68 Jelly1
		KSJ_U3C130C_MRYNO,     // 69 Not Support
		KSJ_U3C130M_MRYNO,     // 70 Not Support
		KSJ_U3C320C_MRYNO,     // 71 Not Support
		KSJ_U3C500C_MRYNO,     // 72 Guass3
		KSJ_U3C500M_MRYNO,     // 73 Guass3
		KSJ_MU3C1401C_MRYYO,   // 74 DELETE Not Support 
		KSJ_MU3C1001C_MRYYO,   // 75 DELETE Not Support
		KSJ_MUC131M_MRYN,      // 76 OEM Device
		KSJ_MU3C501C_MRYYO,    // 77 DELETE Not Support
		KSJ_MU3C501M_MRYYO,    // 78 DELETE Not Support
		KSJ_MUC120C_MGYYO,     // 79 Jelly2
		KSJ_MUC120M_MGYYO,     // 80 Jelly2
		KSJ_MU3E131C_EGYYO,    // 81 DELETE Not Support
		KSJ_MU3E131M_EGYYO,    // 82 DELETE Not Support
		KSJ_MU3E201C_EGYYO,    // 83 DELETE Not Support
		KSJ_MU3E201M_EGYYO,    // 84 DELETE Not Support   
		KSJ_MISSING_DEVICE,	   // 85 Device Lost Program
		KSJ_MU3S230C_SGYYO,    // 86 Jelly3 Sony IMX174
		KSJ_MU3S230M_SGYYO,    // 87 Jelly3 Sony IMX174
		KSJ_MU3S640C_SRYYO,    // 88 Jelly3 Sony IMX178
		KSJ_MU3S640M_SRYYO,    // 89 Jelly3 Sony IMX178
		KSJ_CUD285C_SGYYO,     // 90
		KSJ_CUD285M_SGYYO,     // 91
		KSJ_MU3S231C_SGYYO,    // 92 Jelly3 Sony IMX249
		KSJ_MU3S231M_SGYYO,    // 93 Jelly3 Sony IMX249
		KSJ_MU3S500C_SGYYO,    // 94
		KSJ_MU3S500M_SGYYO,    // 95
		KSJ_MU3S1200C_SRYYO,   // 96
		KSJ_MU3S1200M_SRYYO,   // 97
		KSJ_MU3L2K7C_AGYYO,    // 98
		KSJ_MU3L2K7M_AGYYO,    // 99
		KSJ_MU3L4K3C_AGYYO,    // 100
		KSJ_MU3L4K3M_AGYYO,    // 101
		KSJ_MU3HS2000C_SRYYO,  // 102
		KSJ_MU3HS2000M_SRYYO,  // 103
		KSJ_MU3HS500C_SGYYO,   // 104
		KSJ_MU3HS500M_SGYYO,   // 105
		KSJ_MU3HS230C_SGYYO,   // 106 imx174 
		KSJ_MU3HS230M_SGYYO,   // 107
		KSJ_MU3HI400C_IGYYO,   // 108
		KSJ_MU3HI400M_IGYYO,   // 109
		KSJ_TEST_CAMERA,       // 110
		KSJ_MU3HI401C_IGYYO, 
		KSJ_MU3HI401M_IGYYO,
		KSJ_MU3S40C_SGYYO, 
		KSJ_MU3S40M_SGYYO,     // 114
		KSJ_MU3S210C_SRYYO,    // 115
		KSJ_MU3S210M_SRYYO,    // 116
		KSJ_MU3I130C_IGYYO,    // 117
		KSJ_MU3I130M_IGYYO,    // 118
		KSJ_MU3S321C_SGYYO,    // 119
		KSJ_MU3S321M_SGYYO,     // 120
		KSJ_MU3S641M_SRYYO,
		KSJ_MU3S1201M_SRYYO,
		KSJ_MU3HS2001M_SRYYO,
		KSJ_MU3S211M_SRYYO,
		KSJ_MU3C36C_MGYY,
		KSJ_MU3C36M_MGYY,
		KSJ_MU3HS1200C_SRYYO,
		KSJ_MU3HS1200M_SRYYO

	};
	
	//-----------------------------------------------------------------------------
    // ������KSJ_LogSet
    // ���ܣ�����Log��־�Ƿ����������ı���Ŀ¼
    // ������
    //       bEnable�� ���룬�Ƿ��Log��־���������
    //       pszFolder�����룬�����Log��־�������Ŀ¼������ΪNULL����ַ��������ΪNULL����ַ����������Ŀ¼���Զ�������Ŀ¼λ����KSJAPI.dll����Ŀ¼�´���KSJApiLogĿ¼��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogSet(bool bEnable, const TCHAR *pszFolder);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_LogGet
    // ���ܣ������־�����Ϣ
    // ������
    //       bEnable�� ����������Ƿ��Ѿ���Log��־���������
    //       pszFolder����������������Log��־�������Ŀ¼������ΪNULL����ַ�������ʾ�����ȡ����Ϣ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogGet(bool *bEnable, TCHAR *pszFolder);

	//-----------------------------------------------------------------------------
    // ������KSJ_GetVersion
    // ���ܣ���ȡKSJAPI��İ汾��
    // ������
    //       pnMaj1��������������汾��1��һ������Ҫ����ṹ����ʱ��ı䣬����1
    //       pnMaj2��������������汾��2��һ������������ʱ��ı䣬����1
	//       pnMin1����������شΰ汾��1��һ������Ҫ����ṹ����ʱ��ı䣬����1
	//       pnMin2�����شΰ汾��2��һ����С�ĸĶ�ʱ��ı䣬����1
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������������ʱ�̵���
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetVersion(OUT int *pnMaj1, OUT int *pnMaj2, OUT int *pnMin1, OUT int *pnMin2);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_GetErrorInfo
    // ���ܣ���ô������ϸ��Ϣ
    // ������
    //       nErrorNo ���룬���������룬�ο�����״̬�루KSJCode.H��
    //       pszErrorInfo��������������������Ϣ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetErrorInfo(IN int nErrorNo, OUT TCHAR pszErrorInfo[256]);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_Init
    // ���ܣ���ʼ��KSJApi��̬��
    // ��������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵���������ʼ��ʱ����
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_Init(void);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_UnInit
    // ���ܣ�����ʼ��KSJApi��̬��
    // ��������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�����ͷŷ�����Դ���رձ������������Ѿ��򿪵��豸
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_UnInit(void);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_DeviceGetCount
    // ���ܣ��õ��豸��Ŀ
    // ��������
    // ���أ����ӵ������ϵ�KSJ�豸��Ŀ
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetCount(void);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_DeviceGetInformation
    // ���ܣ��õ��豸��Ϣ���ͺţ���ţ��̼��汾�ţ�
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pDeviceType������������豸���͵ĵ�ַָ�루�豸���͵Ķ�����ο�KSJ_DEVICETYPE��
	//       pnSerials������������豸��ŵĵ�ַָ��
	//       pwFirmwareVersion������������豸�̼��汾�ŵĵ�ַָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformation(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_DeviceGetInformationEx
    // ���ܣ��õ��豸��Ϣ���ͺţ���ţ��̼��汾�ţ�
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pDeviceType������������豸���͵ĵ�ַָ�루�豸���͵Ķ�����ο�KSJ_DEVICETYPE��
	//       pnSerials������������豸��ŵĵ�ַָ��
	//       pwFirmwareVersion������������豸�̼��汾�ŵĵ�ַָ��
	//       pwFpgaVersion������������豸FPGA�汾�ŵĵ�ַָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformationEx(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion, OUT unsigned short *pwFpgaVersion);
	
	enum KSJ_PARAM//���������ö������
	{
		KSJ_EXPOSURE = 0,        // Exposure Time (ms)
		KSJ_RED,                 // Red Gain, for line scan sensor map to seg0, for ccd map to KSJ_VGAGAIN
		KSJ_GREEN,               // Green Gain, for line scan sensor map to seg1, for ccd map to KSJ_LAMPLEVEL
		KSJ_BLUE,                // Blue Gain, for CCD map to KSJ_CDSGAIN
		KSJ_GAMMA,               // Gamma
		KSJ_PREVIEW_COLUMNSTART, // Preview Col Start
		KSJ_PREVIEW_ROWSTART,    // Preview Row Start
		KSJ_CAPTURE_COLUMNSTART, // Capture Col Start
		KSJ_CAPTURE_ROWSTART,    // Capture Row Start
		KSJ_HORIZONTALBLANK,     // Horizontal Blank
		KSJ_VERTICALBLANK,       // Vertical Blank
		KSJ_FLIP,                // Flip
		KSJ_BIN,                 // Binning
		KSJ_MIRROR,              // Mirror
		KSJ_CONTRAST,            // Contrast
		KSJ_BRIGHTNESS,          // Brightness
		KSJ_VGAGAIN,             // VGA Gain(CCD)
		KSJ_CLAMPLEVEL,          // Clamp Level(CCD)
		KSJ_CDSGAIN,             // CDS Gain(CCD)
		KSJ_RED_SHIFT,           // Not Use
		KSJ_GREEN_SHIFT,         // Not Use
		KSJ_BLUE_SHIFT,          // Not Use
		KSJ_COMPANDING,          // Companding
		KSJ_EXPOSURE_LINES,      // Exposure Lines
		KSJ_SATURATION,          // Saturation
		KSJ_TRIGGERDELAY,        // Trigger Delay Step = 100uS
		KSJ_STROBEDELAY,         // Not Use
		KSJ_TRIGGER_MODE,        // Trigger Mode
		KSJ_TRIGGER_METHOD,      // Trigger Method
		KSJ_BLACKLEVEL,          // Black Level
		KSJ_BLACKLEVEL_THRESHOLD_AUTO, // Black Level Threshold Auto
		KSJ_BLACKLEVEL_THRESHOLD_LO,   // Black Level Low Threshold
		KSJ_BLACKLEVEL_THRESHOLD_HI    // Black Level High Threshold
	};

	//-----------------------------------------------------------------------------
    // ������KSJ_GetParamRange
    // ���ܣ���ȡ���������÷�Χ
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       Param�����룬ָ���Ĳ������ο�KSJ_PARAM���壩
	//       pnMinValue�������ȡ��ָ���������õ���Сֵ
	//       pnMaxValue�������ȡ��ָ���������õ����ֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParamRange(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnMinValue, OUT int *pnMaxValue);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_SetParam
    // ���ܣ������������
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       Param�����룬ָ���Ĳ������ο�KSJ_PARAM���壩
    //       nValue�����룬�������õ�ֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetParam(IN int nIndex, IN KSJ_PARAM Param, IN  int nValue);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_GetParam
    // ���ܣ���ȡ�������
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       Param�����룬ָ���Ĳ������ο�KSJ_PARAM���壩
	//       pnValue�����������ֵָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParam(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnValue);

	//-----------------------------------------------------------------------------
    // ������KSJ_ExposureTimeSet
    // ���ܣ������ع�ʱ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       fExposureTimeMs�����룬���õ��ع�ʱ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeSet(int nIndex, float fExposureTimeMs);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_ExposureTimeGet
    // ���ܣ���ȡ�ع�ʱ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pfExpTimeMs������������ع�ʱ���ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeGet(int nIndex, float *pfExpTimeMs);

	//-----------------------------------------------------------------------------
    // ������KSJ_GlobalResetShutterSet
    // ���ܣ�����ȫ�ָ�λ��������
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bGlobalReset�����룬����ȫ�ָ�λ����������Ч
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GlobalResetShutterSet(int nIndex, bool bGlobalReset);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_GlobalResetShutterGet
    // ���ܣ��õ�ȫ�ָ�λ��������״̬
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbGlobalReset�����������ȫ�ָ�λ��������״ָ̬��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GlobalResetShutterGet(int nIndex, bool* pbGlobalReset);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreExposureRangeGet
    // ���ܣ��õ�Ԥ�ع�ʱ�䷶Χ
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnMinValue�����������Ԥ�ع�ʱ����Сֵָ�룬��λΪ�ع���
	//       pnMaxValue�����������Ԥ�ع�ʱ�����ֵָ�룬��λΪ�ع���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureRangeGet(int nIndex, int *pnMinValue, int *pnMaxValue);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreExposureTimeSet
    // ���ܣ�����Ԥ�ع�ʱ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       fPreExpTimeMs�����룬���õ�Ԥ�ع�ʱ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeSet(int nIndex, float fPreExpTimeMs);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreExposureTimeGet
    // ���ܣ���ȡԤ�ع�ʱ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pfPreExpTimeMs�����������Ԥ�ع�ʱ���ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeGet(int nIndex, float *pfPreExpTimeMs);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreExposureLinesSet
    // ���ܣ�����Ԥ�ع���
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nPreExpLines�����룬���õ�Ԥ�ع���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesSet(int nIndex, int nPreExpLines);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreExposureLinesGet
    // ���ܣ���ȡԤ�ع���
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnPreExpLines�����������Ԥ�ع�ʱ���ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesGet(int nIndex, int* pnPreExpLines);

	enum KSJ_ADDRESSMODE //ö�����Ϳ��Ӽѳ��ģʽ���壨��Ϊ�г����г�㣩
	{ 
		KSJ_SKIPNONE = 0, //������������ӳ����÷�Χ�ڵ����ص�
		KSJ_SKIP2, //������Ϊ��ʱ�����col0, col1, col4, col5, col8, col9�ȣ�    ������Ϊ��ʱ�����row0, row1, row4, row5, row8, row9��
		KSJ_SKIP3, //������Ϊ��ʱ�����col0, col1, col6, col7, col12, col13�ȣ�  ������Ϊ��ʱ�����row0, row1, row6, row7, row12, row13��
		KSJ_SKIP4, //������Ϊ��ʱ�����col0, col1, col8, col9, col16, col17�ȣ�  ������Ϊ��ʱ�����row0, row1, row8, row9, row16, row17��
		KSJ_SKIP8  //������Ϊ��ʱ�����col0, col1, col16, col17, col32, col33�ȣ�������Ϊ��ʱ�����row0, row1, row16, row17, row32, row33��
	};
	///////////////////////////////////////////Capture/////////////////////////////////
	//-----------------------------------------------------------------------------
    // ������KSJ_CheckFieldOfView
    // ���ܣ����������ӳ�����������Ƿ�ƥ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� ���룬Ҫ����ˮƽ������ʼλ��
    //       pnRowStart�����룬Ҫ���Ĵ�ֱ����ʼλ��
	//       pnColSize�� ���룬Ҫ����ˮƽ������
    //       pnRowSize�����룬Ҫ���Ĵ�ֱ����
	//       AmCol�� ���룬Ҫ������Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       AmRow�����룬Ҫ������Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    // ���أ��ο�����1��ʾƥ�䣬����ƥ��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CheckFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);

	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureGetDefaultFieldOfView
    // ���ܣ���ȡ�豸��Ĭ�ϲɼ��ӳ���С��Ҳ�����豸��֧�ֵ�����ӳ�
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� ���������ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
    //       pnRowStart�����������ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	//       pnColSize�� ���������ͼ��й�оƬ�ɼ�ʱ����й����Ч����ˮƽ������
    //       pnRowSize�����������ͼ��й�оƬ�ɼ�ʱ����й����Ч����ֱ����
	//       pColAddressMode�� ���������ͼ��й�оƬ�ɼ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       pRowAddressMode�����������ͼ��й�оƬ�ɼ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureSetFieldOfView
    // ���ܣ����òɼ��ӳ���С
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� ���룬�ɼ�ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    //       pnRowStart�����룬�ɼ�ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	//       pnColSize�� ���룬�ɼ�ʱ��Ч���������ˮƽ������
    //       pnRowSize�����룬�ɼ�ʱ��Ч��������Ĵ�ֱ����
	//       AmCol�� ���룬�ɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       AmRow�����룬�ɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureGetFieldOfView
    // ���ܣ���ȡ�ɼ��ӳ���ʵ�ʴ�С
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� ��������زɼ�ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    //       pnRowStart����������زɼ�ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	//       pnColSize�� ��������زɼ�ʱ��Ч���������ˮƽ������
    //       pnRowSize������������زɼ�ʱ��Ч��������Ĵ�ֱ����
	//       pColAddressMode�� ��������زɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       pRowAddressMode����������زɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureGetSize
    // ���ܣ���ȡ�ɼ�ͼ��Ŀ�Ⱥ͸߶�
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnWidth�� ��������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ؿ��
    //       pnHeight����������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ظ߶�
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSize(int nIndex, int *pnWidth, int *pnHeight);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureGetSizeEx
    // ���ܣ���ȡ�ɼ�ͼ��Ŀ�Ⱥ͸߶ȣ���λ�����أ���λͼ��ȣ�8��24��32��
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnWidth�� ��������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ؿ��
    //       pnHeight����������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ظ߶�
    //       pnBitCount����������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureRawData
    // ���ܣ��ɼ�һ֡ԭʼ��ڰ�ͼ������
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pRawData����������û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize��KSJ_CaptureGetSizeEx�������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawData(int nIndex, unsigned char *pRawData);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureRgbData
    // ���ܣ��ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pRgbData����������û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbData(int nIndex, unsigned char *pRgbData);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureRgbDataEx
    // ���ܣ��ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pRgbData����������û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
	//       pnWidth�� ���������ͼ��Ŀ�ȣ����أ�
    //       pnHeight�����������ͼ��ĸ߶ȣ����أ�
    //       pnBitCount����������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataEx(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_HelperSaveToBmp
    // ���ܣ���ͼ�����ݱ���ΪBMP�ļ�
    // ������
    //       pData�� ���룬ָ��ͼ�����ݵ��׵�ַָ��
	//       nWidth�� ���룬ͼ��Ŀ�ȣ����أ�
    //       nHeight�����룬ͼ��ĸ߶ȣ����أ�
    //       nBitCount�����룬8Ϊ�Ҷ�ͼ�����ݣ�24Ϊ24λ��ɫͼ�����ݣ�����ֵ��֧��
    //       pszFileName�����룬�����ļ���ȫ·������·��������ڣ�
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������������ʱ�̵���
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, const TCHAR *pszFileName);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_HelperSaveToJpg
    // ���ܣ���ͼ�����ݱ���ΪJPG�ļ�
    // ������
    //       pData�� ���룬ָ��ͼ�����ݵ��׵�ַָ��
	//       nWidth�� ���룬ͼ��Ŀ�ȣ����أ�
    //       nHeight�����룬ͼ��ĸ߶ȣ����أ�
    //       nBitCount�����룬8Ϊ�Ҷ�ͼ�����ݣ�24Ϊ24λ��ɫͼ�����ݣ�����ֵ��֧��
    //       pszFileName�����룬�����ļ���ȫ·������·��������ڣ�
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������������ʱ�̵���
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToJpg(unsigned char *pData, int nWidth, int nHeight, int nBitCount, int nQulity, const TCHAR *pszFileName);

	///////////////////////////////////////////Preview/////////////////////////////////
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetDefaultFieldOfView
    // ���ܣ���ȡ�豸��Ĭ��Ԥ���ӳ���С��Ҳ�����豸��֧�ֵ�����ӳ�
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� ���������ͼ��й�оƬԤ��ʱ����й����Ч������ʼ��λ��
    //       pnRowStart�����������ͼ��й�оƬԤ��ʱ����й����Ч������ʼ��λ��
	//       pnColSize�� ���������ͼ��й�оƬԤ��ʱ����й����Ч����ˮƽ������
    //       pnRowSize�����������ͼ��й�оƬԤ��ʱ����й����Ч����ֱ����
	//       pColAddressMode�� ���������ͼ��й�оƬԤ��ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       pRowAddressMode�����������ͼ��й�оƬԤ��ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewSetFieldOfView
    // ���ܣ�����Ԥ���ӳ���С
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� ���룬Ԥ��ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    //       pnRowStart�����룬Ԥ��ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	//       pnColSize�� ���룬Ԥ��ʱ��Ч���������ˮƽ������
    //       pnRowSize�����룬Ԥ��ʱ��Ч��������Ĵ�ֱ����
	//       AmCol�� ���룬Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       AmRow�����룬Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetFieldOfView
    // ���ܣ���ȡԤ���ӳ��Ĵ�С
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� ���������Ԥ��ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    //       pnRowStart�����������Ԥ��ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	//       pnColSize�� ���������Ԥ��ʱ��Ч���������ˮƽ������
    //       pnRowSize�������������Ԥ��ʱ��Ч��������Ĵ�ֱ����
	//       pColAddressMode�� ���������Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       pRowAddressMode�����������Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetSize
    // ���ܣ��õ�Ԥ��ͼ��Ŀ�Ⱥ͸߶�
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnWidth�� ��������ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ������ؿ��
    //       pnHeight����������ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ������ظ߶�
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSize(int nIndex, int *pnWidth, int *pnHeight);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetSizeEx
    // ���ܣ������־�����Ϣ
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pnWidth�� ���������ͼ��Ŀ�ȣ����أ�
    //       pnHeight�����������ͼ��ĸ߶ȣ����أ�
    //       pnBitCount����������ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ���λͼ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewSetPos
    // ���ܣ�������Ƶͼ���ڴ����ϵ���ʾλ��
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       hWnd�� ���룬��ʾ���ڵľ��
    //       x�� ���룬��ʾλ����Դ������Ͻ�ˮƽƫ�ƣ����أ�
	//       y�� ���룬��ʾλ����Դ������ϽǴ�ֱƫ�ƣ����أ�
	//       nWidth�� ���룬��ʾ�Ŀ�ȣ��������������Ԥ��ͼ��Ŀ�ȣ�ͼ���ˮƽ�Ŵ󣬷�֮��С
	//       nHeight�� ���룬��ʾͼ��ĸ߶ȣ��������������Ԥ��ͼ��ĸ߶ȣ�ͼ��ᴹֱ�Ŵ󣬷�֮��С
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetPos(int nIndex, HWND hWnd, int x, int y, int nWidth, int nHeight);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetPos
    // ���ܣ��õ���ǰ��ƵԤ��ͼ�����ʾλ��
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       px�� �����������ʾλ����Դ������Ͻ�ˮƽƫ�ƣ����أ�
	//       py�� �����������ʾλ����Դ������ϽǴ�ֱƫ�ƣ����أ�
	//       pnWidth�� �����������ʾ�Ŀ��
	//       pnHeight�� �����������ʾͼ��ĸ߶�
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPos(int nIndex, int *px, int *py, int *pnWidth, int *pnHeight);
	// Preview Mode
	enum KSJ_PREVIEWMODE// ö��������ƵԤ��ģʽ
	{
		PM_RAWDATA, //Ԥ��ԭʼ���ݣ����ںڰ��豸����������ΪPM_RAWDATA
		PM_RGBDATA  //Ԥ��24λ��32λ��ɫ���ݣ���Bayerģʽ������
	};
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewSetMode
    // ���ܣ�������Ƶ��Ϊԭʼ�ɼ����ݻ���RGB 24λ��32λ��ɫ���ݸ�ʽ��һ���û���������
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       PreviewMode�� ���룬���õ�Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetMode(int nIndex, KSJ_PREVIEWMODE PreviewMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetMode
    // ���ܣ���ȡ����ĵ�ǰԤ��ģʽ
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pPreviewMode  �� �������ȡ��ǰ��Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetDefaultMode
    // ���ܣ���ȡ�豸Ĭ�ϵ�Ԥ��ģʽ
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pPreviewMode  �� �������ȡ���Ĭ�ϵ�Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);
   
   //-----------------------------------------------------------------------------
    // ������KSJ_PreviewStart
    // ���ܣ�������Ƶ�����û�������ͨ��KSJ_PreviewSetPos��������Ƶ��ʾ�Ĵ��ڼ�λ�ô���һ��Ԥ�����ڣ����򽫿�����Ԥ����Ƶ��
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bStart  �� ���룬true ����Ƶ������ʾ�ڴ���ָ��λ�ã��ο�KSJ_PreviewSetPos��������false �ر���Ƶ�� 
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStart(int nIndex, bool bStart);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewPause
    // ���ܣ���ͣ�������Ƶ��
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bPause  �� ���룬true ��ͣ��Ƶ����false ������Ƶ�� 
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewPause(int nIndex, bool bPause);
	
	enum    KSJ_PREVIEWSTATUS //Ԥ����Ƶ����״̬
	{
		PS_STOP, //��Ƶ��ֹͣ
		PS_START,//��Ƶ������
		PS_PAUSE //��Ƶ����ͣ
	};
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetStatus
    // ���ܣ���ȡ��ƵԤ����״̬
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pPreviewStatus: ���������Ԥ��״̬
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatus(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetFrameRate
    // ���ܣ���ȡ֡��
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       fFrameRate�� ��������ص�ǰ��Ƶ����֡��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRate(int nIndex, float *fFrameRate);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetPausedData
    // ���ܣ���ȡ��ͣʱ����һ֡ͼ������
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pData�� ��������û��ṩ���������򣬺������÷��غ󣬴�����ᱻ�����ͣʱ��ͼ������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedData(int nIndex, unsigned char *pData);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetPausedDataEx
    // ���ܣ���ȡ��ͣʱ����һ֡ͼ������
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pData�� ��������û��ṩ���������򣬺������÷��غ󣬴�����ᱻ�����ͣʱ��ͼ������
	//       pnWidth�� ���������ͼ��Ŀ�ȣ����أ�
    //       pnHeight�����������ͼ��ĸ߶ȣ����أ�
    //       pnBitCount�����������ͼ���ÿ������λ����8��24��32��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedDataEx(int nIndex, unsigned char *pData, int *pnWidth, int *pnHeight, int *pnBitCount);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewStartEx
    // ���ܣ��ò���ģʽ������Ƶ�����û�������ͨ��KSJ_PreviewSetPos��������Ƶ��ʾ�Ĵ��ڼ�λ�ô���һ��Ԥ�����ڣ����򽫿�����Ԥ����Ƶ��
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bPause�� ���룬true ��ͣ��Ƶ����false ������Ƶ�� 
	//       bParallel�� ���룬true �ò���ģʽ����Ƶ����false ��ʹ�ò���ģʽ 
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStartEx(int nIndex, bool bStart, bool bParallel );

	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetStatusEx
    // ���ܣ���ȡ��ƵԤ���Ͳ��е�״̬
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pPreviewStatus�� ���������Ԥ��״̬ 
	//       pbParallel�� ��������ز���״̬
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatusEx(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus, bool *pbParallel);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetFrameRateEx
    // ���ܣ���ȡ�ɼ�����ʾ��֡��
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       fFrameRateCapture�� ��������ص�ǰ�ɼ���֡�� 
	//       fFrameRateShow�� ��������ص�ǰ��Ƶ����֡��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRateEx(int nIndex, float *fFrameRateCapture, float *fFrameRateShow);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_GetPreviewFrameCount
    // ���ܣ���ȡԤ���ɼ�����ʾ��ͼ����
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnCaptureFrameCount�� ��������ص�ǰԤ��һ���ɼ���ͼ���� 
	//       pnShowFrameCount�� ��������ص�ǰԤ��һ����ʾ��ͼ��ͼ����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetPreviewFrameCount(int nIndex, int *pnCaptureFrameCount, int *pnShowFrameCount);

	//-----------------------------------------------------------------------------
    // KSJ_SetBufferCount
    // ���ܣ�����Ԥ��ͼ�񻺴������
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nCount ���룬����Ԥ����������� 
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetBufferCount(int nIndex, int nCount);
	
	//-----------------------------------------------------------------------------
    // KSJ_GetBufferCount
    // ���ܣ���ȡԤ��ͼ�񻺴������
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnCount ���������Ԥ����������� 
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetBufferCount(int nIndex, int* pnCount);

	enum KSJ_USBSPEED//���USB����״̬
	{
		USB_NOT_CONNECTED = 0x00,        //USBͨ��ʧ��
		USB_FULL_SPEED,                  //ȫ��USB
		USB_HIGH_SPEED,                  //����USB
		USB_SUPER_SPEED                  //USB3.0
	};

	//-----------------------------------------------------------------------------
    // ������KSJ_GetUsbState
    // ���ܣ���ȡUSB����״̬
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pUSBSpeed: ��������ص�ǰUSB����״̬ 
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetUsbState(int nIndex, KSJ_USBSPEED* pUSBSpeed);

	//-----------------------------------------------------------------------------
    // ������KSJ_RebootDevice
    // ���ܣ������������������������������º���������USB����
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RebootDevice(int nIndex);


#ifdef __cplusplus
}
#endif

#endif
