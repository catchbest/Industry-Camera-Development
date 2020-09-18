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
	enum KSJ_DEVICETYPE// 定义了所有KSJApi开发包所支持的相机类型
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
    /// @brief     设置Log日志是否输出及输出的保存目录
    /// @param     bEnable [in] 是否打开Log日志的输出功能
    /// @param     pszFolder [in] 输出的Log日志所保存的目录（可以为NULL或空字符串，如果为NULL或空字符串，则输出目录会自动创建，目录位置在KSJAPI.dll所在目录下创建KSJApiLog目录）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogSet(bool bEnable, const TCHAR *pszFolder);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获得日志相关信息
    /// @param     bEnable [out] 返回是否已经打开Log日志的输出功能
    /// @param     pszFolder[out] 返回输出的Log日志所保存的目录（可以为NULL或空字符串，表示不需获取此信息）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 可以在任意时刻调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogGet(bool *bEnable, TCHAR *pszFolder);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取KSJAPI库的版本号
    /// @param     pnMaj1[out] 返回主版本号1，一般做重要整体结构调整时会改变，增加1
    /// @param     pnMaj2[out] 返回主版本号2，一般做功能增加时会改变，增加1
	/// @param     pnMin1[out] 返回次版本号1，一般做重要整体结构调整时会改变，增加1
	/// @param     pnMin2：返回次版本号2，一般在小的改动时会改变，增加1
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetVersion(OUT int *pnMaj1, OUT int *pnMaj2, OUT int *pnMin1, OUT int *pnMin2);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获得错误的详细信息
    /// @param     nErrorNo [in] 传入错误代码，参考返回状态码（KSJCode.H）
    /// @param     pszErrorInfo[out] 传出错误代码信息
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetErrorInfo(IN int nErrorNo, OUT TCHAR pszErrorInfo[256]);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     初始化KSJApi动态库，该函数在整个进程运行期间只需要调用一次。
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 程序初始化时调用；相机在这个执行这个函数之前与电脑连接好；如果需要更新设备，请执行KSJ_UnInit/KSJ_Init，必须注意的是，重新执行后，物理相机对应的索引号可能会改变。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_Init(void);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     反初始化KSJApi动态库
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后，释放分配资源并关闭本进程中所有已经打开的设备
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_UnInit(void);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到设备数目
    /// @return    连接到主机上的KSJ设备数目
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetCount(void);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到设备信息（型号，序号，固件版本号）
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pDeviceType[out] 返回设备类型的地址指针（设备类型的定义请参考KSJ_DEVICETYPE）
	/// @param     pnSerials[out] 返回设备序号的地址指针
	/// @param     pwFirmwareVersion[out] 返回设备固件版本号的地址指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformation(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到设备信息（型号，序号，固件版本号）
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pDeviceType[out] 返回设备类型的地址指针（设备类型的定义请参考KSJ_DEVICETYPE）
	/// @param     pnSerials[out] 返回设备序号的地址指针
	/// @param     pwFirmwareVersion[out] 返回设备固件版本号的地址指针
	/// @param     pwFpgaVersion[out] 返回设备FPGA版本号的地址指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
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

	/// 相机参数类型
	enum KSJ_PARAM //相机参数的枚举类型
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
	/// @brief     获取对应参数设置的取值范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     Param [in] 指定的参数（参考KSJ_PARAM定义）
	/// @param     pnMinValue[out] 取得指定参数设置的最小值
	/// @param     pnMaxValue[out] 取得指定参数设置的最大值
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParamRange(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnMinValue, OUT int *pnMaxValue);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置相机参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     Param [in] 指定的参数（参考KSJ_PARAM定义）
    /// @param     nValue [in] 参数设置的值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetParam(IN int nIndex, IN KSJ_PARAM Param, IN  int nValue);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机参数
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     Param [in] 指定的参数（参考KSJ_PARAM定义）
	/// @param     pnValue[out] 参数值指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParam(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnValue);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置曝光时间
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fExposureTimeMs [in] 设置的曝光时间
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeSet(int nIndex, float fExposureTimeMs);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取曝光时间
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfExpTimeMs [out] 返回曝光时间的指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeGet(int nIndex, float *pfExpTimeMs);

	enum KSJ_ADDRESSMODE ///枚举类型凯视佳抽点模式定义（分为列抽点和行抽点）
	{ 
		KSJ_SKIPNONE = 0, ///正常输出所有视场设置范围内的像素点
		KSJ_SKIP2, ///当设置为列时，输出col0, col1, col4, col5, col8, col9等，    当设置为行时，输出row0, row1, row4, row5, row8, row9等
		KSJ_SKIP3, ///当设置为列时，输出col0, col1, col6, col7, col12, col13等，  当设置为行时，输出row0, row1, row6, row7, row12, row13等
		KSJ_SKIP4, ///当设置为列时，输出col0, col1, col8, col9, col16, col17等，  当设置为行时，输出row0, row1, row8, row9, row16, row17等
		KSJ_SKIP8  ///当设置为列时，输出col0, col1, col16, col17, col32, col33等，当设置为行时，输出row0, row1, row16, row17, row32, row33等
	};
	////////////////////////////////////////////Capture/////////////////////////////////
	///-----------------------------------------------------------------------------
    ///
    /// @brief     检测输入的视场参数与相机是否匹配
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [in] 要检测的水平像素起始位置
    /// @param     pnRowStart [in] 要检测的垂直行起始位置
	/// @param     pnColSize [in] 要检测的水平像素数
    /// @param     pnRowSize [in] 要检测的垂直行数
	/// @param     AmCol [in] 要检测的有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     AmRow [in] 要检测的有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @return    参考返回1表示匹配，否则不匹配
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CheckFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取设备的默认采集视场大小，也就是设备所支持的最大视场
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [out] 返回图像感光芯片采集时成像感光的有效区域起始列位置
    /// @param     pnRowStart[out] 返回图像感光芯片采集时成像感光的有效区域起始行位置
	/// @param     pnColSize [out] 返回图像感光芯片采集时成像感光的有效区域水平像素数
    /// @param     pnRowSize [out] 返回图像感光芯片采集时成像感光的有效区域垂直行数
	/// @param     pColAddressMode [out] 返回图像感光芯片采集列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     pRowAddressMode [out] 返回图像感光芯片采集行抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置采集视场大小
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [in] 采集时有效成像区域相对于默认最大成像区域的水平像素起始位置
    /// @param     pnRowStart [in] 采集时有效成像区域相对于最大成像区域的垂直行起始位置
	/// @param     pnColSize [in] 采集时有效成像区域的水平像素数
    /// @param     pnRowSize [in] 采集时有效成像区域的垂直行数
	/// @param     AmCol [in] 采集时针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     AmRow [in] 采集时针对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取采集视场的实际大小
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [out] 返回采集时有效成像区域相对于默认最大成像区域的水平像素起始位置
    /// @param     pnRowStart[out] 返回采集时有效成像区域相对于最大成像区域的垂直行起始位置
	/// @param     pnColSize [out] 返回采集时有效成像区域的水平像素数
    /// @param     pnRowSize [out] 返返回采集时有效成像区域的垂直行数
	/// @param     pColAddressMode [out] 返回采集时针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     pRowAddressMode [out] 返回采集时针对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取采集图像的宽度和高度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnWidth [out] 返回当前视场模式设置下的实际采集图像的像素宽度
    /// @param     pnHeight [out] 返回当前视场模式设置下的实际采集图像的像素高度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSize(int nIndex, int *pnWidth, int *pnHeight);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取采集图像的宽度和高度（单位：像素）及位图深度（8，24，32）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnWidth [out] 返回当前视场模式设置下的实际采集图像的像素宽度
    /// @param     pnHeight [out] 返回当前视场模式设置下的实际采集图像的像素高度
    /// @param     pnBitCount [out] 返回当前视场模式设置下的实际采集图像的位图深度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     采集一帧原始或黑白图像数据
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pRawData[out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawData(int nIndex, unsigned char *pRawData);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     采集一帧8位原始或灰度图像或24，32位彩色数据图像
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pRgbData[out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbData(int nIndex, unsigned char *pRgbData);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     采集一帧8位原始或灰度图像或24，32位彩色数据图像
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pRgbData[out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
	/// @param     pnWidth [out] 返回图像的宽度（像素）
    /// @param     pnHeight[out] 返回图像的高度（像素）
    /// @param     pnBitCount[out] 返回当前视场模式设置下的实际采集图像的位图深度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataEx(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     将图像数据保存为BMP文件
    /// @param     pData [in] 指向图像数据的首地址指针
	/// @param     nWidth [in] 图像的宽度（像素）
    /// @param     nHeight [in] 图像的高度（像素）
    /// @param     nBitCount [in] 8为灰度图像数据，24为24位彩色图像数据，其他值不支持
    /// @param     pszFileName [in] 保存文件的全路径名（路径必须存在）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, const TCHAR *pszFileName);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     将图像数据保存为JPG文件
    /// @param     pData [in] 指向图像数据的首地址指针
	/// @param     nWidth [in] 图像的宽度（像素）
    /// @param     nHeight [in] 图像的高度（像素）
    /// @param     nBitCount [in] 8为灰度图像数据，24为24位彩色图像数据，其他值不支持
    /// @param     pszFileName [in] 保存文件的全路径名（路径必须存在）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToJpg(unsigned char *pData, int nWidth, int nHeight, int nBitCount, int nQulity, const TCHAR *pszFileName);

	////////////////////////////////////////////Preview/////////////////////////////////
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取设备的默认预览视场大小，也就是设备所支持的最大视场
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [out] 返回图像感光芯片预览时成像感光的有效区域起始列位置
    /// @param     pnRowStart[out] 返回图像感光芯片预览时成像感光的有效区域起始行位置
	/// @param     pnColSize [out] 返回图像感光芯片预览时成像感光的有效区域水平像素数
    /// @param     pnRowSize[out] 返回图像感光芯片预览时成像感光的有效区域垂直行数
	/// @param     pColAddressMode [out] 返回图像感光芯片预览时成像感光的有效区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     pRowAddressMode[out] 返回图像感光芯片预览时成像感光的有效区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置预览视场大小
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [in] 预览时有效成像区域相对于默认最大成像区域的水平像素起始位置
    /// @param     pnRowStart [in] 预览时有效成像区域相对于最大成像区域的垂直行起始位置
	/// @param     pnColSize [in] 预览时有效成像区域的水平像素数
    /// @param     pnRowSize [in] 预览时有效成像区域的垂直行数
	/// @param     AmCol [in] 预览时针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     AmRow [in] 预览时针对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取预览视场的大小
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnColStart [out] 返回预览时有效成像区域相对于默认最大成像区域的水平像素起始位置
    /// @param     pnRowStart[out] 返回预览时有效成像区域相对于最大成像区域的垂直行起始位置
	/// @param     pnColSize [out] 返回预览时有效成像区域的水平像素数
    /// @param     pnRowSize[out] 返返回预览时有效成像区域的垂直行数
	/// @param     pColAddressMode [out] 返回预览时针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @param     pRowAddressMode[out] 返回预览时针对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到预览图像的宽度和高度
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnWidth [out] 返回当前视场模式设置下的实际预览图像的像素宽度
    /// @param     pnHeight[out] 返回当前视场模式设置下的实际预览图像的像素高度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSize(int nIndex, int *pnWidth, int *pnHeight);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获得日志相关信息
    /// 参数：
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnWidth [out] 返回图像的宽度（像素）
    /// @param     pnHeight[out] 返回图像的高度（像素）
    /// @param     pnBitCount[out] 返回当前视场模式设置下的实际预览图像的位图深度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置视频图像在窗口上的显示位置
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     hWnd [in] 显示窗口的句柄
    /// @param     x [in] 显示位置相对窗口左上角水平偏移（像素）
	/// @param     y [in] 显示位置相对窗口左上角垂直偏移（像素）
	/// @param     nWidth [in] 显示的宽度，这个宽度如果大于预览图像的宽度，图像会水平放大，反之缩小
	/// @param     nHeight [in] 显示图像的高度，这个宽度如果大于预览图像的高度，图像会垂直放大，反之缩小
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetPos(int nIndex, HWND hWnd, int x, int y, int nWidth, int nHeight);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到当前视频预览图像的显示位置
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     px [out] 返回显示位置相对窗口左上角水平偏移（像素）
	/// @param     py [out] 返回显示位置相对窗口左上角垂直偏移（像素）
	/// @param     pnWidth [out] 返回显示的宽度
	/// @param     pnHeight [out] 返回显示图像的高度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPos(int nIndex, int *px, int *py, int *pnWidth, int *pnHeight);
	/// Preview Mode
	enum KSJ_PREVIEWMODE// 枚举类型视频预览模式
	{
		PM_RAWDATA, ///预览原始数据，对于黑白设备，必须设置为PM_RAWDATA
		PM_RGBDATA  ///预览24位或32位彩色数据（由Bayer模式决定）
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置视频流为原始采集数据还是RGB 24位或32位彩色数据格式，一般用户无需设置
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     PreviewMode [in] 设置的预览模式（参考KSJ_PREVIEWMODE定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetMode(int nIndex, KSJ_PREVIEWMODE PreviewMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机的当前预览模式
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pPreviewMode   [out] 获取当前的预览模式（参考KSJ_PREVIEWMODE定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取设备默认的预览模式
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pPreviewMode   [out] 获取相机默认的预览模式（参考KSJ_PREVIEWMODE定义）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);
   
    ///-----------------------------------------------------------------------------
    ///
    /// @brief     启动视频流，用户必须先通过KSJ_PreviewSetPos来设置视频显示的窗口及位置创建一个预览窗口，否则将看不到预览视频流
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bStart   [in] true 打开视频流，显示在窗口指定位置（参考KSJ_PreviewSetPos函数），false 关闭视频流 
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStart(int nIndex, bool bStart);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     暂停或继续视频流
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bPause   [in] true 暂停视频流，false 继续视频流 
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewPause(int nIndex, bool bPause);
	
	enum    KSJ_PREVIEWSTATUS ///预览视频流的状态
	{
		PS_STOP, ///视频流停止
		PS_START,//视频流运行
		PS_PAUSE ///视频流暂停
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取视频预览的状态
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pPreviewStatus [out] 返回预览状态
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatus(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取帧速
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fFrameRate [out] 返回当前视频流的帧速
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRate(int nIndex, float *fFrameRate);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取暂停时的那一帧图像数据
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pData [out] 由用户提供的数据区域，函数调用返回后，此区域会被填充暂停时的图像数据
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedData(int nIndex, unsigned char *pData);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取暂停时的那一帧图像数据
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pData [out] 由用户提供的数据区域，函数调用返回后，此区域会被填充暂停时的图像数据
	/// @param     pnWidth [out] 返回图像的宽度（像素）
    /// @param     pnHeight[out] 返回图像的高度（像素）
    /// @param     pnBitCount[out] 返回图像的每个像素位数（8，24或32）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedDataEx(int nIndex, unsigned char *pData, int *pnWidth, int *pnHeight, int *pnBitCount);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     用并行模式启动视频流，用户必须先通过KSJ_PreviewSetPos来设置视频显示的窗口及位置创建一个预览窗口，否则将看不到预览视频流
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bPause [in] true 暂停视频流，false 继续视频流 
	/// @param     bParallel [in] true 用并行模式打开视频流，false 不使用并行模式 
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStartEx(int nIndex, bool bStart, bool bParallel );

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取视频预览和并行的状态
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pPreviewStatus [out] 返回预览状态 
	/// @param     pbParallel [out] 返回并行状态
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatusEx(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus, bool *pbParallel);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取采集和显示的帧速
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fFrameRateCapture [out] 返回当前采集的帧速 
	/// @param     fFrameRateShow [out] 返回当前视频流的帧速
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRateEx(int nIndex, float *fFrameRateCapture, float *fFrameRateShow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取预览采集和显示的图像数
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnCaptureFrameCount [out] 返回当前预览一共采集的图像数 
	/// @param     pnShowFrameCount [out] 返回当前预览一共显示的图像图像数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetPreviewFrameCount(int nIndex, int *pnCaptureFrameCount, int *pnShowFrameCount);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置预览图像缓存的数量
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nCount [in] 设置预览缓存的数量 
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetBufferCount(int nIndex, int nCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取预览图像缓存的数量
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnCount [out] 返回预览缓存的数量 
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetBufferCount(int nIndex, int* pnCount);

	enum KSJ_USBSPEED//相机USB连接状态
	{
		USB_NOT_CONNECTED = 0x00,        ///USB通信失败
		USB_FULL_SPEED,                  ///全速USB
		USB_HIGH_SPEED,                  ///高速USB
		USB_SUPER_SPEED                  ///USB3.0
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取USB连接状态
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pUSBSpeed [out] 返回当前USB连接状态 
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetUsbState(int nIndex, KSJ_USBSPEED* pUSBSpeed);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     重启相机，相机将会重新启动，重新和主机建立USB连接
    /// 参数：
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RebootDevice(int nIndex);


#ifdef __cplusplus
}
#endif

#endif
