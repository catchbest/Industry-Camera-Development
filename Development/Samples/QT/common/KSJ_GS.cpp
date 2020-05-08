//#include "stdafx.h"
#include "KSJ_GS.H"

const TCHAR * g_szDeviceType[] =
{
	_T("Gauss2 UC130C(MRNN)"),
	_T("Gauss2 UC130M(MRNN)"),
	_T("xxxxxxxxxxxxxxxxxxx"),
	_T("Gauss2 UC320C(MRNN)"),
	_T("Gauss2 UC130C(MRYN)"),
	_T("Gauss2 UC130M(MRYN)"),
	_T("xxxxxxxxxxxxxxxxxxx"),
	_T("Gauss2 UC320C(MRYN)"),
	_T("Gauss2 UC500C(MRNN)"),
	_T("Gauss2 UC500M(MRNN)"),
	_T("Gauss2 UC500C(MRYN)"),
	_T("Gauss2 UC500M(MRYN)"),
	_T("xxxxxxx UC320C(OCR)"),
	_T("xxxxxxx UC900C(MRNN)"),
	_T("xxxxxxx UC1000C(MRNN)"),
	_T("xxxxxxx UC900C(MRYN)"),
	_T("xxxxxxx UC1000C(MRYN)"),
	_T("Elanus2 UC130C(MRYY)"),
	_T("Elanus2 UC130M(MRYY)"),
	_T("xxxxxxx UD140C(SRNN)"),
	_T("xxxxxxx UD140M(SRNN)"),
	_T("xxxxxxx UC36C(MGNN)"),
	_T("xxxxxxx UC36M(MGNN)"),
	_T("xxxxxxx UC36C(MGYN)"),
	_T("xxxxxxx UC36M(MGYN)"),
	_T("Elanus2 UC900C(MRYY)"),
	_T("Elanus2 UC1000C(MRYY)"),
	_T("Elanus2 UC1400C(MRYY)"),
	_T("Elanus2 UC36C(MGYY)"),
	_T("Elanus2 UC36M(MGYY)"),
	_T("Elanus2 UC320C(MRYY)"),
	_T("Elanus2 UC500C(MRYY)"),
	_T("Elanus2 UC500M(MRYY)"),
	_T("CatchBEST MUC130C(MRYN)"),
	_T("CatchBEST MUC130M(MRYN)"),
	_T("CatchBEST MUC320C(MRYN)"),
	_T("Jelly2 MUC36C(MGYYO)"),
	_T("Jelly2 MUC36M(MGYYO)"),
	_T("xxxxxx MUC130C(MRYY)"),
	_T("Jelly2 MUC130M(MRYY)"),
	_T("Jelly2 MUC320C(MRYY)"),
	_T("Jelly2 MUC500C(MRYYO)"),
	_T("Jelly2 MUC500M(MRYYO)"),
	_T("xxxxxx MUC900C(MRYY)"),
	_T("xxxxxx MUC1000C(MRYY)"),
	_T("xxxxxx MUC1400C(MRYY)"),
	_T("Elanus2 UD205C(SGYY)"),
	_T("Elanus2 UD205M(SGYY)"),
	_T("Elanus2 UD274C(SGYY)"),
	_T("Elanus2 UD274M(SGYY)"),
	_T("Elanus2 UD285C(SGYY)"),
	_T("Elanus2 UD285M(SGYY)"),
	_T("Jelly3 MU3C500C(MRYYO)"),
	_T("Jelly3 MU3C500M(MRYYO)"),
	_T("Jelly3 MU3C1000C(MRYYO)"),
	_T("Jelly3 MU3C1400C(MRYYO)"),
	_T("Jelly3 MU3V130C(CGYYO)"),
	_T("Jelly3 MU3V130M(CGYYO)"),
	_T("Jelly3 MU3E130C(EGYYO)"),
	_T("Jelly3 MU3E130M(EGYYO)"),
	_T("Jelly1 MUC36C(MGYFO)"),
	_T("Jelly1 MUC36M(MGYFO)"),
	_T("Jelly3 MU3C120C(MGYYO)"),
	_T("Jelly3 MU3C120M(MGYYO)"),
	_T("Jelly3 MU3E200C(EGYYO)"),
	_T("Jelly3 MU3E200M(EGYYO)"),
	_T("Jelly1 MUC130C(MRYNO)"),    // Jelly1 ++20150208
	_T("Jelly1 MUC130M(MRYNO)"),    // Jelly1 ++20150208
	_T("Jelly1 MUC320C(MRYNO)"),    // Jelly1 ++20150208
	_T("Gauss3 U3C130C(MRYNO)"),
	_T("Gauss3 U3C130M(MRYNO)"),
	_T("Gauss3 U3C320C(MRYNO)"),
	_T("Gauss3 U3C500C(MRYNO)"),
	_T("Gauss3 U3C500M(MRYNO)"),
	_T("xxxxxx MU3C1401C(MRYYO)"),
	_T("xxxxxx MU3C1001C(MRYYO)"),
	_T("xxxxxx MUC131M(MRYN)"),
	_T("xxxxxx MU3C501C(MRYYO)"),
	_T("xxxxxx MU3C501M(MRYYO)"),
	_T("Jelly2 MUC120C(MGYYO)"),
	_T("Jelly2 MUC120M(MGYYO)"),
	_T("xxxxxx MU3E131C(EGYY)"),
	_T("xxxxxx MU3E131M(EGYY)"),
	_T("xxxxxx MU3E201C(EGYYO)"),
	_T("xxxxxx MU3E201M(EGYYO)"),
	_T("Missing Device"),
	_T("Jelly3 MU3S230C(SGYYO)"),
	_T("Jelly3 MU3S230M(SGYYO)"),
	_T("Jelly3 MU3S640C(SRYYO)"),
	_T("Jelly3 MU3S640M(SRYYO)"),
	_T("Cooler CUD285C(SGYYO)"),
	_T("Cooler CUD285M(SGYYO)"),
	_T("Jelly3 MU3S231C(SGYYO)"),
	_T("Jelly3 MU3S231M(SGYYO)"),
	_T("Jelly3 MU3S500C(SGYYO)"),
	_T("Jelly3 MU3S500M(SGYYO)"),

	_T("Jelly3 MU3S1200C(SRYYO)"),
	_T("Jelly3 MU3S1200M(SRYYO)"),

	_T("Jelly4 MU3L2K7C(AGYYO)"),
	_T("Jelly4 MU3L2K7M(AGYYO)"),
	_T("Jelly4 MU3L4K3C(AGYYO)"),
	_T("Jelly4 MU3L4K3M(AGYYO)"),

	_T("Jelly6 MU3HS2000C(SRYYO)"),
	_T("Jelly6 MU3HS2000M(SRYYO)"),

	_T("Jelly6 MU3HS500C(SRYYO)"),
	_T("Jelly6 MU3HS500M(SRYYO)"),

	_T("Jelly6 MU3HS230C(SGYYO)"),
	_T("Jelly6 MU3HS230M(SGYYO)"),

	_T("Jelly6 MU3HI400C(IGYYO)"),
	_T("Jelly6 MU3HI400M(IGYYO)"),

	_T("TEST CAMERA"),

	_T("Jelly6 MU3HI401C(IGYYO)"),
	_T("Jelly6 MU3HI401M(IGYYO)"),

	_T("Jelly6 MU3S40C(SGYYO)"),
	_T("Jelly6 MU3S40M(SGYYO)"),

	_T("Jelly6 MU3S210C(SRYYO)"),
	_T("Jelly6 MU3S210M(SRYYO)"),
	_T("Jelly6 MU3I130C(IGYYO)"),
	_T("Jelly6 MU3I130M(IGYYO)"),

	_T("Jelly6 MU3S321C(SGYYO)"),
	_T("Jelly6 MU3S321M(SGYYO)"),

	_T("Jelly3 MU3S641M(SRYYO)"),
	_T("Jelly3 MU3S1201M(SRYYO)"),
	_T("Jelly6 MU3HS2001M(SRYYO)"),

	_T("Jelly3 MU3S211M(SRYYO)"),
	_T("Jelly3 MU3C36C(MGYY)"),
	_T("Jelly3 MU3C36M(MGYY)"),
	_T("Jelly6 MU3HS1200C(SRYYO)"),
	_T("Jelly6 MU3HS1200M(SRYYO)"),

	_T("UNKOWN TYPE"),
	_T("UNKOWN TYPE"),
	_T("UNKOWN TYPE"),
	_T("UNKOWN TYPE"),
	_T("UNKOWN TYPE"),
	_T("UNKOWN TYPE"),
};
const int g_nDeviceType = sizeof(g_szDeviceType) / sizeof(TCHAR*);

