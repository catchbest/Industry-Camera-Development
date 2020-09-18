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

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取Gamma的设置范围（-9 - 9）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnMinGamma [out] 取得Gamma设置的最小值
	/// @param     pnMaxGamm [out] 取得Gamma设置的最大值
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaGetRange(int nIndex, int *pnMinGamma, int *pnMaxGamm);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置Gamma
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nValue [in] Gamma设置的值
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaSetValue(int nIndex, int nValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取Gamma
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnValue [out] 返回Gamma
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaGetValue(int nIndex, int *pnValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置相机对比度参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nContrast [in] 对比度设置的值
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessContrastSet(int nIndex, int nContrast);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取相机对比度参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnContrast [out] 返回对比度设置的最小值
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessContrastGet(int nIndex, int *pnContrast);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取亮度的设置范围（-128~128）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnMinBrightness [out] 取得亮度设置的最小值
	/// @param     pnMaxBrightness [out] 取得亮度设置的最大值
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessGetRange(int nIndex, int *pnMinBrightness, int *pnMaxBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置相机的亮度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nBrightness [in] 亮度设置的值
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessSet(int nIndex, int nBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取相机亮度参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnBrightness [out] 返回相机亮度
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessGet(int nIndex, int *pnBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     是否读取超时后恢复设备
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bRecover [in] 读取超时后是否恢复设备,true恢复,false不恢复
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetRecover(int nIndex, bool bRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取当前关于超时恢复的设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbRecover [out] 获取设置读取超时后是否恢复设备,true恢复,false不恢复
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetRecover(int nIndex, bool *pbRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     同时设置超时时间及超时后是否恢复设备
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     dwTimeOut [in] 设置超时时间,单位为毫秒
	/// @param     bRecover [in] 读取超时后是否恢复设备,true恢复,false不恢复
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetTimeOutEx(int nIndex, unsigned long dwTimeOut, bool bRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取关于超时和恢复的设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pdwTimeOut [out] 获取读取一帧图像的超时时间，单位为毫秒
	/// @param     pbRecover [out] 获取设置读取超时后是否恢复设备,true恢复,false不恢复
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetTimeOutEx(int nIndex, unsigned long *pdwTimeOut, bool *pbRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     定义自动曝光操作结束后的回调函数
	/// @param     bSuccess [out] 传回自动白平衡操作是否调节到用户设定的目标值（参考KSJ_AEStart函数），TRUE，表示自动白平衡调节到达了目标值，FALSE，表示自动白平衡超过用户设定的调节次数，没有达到目标值
	/// @param     nValueR [out] 在自动白平衡调节结束后，红增益的设置值
	/// @param     nValueG [out] 在自动白平衡调节结束后，绿增益的设置值
	/// @param     nValueB [out] 在自动白平衡调节结束后，蓝增益的设置值
	/// @param     lpContext [out] 用户上下文指针，这个指针是用户调用KSJ_AWBSetCallback时传入的上下文指针
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用，不再推荐使用, 请用KSJApiMatrix.h内函数
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AWBCALLBACK)(bool bSuccess, int nValueR, int nValueG, int nValueB, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     定义自动白平衡操作结束后的回调函数，当自动曝光结束时，KSJ开发包会自动调用pfAWBCallback用户指定的回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fpAWBCallback [in] 用户定义的自动白平衡回调函数指针（参考KSJ_AWBCALLBACK函数的定义）
	/// @param     lpContext [in] 回调函数的上下文指针
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用，不再推荐使用, 请用KSJApiMatrix.h内函数
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBSetCallback(int nIndex, KSJ_AWBCALLBACK fpAWBCallback, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     启动或结束自动曝光操作
	/// @param     bSuccess [out] 传回自动白平衡操作是否调节到用户设定的目标值（参考KSJ_AEStart函数），TRUE，表示自动白平衡调节到达了目标值，FALSE，表示自动白平衡超过用户设定的调节次数，没有达到目标值
	/// @param     bStart [in] TRUE 开始自动白平衡调节，FALSE 终止或结束自动白平衡调节
	/// @param     nMaxCount [out] 设定最多调节几次就结束。如果在用户设置的次数内白平衡调节没有达到用户设定的目标值，回调函数会提示自动白平衡失败
	/// @param     nRTarget [out] 调节到的目标红分量值（0-255）
	/// @param     nGTarget [out] 调节到的目标绿分量值（0-255）
	/// @param     nBTarget [out] 调节到的目标蓝分量值（0-255）
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用，不再推荐使用, 请用KSJApiMatrix.h内函数
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBStart(int nIndex, bool bStart, int nMaxCount, int nRTarget, int nGTarget, int nBTarget);


	/// 打开或关闭Gamma校正，即影响预览又影响采集
	KSJ_API  int __stdcall KSJ_GammaOn(int nIndex, bool bOn);    /// Not Support Now.


	// 设置固定帧速(通过设置sensor寄存器,使sensor输出固定帧率)，只有MUC36C/M(MGYY)和MU3E130C/M(CGYY)支持
	// V4.0.86.12版本开始，bEnable参数无效，通过用户设置KSJ_TRIGGER_FIXFRAMERATE模式来决定是否使能。
	KSJ_API  int __stdcall KSJ_SetFixedFrameRate(int nIndex, bool bEnable, float fFrameRate);
	KSJ_API  int __stdcall KSJ_GetFixedFrameRate(int nIndex, bool *pbEnable, float *pfFrameRate);

	// 闪光灯信号输出到实际相机输出的延时设置（暂不支持）
	KSJ_API  int __stdcall KSJ_StrobeDelaySet(int nIndex, unsigned short wDelay);
	KSJ_API  int __stdcall KSJ_StrobeDelayGet(int nIndex, unsigned short *pwDelay);
	KSJ_API  int __stdcall KSJ_StrobeDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);


	// 设置图像传感器的工作方式（暂不支持）
	enum KSJ_SENSORMODE { KSJ_SM_TRIGGER_MODE, KSJ_SM_FREERUN_MODE, KSJ_SM_GRR_MODE };
	KSJ_API  int __stdcall KSJ_SensorModeSet(int nIndex, KSJ_SENSORMODE SensorMode);
	KSJ_API  int __stdcall KSJ_SensorModeGet(int nIndex, KSJ_SENSORMODE *SensorMode);

	///////////////////////////////////////////////Color Correction////////////////////////////////////////////////////////////////
	typedef void(__stdcall *KSJ_CCCALLBACK)(bool bSuccess, int nRShift, int nGShift, int nBShift, void *lpContext);

	// 如下函数为软件颜色校正
	KSJ_API  int __stdcall KSJ_ColorCorrectSetCallback( int nIndex, KSJ_CCCALLBACK fpCCCallback, void *lpContext );

	enum KSJ_COLORCORRECT { KSJ_CC_NONE, KSJ_CC_SHIFTRGB, KSJ_CC_EQRGB, KSJ_CC_EQALL, KSJ_CC_WB };
	KSJ_API  int __stdcall KSJ_ColorCorrectSet  ( int nIndex, KSJ_COLORCORRECT ColorCorrect, int nRTarget, int nGTarget, int nBTarget );
	KSJ_API  int __stdcall KSJ_ColorCorrectGet  ( int nIndex, KSJ_COLORCORRECT *pColorCorrect );
	KSJ_API  int __stdcall KSJ_ColorCorrectGetEx( int nIndex, KSJ_COLORCORRECT *pColorCorrect, int *pnRTarget, int *pnGTarget, int *pnBTarget );

	KSJ_API  int __stdcall KSJ_ColorCorrectTableSave( int nIndex, const TCHAR *pszFileName );
	KSJ_API  int __stdcall KSJ_ColorCorrectTableLoad( int nIndex, const TCHAR *pszFileName );
	KSJ_API  int __stdcall KSJ_IsColorCorrectTableLoad( int nIndex, bool *bLoad );

	// KSJ_IR 红外灯， KSJ_UV 紫外灯，KSJ_VI 可见光灯
	enum KSJ_LED { KSJ_IR = 0, KSJ_UV, KSJ_VI };
	// KSJ_ON 灯亮，KSJ_OFF 灯关
	enum KSJ_LEDSTATUS { KSJ_OFF = 0, KSJ_ON };

	// 设置灯的状态
	KSJ_API  int __stdcall KSJ_LedSetStatus( int nIndex, KSJ_LED Led, KSJ_LEDSTATUS LedStatus );
	KSJ_API  int __stdcall KSJ_LedGetStatus( int nIndex, KSJ_LED Led, KSJ_LEDSTATUS *pLedStatus );


	enum KSJ_FLASHMODE//闪光灯模式（暂不支持）
	{
		KSJ_FM_TROW,
		KSJ_FM_SIMULTANEOUSEXPOSURE,
		KSJ_FM_SHUTTERWIDTH
	};
	KSJ_API  int __stdcall KSJ_FlashSetMode(int nIndex, KSJ_FLASHMODE FlashMode);//设置闪光灯模式（暂不支持）
	KSJ_API  int __stdcall KSJ_FlashGetMode(int nIndex, KSJ_FLASHMODE *pFlashMode);//获取闪光灯模式（暂不支持）

#if 0

KSJ_API  int __stdcall KSJ_IsSupportLUT( int nIndex );                      /// Use KSJ_QueryFunction
KSJ_API  int __stdcall KSJ_EnableLUT( int nIndex, bool bEnable );           /// Use KSJ_LutSetEnable
KSJ_API  int __stdcall KSJ_IsEnableLUT( int nIndex, bool *pbEnable );       /// Use KSJ_LutGetEnable


// 这个函数会使相机将查找表写入到24LC1024的LUT_BASE_ADDRESS为基址的ulOffsetAddress为偏移的地址。
KSJ_API  int __stdcall KSJ_ReadLUT ( int nIndex, unsigned short usOffsetAddress, int nBytes, unsigned char *pData   );
// nBytes必须不大于64字节，usOffsetAddress 从0开始。
KSJ_API  int __stdcall KSJ_WriteLUT( int nIndex, unsigned short usOffsetAddress, unsigned char *pData, int nBytes  );

// 加载影射表
// 这个表要通过凯视佳专用的影射表生成工具生成, 此函数会根据查找表的不同类型进行相应的加载
// 对于12bit->8bit或者10bit->8bit映射表, 库函数会在设置16bit数据传输模式时,通过影射之后进行显示，此功能由PC端计算完成。
KSJ_API  int __stdcall KSJ_LoadMapTableFile( int nIndex, bool bLoad, const TCHAR *pszTableName );    /// Use KSJ_LutFileDownload
/*
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetOnce( int nIndex, bool bOnce );               /// You should call KSJ_WhiteBalanceSetEnable after call this function.
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetContinuous( int nIndex, bool bContinuous );   /// You should call KSJ_WhiteBalanceSetEnable after call this function.

KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGetOnce( int nIndex, bool *pbOnce );             /// You should call KSJ_WhiteBalanceSetEnable after call this function.
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGetContinuous( int nIndex, bool *pbContinuous );

KSJ_API  int __stdcall KSJ_WhiteBalanceSetEnable( int nIndex, bool bEnable );
KSJ_API  int __stdcall KSJ_WhiteBalanceGetEnable( int nIndex, bool *pbEnable );
*/

// 白平衡后再做颜色校正处理
//enum KSJ_COLORCORRECTION { KSJCC_NONE = 0, KSJCC_WARMLIGHT, KSJCC_COOLLIGHT, KSJCC_SUNLIGHT, KSJCC_OV, KSJCC_KODAK };
//KSJ_API  int __stdcall KSJ_ColorCorrectionSet( int nIndex, KSJ_COLORCORRECTION  ColorCorrect  );
//KSJ_API  int __stdcall KSJ_ColorCorrectionGet( int nIndex, KSJ_COLORCORRECTION *pColorCorrect );


// KSJ_API  int __stdcall KSJ_ColorCorrectionSetEnable( int nIndex, bool bEnable );
// KSJ_API  int __stdcall KSJ_ColorCorrectionGetEnable( int nIndex, bool *pbEnable );


#endif
#ifdef __cplusplus
}
#endif

#endif