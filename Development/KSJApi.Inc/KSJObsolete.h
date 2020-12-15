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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaGetRange(int nIndex, int *pnMinGamma, int *pnMaxGamm);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置Gamma
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nValue [in] Gamma设置的值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaSetValue(int nIndex, int nValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取Gamma
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnValue [out] 返回Gamma
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaGetValue(int nIndex, int *pnValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置相机对比度参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nContrast [in] 对比度设置的值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessContrastSet(int nIndex, int nContrast);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取相机对比度参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnContrast [out] 返回对比度设置的最小值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessGetRange(int nIndex, int *pnMinBrightness, int *pnMaxBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置相机的亮度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nBrightness [in] 亮度设置的值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessSet(int nIndex, int nBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取相机亮度参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnBrightness [out] 返回相机亮度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessGet(int nIndex, int *pnBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     是否读取超时后恢复设备
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bRecover [in] 读取超时后是否恢复设备,true恢复,false不恢复
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetRecover(int nIndex, bool bRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取当前关于超时恢复的设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbRecover [out] 获取设置读取超时后是否恢复设备,true恢复,false不恢复
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
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

	///-----------------------------------------------------------------------------
	///
	/// @brief     定义通过KSJ_AEStartEx启动的自动曝光操作的回调函数，当自动曝光进行每一次调节时，KSJ开发包会自动调用pfAECallbackEx用户指定的回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfAECallback [in] 用户定义的自动曝光回调函数指针（参考KSJ_AECALLBACK函数的定义）
	/// @param     lpContext [in] 回调函数的上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用, 不再推荐使用，请使用KSJ_AESetCallbackEx代替
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetCallback(int nIndex, KSJ_AECALLBACK pfAECallback, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     启动或结束自动曝光操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bStart [in] 设定最多调节几次就结束。如果在用户设置的次数内曝光调节没有达到用户设定的目标值，回调函数会提示自动曝光失败
	/// @param     nMaxCount [in] TRUE 开始自动曝光调节，FALSE 终止或结束自动曝光调节
	/// @param     nTarget [in] 调节到的目标亮度值（0-255）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用, 不再推荐使用，请使用KSJ_AEStartEx代替
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEStart(int nIndex, bool bStart, int nMaxCount, int nTarget);

	/// 设置聚焦评估区域
	///-----------------------------------------------------------------------------
	///
	/// @brief     设置自动聚焦评估的参考区域，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nX [in] 相对于无缩放预览图像的左上角水平像素偏移
	/// @param     nY [in] 相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     nW [in] 相对于无缩放预览图像的自动曝光区域的宽度以像素为单位
	/// @param     nH [in] 相对于无缩放预览图像的自动曝光区域的高度以像素为单位
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFSetRegion(int nIndex, int nX, int nY, int nW, int nH);

	///-----------------------------------------------------------------------------
	///
	/// @brief     是否显示自动聚焦的参考区域
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bShow [in] 是否显示自动聚焦参考区域
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFShowRegion(int nIndex, bool bShow);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取自动聚焦的参考区域及显示状态，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnX [out] 返回相对于无缩放预览图像的左上角水平像素偏移
	/// @param     pnY [out] 返回相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     pnW [out] 返回相对于无缩放预览图像的自动曝光区域的宽度以像素为单位
	/// @param     pnH [out] 返回相对于无缩放预览图像的自动曝光区域的高度以像素为单位
	/// @param     pbShow [out] 参考区域是否显示
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);

	///-----------------------------------------------------------------------------
	///
	/// @brief     定义自动聚焦评估操作结束后的回调函数
	/// @param     nValue [out] 聚焦评估值(0-10200)
	/// @param     lpContext [out] 用户上下文指针，这个指针是用户调用KSJ_AFSetCallback时传入的上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AFCALLBACK)(int nValue, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     定义自动聚焦评估值计算结束后的回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fpAFCallback [in] 用户定义的自动聚焦评估回调函数指针（参考KSJ_AFCALLBACK函数的定义）
	/// @param     lpContext [in] 回调函数的上下文指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFSetCallback(int nIndex, KSJ_AFCALLBACK fpAFCallback, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     开始或停止自动聚焦自动评估操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bStart [in] TRUE 开始自动聚焦评估计算，FALSE 终止或结束自动聚焦评估计算
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFStart(int nIndex, bool bStart);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// 硬件自动曝光
	///-----------------------------------------------------------------------------
	///
	/// @brief     开启或关闭AEC功能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] true 开启AEC功能，false 关闭AEC功能
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECSetEnable ( int nIndex, bool bEnable  );

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取AEC功能是否开启
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] true AEC功能已经开启，false AEC功能已经关闭
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECGetEnable ( int nIndex, bool *pbEnable  );

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置AEC的调节范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     usMin [in] AEC调节下限（曝光行）
	/// @param     usMax [in] AEC调节上限（曝光行）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECSetRange ( int nIndex, unsigned short usMin,  unsigned short usMax  );

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取AEC的调节范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pusMin [out] 返回AEC调节下限（曝光行）
	/// @param     pusMax [out] 返回AEC调节上限（曝光行）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECGetRange(int nIndex, unsigned short *pusMin, unsigned short *pusMax);

	///-----------------------------------------------------------------------------
	///
	/// @brief     得到AEC的当前曝光行
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     usCur [out] 返回AEC当前值（曝光行）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECGetCur(int nIndex, unsigned short *usCur);

	///-----------------------------------------------------------------------------
	///
	/// @brief     开启或关闭AGC功能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] true 开启AGC功能，false 关闭AGC功能
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCSetEnable(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取AGC功能是否开启
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] true  AGC功能已经开启，false  AGC功能已经关闭
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetEnable(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置AGC的调节范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     usMin [in] AGC调节增益下限
	/// @param     usMax [in] AGC调节增益上限
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCSetRange(int nIndex, unsigned short usMin, unsigned short usMax);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取AGC的调节范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pusMin [out] 返回AGC调节增益下限
	/// @param     pusMax [out] 返回AGC调节增益上限
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetRange(int nIndex, unsigned short *pusMin, unsigned short *pusMax);

	///-----------------------------------------------------------------------------
	///
	/// @brief     得到AGC的当前增益值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pusCur [out] 返回AGC当前增益值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetCur(int nIndex, unsigned short *pusCur);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GammaLutFileDownload
	/// @brief     以ktb文件形式，下载Gamma LUT查找表至相机
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pszKtbFile [in] .ktb文件路径
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaLutFileDownload(int nIndex, const TCHAR *pszKtbFile );

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GammaLutDataDownload
	/// @brief     加载用户自定义的Gamma LUT查找表数据
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pData [out] 指向查找表数据的指针，每个元素为双字节
	/// @param     nWords [in] 查找表数据个数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaLutDataDownload(int nIndex, unsigned short *pData, int nWords );

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GammaLutSetEnable
	/// @brief     使能Gamma LUT查找表功能
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] 设置是否使Gamma LUT功能生效
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaLutSetEnable(int nIndex, bool bEnable   );

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GammaLutGetEnable
	/// @brief     获取Gamma LUT查找表是否使能
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] 返回是否Gamma LUT功能已生效
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaLutGetEnable(int nIndex, bool *pbEnable);


	enum KSJ_WATERMARKMODE ///水印模式
	{ 
		KSJ_WMM_TIMESTAMP, 
		KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, 
		KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER 
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置水印模式（新版本水印已经不支持水印模式设置，默认KSJ_WMM_TIMESTAMP）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     WaterMarkMode [in] 设置水印模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetMode(int nIndex, KSJ_WATERMARKMODE WaterMarkMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取水印模式（新版本水印已经不支持水印模式设置，默认KSJ_WMM_TIMESTAMP）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pWaterMarkMode [out] 获取当前水印模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetMode(int nIndex, KSJ_WATERMARKMODE *pWaterMarkMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetErrorInfo
	/// @brief     获得错误的详细信息字符串
	/// @param     nErrorNo [in] 传入错误代码, 请参考 KSJCode.h 中错误码的定义。
	/// @param     pszErrorInfo[out] 传出错误代码信息字符串
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 可以在任意时刻调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetErrorInfo(IN int nErrorNo, OUT TCHAR pszErrorInfo[256]);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetFrameRate
	/// @brief     获取帧速
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fFrameRate [out] 返回当前视频流的帧速
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRate(int nIndex, float *fFrameRate);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取暂停时的那一帧图像数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pData [out] 由用户提供的数据区域，函数调用返回后，此区域会被填充暂停时的图像数据
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedData(int nIndex, unsigned char *pData);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewPause
	/// @brief     暂停或继续视频流
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bPause   [in] true 暂停视频流，false 继续视频流 
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewPause(int nIndex, bool bPause);

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取暂停时的那一帧图像数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pData [out] 由用户提供的数据区域，函数调用返回后，此区域会被填充暂停时的图像数据
	/// @param     pnWidth [out] 返回图像的宽度（像素）
	/// @param     pnHeight[out] 返回图像的高度（像素）
	/// @param     pnBitCount[out] 返回图像的每个像素位数（8，24或32）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedDataEx(int nIndex, unsigned char *pData, int *pnWidth, int *pnHeight, int *pnBitCount);

	/// Preview Mode
	enum KSJ_PREVIEWMODE// 枚举类型视频预览模式
	{
		PM_RAWDATA, ///预览原始数据，对于黑白设备，必须设置为PM_RAWDATA
		PM_RGBDATA  ///预览24位或32位彩色数据（由Bayer模式决定）
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     获取设备默认的预览模式
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pPreviewMode   [out] 获取相机默认的预览模式（参考KSJ_PREVIEWMODE定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewSetMode
	/// @brief     设置视频流为原始采集数据还是RGB 24位或32位彩色数据格式，一般用户无需设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     PreviewMode [in] 设置的预览模式（参考KSJ_PREVIEWMODE定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetMode(int nIndex, KSJ_PREVIEWMODE PreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetMode
	/// @brief     获取相机的当前预览模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pPreviewMode   [out] 获取当前的预览模式（参考KSJ_PREVIEWMODE定义）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreviewSetCalibration
	/// @brief     对预览流是否进行畸变矫正处理
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] 为true时时开启畸变矫正, false时关闭畸变矫正
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreviewGetCalibration
	/// @brief     获取当前预览流是否进行畸变矫正处理
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] 返回畸变矫正对于预览的使能状态
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetCalibration(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureSetCalibration
	/// @brief     对采集是否进行畸变矫正处理
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] 为true时时开启畸变矫正, false时关闭畸变矫正
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureGetCalibration
	/// @brief     获取采集时是否进行畸变矫正处理
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] 返回畸变矫正对于采集的使能状态
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetCalibration(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LoadCalibrationMapFile
	/// @brief     用于从文件加载畸变校正参数信息
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pszFilePath [in] 需要加载载畸变校正参数的文件名（完整路径）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadCalibrationMapFile(int nIndex, const TCHAR *pszFilePath);

	enum KSJ_MAPMODE ///凯视佳工业相机畸变校正目标值计算方式定义
	{
		KSJ_MM_NEARESTNEIGHBOR,
		KSJ_MM_BILINEAR
	};

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SetCalibrationMapMode
	/// @brief     设置畸变校正目标值计算方法
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     MapMode [in] 设置畸变校正目标值计算方法
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetCalibrationMapMode(int nIndex, KSJ_MAPMODE MapMode);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GetCalibrationMapMode
	/// @brief     获取畸变校正目标值计算方法
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pMapMode [out] 当前畸变校正目标值的计算方法
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetCalibrationMapMode(int nIndex, KSJ_MAPMODE *pMapMode);


	enum KSJ_SNAPBUTTONSTATUS ///Snap功能引脚状态
	{
		KSJ_UP, 	///按键处于闭合状态
		KSJ_DOWN 	///按键处于开启状态
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     读取Snap功能引脚状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pSnapButtonStatus [out] 返回Snap功能引脚状态, KSJ_SNAPBUTTONSTATUS类型
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SnapButtonStatus(int nIndex, KSJ_SNAPBUTTONSTATUS *pSnapButtonStatus);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HelperStretchBmp
	/// @brief     将pData(宽度为nWidth, 高度为nHeight, 比特位数为nBitCount)的图像数据缩放为宽度为nStretchWidh, 高度为nStretchHeight的数据并填充到用户分配的pStretchData缓冲区,比特位数不变
	/// 参数：
	/// @param     pData [in] 输入图像的数据指针
	/// @param     nWidth [in] 输入图像的宽度
	/// @param     nHeight [in] 输入图像的高度
	/// @param     nBitCount [in] 输入图像的比特深度
	/// @param     pStretchData [out] 输出图像保存内存地址指针
	/// @param     nStretchWidth [out] 输出图像的宽度
	/// @param     nStretchHeight [out] 输出图像的高度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperStretchBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char *pStretchData, int nStretchWidth, int nStretchHeight);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HelperGetBmpFileHeaderSize
	/// @brief     根据图像的比特深度得到BMP图像的文件头,信息头,及颜色表总的字节数目
	/// 参数：
	/// @param     nBitCount [in] 图像的比特深度
	/// @param     pnTotalBytes [out] BMP的文件头，信息头，以及颜色表的总字节数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeaderSize(int nBitCount, int *pnTotalBytes);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HelperGetBmpFileHeader
	/// @brief     得到BMP图像的文件头和信息头
	/// 参数：
	/// @param     nWidth [in] 图像的宽度
	/// @param     nHeight [in] 图像的高度
	/// @param     nBitCount [in] 图像的比特深度
	/// @param     pHeader [out] BMP的文件头和信息头数据保存的地址指针
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, void *pHeader);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureRgbDataToClipboard
	/// @brief     采集一帧图像到系统剪贴板，从一个相机采集一帧图像并放到系统的剪切板
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataToClipboard(int nIndex);

	KSJ_API  int __stdcall KSJ_GammaLutInfoProgram(int nIndex, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_GammaLutInfoReadout(int nIndex, unsigned short *pValue);

	KSJ_API  int __stdcall KSJ_GammaLutFileProgram(int nIndex, TCHAR *pszFile);
	KSJ_API  int __stdcall KSJ_GammaLutDataProgram(int nIndex, unsigned short *pData, int nWords);
	KSJ_API  int __stdcall KSJ_GammaLutDataReadout(int nIndex, unsigned short *pData, int *pnWords);

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