const TCHAR*      g_szParam[] =
{
	_T("KSJ_EXPOSURE"),
	_T("KSJ_RED"),
	_T("KSJ_GREEN"),
	_T("KSJ_BLUE"),
	_T("KSJ_GAMMA"),
	_T("KSJ_PREVIEW_COLUMNSTART"),
	_T("KSJ_PREVIEW_ROWSTART"),
	_T("KSJ_CAPTURE_COLUMNSTART"),
	_T("KSJ_CAPTURE_ROWSTART"),
	_T("KSJ_HORIZONTALBLANK"),
	_T("KSJ_VERTICALBLANK"),
	_T("KSJ_FLIP"),
	_T("KSJ_BIN"),
	_T("KSJ_MIRROR"),
	_T("KSJ_CONTRAST"),
	_T("KSJ_BRIGHTNESS"),
	_T("KSJ_VGAGAIN"),
	_T("KSJ_CLAMPLEVEL"),
	_T("KSJ_CDSGAIN"),
	_T("KSJ_RED_SHIFT"),
	_T("KSJ_GREEN_SHIFT"),
	_T("KSJ_BLUE_SHIFT"),
	_T("KSJ_COMPANDING"),
	_T("KSJ_EXPOSURE_LINES"),
	_T("KSJ_SATURATION"),
	_T("KSJ_TRIGGERDELAY"),
	_T("KSJ_STROBEDELAY"),
	_T("KSJ_TRIGGER_MODE"),
	_T("KSJ_TRIGGER_METHOD"),
	_T("KSJ_BLACKLEVEL"),
	_T("KSJ_BLACKLEVEL_THRESHOLD_AUTO"),
	_T("KSJ_BLACKLEVEL_THRESHOLD_LO"),
	_T("KSJ_BLACKLEVEL_THRESHOLD_HI")
};
const int g_nParam = sizeof(g_szParam) / sizeof(TCHAR*);

