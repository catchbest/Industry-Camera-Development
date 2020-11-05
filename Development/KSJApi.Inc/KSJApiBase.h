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
	
	/// 定义了所有KSJApi开发包所支持的相机类型
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
	/// @brief     初始化KSJApi动态库，该函数在整个进程运行期间只需要调用一次。
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 一般在程序初始化时调用
	///          \li 相机在这个执行这个函数之前与电脑连接好
	///          \li 如果需要更新设备，请执行反初始化KSJ_UnInit()后再执行KSJ_Init()，需要特别注意的是：重新这样操作以后，具体物理相机所对应的索引号可能会改变。
	///          \li 如果需要操作指定的相机，需要给物理相机分配不同的序号Serials（KSJ_SetSerials()），根据不同的序号关联到当前的索引号
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_Init(void);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_UnInit
	/// @brief     反初始化KSJApi动态库
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后，释放分配资源并关闭本进程中所有已经打开的设备
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_UnInit(void);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_DeviceGetCount
	/// @brief     得到设备数目
	/// @return    连接到主机上的KSJ设备数目
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetCount(void);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_DeviceGetInformation
	/// @brief     得到设备信息（型号，序号，固件版本号）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pusDeviceType[out] 返回设备类型的地址指针
	/// @param     pnSerials[out] 返回设备序号的地址指针，通过设个序号可以区别不同的物理相机，这个序号可以通过KSJ_SetSerials()修改
	/// @param     pusFirmwareVersion[out] 返回设备固件版本号的地址指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformation(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_DeviceGetInformationEx
	/// @brief     得到设备信息（型号，序号，固件版本号）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pusDeviceType[out] 返回设备类型的地址指针
	/// @param     pnSerials[out] 返回设备序号的地址指针，通过设个序号可以区别不同的物理相机，这个序号可以通过KSJ_SetSerials()修改
	/// @param     pusFirmwareVersion[out] 返回设备固件版本号的地址指针
	/// @param     pusFpgaVersion[out] 返回设备FPGA版本号的地址指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetInformationEx(IN int nIndex, OUT KSJ_DEVICETYPE *pDeviceType, OUT int *pnSerials, OUT unsigned short *pwFirmwareVersion, OUT unsigned short *pwFpgaVersion);

	/// 相机参数类型
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
	/// @brief     获取指定参数的取值范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     Param [in] 指定的参数（参考KSJ_PARAM定义）
	/// @param     pnMinValue[out] 取得指定参数的最小值
	/// @param     pnMaxValue[out] 取得指定参数的最大值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParamRange(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnMinValue, OUT int *pnMaxValue);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetParam
	/// @brief     设置相机参数值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     Param [in] 指定的参数（参考KSJ_PARAM定义）
	/// @param     nValue [in] 参数设置的值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetParam(IN int nIndex, IN KSJ_PARAM Param, IN  int nValue);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetParam
	/// @brief     获取相机参数值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     Param [in] 指定的参数（参考KSJ_PARAM定义）
	/// @param     pnValue[out] 参数值的地址指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetParam(IN int nIndex, IN KSJ_PARAM Param, OUT int *pnValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ExposureTimeSet
	/// @brief     设置曝光时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fExposureTimeMs [in] 设置的曝光时间，单位：毫秒
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeSet(int nIndex, float fExposureTimeMs);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ExposureTimeGet
	/// @brief     获取曝光时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfExpTimeMs [out] 返回曝光时间的指针，单位：毫秒
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ExposureTimeGet(int nIndex, float *pfExpTimeMs);

	///< 枚举类型凯视佳抽点模式定义（分为列抽点和行抽点）
	enum KSJ_ADDRESSMODE
	{ 
		KSJ_SKIPNONE = 0, ///< 正常输出所有视场设置范围内的像素点
		KSJ_SKIP2,        ///< 当设置为列时，输出col0, col2, col4, col6, col8, col10等，   当设置为行时，输出row0, row2, row4, row6, row8, row10等
		KSJ_SKIP3,        ///< 当设置为列时，输出col0, col3, col6, col9, col12, col15等，  当设置为行时，输出row0, row3, row6, row9, row12, row15等
		KSJ_SKIP4,        ///< 当设置为列时，输出col0, col4, col8, col12, col16, col20等， 当设置为行时，输出row0, row4, row8, row12, row16, row20等
		KSJ_SKIP8         ///< 当设置为列时，输出col0, col8, col16, col24, col32, col40等，当设置为行时，输出row0, row8, row16, row24, row32, row40等
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetDefaultFieldOfView
	/// @brief     获取设备的默认采集视场大小，也就是设备所支持的最大视场
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [out] 返回图像感光芯片采集时成像感光的有效区域起始列位置
	/// @param     pnRowStart[out] 返回图像感光芯片采集时成像感光的有效区域起始行位置
	/// @param     pnColSize [out] 返回图像感光芯片采集时成像感光的有效区域水平像素数
	/// @param     pnRowSize [out] 返回图像感光芯片采集时成像感光的有效区域垂直行数
	/// @param     pAmCol [out] 返回图像感光芯片采集列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pAmRow [out] 返回图像感光芯片采集行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureSetFieldOfView
	/// @brief     设置采集视场大小
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [in] 采集时有效成像区域相对于默认最大成像区域的水平像素起始位置
	/// @param     pnRowStart [in] 采集时有效成像区域相对于最大成像区域的垂直行起始位置
	/// @param     pnColSize [in] 采集时有效成像区域的水平像素数
	/// @param     pnRowSize [in] 采集时有效成像区域的垂直行数
	/// @param     ColAddressMode [in] 采集时针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     RowAddressMode [in] 采集时针对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 如果设置的参数不符合相机的FOV要求（例如有一些相机要求Start位置必须满足2的倍数，Size必须满足4的倍数，不能设置某个抽点模式），函数内部将会自动使用最接近的参数进行设置，并返回RET_SUCCESS(0)
	///           \li 所以设置以后，需要重新获取当前实际生效的参数。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetFieldOfView
	/// @brief     获取采集视场的实际大小
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [out] 返回采集时有效成像区域相对于默认最大成像区域的水平像素起始位置
	/// @param     pnRowStart[out] 返回采集时有效成像区域相对于最大成像区域的垂直行起始位置
	/// @param     pnColSize [out] 返回采集时有效成像区域的水平像素数
	/// @param     pnRowSize [out] 返返回采集时有效成像区域的垂直行数
	/// @param     pAmCol [out] 返回采集时针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pAmRow [out] 返回采集时针对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetSize
	/// @brief     获取采集图像的宽度和高度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnWidth [out] 返回当前视场模式设置下的实际采集图像的像素宽度
	/// @param     pnHeight [out] 返回当前视场模式设置下的实际采集图像的像素高度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 实际采集图像的像素宽度与采集视场行大小、抽点模式有关
	///           \li 实际采集图像的像素高度与采集视场列大小、抽点模式、多帧采集数有关
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSize(int nIndex, int *pnWidth, int *pnHeight);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetSizeEx
	/// @brief     获取采集图像的宽度和高度（单位：像素）及位图深度（8，24，32）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnWidth [out] 返回当前视场模式设置下的实际采集图像的像素宽度
	/// @param     pnHeight [out] 返回当前视场模式设置下的实际采集图像的像素高度
	/// @param     pnBitCount [out] 返回当前视场模式设置下的实际采集图像的位图深度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 实际采集图像的像素宽度与采集视场行大小、抽点模式有关
	///           \li 实际采集图像的像素高度与采集视场列大小、抽点模式、多帧采集数有关
	///           \li 实际采集图像的位图深度与当前相机类型以及Bayer模式有关
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureRawData
	/// @brief     采集一帧原始或黑白图像数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRawData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize或KSJ_CaptureGetSizeEx函数获得
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li pRawData必须使用者提前分配，分配的大小应为KSJ_CaptureGetSize得到的图像宽度*图像高度，如果是16bit数，应该是再乘以2。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawData(int nIndex, unsigned char *pRawData);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureRgbData
	/// @brief     采集一帧8位原始或灰度图像或24，32位彩色数据图像
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li pRgbData必须使用者提前分配，分配的大小应为KSJ_CaptureGetSizeEx得到的图像宽度*图像高度*位图深度/8。
	///           \li 如果是黑白相机，该函数取得的图像会原始灰度图，和KSJ_CaptureRawData得到的图像数据一样。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbData(int nIndex, unsigned char *pRgbData);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureRgbDataEx
	/// @brief     采集一帧8位原始或灰度图像或24，32位彩色数据图像
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
	/// @param     pnWidth [out] 返回图像的宽度（像素）
	/// @param     pnHeight [out] 返回图像的高度（像素）
	/// @param     pnBitCount [out] 返回当前视场模式设置下的实际采集图像的位图深度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataEx(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetDefaultFieldOfView
	/// @brief     获取设备的默认预览视场大小，也就是设备所支持的最大视场
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [out] 返回图像感光芯片采集时成像感光的有效区域起始列位置
	/// @param     pnRowStart[out] 返回图像感光芯片采集时成像感光的有效区域起始行位置
	/// @param     pnColSize [out] 返回图像感光芯片采集时成像感光的有效区域水平像素数
	/// @param     pnRowSize [out] 返回图像感光芯片采集时成像感光的有效区域垂直行数
	/// @param     pAmCol [out] 返回图像感光芯片采集列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pAmRow [out] 返回图像感光芯片采集行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewSetFieldOfView
	/// @brief     设置预览视场大小
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [in] 预览时有效成像区域相对于默认最大成像区域的水平像素起始位置
	/// @param     pnRowStart [in] 预览时有效成像区域相对于最大成像区域的垂直行起始位置
	/// @param     pnColSize [in] 预览时有效成像区域的水平像素数
	/// @param     pnRowSize [in] 预览时有效成像区域的垂直行数
	/// @param     ColAddressMode [in] 预览时针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     RowAddressMode [in] 预览时针对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 如果设置的参数不符合相机的FOV要求（例如有一些相机要求Start位置必须满足2的倍数，Size必须满足4的倍数，不能设置某个抽点模式），函数内部将会自动使用最接近的参数进行设置，并返回RET_SUCCESS(0)
	///           \li 所以设置以后，需要重新获取当前实际生效的参数。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetFieldOfView
	/// @brief     获取预览视场的实际大小
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnColStart [out] 返回采集时有效成像区域相对于默认最大成像区域的水平像素起始位置
	/// @param     pnRowStart[out] 返回采集时有效成像区域相对于最大成像区域的垂直行起始位置
	/// @param     pnColSize [out] 返回采集时有效成像区域的水平像素数
	/// @param     pnRowSize [out] 返返回采集时有效成像区域的垂直行数
	/// @param     pAmCol [out] 返回采集时针对有效成像区域列抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @param     pAmRow [out] 返回采集时针对有效成像区域行抽点模式（请参考KSJ_ADDRESSMODE的定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetSize
	/// @brief     获取预览图像的宽度和高度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnWidth [out] 返回当前视场模式设置下的实际预览图像的像素宽度
	/// @param     pnHeight [out] 返回当前视场模式设置下的实际预览图像的像素高度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 实际预览图像的像素宽度与采集视场行大小、抽点模式有关
	///           \li 实际预览图像的像素高度与采集视场列大小、抽点模式、多帧采集数有关
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSize(int nIndex, int *pnWidth, int *pnHeight);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetSizeEx
	/// @brief     获取预览图像的宽度和高度（单位：像素）及位图深度（8，24，32）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnWidth [out] 返回当前视场模式设置下的实际预览图像的像素宽度
	/// @param     pnHeight [out] 返回当前视场模式设置下的实际预览图像的像素高度
	/// @param     pnBitCount [out] 返回当前视场模式设置下的实际预览图像的位图深度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 实际预览图像的像素宽度与采集视场行大小、抽点模式有关
	///           \li 实际预览图像的像素高度与采集视场列大小、抽点模式、多帧采集数有关
	///           \li 实际预览图像的位图深度与当前相机类型以及Bayer模式有关
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetSizeEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount);
	
	///-----------------------------------------------------------------------------
    ///
	/// @brief     KSJ_PreviewSetPos
    /// @brief     设置视频图像在窗口上的显示位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     hWnd [in] 显示窗口的句柄
    /// @param     x [in] 显示位置相对窗口左上角水平偏移（像素）
	/// @param     y [in] 显示位置相对窗口左上角垂直偏移（像素）
	/// @param     nWidth [in] 显示的宽度，这个宽度如果大于预览图像的宽度，图像会水平放大，反之缩小
	/// @param     nHeight [in] 显示图像的高度，这个宽度如果大于预览图像的高度，图像会垂直放大，反之缩小
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetPos(int nIndex, HWND hWnd, int x, int y, int nWidth, int nHeight);
	
	///-----------------------------------------------------------------------------
    ///
	/// @brief     KSJ_PreviewGetPos
    /// @brief     得到当前视频预览图像的显示位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     px [out] 返回显示位置相对窗口左上角水平偏移（像素）
	/// @param     py [out] 返回显示位置相对窗口左上角垂直偏移（像素）
	/// @param     pnWidth [out] 返回显示的宽度
	/// @param     pnHeight [out] 返回显示图像的高度
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPos(int nIndex, int *px, int *py, int *pnWidth, int *pnHeight);
   
    ///-----------------------------------------------------------------------------
    ///
	/// @brief     KSJ_PreviewStart
    /// @brief     启动视频流，用户必须先通过KSJ_PreviewSetPos来设置视频显示的窗口及位置创建一个预览窗口，否则将看不到预览视频流
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bStart [in] true 打开视频流，显示在窗口指定位置（参考KSJ_PreviewSetPos函数），false 关闭视频流 
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStart(int nIndex, bool bStart);
	
	/// 预览视频流的状态
	enum KSJ_PREVIEWSTATUS 
	{
		PS_STOP,   ///< 视频流停止
		PS_START,  ///< 视频流运行
		PS_PAUSE   ///< 视频流暂停
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_PreviewGetStatus
    /// @brief     获取视频预览的状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pPreviewStatus [out] 返回预览状态
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatus(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_PreviewStartEx
    /// @brief     用并行模式启动视频流，用户必须先通过KSJ_PreviewSetPos来设置视频显示的窗口及位置创建一个预览窗口，否则将看不到预览视频流
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bStart [in] true 开启视频流，false 关闭视频流 
	/// @param     bParallel [in] true 用并行模式打开视频流，false 使用串行模式 
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewStartEx(int nIndex, bool bStart, bool bParallel );

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_PreviewGetStatusEx
    /// @brief     获取视频预览和并行的状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pPreviewStatus [out] 返回预览状态 
	/// @param     pbParallel [out] 返回并行状态
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetStatusEx(int nIndex, KSJ_PREVIEWSTATUS *pPreviewStatus, bool *pbParallel);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_PreviewGetFrameRateEx
    /// @brief     预览时，获取采集和显示的帧速
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fFrameRateCapture [out] 返回当前采集的帧速 
	/// @param     fFrameRateShow [out] 返回当前视频流的帧速
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRateEx(int nIndex, float *fFrameRateCapture, float *fFrameRateShow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_GetPreviewFrameCount
    /// @brief     获取预览采集和显示的图像数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnCaptureFrameCount [out] 返回当前预览一共采集的图像数 
	/// @param     pnShowFrameCount [out] 返回当前预览一共显示的图像图像数
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetPreviewFrameCount(int nIndex, int *pnCaptureFrameCount, int *pnShowFrameCount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SendPktEnd
	/// @brief     主动结束当前传输请求
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///           \li 在使用KSJ_CaptureRgbData等函数采集图像时，如果一直没有图像传回（比如外触发模式下，当前没有外触发信号），需要在超时时间内结束采集，可以执行该操作，Capture函数立即返回。
	///           \li Capture函数立即返回有可能是零帧（RET_ZEROFRAME）或者半帧（RET_INVALIDFRAME，数据传到一半被中断）
	///           \li 如果当前没有执行采集操作，执行了该操作（一次或者多次），那么下一次将会采集到一个零帧（RET_ZEROFRAME）
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SendPktEnd(int nIndex);

	///-----------------------------------------------------------------------------
    ///
	/// @brief     KSJ_RebootDevice
    /// @brief     重启相机，相机将会重新启动，重新和主机建立USB连接
    /// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RebootDevice(int nIndex);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LogSet
	/// @brief     设置Log日志是否输出及输出的保存目录
	/// @param     bEnable [in] 是否打开Log日志的输出功能
	/// @param     pszFolder [in] 输出的Log日志所保存的目录；可以为NULL或空字符串。
	///				\li 如果为NULL或空字符串，则Log输出目录会自动创建，目录位置在KSJAPI库所在目录下创建名称为KSJApiLog的目录
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogSet(bool bEnable, const TCHAR *pszFolder);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LogGet
	/// @brief     获得日志相关信息
	/// @param     bEnable [out] 返回是否已经打开Log日志的输出功能
	/// @param     pszFolder[out] 返回输出的Log日志所保存的目录（可以为NULL，表示不需获取此信息）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 可以在任意时刻调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LogGet(bool *bEnable, TCHAR *pszFolder);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetVersion
	/// @brief     获取KSJAPI库的版本号
	/// @param     pnMaj1[out] 返回主版本号1，一般做重要整体结构调整时会改变，增加1；主版本号1不同的API库不兼容
	/// @param     pnMaj2[out] 返回主版本号2，一般做主要功能增加时会改变，增加1
	/// @param     pnMin1[out] 返回次版本号1，一般做重要整体结构调整或者修改主要逻辑时会改变，增加1
	/// @param     pnMin2[out] 返回次版本号2，一般在小的改动、修改Bug时会改变，增加1
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetVersion(OUT int *pnMaj1, OUT int *pnMaj2, OUT int *pnMin1, OUT int *pnMin2);


	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetDriveVersion
	/// @brief     获取KSJ设备驱动的版本号
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnMaj1[out] 返回主版本号1
	/// @param     pnMaj2[out] 返回主版本号2
	/// @param     pnMin1[out] 返回次版本号1
	/// @param     pnMin2[out] 返回次版本号2
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetDriveVersion(int nIndex, int *pnMaj1, int *pnMaj2, int *pnMin1, int *pnMin2);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HelperSaveToBmp
	/// @brief     将图像数据保存为BMP文件
	/// @param     pData [in] 指向图像数据的首地址指针
	/// @param     nWidth [in] 图像的宽度（像素）
	/// @param     nHeight [in] 图像的高度（像素）
	/// @param     nBitCount [in] 8为灰度图像数据，24为24位彩色图像数据，其他值不支持
	/// @param     pszFileName [in] 保存文件的全路径名（所在路径目录必须存在）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, const TCHAR *pszFileName);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HelperSaveToJpg
	/// @brief     将图像数据保存为JPG文件
	/// @param     pData [in] 指向图像数据的首地址指针
	/// @param     nWidth [in] 图像的宽度（像素）
	/// @param     nHeight [in] 图像的高度（像素）
	/// @param     nBitCount [in] 8为灰度图像数据，24为24位彩色图像数据，其他值不支持
	/// @param     pszFileName [in] 保存文件的全路径名（所在路径目录必须存在）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToJpg(unsigned char *pData, int nWidth, int nHeight, int nBitCount, int nQulity, const TCHAR *pszFileName);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_OpenSettingPage
	/// @brief     打开相机设置界面
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     hWndParent [in] 弹出设置对话框的主窗口句柄
	/// @param     nLeft [in] 弹出设置对话框相对主窗口的左偏移
	/// @param     nTop [in] 弹出设置对话框相对主窗口的右偏移
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_OpenSettingPage(IN int nIndex, IN void *hWndParent, int nLeft, int nTop);

#ifdef __cplusplus
}
#endif

#endif
