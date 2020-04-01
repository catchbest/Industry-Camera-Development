#ifndef __KSJ_API_OBSOLETE_H__
#define __KSJ_API_OBSOLETE_H__

// #pragma message("Include KSJApiObsolete.h") 


#ifdef KSJAPI_EXPORTS
    #define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
	#define KSJ_API
#else
    #define KSJ_API __declspec(dllimport)
#endif

// 为了保持对老客户调用的兼容性，这个文件中的函数是以前版本定义的，但在新版本中仍然保留，但我们已经不推荐使用的函数。
// 其中有一些函数可以由其他函数替代，也有些函数已经不再支持。
#ifdef __cplusplus
extern "C"{
#endif

	// 打开或关闭Gamma校正，即影响预览又影响采集
	KSJ_API  int __stdcall KSJ_GammaOn(int nChannel, bool bOn);    // Not Support Now.


// 设置固定帧速(通过设置sensor寄存器,使sensor输出固定帧率)，只有MUC36C/M(MGYY)和MU3E130C/M(CGYY)支持
// V4.0.86.12版本开始，bEnable参数无效，通过用户设置KSJ_TRIGGER_FIXFRAMERATE模式来决定是否使能。
KSJ_API  int __stdcall KSJ_SetFixedFrameRate(int nChannel, bool bEnable, float fFrameRate);
KSJ_API  int __stdcall KSJ_GetFixedFrameRate(int nChannel, bool *pbEnable, float *pfFrameRate);

// 闪光灯信号输出到实际相机输出的延时设置（暂不支持）
KSJ_API  int __stdcall KSJ_StrobeDelaySet(int nChannel, unsigned short wDelay);
KSJ_API  int __stdcall KSJ_StrobeDelayGet(int nChannel, unsigned short *pwDelay);
KSJ_API  int __stdcall KSJ_StrobeDelayGetRange(int nChannel, unsigned short *wMin, unsigned short *wMax);


// 设置图像传感器的工作方式（暂不支持）
enum KSJ_SENSORMODE { KSJ_SM_TRIGGER_MODE, KSJ_SM_FREERUN_MODE, KSJ_SM_GRR_MODE };
KSJ_API  int __stdcall KSJ_SensorModeSet(int nChannel, KSJ_SENSORMODE SensorMode);
KSJ_API  int __stdcall KSJ_SensorModeGet(int nChannel, KSJ_SENSORMODE *SensorMode);

///////////////////////////////////////////////Color Correction////////////////////////////////////////////////////////////////
typedef void(__stdcall *KSJ_CCCALLBACK)(bool bSuccess, int nRShift, int nGShift, int nBShift, void *lpContext);

// 如下函数为软件颜色校正
KSJ_API  int __stdcall KSJ_ColorCorrectSetCallback( int nChannel, KSJ_CCCALLBACK fpCCCallback, void *lpContext );

enum KSJ_COLORCORRECT { KSJ_CC_NONE, KSJ_CC_SHIFTRGB, KSJ_CC_EQRGB, KSJ_CC_EQALL, KSJ_CC_WB };
KSJ_API  int __stdcall KSJ_ColorCorrectSet  ( int nChannel, KSJ_COLORCORRECT ColorCorrect, int nRTarget, int nGTarget, int nBTarget );
KSJ_API  int __stdcall KSJ_ColorCorrectGet  ( int nChannel, KSJ_COLORCORRECT *pColorCorrect );
KSJ_API  int __stdcall KSJ_ColorCorrectGetEx( int nChannel, KSJ_COLORCORRECT *pColorCorrect, int *pnRTarget, int *pnGTarget, int *pnBTarget );

KSJ_API  int __stdcall KSJ_ColorCorrectTableSave( int nChannel, const TCHAR *pszFileName );
KSJ_API  int __stdcall KSJ_ColorCorrectTableLoad( int nChannel, const TCHAR *pszFileName );
KSJ_API  int __stdcall KSJ_IsColorCorrectTableLoad( int nChannel, bool *bLoad );

// KSJ_IR 红外灯， KSJ_UV 紫外灯，KSJ_VI 可见光灯
enum KSJ_LED { KSJ_IR = 0, KSJ_UV, KSJ_VI };
// KSJ_ON 灯亮，KSJ_OFF 灯关
enum KSJ_LEDSTATUS { KSJ_OFF = 0, KSJ_ON };

// 设置灯的状态
KSJ_API  int __stdcall KSJ_LedSetStatus( int nChannel, KSJ_LED Led, KSJ_LEDSTATUS LedStatus );
KSJ_API  int __stdcall KSJ_LedGetStatus( int nChannel, KSJ_LED Led, KSJ_LEDSTATUS *pLedStatus );


#if 0

KSJ_API  int __stdcall KSJ_IsSupportLUT( int nChannel );                      // Use KSJ_QueryFunction
KSJ_API  int __stdcall KSJ_EnableLUT( int nChannel, bool bEnable );           // Use KSJ_LutSetEnable
KSJ_API  int __stdcall KSJ_IsEnableLUT( int nChannel, bool *pbEnable );       // Use KSJ_LutGetEnable


// 这个函数会使相机将查找表写入到24LC1024的LUT_BASE_ADDRESS为基址的ulOffsetAddress为偏移的地址。
KSJ_API  int __stdcall KSJ_ReadLUT ( int nChannel, unsigned short usOffsetAddress, int nBytes, unsigned char *pData   );
// nBytes必须不大于64字节，usOffsetAddress 从0开始。
KSJ_API  int __stdcall KSJ_WriteLUT( int nChannel, unsigned short usOffsetAddress, unsigned char *pData, int nBytes  );

// 加载影射表
// 这个表要通过凯视佳专用的影射表生成工具生成, 此函数会根据查找表的不同类型进行相应的加载
// 对于12bit->8bit或者10bit->8bit映射表, 库函数会在设置16bit数据传输模式时,通过影射之后进行显示，此功能由PC端计算完成。
KSJ_API  int __stdcall KSJ_LoadMapTableFile( int nChannel, bool bLoad, const TCHAR *pszTableName );    // Use KSJ_LutFileDownload
/*
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetOnce( int nChannel, bool bOnce );               // You should call KSJ_WhiteBalanceSetEnable after call this function.
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetContinuous( int nChannel, bool bContinuous );   // You should call KSJ_WhiteBalanceSetEnable after call this function.

KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGetOnce( int nChannel, bool *pbOnce );             // You should call KSJ_WhiteBalanceSetEnable after call this function.
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGetContinuous( int nChannel, bool *pbContinuous );

KSJ_API  int __stdcall KSJ_WhiteBalanceSetEnable( int nChannel, bool bEnable );
KSJ_API  int __stdcall KSJ_WhiteBalanceGetEnable( int nChannel, bool *pbEnable );
*/

// 白平衡后再做颜色校正处理
//enum KSJ_COLORCORRECTION { KSJCC_NONE = 0, KSJCC_WARMLIGHT, KSJCC_COOLLIGHT, KSJCC_SUNLIGHT, KSJCC_OV, KSJCC_KODAK };
//KSJ_API  int __stdcall KSJ_ColorCorrectionSet( int nChannel, KSJ_COLORCORRECTION  ColorCorrect  );
//KSJ_API  int __stdcall KSJ_ColorCorrectionGet( int nChannel, KSJ_COLORCORRECTION *pColorCorrect );


// KSJ_API  int __stdcall KSJ_ColorCorrectionSetEnable( int nChannel, bool bEnable );
// KSJ_API  int __stdcall KSJ_ColorCorrectionGetEnable( int nChannel, bool *pbEnable );


#endif
#ifdef __cplusplus
}
#endif

#endif