const TCHAR* g_szRomType[] =
{
	_T("24LC64"),
	_T("24LC1024x2"),
	_T("24LC128"),
};
const int g_nRomType = sizeof(g_szRomType) / sizeof(TCHAR*);

const TCHAR* g_szBayerMode[] =
{
	_T("BGGR"),
	_T("GRBG"),
	_T("RGGB"),
	_T("GBRG"),
	_T("MONO"),
};
const int g_nBayerMode = sizeof(g_szBayerMode) / sizeof(TCHAR*);

const TCHAR * g_szFovSkipItems[] =
{
	_T("Normal"),
	_T("2 x 2 Skip"),
	_T("3 x 3 Skip"),
	_T("4 x 4 Skip"),
	_T("8 x 8 Skip"),
};
const int g_nFovSkipItems = sizeof(g_szFovSkipItems) / sizeof(TCHAR*);

const TCHAR* g_szTriggerMode[] =
{
	_T("Internal"),
	_T("External"),
	_T("Software"),
	_T("Fixed Frame Rate"),
};
const int g_nTriggerMode = sizeof(g_szTriggerMode) / sizeof(TCHAR*);

const TCHAR* g_szTriggerMethod[] =
{
	_T("Falling Edge"),
	_T("Rising Edge"),
	_T("High Level"),
	_T("Low Level")
};
const int g_nTriggerMethod = sizeof(g_szTriggerMethod) / sizeof(TCHAR*);

const TCHAR* g_szSensitivity[] =
{
	_T("Low"),
	_T("Mid"),
	_T("High"),
	_T("Higher"),
	_T("Highest")
};
const int g_nSensitivity = sizeof(g_szSensitivity) / sizeof(TCHAR*);

const TCHAR* g_szBadPixelThreshold[] =
{
	_T("High"),
	_T("Low"),
};
const int g_nBadPixelThreshold = sizeof(g_szBadPixelThreshold) / sizeof(TCHAR*);

