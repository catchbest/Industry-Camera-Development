#ifndef __KSJ_API_FUNCTION_H__
#define __KSJ_API_FUNCTION_H__

// #pragma message("Include KSJApiFunction.h") 


#ifdef KSJAPI_EXPORTS
    #define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
	#define KSJ_API
#else
    #define KSJ_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"{
#endif


enum KSJ_FUNCTION 
{
	KSJ_PROPERTY_MONO_DEVICE,                /// 是否为黑白相机，     1 - 是；     0 - 不是
	KSJ_PROPERTY_ADC_RESOLUTION,             /// 相机ADC的转换比特位数，8，10，12，与KSJ_GetADCResolution功能相同
	KSJ_SUPPORT_MIRROR,                      /// 是否支持硬件水平翻转
	KSJ_SUPPORT_FLIP,                        /// 是否支持硬件垂直翻转
	KSJ_SUPPORT_SKIP2,                       /// 是否支持SKIP2
	KSJ_SUPPORT_SKIP3,
	KSJ_SUPPORT_SKIP4,
	KSJ_SUPPORT_SKIP8,
	KSJ_SUPPORT_BINNING,
	KSJ_SUPPORT_AGC,
	KSJ_SUPPORT_AEC,

	KSJ_SUPPORT_TRIGGER_MODE_EXTERNAL,       /// 是否支持外触发
	KSJ_SUPPORT_TRIGGER_MODE_SOFTWARE,       /// 是否支持软件触发
	KSJ_SUPPORT_TRIGGER_MODE_FIXED_FRAMERATE,// 是否支持固件帧率触发
	KSJ_SUPPORT_FIXED_FRAMERATE_SW,	         /// 是否支持通过软件设置sensor固定帧率。0 - 不支持，1 - 支持
	KSJ_SUPPORT_FIXED_FRAMERATE_HW,          /// 是否支持通过硬件设置FPGA固定触发频率
	KSJ_SUPPORT_LUT_ENABLE,                  /// 是否支持硬件查找表使能， 0 - 不支持； 1 - 支持
	KSJ_SUPPORT_TRIGGER_METHOD_NEGEDGE,      /// 是否支持下降沿触发
	KSJ_SUPPORT_TRIGGER_METHOD_POSEDGE,
	KSJ_SUPPORT_TRIGGER_METHOD_HIGH_LEVEL,
	KSJ_SUPPORT_TRIGGER_METHOD_LOW_LEVEL,
	KSJ_SUPPORT_EMPTY_FRAMEBUFFER,      /// 是否支持清空帧存。0 - 不支持； 1 - 支持
	KSJ_SUPPORT_SENSITIVITY_MODE,       /// 是否支持截取8位获取不同的灵敏度
	KSJ_SUPPORT_16BITS,			        /// 是否支持双字节传输，一个像素用2个字节，数据读取加倍。0 - 不支持，1 - 支持
	KSJ_SUPPORT_BAD_PIXEL_CORRECTION,   /// 是否支持坏点校正
	KSJ_SUPPORT_LUT_DOWNLOAD,           /// 是否支持LUT查找表下载到FPGA
	KSJ_SUPPORT_HWB_PRESETTINGS,        /// 硬件白平衡是否支持预设值
	KSJ_SUPPORT_HWB_PRESETTINGS_NUM,    /// 硬件白平衡预设值有几组
	KSJ_SUPPORT_HWB_AUTO_ONCE,          /// 硬件是否支持单次白平衡操作
	KSJ_SUPPORT_HWB_AUTO_CONTINUOUS,    /// 硬件是否支持连续白平衡操作
	KSJ_SUPPORT_HCCM_PRESETTINGS,       /// 硬件CCM是否支持预设值
	KSJ_SUPPORT_HCCM_PRESETTINGS_NUM,   /// 硬件CCM有几组预设值
	KSJ_SUPPORT_GAMMA_LUT_ENABLE,       /// 硬件是否支持GAMMA LUT查找表使能
	KSJ_SUPPORT_GAMMA_LUT_DOWNLOAD,     /// 是否支持Gamma LUT下载到FPGA，如果支持此功能，就可以使能操作
	KSJ_SUPPORT_TRIGGER_DELAY,		    /// 是否支持对外触发信号的延时的设置。0 - 不支持，1 - 支持
	KSJ_SUPPORT_MULTI_FRAMES,	        /// 是否支持一次读取多帧数据进行垂直拼图。0 - 不支持，1 - 支持
	KSJ_SUPPORT_HWB_MATRIX,             /// 硬件是否支持设置白平衡矩阵
	KSJ_SUPPORT_HCCM_MATRIX,            /// 硬件是否支持设置CCM矩阵
	KSJ_SUPPORT_GPIO_NORMAL,            /// 是否支持外触发输入作为普通输入IO可以进行读取并且闪光灯输出作为普通输出IO进行进行设置
	KSJ_SUPPORT_IO_FILTER,              /// 对输入源进行滤波
	KSJ_SUPPORT_WATERMAK,               /// 是否支持水印功能（时间戳模式，外触发区分，外触发加密）

