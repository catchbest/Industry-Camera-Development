using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace KSJ_GS
{
    public class KSJGS
    {
        public static string[] g_szDeviceType = 
        {
	        ("Gauss2 UC130C(MRNN)"),
	        ("Gauss2 UC130M(MRNN)"),
	        ("xxxxxxxxxxxxxxxxxxx"),
	        ("Gauss2 UC320C(MRNN)"),
	        ("Gauss2 UC130C(MRYN)"),
	        ("Gauss2 UC130M(MRYN)"),
	        ("xxxxxxxxxxxxxxxxxxx"),
	        ("Gauss2 UC320C(MRYN)"),
	        ("Gauss2 UC500C(MRNN)"),
	        ("Gauss2 UC500M(MRNN)"),
	        ("Gauss2 UC500C(MRYN)"),
	        ("Gauss2 UC500M(MRYN)"),
	        ("xxxxxxx UC320C(OCR)"),
	        ("xxxxxxx UC900C(MRNN)"),
	        ("xxxxxxx UC1000C(MRNN)"),
	        ("xxxxxxx UC900C(MRYN)"),
	        ("xxxxxxx UC1000C(MRYN)"),
	        ("Elanus2 UC130C(MRYY)"),
	        ("Elanus2 UC130M(MRYY)"),
	        ("xxxxxxx UD140C(SRNN)"),
	        ("xxxxxxx UD140M(SRNN)"),
	        ("xxxxxxx UC36C(MGNN)"),
	        ("xxxxxxx UC36M(MGNN)"),
	        ("xxxxxxx UC36C(MGYN)"),
	        ("xxxxxxx UC36M(MGYN)"),

	        ("Elanus2 UC900C(MRYY)"),
	        ("Elanus2 UC1000C(MRYY)"),
	        ("Elanus2 UC1400C(MRYY)"),
	        ("Elanus2 UC36C(MGYY)"),
	        ("Elanus2 UC36M(MGYY)"),
	        ("Elanus2 UC320C(MRYY)"),
	        ("Elanus2 UC500C(MRYY)"),
	        ("Elanus2 UC500M(MRYY)"),

	        ("CatchBEST MUC130C(MRYN)"),
	        ("CatchBEST MUC130M(MRYN)"),
	        ("CatchBEST MUC320C(MRYN)"),

	        ("Jelly2 MUC36C(MGYYO)"),
	        ("Jelly2 MUC36M(MGYYO)"),

	        ("xxxxxx MUC130C(MRYY)"),
	        ("xxxxxx MUC130M(MRYY)"),
	        ("xxxxxx MUC320C(MRYY)"),
	        ("xxxxxx MUC500C(MRYY)"),
	        ("xxxxxx MUC500M(MRYY)"),
	        ("xxxxxx MUC900C(MRYY)"),
	        ("xxxxxx MUC1000C(MRYY)"),
	        ("xxxxxx MUC1400C(MRYY)"),

	        ("Elanus2 UD205C(SGYY)"),
	        ("Elanus2 UD205M(SGYY)"),
	        ("Elanus2 UD274C(SGYY)"),
	        ("Elanus2 UD274M(SGYY)"),
	        ("Elanus2 UD285C(SGYY)"),
	        ("Elanus2 UD285M(SGYY)"),

	        ("Jelly3 MU3C500C(MRYYO)"),
	        ("Jelly3 MU3C500M(MRYYO)"),
	        ("Jelly3 MU3C1000C(MRYYO)"),
	        ("Jelly3 MU3C1400C(MRYYO)"),
	        ("Jelly3 MU3V130C(CGYYO)"),
	        ("Jelly3 MU3V130M(CGYYO)"),
	        ("Jelly3 MU3E130C(EGYYO)"),
	        ("Jelly3 MU3E130M(EGYYO)"),
	        ("Jelly1 MUC36C(MGYFO)"),
	        ("Jelly1 MUC36M(MGYFO)"),

	        ("Jelly3 MU3C120C(MGYYO)"),
	        ("Jelly3 MU3C120M(MGYYO)"),
	        ("Jelly3 MU3E200C(EGYYO)"),
	        ("Jelly3 MU3E200M(EGYYO)"),

	        ("Jelly1 MUC130C(MRYNO)"),    // Jelly1 ++20150208
	        ("Jelly1 MUC130M(MRYNO)"),    // Jelly1 ++20150208
	        ("Jelly1 MUC320C(MRYNO)"),    // Jelly1 ++20150208

	        ("Gauss3 U3C130C(MRYNO)"),
	        ("Gauss3 U3C130M(MRYNO)"),
	        ("Gauss3 U3C320C(MRYNO)"),
	        ("Gauss3 U3C500C(MRYNO)"),
	        ("Gauss3 U3C500M(MRYNO)"),

	        ("xxxxxx MU3C1401C(MRYYO)"),
	        ("xxxxxx MU3C1001C(MRYYO)"),
	        ("xxxxxx MUC131M(MRYN)"),

	        ("xxxxxx MU3C501C(MRYYO)"),
	        ("xxxxxx MU3C501M(MRYYO)"),
	        ("xxxxxx MU3C121C(MGYYO)"),
	        ("xxxxxx MU3C121M(MGYYO)"),
	        ("xxxxxx MU3E131C(EGYY)"),
	        ("xxxxxx MU3E131M(EGYY)"),
	        ("xxxxxx MU3E201C(EGYYO)"),
	        ("xxxxxx MU3E201M(EGYYO)"),

	        ("Missing Device"),

	        ("Jelly3 MU3S230C(SGYYO)"),
	        ("Jelly3 MU3S230M(SGYYO)"),

	        ("Jelly3 MU3S640C(SRYYO)"),
	        ("Jelly3 MU3S640M(SRYYO)"),

	        ("Cooler CUD285C(SGYYO)"),
	        ("Cooler CUD285M(SGYYO)"),

	        ("Jelly3 MU3S231C(SGYYO)"),
	        ("Jelly3 MU3S231M(SGYYO)"),

            ("Jelly3 MU3S500C(SGYYO)"),
	        ("Jelly3 MU3S500M(SGYYO)"),

	        ("Jelly3 MU3S1200C(SRYYO)"),
	        ("Jelly3 MU3S1200M(SRYYO)"),

	        ("Jelly4 MU3L2K7C(AGYYO)"),
	        ("Jelly4 MU3L2K7M(AGYYO)"),
	        ("Jelly4 MU3L4K3C(AGYYO)"),
	        ("Jelly4 MU3L4K3M(AGYYO)"),

	        ("MU3HS2000C(SRYYO)"),
	        ("MU3HS2000M(SRYYO)"),

            ("Jelly6 MU3HS500C(SRYYO)"),
	        ("Jelly6 MU3HS500M(SRYYO)"),

	        ("Jelly6 MU3HS230C(SGYYO)"),
	        ("Jelly6 MU3HS230M(SGYYO)"),

	        ("Jelly6 MU3HI400C(IGYYO)"),
	        ("Jelly6 MU3HI400M(IGYYO)"),

	        ("TEST CAMERA"),

	        ("Jelly6 MU3HI401C(IGYYO)"),
	        ("Jelly6 MU3HI401M(IGYYO)"),

	        ("Jelly6 MU3S40C(SGYYO)"),
	        ("Jelly6 MU3S40M(SGYYO)"),

	        ("Jelly6 MU3S210C(SRYYO)"),
	        ("Jelly6 MU3S210M(SRYYO)"),
	        ("Jelly6 MU3I130C(IGYYO)"),
	        ("Jelly6 MU3I130M(IGYYO)"),

	        ("Jelly6 MU3S321C(SGYYO)"),
	        ("Jelly6 MU3S321M(SGYYO)"),

	        ("Jelly3 MU3S641M(SRYYO)"),
	        ("Jelly3 MU3S1201M(SRYYO)"),
	        ("Jelly3 MU3S2001M(SRYYO)"),
	        ("UNKOWN TYPE"),
	        ("UNKOWN TYPE"),
	        ("UNKOWN TYPE"),
	        ("UNKOWN TYPE"),
	        ("UNKOWN TYPE"),
	        ("UNKOWN TYPE"),
        };

        public static int g_nDeviceType = g_szDeviceType.Length;

        public static string[] g_szParam =
        {
	        ("KSJ_EXPOSURE"),
	        ("KSJ_RED"),
	        ("KSJ_GREEN"),
	        ("KSJ_BLUE"),
	        ("KSJ_GAMMA"),
	        ("KSJ_PREVIEW_COLUMNSTART"),
	        ("KSJ_PREVIEW_ROWSTART"),
	        ("KSJ_CAPTURE_COLUMNSTART"),
	        ("KSJ_CAPTURE_ROWSTART"),
	        ("KSJ_HORIZONTALBLANK"),
	        ("KSJ_VERTICALBLANK"),
	        ("KSJ_FLIP"),
	        ("KSJ_BIN"),
	        ("KSJ_MIRROR"),
	        ("KSJ_CONTRAST"),
	        ("KSJ_BRIGHTNESS"),
	        ("KSJ_VGAGAIN"),
	        ("KSJ_CLAMPLEVEL"),
	        ("KSJ_CDSGAIN"),
	        ("KSJ_RED_SHIFT"),
	        ("KSJ_GREEN_SHIFT"),
	        ("KSJ_BLUE_SHIFT"),
	        ("KSJ_COMPANDING"),
	        ("KSJ_EXPOSURE_LINES"),
	        ("KSJ_SATURATION"),
	        ("KSJ_TRIGGERDELAY"),
	        ("KSJ_STROBEDELAY"),
	        ("KSJ_TRIGGER_MODE"),
	        ("KSJ_TRIGGER_METHOD"),
	        ("KSJ_BLACKLEVEL"),
	        ("KSJ_BLACKLEVEL_THRESHOLD_AUTO"),
	        ("KSJ_BLACKLEVEL_THRESHOLD_LO"),
	        ("KSJ_BLACKLEVEL_THRESHOLD_HI")
        };
        public static int g_nParam = g_szParam.Length;

        public static string[] g_szRomType =
        {
            ("24LC64"),
            ("24LC1024x2"),
            ("24LC128"),
        };
        public static int g_nRomType = g_szRomType.Length;

        public static string[] g_szBayerMode =
        {
            ("BGGR"),
            ("GRBG"),
            ("RGGB"),
            ("GBRG"),
            ("MONO"),
        };
        public static int g_nBayerMode = g_szBayerMode.Length;

        public static string[] g_szFovSkipItems =
        {
            ("Normal"),
            ("2 x 2 Skip"),
            ("3 x 3 Skip"),
            ("4 x 4 Skip"),
            ("8 x 8 Skip"),
        };
        public static int g_nFovSkipItems = g_szFovSkipItems.Length;

        public static string[] g_szTriggerMode =
        {
            ("Internal"),
            ("External"),
            ("Software"),
            ("Fixed Frame Rate"),
        };
        public static int g_nTriggerMode = g_szTriggerMode.Length;

         public static string[] g_szTriggerMethod =
        {
            ("Falling Edge"),
            ("Rising Edge"),
            ("High Level"),
            ("Low Level")
        };
        public static int g_nTriggerMethod = g_szTriggerMethod.Length;

        public static string[] g_szSensitivity =
        {
            ("Low"),
            ("Mid"),
            ("High"),
            ("Higher"),
            ("Highest")
        };
        public static int g_nSensitivity = g_szSensitivity.Length;

        public static string[] g_szBadPixelThreshold =
        {
            ("High"),
            ("Low"),
        };
        public static int g_nBadPixelThreshold = g_szBadPixelThreshold.Length;

        // enum KSJ_COLOR_TEMPRATURE { KSJ_CT_5000K, KSJ_CT_6500K, KSJ_CT_2800K };
        public static string[] g_szCCMPresettings =
        {
            ("Color Temperature 5000K"),
            ("Color Temperature 6500K"),
            ("Color Temperature 2800K"),
        };
        public static int g_nCCMPresettings = g_szCCMPresettings.Length;

        // enum KSJ_WB_MODE { KSJ_WB_DISABLE, KSJ_SWB_PRESETTINGS, KSJ_SWB_AUTO_ONCE, KSJ_SWB_AUTO_CONITNUOUS, KSJ_SWB_MANUAL, KSJ_HWB_PRESETTINGS, KSJ_HWB_AUTO_ONCE, KSJ_HWB_AUTO_CONITNUOUS, KSJ_HWB_MANUAL };
        public static string[] g_szWBMode =
        {
            ("Disable"),
            ("Software Presettings"),
            ("Software Auto Once"),
            ("Software Auto Continuous"),
            ("Software Manual"),
            ("Hardware Presettings"),
            ("Hardware Auto Once"),
            ("Hardware Auto Continuous"),
            ("Hardware Manual"),
        };
        public static int g_nWBMode = g_szWBMode.Length;

        public static string[] g_szHWBMode =
        { 
            ("Hardware Presettings"),
            ("Hardware Auto Once"),
            ("Hardware Auto Continuous"),
            ("Hardware Manual"),
        };
        public static int g_nHWBMode = g_szHWBMode.Length;

        // enum KSJ_CCM_MODE { KSJ_SCCM_DISABLE, KSJ_SCCM_PRESETTINGS, KSJ_SCCM_MANUAL, KSJ_HCCM_PRESETTINGS, KSJ_HCCM_MANUAL };
        public static string[] g_szCCMMode =
        {
            ("Disable"),
            ("Software Presettings"),
            ("Software Manual"),
            ("Hardware Presettings"),
            ("Hardware Manual"),
        };
        public static int g_nCCMMode = g_szCCMMode.Length;

        public static string[] g_szHCCMMode =
        {
            ("Disable"),
            ("Hardware Presettings"),
            ("Hardware Manual"),
        };
        public static int g_nHCCMMode = g_szHCCMMode.Length;

        public static string[] g_szFlashMode =
        {
            ("Row Time"),
            ("Simultaneous Exposure"),
            ("Shutter Width"),
        };
        public static int g_nFlashMode = g_szFlashMode.Length;

        public static string[] g_szSensorMode =
        {
            ("Trigger SnapShot"),
            ("Free Run"),
            ("Global Reset"),
        };
        public static int g_nSensorMode = g_szSensorMode.Length;

        // enum KSJ_WATERMARKMODE { KSJ_WMM_TIMESTAMP, KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER };
        public static string[] g_szWaterMarkMode =
        {
            ("Time Stamp"),
            ("Distinguish External Trigger"),
            ("Analysis External Trigger"),
        };
        public static int g_nWaterMarkMode = g_szWaterMarkMode.Length;


        public static string[] g_szFunction = 
        {
            ("KSJ_PROPERTY_MONO_DEVICE"),                // 是否为黑白相机，     0 - 是；     1 - 不是
            ("KSJ_PROPERTY_ADC_RESOLUTION"),             // 相机ADC的转换比特位数，8，10，12，与KSJ_GetADCResolution功能相同
            ("KSJ_SUPPORT_MIRROR"),                      // 是否支持硬件水平翻转
            ("KSJ_SUPPORT_FLIP"),                        // 是否支持硬件垂直翻转
            ("KSJ_SUPPORT_SKIP2"),                       // 是否支持SKIP2
            ("KSJ_SUPPORT_SKIP3"),
            ("KSJ_SUPPORT_SKIP4"),
            ("KSJ_SUPPORT_SKIP8"),
            ("KSJ_SUPPORT_BINNING"),
            ("KSJ_SUPPORT_AGC"),
            ("KSJ_SUPPORT_AEC"),

            ("KSJ_SUPPORT_TRIGGER_MODE_EXTERNAL"),       // 是否支持外触发
            ("KSJ_SUPPORT_TRIGGER_MODE_SOFTWARE"),       // 是否支持软件触发
            ("KSJ_SUPPORT_TRIGGER_MODE_FIXED_FRAMERATE"),// 是否支持固件帧率触发
            ("KSJ_SUPPORT_FIXED_FRAMERATE_SW"),	         // 是否支持通过软件设置sensor固定帧率。0 - 不支持，1 - 支持
            ("KSJ_SUPPORT_FIXED_FRAMERATE_HW"),          // 是否支持通过硬件设置FPGA固定触发频率
            ("KSJ_SUPPORT_LUT_ENABLE"),                  // 是否支持硬件查找表使能， 0 - 不支持； 1 - 支持
            ("KSJ_SUPPORT_TRIGGER_METHOD_NEGEDGE"),      // 是否支持下降沿触发
            ("KSJ_SUPPORT_TRIGGER_METHOD_POSEDGE"),
            ("KSJ_SUPPORT_TRIGGER_METHOD_HIGH_LEVEL"),
            ("KSJ_SUPPORT_TRIGGER_METHOD_LOW_LEVEL"),
            ("KSJ_SUPPORT_EMPTY_FRAMEBUFFER"),      // 是否支持清空帧存。0 - 不支持； 1 - 支持
            ("KSJ_SUPPORT_SENSITIVITY_MODE"),       // 是否支持截取8位获取不同的灵敏度
            ("KSJ_SUPPORT_16BITS"),			        // 是否支持双字节传输，一个像素用2个字节，数据读取加倍。0 - 不支持，1 - 支持
            ("KSJ_SUPPORT_BAD_PIXEL_CORRECTION"),   // 是否支持坏点校正
            ("KSJ_SUPPORT_LUT_DOWNLOAD"),           // 是否支持LUT查找表下载到FPGA
            ("KSJ_SUPPORT_HWB_PRESETTINGS"),        // 硬件白平衡是否支持预设值
            ("KSJ_SUPPORT_HWB_PRESETTINGS_NUM"),    // 硬件白平衡预设值有几组
            ("KSJ_SUPPORT_HWB_AUTO_ONCE"),          // 硬件是否支持单次白平衡操作
            ("KSJ_SUPPORT_HWB_AUTO_CONTINUOUS"),    // 硬件是否支持连续白平衡操作
            ("KSJ_SUPPORT_HCCM_PRESETTINGS"),       // 硬件CCM是否支持预设值
            ("KSJ_SUPPORT_HCCM_PRESETTINGS_NUM"),   // 硬件CCM有几组预设值
            ("KSJ_SUPPORT_GAMMA_LUT_ENABLE"),       // 硬件是否支持GAMMA LUT查找表使能
            ("KSJ_SUPPORT_GAMMA_LUT_DOWNLOAD"),     // 是否支持Gamma LUT下载到FPGA，如果支持此功能，就可以使能操作
            ("KSJ_SUPPORT_TRIGGER_DELAY"),		    // 是否支持对外触发信号的延时的设置。0 - 不支持，1 - 支持
            ("KSJ_SUPPORT_MULTI_FRAMES"),	        // 是否支持一次读取多帧数据进行垂直拼图。0 - 不支持，1 - 支持
            ("KSJ_SUPPORT_HWB_MATRIX"),             // 硬件是否支持设置白平衡矩阵
            ("KSJ_SUPPORT_HCCM_MATRIX"),            // 硬件是否支持设置CCM矩阵
            ("KSJ_SUPPORT_GPIO_NORMAL"),            // 是否支持外触发输入作为普通输入IO可以进行读取并且闪光灯输出作为普通输出IO进行进行设置
            ("KSJ_SUPPORT_IO_FILTER"),              // 对输入源进行滤波
            ("KSJ_SUPPORT_WATERMAK"),               // 是否支持水印功能（时间戳模式，外触发区分，外触发加密）
            ("KSJ_SUPPORT_GET_FRAME_BUFFER_STATE"), // 固件是否支持获取帧存状态
            ("KSJ_SUPPORT_RESET_DEVICE"),           // 是否支持复位设备，   0 - 不支持； 1 - 支持
            ("KSJ_SUPPORT_SEND_PKT_END"),           // 是否支持终止一帧传输
            ("KSJ_SUPPORT_RECONNECT"),              // 设备是否支持重新连接
            ("KSJ_SUPPORT_FAST_UPDATE"),            // 是否支持快速升级
            ("KSJ_SUPPORT_WORKINGMODE_PROGRAM"),    // 是否支持固化工作模式
            ("KSJ_SUPPORT_SERIALSDESC_PROGRAM"),    // 是否支持固化设备序号描述符
            ("KSJ_SUPPORT_LUT_PROGRAM"),            // 是否支持固化LUT查找表数据
            ("KSJ_SUPPORT_GAMMA_LUT_PROGRAM"),      // 是否支持固化Gamma LUT到相机中
            ("KSJ_SUPPORT_WORKINGMODEEX_PROGRAM"),  // 是否支持固化超级工作模式
            ("KSJ_SUPPORT_COLORMODE_PROGRAM"),      // 是否支持固化色彩模式
            ("KSJ_SUPPORT_COLORMATRIX_PROGRAM"),    // 是否支持将HWB,HCCM校正矩阵固化
            ("KSJ_SUPPORT_SNAP_BUTTON"),            // 
            ("KSJ_SUPPORT_IO_NUM")
        };
        public static int g_nFunction = g_szFunction.Length;

        public static string[] g_szFunctionDesc =
        {
            ("Is Mono Camera"),                // 是否为黑白相机，     0 - 是；     1 - 不是
            ("What Resolution of Sensor"),             // 相机ADC的转换比特位数，8，10，12，与KSJ_GetADCResolution功能相同
            ("Does Sensor Support Mirror"),                      // 是否支持硬件水平翻转
            ("Does Sensor Support Flip"),                        // 是否支持硬件垂直翻转
            ("Does Sensor Support Skip2"),                       // 是否支持SKIP2
            ("Does Sensor Support Skip3"),
            ("Does Sensor Support Skip4"),
            ("Does Sensor Support Skip8"),
            ("Does Sensor Support Skip Binning"),
            ("Does Sensor Support AGC(Auto Gain Control)"),
            ("Does Sensor Support AEC(Auto Exposure Control"),
            ("Does Hardware Support External Trigger Mode"),       // 是否支持外触发
            ("Does Hardware Support Software Trigger Mode"),       // 是否支持软件触发
            ("Does Hardware Support Software Fixed Frame Trigger Mode"),// 是否支持固件帧率触发
            ("Does Software Support Fixed Frame Rate"),	         // 是否支持通过软件设置sensor固定帧率。0 - 不支持，1 - 支持
            ("Does Hardware Support Fixed Frame Rate"),          // 是否支持通过硬件设置FPGA固定触发频率
            ("Does Hardware Support LUT(16TO8 Look Up Table)"),                  // 是否支持硬件查找表使能， 0 - 不支持； 1 - 支持
            ("Does Hardware Support Negedge Trigger Method"),      // 是否支持下降沿触发
            ("Does Hardware Support Posedge Trigger Method"),
            ("Does Hardware Support High Level Trigger Method"),
            ("Does Hardware Support Low Level Trigger Method"),
            ("Does Hardware Support User Empty Frame Buffer"),      // 是否支持清空帧存。0 - 不支持； 1 - 支持
            ("Does Hardware Support Sensitivity Switch"),       // 是否支持截取8位获取不同的灵敏度
            ("Does Hardware Support 16bits Transfer"),			        // 是否支持双字节传输，一个像素用2个字节，数据读取加倍。0 - 不支持，1 - 支持
            ("Does Hardware Support Bad Pixel Correction"),   // 是否支持坏点校正
            ("Does Hardware Support LUT Download"),           // 是否支持LUT查找表下载到FPGA
            ("Does Hardware Support White Balance Matrix Presettings"),        // 硬件白平衡是否支持预设值
            ("How many Hardware White Balance Presettings Support"),    // 硬件白平衡预设值有几组
            ("Does Hardware Support Once White Balance"),          // 硬件是否支持单次白平衡操作
            ("Does Hardware Support Continuous White Balance"),    // 硬件是否支持连续白平衡操作
            ("Does Hardware Support Color Correction Matrix Presettings"),       // 硬件CCM是否支持预设值
            ("How many Hardware Color Correction Presettings Support"),   // 硬件CCM有几组预设值
            ("Does Hardware Support Gamma LUT(16TO16 Look Up Table)"),       // 硬件是否支持GAMMA LUT查找表使能
            ("Does Hardware Support Gamma LUT Download"),     // 是否支持Gamma LUT下载到FPGA，如果支持此功能，就可以使能操作
            ("Does Hardware Support Trigger Delay"),		    // 是否支持对外触发信号的延时的设置。0 - 不支持，1 - 支持
            ("Does Hardware Support MultiFrames"),	        // 是否支持一次读取多帧数据进行垂直拼图。0 - 不支持，1 - 支持
            ("Does Hardware Support Read Write White Balance Matrix"),             // 硬件是否支持设置白平衡矩阵
            ("Does Hardware Support Read Write Color Correction Matrix"),            // 硬件是否支持设置CCM矩阵
            ("Does Hardware Support Set IO to Gpio"),            // 是否支持外触发输入作为普通输入IO可以进行读取并且闪光灯输出作为普通输出IO进行进行设置
            ("Does Hardware Support Io Filter"),              // 对输入源进行滤波
            ("Does Hardware Support Water Mark"),               // 是否支持水印功能（时间戳模式，外触发区分，外触发加密）
            ("Does Hardware Support Get Frame Buffer Status"), // 固件是否支持获取帧存状态
            ("Does Hardware Support Reset Device"),           // 是否支持复位设备，   0 - 不支持； 1 - 支持
            ("Does Hardware Support Interrupt Current Read Operation"),           // 是否支持终止一帧传输
            ("Does Hardware Support Reconnect"),              // 设备是否支持重新连接
            ("Does Hardware Support Fast Upate"),            // 是否支持快速升级
            ("Does Hardware Support Program WorkingMode"),    // 是否支持固化工作模式
            ("Does Hardware Support Program Serials Descriptor"),    // 是否支持固化设备序号描述符
            ("Does Hardware Support Program LUT"),            // 是否支持固化LUT查找表数据
            ("Does Hardware Support Program Gamma LUT"),      // 是否支持固化Gamma LUT到相机中
            ("Does Hardware Support Program WorkingModeEx"),  // 是否支持固化超级工作模式
            ("Does Hardware Support Program ColorMode"),      // 是否支持固化色彩模式
            ("Does Hardware Support Program Color Matrix"),    // 是否支持将HWB,HCCM校正矩阵固化
            ("Does Hardware Support Snap Button"),            // 
            ("How many GPIO does Hardware Support")
        };

        public static string[] g_szGpioDirection = 
        {
            ("Input"),
            ("Output")
        };
        public static int g_nGpioDirection = g_szGpioDirection.Length;

        public static string[] g_szGpioStatus = 
        {
            ("Low Level"), 
            ("High Level")
        };
        public static int g_nGpioStatus = g_szGpioStatus.Length;
    }
}
