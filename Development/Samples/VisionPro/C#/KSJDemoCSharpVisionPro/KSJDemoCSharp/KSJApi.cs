using System;
using System.Runtime.InteropServices;
using System.Text;

/// <summary>
/// 2010.07.25 还有些简单函数没有列出，客户可参考例程自己加入
/// </summary>
namespace KSJCamera
{
	public class KSJApiBase
	{
        public enum KSJ_DEVICETYPE
        {
            KSJ_UC130C_MRNN = 0,  // Guass2
            KSJ_UC130M_MRNN,      // Guass2
            KSJ_RESERVED0,
            KSJ_UC320C_MRNN,      // Guass2
            KSJ_UC130C_MRYN,
            KSJ_UC130M_MRYN,
            KSJ_RESERVED1,
            KSJ_UC320C_MRYN,
            KSJ_UC500C_MRNN,
            KSJ_UC500M_MRNN,
            KSJ_UC500C_MRYN,
            KSJ_UC500M_MRYN,
            KSJ_UC320C_OCR,      // Not Support
            KSJ_UC900C_MRNN,     // Not Support
            KSJ_UC1000C_MRNN,    // Not Support
            KSJ_UC900C_MRYN,     // Not Support
            KSJ_UC1000C_MRYN,    // Not Support
            KSJ_UC130C_MRYY,     // Elanus2
            KSJ_UC130M_MRYY,     // Elanus2 
            KSJ_UD140C_SGNN,     // Not Support
            KSJ_UD140M_SGNN,     // Not Support
            KSJ_UC36C_MGNN,      // Not Support
            KSJ_UC36M_MGNN,      // Not Support
            KSJ_UC36C_MGYN,      // Not Support
            KSJ_UC36M_MGYN,      // Not Support
            KSJ_UC900C_MRYY,     // Elanus2
            KSJ_UC1000C_MRYY,    // Elanus2
            KSJ_UC1400C_MRYY,    // Elanus2
            KSJ_UC36C_MGYY,      // Elanus2
            KSJ_UC36M_MGYY,      // Elanus2
            KSJ_UC320C_MRYY,     // Elanus2
            KSJ_UC500C_MRYY,     // Elanus2
            KSJ_UC500M_MRYY,     // Elanus2
            KSJ_MUC130C_MRYN,    // OEM
            KSJ_MUC130M_MRYN,    // OEM
            KSJ_MUC320C_MRYN,    // OEM
            KSJ_MUC36C_MGYYO,    // Jelly2
            KSJ_MUC36M_MGYYO,    // Jelly2 
            KSJ_MUC130C_MRYY,    // Not Support
            KSJ_MUC130M_MRYY,    // Not Support
            KSJ_MUC320C_MRYY,    // Not Support
            KSJ_MUC500C_MRYYO,   // Jelly2
            KSJ_MUC500M_MRYYO,   // Jelly2
            KSJ_MUC900C_MRYY,    // Not Support
            KSJ_MUC1000C_MRYY,   // Not Support
            KSJ_MUC1400C_MRYY,   // Not Support
            KSJ_UD205C_SGYY,     // Elanus2
            KSJ_UD205M_SGYY,     // Elanus2
            KSJ_UD274C_SGYY,     // Elanus2
            KSJ_UD274M_SGYY,     // Elanus2
            KSJ_UD285C_SGYY,     // Elanus2
            KSJ_UD285M_SGYY,     // Elanus2
            KSJ_MU3C500C_MRYYO,  // Jelly3 
            KSJ_MU3C500M_MRYYO,  // Jelly3
            KSJ_MU3C1000C_MRYYO, // Jelly3
            KSJ_MU3C1400C_MRYYO, // Jelly3
            KSJ_MU3V130C_CGYYO,  // Jelly3
            KSJ_MU3V130M_CGYYO,  // Jelly3
            KSJ_MU3E130C_EGYYO,  // Jelly3
            KSJ_MU3E130M_EGYYO,  // Jelly3
            KSJ_MUC36C_MGYFO,    // Jelly1
            KSJ_MUC36M_MGYFO,    // Jelly1
            KSJ_MU3C120C_MGYYO,  // Jelly3
            KSJ_MU3C120M_MGYYO,  // Jelly3
            KSJ_MU3E200C_EGYYO,  // Jelly3
            KSJ_MU3E200M_EGYYO,  // Jelly3
            KSJ_MUC130C_MRYNO,   // Jelly1
            KSJ_MUC130M_MRYNO,   // Jelly1
            KSJ_MUC320C_MRYNO,   // Jelly1
            KSJ_U3C130C_MRYNO,   // Not Support
            KSJ_U3C130M_MRYNO,   // Not Support
            KSJ_U3C320C_MRYNO,   // Not Support
            KSJ_U3C500C_MRYNO,   // Guass3
            KSJ_U3C500M_MRYNO,   // Guass3
            KSJ_MU3C1401C_MRYYO,
            KSJ_MU3C1001C_MRYYO,
            KSJ_MUC131M_MRYN,    // OEM Device
            KSJ_MU3C501C_MRYYO,
            KSJ_MU3C501M_MRYYO,
            KSJ_MU3C121C_MGYYO,
            KSJ_MU3C121M_MGYYO,
            KSJ_MU3E131C_EGYYO,
            KSJ_MU3E131M_EGYYO,
            KSJ_MU3E201C_EGYYO,
            KSJ_MU3E201M_EGYYO,
            KSJ_MISSING_DEVICE,	  // Device Lost Program
            KSJ_MU3S230C_SGYYO,   // Jelly3 Sony IMX174
            KSJ_MU3S230M_SGYYO,   // Jelly3 Sony IMX174
            KSJ_MU3S640C_SRYYO,   // Jelly3 Sony IMX178
            KSJ_MU3S640M_SRYYO,   // Jelly3 Sony IMX178
            KSJ_CUD285C_SGYYO,
            KSJ_CUD285M_SGYYO,
            KSJ_MU3S231C_SGYYO,   // Jelly3 Sony IMX249
            KSJ_MU3S231M_SGYYO,   // Jelly3 Sony IMX249
            KSJ_MU3S500C_SGYYO,
            KSJ_MU3S500M_SGYYO,
            KSJ_MU3S1200C_SRYYO,
            KSJ_MU3S1200M_SRYYO,
            KSJ_MU3L2K7C_AGYYO,
            KSJ_MU3L2K7M_AGYYO,
            KSJ_MU3L4K3C_AGYYO,    // 100
            KSJ_MU3L4K3M_AGYYO,
            KSJ_MU3HS2000C_SRYYO,
            KSJ_MU3HS2000M_SRYYO,

