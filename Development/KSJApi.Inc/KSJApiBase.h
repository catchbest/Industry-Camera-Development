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
		KSJ_UC130C_MRNN = 0,   /// 0 Guass2
		KSJ_UC130M_MRNN,       /// 1 Guass2
		KSJ_RESERVED0,         /// 2 Not Support
		KSJ_UC320C_MRNN,       /// 3 Guass2
		KSJ_UC130C_MRYN,       /// 4 Guass2
		KSJ_UC130M_MRYN,       /// 5 Guass2
		KSJ_RESERVED1,         /// 6 Not Support
		KSJ_UC320C_MRYN,       /// 7 Guass2
		KSJ_UC500C_MRNN,       /// 8 Guass2
		KSJ_UC500M_MRNN,       /// 9 Guass2
		KSJ_UC500C_MRYN,       /// 10 Guass2
		KSJ_UC500M_MRYN,       /// 11 Guass2
		KSJ_UC320_OCR,         /// 12 Not Support
		KSJ_UC900C_MRNN,       /// 13 Not Support
		KSJ_UC1000C_MRNN,      /// 14 Not Support
		KSJ_UC900C_MRYN,       /// 15 Not Support
		KSJ_UC1000C_MRYN,      /// 16 Not Support
		KSJ_MUC120C_MRYYO,     /// 17 Jelly2 V6.0.121.16
		KSJ_MUC120M_MRYYO,     /// 18 Jelly2 V6.0.121.16
		KSJ_UD140C_SRNN,       /// 19 Not Support
		KSJ_UD140M_SRNN,       /// 20 Not Support
		KSJ_UC36C_MGNN,        /// 21 Elanus2 Not Support
		KSJ_UC36M_MGNN,        /// 22 Elanus2 Not Support
		KSJ_UC36C_MGYN,        /// 23 Elanus2 Not Support
		KSJ_UC36M_MGYN,        /// 24 Elanus2 Not Support
		KSJ_UC900C_MRYY,       /// 25 Elanus2
		KSJ_UC1000C_MRYY,      /// 26 Elanus2
		KSJ_UC1400C_MRYY,      /// 27 Elanus2
		KSJ_UC36C_MGYY,        /// 28 Elanus2 Not Support
		KSJ_UC36M_MGYY,        /// 29 Elanus2 Not Support
		KSJ_UC320C_MRYY,       /// 30 Elanus2 Not Support
		KSJ_UC500C_MRYY,       /// 31 Elanus2 Not Support
		KSJ_UC500M_MRYY,       /// 32 Elanus2 Not Support
		KSJ_MUC130C_MRYN,      /// 33 OEM
		KSJ_MUC130M_MRYN,      /// 34 OEM.
		 
		KSJ_MUC320C_MRYN,      /// 35 OEM
		KSJ_MUC36C_MGYYO,      /// 36 Jelly2
		KSJ_MUC36M_MGYYO,      /// 37 Jelly2 
		KSJ_MUC130C_MRYY,      /// 38 Not Support
		KSJ_MUC130M_MRYY,      /// 39 Not Support
		KSJ_MUC320C_MRYY,      /// 40 Not Support
		KSJ_MUC500C_MRYYO,     /// 41 Jelly2
		KSJ_MUC500M_MRYYO,     /// 42 Jelly2
		KSJ_MUC900C_MRYY,      /// 43 Not Support
		KSJ_MUC1000C_MRYY,     /// 44 Not Support
		KSJ_MUC1400C_MRYY,     /// 45 Not Support
		KSJ_UD205C_SGYY,       /// 46 Elanus2
		KSJ_UD205M_SGYY,       /// 47 Elanus2
		KSJ_UD274C_SGYY,       /// 48 Elanus2
		KSJ_UD274M_SGYY,       /// 49 Elanus2
		KSJ_UD285C_SGYY,       /// 50 Elanus2
		KSJ_UD285M_SGYY,       /// 51 Elanus2
		KSJ_MU3C500C_MRYYO,    /// 52 Jelly3 
		KSJ_MU3C500M_MRYYO,    /// 53 Jelly3
		KSJ_MU3C1000C_MRYYO,   /// 54 Jelly3
		KSJ_MU3C1400C_MRYYO,   /// 55 Jelly3
		KSJ_MU3V130C_CGYYO,    /// 56 Jelly3
		KSJ_MU3V130M_CGYYO,    /// 57 Jelly3
		KSJ_MU3E130C_EGYYO,    /// 58 Jelly3
		KSJ_MU3E130M_EGYYO,    /// 59 Jelly3
		KSJ_MUC36C_MGYFO,      /// 60 Jelly1
		KSJ_MUC36M_MGYFO,      /// 61 Jelly1
		KSJ_MU3C120C_MGYYO,    /// 62 Jelly3
		KSJ_MU3C120M_MGYYO,    /// 63 Jelly3
		KSJ_MU3E200C_EGYYO,    /// 64 Jelly3
		KSJ_MU3E200M_EGYYO,    /// 65 Jelly3
		KSJ_MUC130C_MRYNO,     /// 66 Jelly1
		KSJ_MUC130M_MRYNO,     /// 67 Jelly1
		KSJ_MUC320C_MRYNO,     /// 68 Jelly1
		KSJ_U3C130C_MRYNO,     /// 69 Not Support
		KSJ_U3C130M_MRYNO,     /// 70 Not Support
		KSJ_U3C320C_MRYNO,     /// 71 Not Support
		KSJ_U3C500C_MRYNO,     /// 72 Guass3
		KSJ_U3C500M_MRYNO,     /// 73 Guass3
		KSJ_MU3C1401C_MRYYO,   /// 74 DELETE Not Support 
		KSJ_MU3C1001C_MRYYO,   /// 75 DELETE Not Support
		KSJ_MUC131M_MRYN,      /// 76 OEM Device
		KSJ_MU3C501C_MRYYO,    /// 77 DELETE Not Support
		KSJ_MU3C501M_MRYYO,    /// 78 DELETE Not Support
		KSJ_MUC120C_MGYYO,     /// 79 Jelly2
		KSJ_MUC120M_MGYYO,     /// 80 Jelly2
		KSJ_MU3E131C_EGYYO,    /// 81 DELETE Not Support
		KSJ_MU3E131M_EGYYO,    /// 82 DELETE Not Support
		KSJ_MU3E201C_EGYYO,    /// 83 DELETE Not Support
		KSJ_MU3E201M_EGYYO,    /// 84 DELETE Not Support   
		KSJ_MISSING_DEVICE,	   /// 85 Device Lost Program
		KSJ_MU3S230C_SGYYO,    /// 86 Jelly3 Sony IMX174
		KSJ_MU3S230M_SGYYO,    /// 87 Jelly3 Sony IMX174
		KSJ_MU3S640C_SRYYO,    /// 88 Jelly3 Sony IMX178
		KSJ_MU3S640M_SRYYO,    /// 89 Jelly3 Sony IMX178
		KSJ_CUD285C_SGYYO,     /// 90
		KSJ_CUD285M_SGYYO,     /// 91
		KSJ_MU3S231C_SGYYO,    /// 92 Jelly3 Sony IMX249
		KSJ_MU3S231M_SGYYO,    /// 93 Jelly3 Sony IMX249
		KSJ_MU3S500C_SGYYO,    /// 94
		KSJ_MU3S500M_SGYYO,    /// 95
		KSJ_MU3S1200C_SRYYO,   /// 96
		KSJ_MU3S1200M_SRYYO,   /// 97
		KSJ_MU3L2K7C_AGYYO,    /// 98
		KSJ_MU3L2K7M_AGYYO,    /// 99
		KSJ_MU3L4K3C_AGYYO,    /// 100
		KSJ_MU3L4K3M_AGYYO,    /// 101
		KSJ_MU3HS2000C_SRYYO,  /// 102
		KSJ_MU3HS2000M_SRYYO,  /// 103
		KSJ_MU3HS500C_SGYYO,   /// 104
		KSJ_MU3HS500M_SGYYO,   /// 105
		KSJ_MU3HS230C_SGYYO,   /// 106 imx174 
		KSJ_MU3HS230M_SGYYO,   /// 107
		KSJ_MU3HI400C_IGYYO,   /// 108
		KSJ_MU3HI400M_IGYYO,   /// 109
		KSJ_TEST_CAMERA,       /// 110
		KSJ_MU3HI401C_IGYYO, 
		KSJ_MU3HI401M_IGYYO,
		KSJ_MU3S40C_SGYYO, 
		KSJ_MU3S40M_SGYYO,     /// 114
		KSJ_MU3S210C_SRYYO,    /// 115
		KSJ_MU3S210M_SRYYO,    /// 116
		KSJ_MU3I130C_IGYYO,    /// 117
		KSJ_MU3I130M_IGYYO,    /// 118
		KSJ_MU3S321C_SGYYO,    /// 119
		KSJ_MU3S321M_SGYYO,     /// 120
		KSJ_MU3S641M_SRYYO,
		KSJ_MU3S1201M_SRYYO,
		KSJ_MU3HS2001M_SRYYO,
		KSJ_MU3S211M_SRYYO,
		KSJ_MU3C36C_MGYY,
		KSJ_MU3C36M_MGYY,
		KSJ_MU3HS1200C_SRYYO,
		KSJ_MU3HS1200M_SRYYO,
		KSJ_MU3S160C_SGYYO,
		KSJ_MU3S160M_SGYYO,
		KSJ_MU3S641C_SRYYO
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ����Log��־�Ƿ����������ı���Ŀ¼
    /// @param     bEnable [in] �Ƿ��Log��־���������
    /// @param     pszFolder [in] �����Log��־�������Ŀ¼������ΪNULL����ַ��������ΪNULL����ַ����������Ŀ¼���Զ�������Ŀ¼λ����KSJAPI.dll����Ŀ¼�´���KSJApiLogĿ¼��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogSet(bool bEnable, const TCHAR *pszFolder);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����־�����Ϣ
    /// @param     bEnable [out] �����Ƿ��Ѿ���Log��־���������
    /// @param     pszFolder[out] ���������Log��־�������Ŀ¼������ΪNULL����ַ�������ʾ�����ȡ����Ϣ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����������ʱ�̵���
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogGet(bool *bEnable, TCHAR *pszFolder);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡKSJAPI��İ汾��
    /// @param     pnMaj1[out] �������汾��1��һ������Ҫ����ṹ����ʱ��ı䣬����1
    /// @param     pnMaj2[out] �������汾��2��һ������������ʱ��ı䣬����1
	/// @param     pnMin1[out] ���شΰ汾��1��һ������Ҫ����ṹ����ʱ��ı䣬����1
	/// @param     pnMin2�����شΰ汾��2��һ����С�ĸĶ�ʱ��ı䣬����1
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetVersion(OUT int *pnMaj1, OUT int *pnMaj2, OUT int *pnMin1, OUT int *pnMin2);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ô������ϸ��Ϣ
    /// @param     nErrorNo [in] ���������룬�ο�����״̬�루KSJCode.H��
    /// @param     pszErrorInfo[out] �������������Ϣ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetErrorInfo(IN int nErrorNo, OUT TCHAR pszErrorInfo[256]);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ʼ��KSJApi��̬�⣬�ú������������������ڼ�ֻ��Ҫ����һ�Ρ�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention �����ʼ��ʱ���ã���������ִ���������֮ǰ��������Ӻã������Ҫ�����豸����ִ��KSJ_UnInit/KSJ_Init������ע����ǣ�����ִ�к����������Ӧ�������ſ��ܻ�ı䡣
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_Init(void);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ����ʼ��KSJApi��̬��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�����ͷŷ�����Դ���رձ������������Ѿ��򿪵��豸
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_UnInit(void);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �õ��豸��Ŀ
    /// @return    ���ӵ������ϵ�KSJ�豸��Ŀ
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetCount(void);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �õ��豸��Ϣ���ͺţ���ţ��̼��汾�ţ�
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pDeviceType[out] �����豸���͵ĵ�ַָ�루�豸���͵Ķ�����ο�KSJ_DEVICETYPE��
	/// @param     pnSerials[out] �����豸��ŵĵ�ַָ��
	/// @param     pwFirmwareVersion[out] �����豸�̼��汾�ŵĵ�ַָ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformation(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �õ��豸��Ϣ���ͺţ���ţ��̼��汾�ţ�
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pDeviceType[out] �����豸���͵ĵ�ַָ�루�豸���͵Ķ�����ο�KSJ_DEVICETYPE��
	/// @param     pnSerials[out] �����豸��ŵĵ�ַָ��
	/// @param     pwFirmwareVersion[out] �����豸�̼��汾�ŵĵ�ַָ��
	/// @param     pwFpgaVersion[out] �����豸FPGA�汾�ŵĵ�ַָ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformationEx(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion, OUT unsigned short *pwFpgaVersion);
	
	enum KSJ_IMAGE_FORMAT
	{
		KSJ_IF_RAW8 = 0,
		KSJ_IF_GRAY8,
		KSJ_IF_RGB24,
		KSJ_IF_RGB32,
		KSJ_IF_BGR24,
		KSJ_IF_BGR32,
		KSJ_IF_RAW16,
		KSJ_IF_GRAY16,
		KSJ_IF_RGB48,
		KSJ_IF_RGB64,
		KSJ_IF_BGR48,
		KSJ_IF_BGR64,
	};

	KSJ_API  int __stdcall KSJ_SetImageFormat(IN int nChannel, IN KSJ_IMAGE_FORMAT ImageFormat);
	KSJ_API  int __stdcall KSJ_GetImageFormat(IN int nChannel, OUT KSJ_IMAGE_FORMAT *pImageFormat);

	/// �����������
	enum KSJ_PARAM //���������ö������
	{
		KSJ_EXPOSURE = 0,        /// Exposure Time (ms)
		KSJ_RED,                 /// Red Gain, for line scan sensor map to seg0, for ccd map to KSJ_VGAGAIN
		KSJ_GREEN,               /// Green Gain, for line scan sensor map to seg1, for ccd map to KSJ_LAMPLEVEL
		KSJ_BLUE,                /// Blue Gain, for CCD map to KSJ_CDSGAIN
		KSJ_GAMMA,               /// Gamma
		KSJ_PREVIEW_COLUMNSTART, /// Preview Col Start
		KSJ_PREVIEW_ROWSTART,    /// Preview Row Start
		KSJ_CAPTURE_COLUMNSTART, /// Capture Col Start
		KSJ_CAPTURE_ROWSTART,    /// Capture Row Start
		KSJ_HORIZONTALBLANK,     /// Horizontal Blank
		KSJ_VERTICALBLANK,       /// Vertical Blank
		KSJ_FLIP,                /// Flip
		KSJ_BIN,                 /// Binning
		KSJ_MIRROR,              /// Mirror
		KSJ_CONTRAST,            /// Contrast
		KSJ_BRIGHTNESS,          /// Brightness
		KSJ_VGAGAIN,             /// VGA Gain(CCD)
		KSJ_CLAMPLEVEL,          /// Clamp Level(CCD)
		KSJ_CDSGAIN,             /// CDS Gain(CCD)
		KSJ_RED_SHIFT,           /// Not Use
		KSJ_GREEN_SHIFT,         /// Not Use
		KSJ_BLUE_SHIFT,          /// Not Use
		KSJ_COMPANDING,          /// Companding
		KSJ_EXPOSURE_LINES,      /// Exposure Lines
		KSJ_SATURATION,          /// Saturation
		KSJ_TRIGGERDELAY,        /// Trigger Delay Step = 100uS
		KSJ_STROBEDELAY,         /// Not Use
		KSJ_TRIGGER_MODE,        /// Trigger Mode
		KSJ_TRIGGER_METHOD,      /// Trigger Method
		KSJ_BLACKLEVEL,          /// Black Level
		KSJ_BLACKLEVEL_THRESHOLD_AUTO, /// Black Level Threshold Auto
		KSJ_BLACKLEVEL_THRESHOLD_LO,   /// Black Level Low Threshold
		KSJ_BLACKLEVEL_THRESHOLD_HI    /// Black Level High Threshold
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ��Ӧ�������õ�ȡֵ��Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     Param [in] ָ���Ĳ������ο�KSJ_PARAM���壩
	/// @param     pnMinValue[out] ȡ��ָ���������õ���Сֵ
	/// @param     pnMaxValue[out] ȡ��ָ���������õ����ֵ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParamRange(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnMinValue, OUT int *pnMaxValue);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     Param [in] ָ���Ĳ������ο�KSJ_PARAM���壩
    /// @param     nValue [in] �������õ�ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetParam(IN int nIndex, IN KSJ_PARAM Param, IN  int nValue);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�������
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     Param [in] ָ���Ĳ������ο�KSJ_PARAM���壩
	/// @param     pnValue[out] ����ֵָ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParam(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnValue);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����ع�ʱ��
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fExposureTimeMs [in] ���õ��ع�ʱ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeSet(int nIndex, float fExposureTimeMs);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�ع�ʱ��
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pfExpTimeMs [out] �����ع�ʱ���ָ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeGet(int nIndex, float *pfExpTimeMs);

	enum KSJ_ADDRESSMODE ///ö�����Ϳ��Ӽѳ��ģʽ���壨��Ϊ�г����г�㣩
	{ 
		KSJ_SKIPNONE = 0, ///������������ӳ����÷�Χ�ڵ����ص�
		KSJ_SKIP2, ///������Ϊ��ʱ�����col0, col1, col4, col5, col8, col9�ȣ�    ������Ϊ��ʱ�����row0, row1, row4, row5, row8, row9��
		KSJ_SKIP3, ///������Ϊ��ʱ�����col0, col1, col6, col7, col12, col13�ȣ�  ������Ϊ��ʱ�����row0, row1, row6, row7, row12, row13��
		KSJ_SKIP4, ///������Ϊ��ʱ�����col0, col1, col8, col9, col16, col17�ȣ�  ������Ϊ��ʱ�����row0, row1, row8, row9, row16, row17��
		KSJ_SKIP8  ///������Ϊ��ʱ�����col0, col1, col16, col17, col32, col33�ȣ�������Ϊ��ʱ�����row0, row1, row16, row17, row32, row33��
	};
	////////////////////////////////////////////Capture/////////////////////////////////
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���������ӳ�����������Ƿ�ƥ��
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnColStart [in] Ҫ����ˮƽ������ʼλ��
    /// @param     pnRowStart [in] Ҫ���Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [in] Ҫ����ˮƽ������
    /// @param     pnRowSize [in] Ҫ���Ĵ�ֱ����
	/// @param     AmCol [in] Ҫ������Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @param     AmRow [in] Ҫ������Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @return    �ο�����1��ʾƥ�䣬����ƥ��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CheckFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�豸��Ĭ�ϲɼ��ӳ���С��Ҳ�����豸��֧�ֵ�����ӳ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnColStart [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
    /// @param     pnRowStart[out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnColSize [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч����ˮƽ������
    /// @param     pnRowSize [out] ����ͼ��й�оƬ�ɼ�ʱ����й����Ч����ֱ����
	/// @param     pColAddressMode [out] ����ͼ��й�оƬ�ɼ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @param     pRowAddressMode [out] ����ͼ��й�оƬ�ɼ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���òɼ��ӳ���С
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnColStart [in] �ɼ�ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    /// @param     pnRowStart [in] �ɼ�ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [in] �ɼ�ʱ��Ч���������ˮƽ������
    /// @param     pnRowSize [in] �ɼ�ʱ��Ч��������Ĵ�ֱ����
	/// @param     AmCol [in] �ɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @param     AmRow [in] �ɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�ɼ��ӳ���ʵ�ʴ�С
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnColStart [out] ���زɼ�ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    /// @param     pnRowStart[out] ���زɼ�ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [out] ���زɼ�ʱ��Ч���������ˮƽ������
    /// @param     pnRowSize [out] �����زɼ�ʱ��Ч��������Ĵ�ֱ����
	/// @param     pColAddressMode [out] ���زɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @param     pRowAddressMode [out] ���زɼ�ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�ɼ�ͼ��Ŀ�Ⱥ͸߶�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnWidth [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ؿ��
    /// @param     pnHeight [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ظ߶�
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSize(int nIndex, int *pnWidth, int *pnHeight);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�ɼ�ͼ��Ŀ�Ⱥ͸߶ȣ���λ�����أ���λͼ��ȣ�8��24��32��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnWidth [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ؿ��
    /// @param     pnHeight [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ظ߶�
    /// @param     pnBitCount [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �ɼ�һ֡ԭʼ��ڰ�ͼ������
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pRawData[out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize��KSJ_CaptureGetSizeEx�������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawData(int nIndex, unsigned char *pRawData);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pRgbData[out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbData(int nIndex, unsigned char *pRgbData);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pRgbData[out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
    /// @param     pnHeight[out] ����ͼ��ĸ߶ȣ����أ�
    /// @param     pnBitCount[out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataEx(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ͼ�����ݱ���ΪBMP�ļ�
    /// @param     pData [in] ָ��ͼ�����ݵ��׵�ַָ��
	/// @param     nWidth [in] ͼ��Ŀ�ȣ����أ�
    /// @param     nHeight [in] ͼ��ĸ߶ȣ����أ�
    /// @param     nBitCount [in] 8Ϊ�Ҷ�ͼ�����ݣ�24Ϊ24λ��ɫͼ�����ݣ�����ֵ��֧��
    /// @param     pszFileName [in] �����ļ���ȫ·������·��������ڣ�
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, const TCHAR *pszFileName);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ͼ�����ݱ���ΪJPG�ļ�
    /// @param     pData [in] ָ��ͼ�����ݵ��׵�ַָ��
	/// @param     nWidth [in] ͼ��Ŀ�ȣ����أ�
    /// @param     nHeight [in] ͼ��ĸ߶ȣ����أ�
    /// @param     nBitCount [in] 8Ϊ�Ҷ�ͼ�����ݣ�24Ϊ24λ��ɫͼ�����ݣ�����ֵ��֧��
    /// @param     pszFileName [in] �����ļ���ȫ·������·��������ڣ�
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToJpg(unsigned char *pData, int nWidth, int nHeight, int nBitCount, int nQulity, const TCHAR *pszFileName);

	////////////////////////////////////////////Preview/////////////////////////////////
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�豸��Ĭ��Ԥ���ӳ���С��Ҳ�����豸��֧�ֵ�����ӳ�
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnColStart [out] ����ͼ��й�оƬԤ��ʱ����й����Ч������ʼ��λ��
    /// @param     pnRowStart[out] ����ͼ��й�оƬԤ��ʱ����й����Ч������ʼ��λ��
	/// @param     pnColSize [out] ����ͼ��й�оƬԤ��ʱ����й����Ч����ˮƽ������
    /// @param     pnRowSize[out] ����ͼ��й�оƬԤ��ʱ����й����Ч����ֱ����
	/// @param     pColAddressMode [out] ����ͼ��й�оƬԤ��ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @param     pRowAddressMode[out] ����ͼ��й�оƬԤ��ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ����Ԥ���ӳ���С
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnColStart [in] Ԥ��ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    /// @param     pnRowStart [in] Ԥ��ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [in] Ԥ��ʱ��Ч���������ˮƽ������
    /// @param     pnRowSize [in] Ԥ��ʱ��Ч��������Ĵ�ֱ����
	/// @param     AmCol [in] Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @param     AmRow [in] Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡԤ���ӳ��Ĵ�С
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnColStart [out] ����Ԥ��ʱ��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    /// @param     pnRowStart[out] ����Ԥ��ʱ��Ч�����������������������Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [out] ����Ԥ��ʱ��Ч���������ˮƽ������
    /// @param     pnRowSize[out] ������Ԥ��ʱ��Ч��������Ĵ�ֱ����
	/// @param     pColAddressMode [out] ����Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @param     pRowAddressMode[out] ����Ԥ��ʱ�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �õ�Ԥ��ͼ��Ŀ�Ⱥ͸߶�
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnWidth [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ������ؿ��
    /// @param     pnHeight[out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ������ظ߶�
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSize(int nIndex, int *pnWidth, int *pnHeight);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����־�����Ϣ
    /// ������
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
    /// @param     pnHeight[out] ����ͼ��ĸ߶ȣ����أ�
    /// @param     pnBitCount[out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ��Ԥ��ͼ���λͼ���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ������Ƶͼ���ڴ����ϵ���ʾλ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     hWnd [in] ��ʾ���ڵľ��
    /// @param     x [in] ��ʾλ����Դ������Ͻ�ˮƽƫ�ƣ����أ�
	/// @param     y [in] ��ʾλ����Դ������ϽǴ�ֱƫ�ƣ����أ�
	/// @param     nWidth [in] ��ʾ�Ŀ�ȣ��������������Ԥ��ͼ��Ŀ�ȣ�ͼ���ˮƽ�Ŵ󣬷�֮��С
	/// @param     nHeight [in] ��ʾͼ��ĸ߶ȣ��������������Ԥ��ͼ��ĸ߶ȣ�ͼ��ᴹֱ�Ŵ󣬷�֮��С
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetPos(int nIndex, HWND hWnd, int x, int y, int nWidth, int nHeight);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �õ���ǰ��ƵԤ��ͼ�����ʾλ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     px [out] ������ʾλ����Դ������Ͻ�ˮƽƫ�ƣ����أ�
	/// @param     py [out] ������ʾλ����Դ������ϽǴ�ֱƫ�ƣ����أ�
	/// @param     pnWidth [out] ������ʾ�Ŀ��
	/// @param     pnHeight [out] ������ʾͼ��ĸ߶�
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPos(int nIndex, int *px, int *py, int *pnWidth, int *pnHeight);
	/// Preview Mode
	enum KSJ_PREVIEWMODE// ö��������ƵԤ��ģʽ
	{
		PM_RAWDATA, ///Ԥ��ԭʼ���ݣ����ںڰ��豸����������ΪPM_RAWDATA
		PM_RGBDATA  ///Ԥ��24λ��32λ��ɫ���ݣ���Bayerģʽ������
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ������Ƶ��Ϊԭʼ�ɼ����ݻ���RGB 24λ��32λ��ɫ���ݸ�ʽ��һ���û���������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     PreviewMode [in] ���õ�Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetMode(int nIndex, KSJ_PREVIEWMODE PreviewMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ����ĵ�ǰԤ��ģʽ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pPreviewMode   [out] ��ȡ��ǰ��Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�豸Ĭ�ϵ�Ԥ��ģʽ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pPreviewMode   [out] ��ȡ���Ĭ�ϵ�Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);
   
    ///-----------------------------------------------------------------------------
    ///
    /// @brief     ������Ƶ�����û�������ͨ��KSJ_PreviewSetPos��������Ƶ��ʾ�Ĵ��ڼ�λ�ô���һ��Ԥ�����ڣ����򽫿�����Ԥ����Ƶ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bStart   [in] true ����Ƶ������ʾ�ڴ���ָ��λ�ã��ο�KSJ_PreviewSetPos��������false �ر���Ƶ�� 
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStart(int nIndex, bool bStart);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ͣ�������Ƶ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bPause   [in] true ��ͣ��Ƶ����false ������Ƶ�� 
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewPause(int nIndex, bool bPause);
	
	enum    KSJ_PREVIEWSTATUS ///Ԥ����Ƶ����״̬
	{
		PS_STOP, ///��Ƶ��ֹͣ
		PS_START,//��Ƶ������
		PS_PAUSE ///��Ƶ����ͣ
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ƵԤ����״̬
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pPreviewStatus [out] ����Ԥ��״̬
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatus(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ֡��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fFrameRate [out] ���ص�ǰ��Ƶ����֡��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRate(int nIndex, float *fFrameRate);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ͣʱ����һ֡ͼ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pData [out] ���û��ṩ���������򣬺������÷��غ󣬴�����ᱻ�����ͣʱ��ͼ������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedData(int nIndex, unsigned char *pData);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ͣʱ����һ֡ͼ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pData [out] ���û��ṩ���������򣬺������÷��غ󣬴�����ᱻ�����ͣʱ��ͼ������
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
    /// @param     pnHeight[out] ����ͼ��ĸ߶ȣ����أ�
    /// @param     pnBitCount[out] ����ͼ���ÿ������λ����8��24��32��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedDataEx(int nIndex, unsigned char *pData, int *pnWidth, int *pnHeight, int *pnBitCount);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     �ò���ģʽ������Ƶ�����û�������ͨ��KSJ_PreviewSetPos��������Ƶ��ʾ�Ĵ��ڼ�λ�ô���һ��Ԥ�����ڣ����򽫿�����Ԥ����Ƶ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bPause [in] true ��ͣ��Ƶ����false ������Ƶ�� 
	/// @param     bParallel [in] true �ò���ģʽ����Ƶ����false ��ʹ�ò���ģʽ 
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStartEx(int nIndex, bool bStart, bool bParallel );

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ƵԤ���Ͳ��е�״̬
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pPreviewStatus [out] ����Ԥ��״̬ 
	/// @param     pbParallel [out] ���ز���״̬
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatusEx(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus, bool *pbParallel);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�ɼ�����ʾ��֡��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fFrameRateCapture [out] ���ص�ǰ�ɼ���֡�� 
	/// @param     fFrameRateShow [out] ���ص�ǰ��Ƶ����֡��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRateEx(int nIndex, float *fFrameRateCapture, float *fFrameRateShow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡԤ���ɼ�����ʾ��ͼ����
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnCaptureFrameCount [out] ���ص�ǰԤ��һ���ɼ���ͼ���� 
	/// @param     pnShowFrameCount [out] ���ص�ǰԤ��һ����ʾ��ͼ��ͼ����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetPreviewFrameCount(int nIndex, int *pnCaptureFrameCount, int *pnShowFrameCount);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ����Ԥ��ͼ�񻺴������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nCount [in] ����Ԥ����������� 
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetBufferCount(int nIndex, int nCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡԤ��ͼ�񻺴������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnCount [out] ����Ԥ����������� 
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetBufferCount(int nIndex, int* pnCount);

	enum KSJ_USBSPEED//���USB����״̬
	{
		USB_NOT_CONNECTED = 0x00,        ///USBͨ��ʧ��
		USB_FULL_SPEED,                  ///ȫ��USB
		USB_HIGH_SPEED,                  ///����USB
		USB_SUPER_SPEED                  ///USB3.0
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡUSB����״̬
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pUSBSpeed [out] ���ص�ǰUSB����״̬ 
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetUsbState(int nIndex, KSJ_USBSPEED* pUSBSpeed);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����������������������������º���������USB����
    /// ������
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RebootDevice(int nIndex);


#ifdef __cplusplus
}
#endif

#endif