// enum KSJ_COLOR_TEMPRATURE { KSJ_CT_5000K, KSJ_CT_6500K, KSJ_CT_2800K };
const TCHAR* g_szCCMPresettings[] =
{
	_T("Color Temperature 5000K"),
	_T("Color Temperature 6500K"),
	_T("Color Temperature 2800K"),
};
const int g_nCCMPresettings = sizeof(g_szCCMPresettings) / sizeof(TCHAR*);

// enum KSJ_WB_MODE { KSJ_WB_DISABLE, KSJ_SWB_PRESETTINGS, KSJ_SWB_AUTO_ONCE, KSJ_SWB_AUTO_CONITNUOUS, KSJ_SWB_MANUAL, KSJ_HWB_PRESETTINGS, KSJ_HWB_AUTO_ONCE, KSJ_HWB_AUTO_CONITNUOUS, KSJ_HWB_MANUAL };
const TCHAR  *g_szWBMode[] =
{
	_T("Disable"),
	_T("Software Presettings"),
	_T("Software Auto Once"),
	_T("Software Auto Continuous"),
	_T("Software Manual"),
	_T("Hardware Presettings"),
	_T("Hardware Auto Once"),
	_T("Hardware Auto Continuous"),
	_T("Hardware Manual"),
};
const int g_nWBMode = sizeof(g_szWBMode) / sizeof(TCHAR*);

const TCHAR  *g_szHWBMode[] =
{ 
	_T("Disable"),
	_T("Hardware Presettings"),
    _T("Hardware Auto Once"),
    _T("Hardware Auto Continuous"),
    _T("Hardware Manual"),
};
const int g_nHWBMode = sizeof(g_szHWBMode) / sizeof(TCHAR*);

// enum KSJ_CCM_MODE { KSJ_SCCM_DISABLE, KSJ_SCCM_PRESETTINGS, KSJ_SCCM_MANUAL, KSJ_HCCM_PRESETTINGS, KSJ_HCCM_MANUAL };
const TCHAR* g_szCCMMode[] =
{
	_T("Disable"),
	_T("Software Presettings"),
	_T("Software Manual"),
	_T("Hardware Presettings"),
	_T("Hardware Manual"),
};
const int g_nCCMMode = sizeof(g_szCCMMode) / sizeof(TCHAR*);

const TCHAR* g_szHCCMMode[] =
{
	_T("Disable"),
	_T("Hardware Presettings"),
	_T("Hardware Manual"),
};
const int g_nHCCMMode = sizeof(g_szHCCMMode) / sizeof(TCHAR*);

const TCHAR* g_szFlashMode[] =
{
	_T("Row Time"),
	_T("Simultaneous Exposure"),
	_T("Shutter Width"),
};
const int g_nFlashMode = sizeof(g_szFlashMode) / sizeof(TCHAR*);

const TCHAR* g_szSensorMode[] =
{
	_T("Trigger SnapShot"),
	_T("Free Run"),
	_T("Global Reset"),
};
const int g_nSensorMode = sizeof(g_szSensorMode) / sizeof(TCHAR*);

// enum KSJ_WATERMARKMODE { KSJ_WMM_TIMESTAMP, KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER };
const TCHAR* g_szWaterMarkMode[] =
{
	_T("Time Stamp"),
	_T("Distinguish External Trigger"),
	_T("Analysis External Trigger"),
};
const int g_nWaterMarkMode = sizeof(g_szWaterMarkMode) / sizeof(TCHAR*);