	KSJ_SUPPORT_GET_FRAME_BUFFER_STATE, /// 固件是否支持获取帧存状态
	KSJ_SUPPORT_RESET_DEVICE,           /// 是否支持复位设备，   0 - 不支持； 1 - 支持
	KSJ_SUPPORT_SEND_PKT_END,           /// 是否支持终止一帧传输
	KSJ_SUPPORT_RECONNECT,              /// 设备是否支持重新连接
	KSJ_SUPPORT_FAST_UPDATE,            /// 是否支持快速升级
	KSJ_SUPPORT_WORKINGMODE_PROGRAM,    /// 是否支持固化工作模式
	KSJ_SUPPORT_SERIALSDESC_PROGRAM,    /// 是否支持固化设备序号描述符
	KSJ_SUPPORT_LUT_PROGRAM,            /// 是否支持固化LUT查找表数据
	KSJ_SUPPORT_GAMMA_LUT_PROGRAM,      /// 是否支持固化Gamma LUT到相机中
	KSJ_SUPPORT_WORKINGMODEEX_PROGRAM,  /// 是否支持固化超级工作模式
	KSJ_SUPPORT_COLORMODE_PROGRAM,      /// 是否支持固化色彩模式
	KSJ_SUPPORT_COLORMATRIX_PROGRAM,    /// 是否支持将HWB,HCCM校正矩阵固化

	KSJ_SUPPORT_SNAP_BUTTON,            /// 是否支持KSJ_SnapButtonStatus, 0 - 不支持，1 - 支持(可能根据用户设置)
	KSJ_SUPPORT_IO_NUM,                 /// 支持几个IO的设置
	KSJ_SUPPORT_TRIGGER_MODE_HIGHLOW_FIXEDFRAMERATE,// 是否支持固件帧率触发（高低电平有效）
	KSJ_SUPPORT_STREAM_MODE,            /// 是否支持流模式
	KSJ_SUPPORT_STARTEND_CAPTURE,       /// 是否支持开始结束采图

};

///-----------------------------------------------------------------------------
///
/// @brief     KSJ_QueryFunction
/// @brief     取得相机的功能信息
/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
/// @param     Function [in] 需要查询的相机功能枚举，请参考KSJ_FUNCTION的定义
/// @param     pInfo [out] 返回当前相机的功能信息（0表示不支持该功能，非0表示支持该功能）
/// @return    参考返回状态码（KSJCode.H）
/// @attention 调用KSJ_Init函数初始化后调用
///
///-----------------------------------------------------------------------------
KSJ_API  int __stdcall KSJ_QueryFunction(int nIndex, KSJ_FUNCTION Function, int *pInfo); 

#ifdef __cplusplus
}
#endif

#endif