            KSJ_MU3HS500C_SGYYO,
            KSJ_MU3HS500M_SGYYO,
            KSJ_MU3HS230C_SGYYO,   // imx174 
            KSJ_MU3HS230M_SGYYO,
            KSJ_MU3HI400C_IGYYO,
            KSJ_MU3HI500M_IGYYO
        };


        // Enable or Disable Log output
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LogSet(bool bEnable, string pszFolder);
        // Get Log Status
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_LogGet(ref bool bEnable, string pszFolder);
        // Get KSJApi.dll Version, call any time.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetVersion(ref int pnMaj1, ref int pnMaj2, ref int pnMin1, ref int pnMin2);
        // Get Return String Information. call any time.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetErrorInfo(int nErrorNo, IntPtr pszErrorInfo);
        // 初始化动态库，必须调用
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_Init();
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_UnInit();
        // 得到接入设备数目
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_DeviceGetCount();
        // 得到设备信息（型号，序号，固件版本号）
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_DeviceGetInformation(int nChannel, ref int pDeviceType, ref int pnIndex, ref ushort pwFirmwareVersion);
        // 得到设备信息（型号，序号，固件版本号）
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_DeviceGetInformationEx(int nChannel, ref KSJ_DEVICETYPE pDeviceType, ref int pnIndex, ref ushort pwFirmwareVersion, ref ushort pwFpgaVersion);

        // 相机参数
        public enum KSJ_PARAM
        {
            KSJ_EXPOSURE = 0,        // Exposure Time (ms)
            KSJ_RED,                 // Red Gain
            KSJ_GREEN,               // Green Gain
            KSJ_BLUE,                // Blue Gain
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
            KSJRIGGERDELAY,        // Trigger Delay Step = 100uS
            KSJ_STROBEDELAY,         // Not Use
            KSJRIGGER_MODE,        // Trigger Mode
            KSJRIGGER_METHOD,      // Trigger Method
            KSJ_BLACKLEVEL,          // Black Level
            KSJ_BLACKLEVELHRESHOLD_AUTO, // Black Level Threshold Auto
            KSJ_BLACKLEVELHRESHOLD_LO,   // Black Level Low Threshold
            KSJ_BLACKLEVELHRESHOLD_HI    // Black Level High Threshold
        };

        // 获得参数的设置范围
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetParamRange(int nChannel, KSJ_PARAM Param, ref int pnMinValue, ref int pnMaxValue);
        // 设置参数
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_SetParam(int nChannel, KSJ_PARAM Param, int nValue);
        // 获取参数当前值
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_GetParam(int nChannel, KSJ_PARAM Param, ref int pnValue);
        // Set Exposure Time (ms) for float format.( more precision )
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ExposureTimeSet(int nChannel, float fExpTimeMs);
        // Get Exposure Time (ms) for float format.
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_ExposureTimeGet(int nChannel, ref float pfExpTimeMs);

        public enum KSJ_ADDRESSMODE
        {
            KSJ_SKIPNONE = 0,
            KSJ_SKIP2,
            KSJ_SKIP3,
            KSJ_SKIP4,
            KSJ_SKIP8
        };