const TCHAR *g_szFunction[] = 
{
	_T("KSJ_PROPERTY_MONO_DEVICE"),                // �Ƿ�Ϊ�ڰ������     0 - �ǣ�     1 - ����
	_T("KSJ_PROPERTY_ADC_RESOLUTION"),             // ���ADC��ת������λ����8��10��12����KSJ_GetADCResolution������ͬ
	_T("KSJ_SUPPORT_MIRROR"),                      // �Ƿ�֧��Ӳ��ˮƽ��ת
	_T("KSJ_SUPPORT_FLIP"),                        // �Ƿ�֧��Ӳ����ֱ��ת
	_T("KSJ_SUPPORT_SKIP2"),                       // �Ƿ�֧��SKIP2
	_T("KSJ_SUPPORT_SKIP3"),
	_T("KSJ_SUPPORT_SKIP4"),
	_T("KSJ_SUPPORT_SKIP8"),
	_T("KSJ_SUPPORT_BINNING"),
	_T("KSJ_SUPPORT_AGC"),
	_T("KSJ_SUPPORT_AEC"),

	_T("KSJ_SUPPORT_TRIGGER_MODE_EXTERNAL"),       // �Ƿ�֧���ⴥ��
	_T("KSJ_SUPPORT_TRIGGER_MODE_SOFTWARE"),       // �Ƿ�֧���������
	_T("KSJ_SUPPORT_TRIGGER_MODE_FIXED_FRAMERATE"),// �Ƿ�֧�ֹ̼�֡�ʴ���
	_T("KSJ_SUPPORT_FIXED_FRAMERATE_SW"),	         // �Ƿ�֧��ͨ���������sensor�̶�֡�ʡ�0 - ��֧�֣�1 - ֧��
	_T("KSJ_SUPPORT_FIXED_FRAMERATE_HW"),          // �Ƿ�֧��ͨ��Ӳ������FPGA�̶�����Ƶ��
	_T("KSJ_SUPPORT_LUT_ENABLE"),                  // �Ƿ�֧��Ӳ�����ұ�ʹ�ܣ� 0 - ��֧�֣� 1 - ֧��
	_T("KSJ_SUPPORT_TRIGGER_METHOD_NEGEDGE"),      // �Ƿ�֧���½��ش���
	_T("KSJ_SUPPORT_TRIGGER_METHOD_POSEDGE"),
	_T("KSJ_SUPPORT_TRIGGER_METHOD_HIGH_LEVEL"),
	_T("KSJ_SUPPORT_TRIGGER_METHOD_LOW_LEVEL"),
	_T("KSJ_SUPPORT_EMPTY_FRAMEBUFFER"),      // �Ƿ�֧�����֡�档0 - ��֧�֣� 1 - ֧��
	_T("KSJ_SUPPORT_SENSITIVITY_MODE"),       // �Ƿ�֧�ֽ�ȡ8λ��ȡ��ͬ��������
	_T("KSJ_SUPPORT_16BITS"),			        // �Ƿ�֧��˫�ֽڴ��䣬һ��������2���ֽڣ����ݶ�ȡ�ӱ���0 - ��֧�֣�1 - ֧��
	_T("KSJ_SUPPORT_BAD_PIXEL_CORRECTION"),   // �Ƿ�֧�ֻ���У��
	_T("KSJ_SUPPORT_LUT_DOWNLOAD"),           // �Ƿ�֧��LUT���ұ����ص�FPGA
	_T("KSJ_SUPPORT_HWB_PRESETTINGS"),        // Ӳ����ƽ���Ƿ�֧��Ԥ��ֵ
	_T("KSJ_SUPPORT_HWB_PRESETTINGS_NUM"),    // Ӳ����ƽ��Ԥ��ֵ�м���
	_T("KSJ_SUPPORT_HWB_AUTO_ONCE"),          // Ӳ���Ƿ�֧�ֵ��ΰ�ƽ�����
	_T("KSJ_SUPPORT_HWB_AUTO_CONTINUOUS"),    // Ӳ���Ƿ�֧��������ƽ�����
	_T("KSJ_SUPPORT_HCCM_PRESETTINGS"),       // Ӳ��CCM�Ƿ�֧��Ԥ��ֵ
	_T("KSJ_SUPPORT_HCCM_PRESETTINGS_NUM"),   // Ӳ��CCM�м���Ԥ��ֵ
	_T("KSJ_SUPPORT_GAMMA_LUT_ENABLE"),       // Ӳ���Ƿ�֧��GAMMA LUT���ұ�ʹ��
	_T("KSJ_SUPPORT_GAMMA_LUT_DOWNLOAD"),     // �Ƿ�֧��Gamma LUT���ص�FPGA�����֧�ִ˹��ܣ��Ϳ���ʹ�ܲ���
	_T("KSJ_SUPPORT_TRIGGER_DELAY"),		    // �Ƿ�֧�ֶ��ⴥ���źŵ���ʱ�����á�0 - ��֧�֣�1 - ֧��
	_T("KSJ_SUPPORT_MULTI_FRAMES"),	        // �Ƿ�֧��һ�ζ�ȡ��֡���ݽ��д�ֱƴͼ��0 - ��֧�֣�1 - ֧��
	_T("KSJ_SUPPORT_HWB_MATRIX"),             // Ӳ���Ƿ�֧�����ð�ƽ�����
	_T("KSJ_SUPPORT_HCCM_MATRIX"),            // Ӳ���Ƿ�֧������CCM����
	_T("KSJ_SUPPORT_GPIO_NORMAL"),            // �Ƿ�֧���ⴥ��������Ϊ��ͨ����IO���Խ��ж�ȡ��������������Ϊ��ͨ���IO���н�������
	_T("KSJ_SUPPORT_IO_FILTER"),              // ������Դ�����˲�
	_T("KSJ_SUPPORT_WATERMAK"),               // �Ƿ�֧��ˮӡ���ܣ�ʱ���ģʽ���ⴥ�����֣��ⴥ�����ܣ�
	_T("KSJ_SUPPORT_GET_FRAME_BUFFER_STATE"), // �̼��Ƿ�֧�ֻ�ȡ֡��״̬
	_T("KSJ_SUPPORT_RESET_DEVICE"),           // �Ƿ�֧�ָ�λ�豸��   0 - ��֧�֣� 1 - ֧��
	_T("KSJ_SUPPORT_SEND_PKT_END"),           // �Ƿ�֧����ֹһ֡����
	_T("KSJ_SUPPORT_RECONNECT"),              // �豸�Ƿ�֧����������
	_T("KSJ_SUPPORT_FAST_UPDATE"),            // �Ƿ�֧�ֿ�������
	_T("KSJ_SUPPORT_WORKINGMODE_PROGRAM"),    // �Ƿ�֧�ֹ̻�����ģʽ
	_T("KSJ_SUPPORT_SERIALSDESC_PROGRAM"),    // �Ƿ�֧�ֹ̻��豸���������
	_T("KSJ_SUPPORT_LUT_PROGRAM"),            // �Ƿ�֧�ֹ̻�LUT���ұ�����
	_T("KSJ_SUPPORT_GAMMA_LUT_PROGRAM"),      // �Ƿ�֧�ֹ̻�Gamma LUT�������
	_T("KSJ_SUPPORT_WORKINGMODEEX_PROGRAM"),  // �Ƿ�֧�ֹ̻���������ģʽ
	_T("KSJ_SUPPORT_COLORMODE_PROGRAM"),      // �Ƿ�֧�ֹ̻�ɫ��ģʽ
	_T("KSJ_SUPPORT_COLORMATRIX_PROGRAM"),    // �Ƿ�֧�ֽ�HWB,HCCMУ������̻�
	_T("KSJ_SUPPORT_SNAP_BUTTON"),            // 
	_T("KSJ_SUPPORT_IO_NUM")
};
const int g_nFunction = sizeof(g_szFunction) / sizeof(TCHAR*);

const TCHAR *g_szFunctionDesc[] =
{
	_T("Is Mono Camera"),                // �Ƿ�Ϊ�ڰ������     0 - �ǣ�     1 - ����
	_T("What Resolution of Sensor"),             // ���ADC��ת������λ����8��10��12����KSJ_GetADCResolution������ͬ
	_T("Does Sensor Support Mirror"),                      // �Ƿ�֧��Ӳ��ˮƽ��ת
	_T("Does Sensor Support Flip"),                        // �Ƿ�֧��Ӳ����ֱ��ת
	_T("Does Sensor Support Skip2"),                       // �Ƿ�֧��SKIP2
	_T("Does Sensor Support Skip3"),
	_T("Does Sensor Support Skip4"),
	_T("Does Sensor Support Skip8"),
	_T("Does Sensor Support Skip Binning"),
	_T("Does Sensor Support AGC(Auto Gain Control)"),
	_T("Does Sensor Support AEC(Auto Exposure Control"),
	_T("Does Hardware Support External Trigger Mode"),       // �Ƿ�֧���ⴥ��
	_T("Does Hardware Support Software Trigger Mode"),       // �Ƿ�֧���������
	_T("Does Hardware Support Software Fixed Frame Trigger Mode"),// �Ƿ�֧�ֹ̼�֡�ʴ���
	_T("Does Software Support Fixed Frame Rate"),	         // �Ƿ�֧��ͨ���������sensor�̶�֡�ʡ�0 - ��֧�֣�1 - ֧��
	_T("Does Hardware Support Fixed Frame Rate"),          // �Ƿ�֧��ͨ��Ӳ������FPGA�̶�����Ƶ��
	_T("Does Hardware Support LUT(16TO8 Look Up Table)"),                  // �Ƿ�֧��Ӳ�����ұ�ʹ�ܣ� 0 - ��֧�֣� 1 - ֧��
	_T("Does Hardware Support Negedge Trigger Method"),      // �Ƿ�֧���½��ش���
	_T("Does Hardware Support Posedge Trigger Method"),
	_T("Does Hardware Support High Level Trigger Method"),
	_T("Does Hardware Support Low Level Trigger Method"),
	_T("Does Hardware Support User Empty Frame Buffer"),      // �Ƿ�֧�����֡�档0 - ��֧�֣� 1 - ֧��
	_T("Does Hardware Support Sensitivity Switch"),       // �Ƿ�֧�ֽ�ȡ8λ��ȡ��ͬ��������
	_T("Does Hardware Support 16bits Transfer"),			        // �Ƿ�֧��˫�ֽڴ��䣬һ��������2���ֽڣ����ݶ�ȡ�ӱ���0 - ��֧�֣�1 - ֧��
	_T("Does Hardware Support Bad Pixel Correction"),   // �Ƿ�֧�ֻ���У��
	_T("Does Hardware Support LUT Download"),           // �Ƿ�֧��LUT���ұ����ص�FPGA
	_T("Does Hardware Support White Balance Matrix Presettings"),        // Ӳ����ƽ���Ƿ�֧��Ԥ��ֵ
	_T("How many Hardware White Balance Presettings Support"),    // Ӳ����ƽ��Ԥ��ֵ�м���
	_T("Does Hardware Support Once White Balance"),          // Ӳ���Ƿ�֧�ֵ��ΰ�ƽ�����
	_T("Does Hardware Support Continuous White Balance"),    // Ӳ���Ƿ�֧��������ƽ�����
	_T("Does Hardware Support Color Correction Matrix Presettings"),       // Ӳ��CCM�Ƿ�֧��Ԥ��ֵ
	_T("How many Hardware Color Correction Presettings Support"),   // Ӳ��CCM�м���Ԥ��ֵ
	_T("Does Hardware Support Gamma LUT(16TO16 Look Up Table)"),       // Ӳ���Ƿ�֧��GAMMA LUT���ұ�ʹ��
	_T("Does Hardware Support Gamma LUT Download"),     // �Ƿ�֧��Gamma LUT���ص�FPGA�����֧�ִ˹��ܣ��Ϳ���ʹ�ܲ���
	_T("Does Hardware Support Trigger Delay"),		    // �Ƿ�֧�ֶ��ⴥ���źŵ���ʱ�����á�0 - ��֧�֣�1 - ֧��
	_T("Does Hardware Support MultiFrames"),	        // �Ƿ�֧��һ�ζ�ȡ��֡���ݽ��д�ֱƴͼ��0 - ��֧�֣�1 - ֧��
	_T("Does Hardware Support Read Write White Balance Matrix"),             // Ӳ���Ƿ�֧�����ð�ƽ�����
	_T("Does Hardware Support Read Write Color Correction Matrix"),            // Ӳ���Ƿ�֧������CCM����
	_T("Does Hardware Support Set IO to Gpio"),            // �Ƿ�֧���ⴥ��������Ϊ��ͨ����IO���Խ��ж�ȡ��������������Ϊ��ͨ���IO���н�������
	_T("Does Hardware Support Io Filter"),              // ������Դ�����˲�
	_T("Does Hardware Support Water Mark"),               // �Ƿ�֧��ˮӡ���ܣ�ʱ���ģʽ���ⴥ�����֣��ⴥ�����ܣ�
	_T("Does Hardware Support Get Frame Buffer Status"), // �̼��Ƿ�֧�ֻ�ȡ֡��״̬
	_T("Does Hardware Support Reset Device"),           // �Ƿ�֧�ָ�λ�豸��   0 - ��֧�֣� 1 - ֧��
	_T("Does Hardware Support Interrupt Current Read Operation"),           // �Ƿ�֧����ֹһ֡����
	_T("Does Hardware Support Reconnect"),              // �豸�Ƿ�֧����������
	_T("Does Hardware Support Fast Upate"),            // �Ƿ�֧�ֿ�������
	_T("Does Hardware Support Program WorkingMode"),    // �Ƿ�֧�ֹ̻�����ģʽ
	_T("Does Hardware Support Program Serials Descriptor"),    // �Ƿ�֧�ֹ̻��豸���������
	_T("Does Hardware Support Program LUT"),            // �Ƿ�֧�ֹ̻�LUT���ұ�����
	_T("Does Hardware Support Program Gamma LUT"),      // �Ƿ�֧�ֹ̻�Gamma LUT�������
	_T("Does Hardware Support Program WorkingModeEx"),  // �Ƿ�֧�ֹ̻���������ģʽ
	_T("Does Hardware Support Program ColorMode"),      // �Ƿ�֧�ֹ̻�ɫ��ģʽ
	_T("Does Hardware Support Program Color Matrix"),    // �Ƿ�֧�ֽ�HWB,HCCMУ������̻�
	_T("Does Hardware Support Snap Button"),            // 
	_T("How many GPIO does Hardware Support")
};