        // Get The Max Capture FOV( Field Of View ） supported by device
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureGetDefaultFieldOfView(int nChannel, ref int pnColStart, ref int nRowStart, ref int pnColSize, ref int pnRowSize, ref KSJ_ADDRESSMODE pColAddressMode, ref KSJ_ADDRESSMODE pRowAddressMode);
        // 设置采集视场大小
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureSetFieldOfView(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE ColAddressMode, KSJ_ADDRESSMODE RowAddressMode);
        // 获取采集视场的实际大小
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureGetFieldOfView(int nChannel, ref int pnColStart, ref int pnRowStart, ref int pnColSize, ref int pnRowSize, ref KSJ_ADDRESSMODE pColAddressMode, ref KSJ_ADDRESSMODE pRowAddressMode);
        // 得到采集图像的宽度和高度（单位：像素）
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureGetSize(int nChannel, ref int pnWidth, ref int pnHeight);
        // 得到采集图像的宽度和高度（单位：像素）及图像比特位数
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureGetSizeEx(int nChannel, ref int pnWidth, ref int pnHeight, ref int pnBitCount);
        // Capture Raw Data. ( Note: When Set 16bits, Buffer Should double )
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureRawData(int nChannel, byte[] pRgbData);
        // Capture 8, 24, 32 Format Image Data.( Note: When Set 16bits, Buffer Should double )
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureRgbData(int nChannel, byte[] pRgbData);
        // Capture 8, 24, 32 Format Image Data.( Note: When Set 16bits, Buffer Should double )
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_CaptureRgbDataEx(int nChannel, byte[] pRgbData, ref int pnWidth, ref int pnHeight, ref int pnBitCount);
        // 保存为Bmp文件
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HelperSaveToBmp(byte[] pData, int nWidth, int nHeight, int nBitCount, string pszFileName);
        // 保存为Jpg文件
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_HelperSaveToJpg(byte[] pData, int nWidth, int nHeight, int nBitCount, int nQulity, string pszFileName);

        // Get The Max Preview FOV( Field Of View ） supported by device
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetDefaultFieldOfView(int nChannel, ref int pnColStart, ref int pnRowStart, ref int pnColSize, ref int pnRowSize, ref KSJ_ADDRESSMODE pColAddressMode, ref KSJ_ADDRESSMODE pRowAddressMode);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewSetFieldOfView(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE ColAddressMode, KSJ_ADDRESSMODE RowAddressMode);
        // 获取采集视场的实际大小
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetFieldOfView(int nChannel, ref int pnColStart, ref int pnRowStart, ref int pnColSize, ref int pnRowSize, ref KSJ_ADDRESSMODE pColAddressMode, ref KSJ_ADDRESSMODE pRowAddressMode);
        // Preview Mode
        public enum KSJ_PREVIEWMODE
        {
            PM_RAWDATA,
            PM_RGBDATA
        };
        // Set Preview Mode
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewSetMode(int nChannel, KSJ_PREVIEWMODE PreviewMode);
        // Get Preview Mode
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetMode(int nChannel, ref KSJ_PREVIEWMODE PreviewMode);
        // Get Default Mode
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetDefaultMode(int nChannel, ref KSJ_PREVIEWMODE PreviewMode);
        public enum KSJ_PREVIEWSTATUS
        {
            PS_STOP,
            PS_START,
            PS_PAUSE
        };
        // Get Preview Status
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetStatus(int nChannel, ref KSJ_PREVIEWSTATUS pPreviewStatus);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetSize(int nChannel, ref int pnWidth, ref int pnHeight);
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetSizeEx(int nChannel, ref int pnWidth, ref int pnHeight, ref int pnBitCount);
        [DllImport("KSJApi.dll")]
		public static extern int KSJ_PreviewSetPos( int nChannel, IntPtr hWnd, int x, int y, int nWidth, int nHeight  );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetPos(int nChannel, ref int x, ref int y, ref int nWidth, ref int nHeight);
        [DllImport("KSJApi.dll")]
		public static extern int KSJ_PreviewStart( int nChannel, bool  bStart );
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewPause(int nChannel, bool bPause);
        // 获取预览帧速
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetFrameRate(int nChannel, ref float fFrameRate);
        // Get Paused Image Data when PS_PAUSE Status
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetPausedData(int nChannel, byte[] pData);
        // Get Paused Image Data when PS_PAUSE Status
        [DllImport("KSJApi.dll")]
        public static extern int KSJ_PreviewGetPausedData(int nChannel, byte[] pData, ref int pnWidth, ref int pnHeight, ref int pnBitCount);

        [DllImport("kernel32.dll")]
        public extern static short QueryPerformanceCounter(ref long x);
        [DllImport("kernel32.dll")]
        public extern static short QueryPerformanceFrequency(ref long x);
    }
}