const TCHAR *g_szGpioDirection[] = 
{
	_T("Input"),
	_T("Output")
};
const int g_nGpioDirection = sizeof(g_szGpioDirection) / sizeof(TCHAR*);

const TCHAR *g_szGpioStatus[] = 
{
	_T("Low Level"), 
	_T("High Level")
};
const int g_nGpioStatus = sizeof(g_szGpioStatus) / sizeof(TCHAR*);


enum KSJ_AE_STATUS { KSJ_AE_ONCE_SUCCESS = 0, KSJ_AE_ONCE_FAIL_MAX_COUNT, KSJ_AE_ONCE_FAIL_WAVE, KSJ_AE_ONCE_FAIL_OVER_RANGE, KSJ_AE_DOING, KSJ_AE_CONTINUE_SUCCESS, KSJ_AE_CONTINUE_FAIL_WAVE, KSJ_AE_CONTINUE_FAIL_OVER_RANGE };

const TCHAR *g_szAEStatus[] =
{
	_T("Once Success"),
	_T("Once Fail Max Count"),
	_T("Once Fail Wave"),
	_T("Once Fail Over Range"),
	_T("Doing"),
	_T("Continue Success"),
	_T("Continue Fail Wave"),
	_T("Continue Fail Over Range"),
};
const int g_nAEStatus = sizeof(g_szAEStatus) / sizeof(TCHAR*);

const TCHAR *g_szBayerFilter[] =
{
	_T("Nearest Neighbor"),
	_T("Bilinear"),
	_T("Smooth Hue"),
	_T("Edge Sensing"),
	_T("Laplacian"),
	_T("Fast Bilinear")

};
const int g_nBayerFilter = sizeof(g_szBayerFilter) / sizeof(TCHAR*);


const TCHAR *g_szBayerMode1[] =
{
	_T("BGGR to BGR24"),
	_T("GRBG to BGR24"),
	_T("RGGB to BGR24"),
	_T("GBRG to BGR24"),
	_T("BGGR to BGR24 FLIP"),
	_T("GRBG to BGR24 FLIP"),
	_T("RGGB to BGR24 FLIP"),
	_T("GBRG to BGR24 FLIP"),
	_T("BGGR to BGR32"),
	_T("GRBG to BGR32"),
	_T("RGGB to BGR32"),
	_T("GBRG to BGR32"),
	_T("BGGR to BGR32 FLIP"),
	_T("GRBG to BGR32 FLIP"),
	_T("RGGB to BGR32 FLIP"),
	_T("GBRG to BGR32 FLIP"),
	_T("BGGR to GRAY8"),
	_T("GRBG to GRAY8"),
	_T("RGGB to GRAY8"),
	_T("GBRG to GRAY8"),
	_T("BGGR to GRAY8 FLIP"),
	_T("GRBG to GRAY8 FLIP"),
	_T("RGGB to GRAY8 FLIP"),
	_T("GBRG to GRAY8 FLIP")
};

const int g_nBayerMode1 = sizeof(g_szBayerMode1) / sizeof(TCHAR*);


const TCHAR *g_szMapMode[] =
{
	_T("Nearest Neighbor"),
	_T("Bilinear")
};
const int g_nMapMode = sizeof(g_szMapMode) / sizeof(TCHAR*);
