#ifndef __KSJ_API_3A_H__
#define __KSJ_API_3A_H__

// #pragma message("Include KSJApi3A.h") 

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

	///-----------------------------------------------------------------------------
	///
    /// @brief     设置自动曝光的参考区域，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nX [in] 相对于无缩放预览图像的左上角水平像素偏移
	/// @param     nY [in] 相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     nW [in] 相对于无缩放预览图像的自动曝光区域的宽度以像素为单位
	/// @param     nH [in] 相对于无缩放预览图像的自动曝光区域的高度以像素为单位
    /// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
    ///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetRegion(int nIndex, int nX, int nY, int nW, int nH);

	///-----------------------------------------------------------------------------
	///
    /// @brief     获取自动曝光的参考区域及显示状态，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnX [out] 返回相对于无缩放预览图像的左上角水平像素偏移
	/// @param     pnY [out] 返回相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     pnW [out] 返回相对于无缩放预览图像的自动曝光区域的宽度以像素为单位
	/// @param     pnH [out] 返回相对于无缩放预览图像的自动曝光区域的高度以像素为单位
	/// @param     pbShow [out] 参考区域是否显示
    /// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
    /// 
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     是否显示自动曝光的参考区域
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bShow [in] 是否显示自动曝光参考区域
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEShowRegion(int nIndex, bool bShow);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置峰值比率
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fRatio [in] 设置的峰值比率,范围0到1
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetPeakAveRatio(int nIndex, float fRatio);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     获取峰值比率
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfRatio [out] 返回峰值比率
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetPeakAveRatio(int nIndex, float *pfRatio);

	///-----------------------------------------------------------------------------
	///
    /// @brief     设置自动曝光的调节范围，影响KSJ_AEStart和KSJ_AEStartEx两个函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fMinExpMs [in] 设置自动曝光调节下限（ms）
	/// @param     fMaxExpMs [in] 设置自动曝光调节上限（ms）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetExposureTimeRange(int nIndex, float fMinExpMs,   float fMaxExpMs);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     获取自动曝光的调节范围，影响KSJ_AEStart和KSJ_AEStartEx两个函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfMinExpMs [in] 返回自动曝光调节下限（ms）
	/// @param     pfMaxExpMs [in] 返回自动曝光调节上限（ms）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetExposureTimeRange(int nIndex, float *pfMinExpMs, float *pfMaxExpMs);

	/// 自动曝光返回状态
	enum KSJ_AE_STATUS 
	{ 
	KSJ_AE_ONCE_SUCCESS = 0, 			///单次调节成功
	KSJ_AE_ONCE_FAIL_MAX_COUNT, 		///单次调节失败，失败原因达到最大调节次数
	KSJ_AE_ONCE_FAIL_WAVE, 				///单次调节失败，失败原因调节上下振动
	KSJ_AE_ONCE_FAIL_OVER_RANGE, 		///单次调节失败，失败原因曝光超出设置范围
	KSJ_AE_DOING, 						///单次调节实现，曝光时间发生了变化
	KSJ_AE_CONTINUE_SUCCESS,			///连续调节成功，当前达到了目标值
	KSJ_AE_CONTINUE_FAIL_WAVE, 			///连续调节失败，失败原因调节上下振动
	KSJ_AE_CONTINUE_FAIL_OVER_RANGE 	///连续调节失败，失败原因曝光超出设置范围
	};
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     定义通过KSJ_AEStartEx启动的自动曝光操作的回调函数
	/// @param     Status [out] 当前自动曝光操作的状态（参考KSJ_AE_STATUS说明）
    /// @param     nExpsoureTimeMs [out] 在自动曝光调节结束后，曝光值是多少（MS）
	/// @param     lpContext [out] 用户上下文指针，这个指针是用户调用KSJ_AESetCallbackEx时传入的上下文指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AECALLBACKEX)( KSJ_AE_STATUS Status, int nExpsoureTimeMs, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     定义通过KSJ_AEStartEx启动的自动曝光操作的回调函数，当自动曝光进行每一次调节时，KSJ开发包会自动调用pfAECallbackEx用户指定的回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfAECallbackEx [in] 用户定义的自动曝光回调函数指针
	/// @param     lpContext [in] 回调函数的上下文指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetCallbackEx(int nIndex, KSJ_AECALLBACKEX pfAECallbackEx, void *lpContext);

	///-----------------------------------------------------------------------------
	///
    /// @brief     设置自动曝光调节最大次数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nMaxCount [in] 设置自动曝光调节最大次数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetMaxCount(int nIndex, int  nMaxCount);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     设置自动曝光调节目标值，影响KSJ_AEStart和KSJ_AEStartEx两个函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nTarget [in] 设置自动曝光调节的目标值。所谓目标值就是调节成功后图像曝光区域所要达到的整体灰度值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetTarget(int nIndex, int  nTarget);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     启动或结束自动曝光操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bStart [in] TRUE 开始自动曝光调节，FALSE 终止或结束自动曝光调节
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEStartEx(int nIndex, bool bStart);

	///-----------------------------------------------------------------------------
	///
    /// @brief     得到自动曝光的设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbStart [out] 得到KSJ_AEStartEx是否启动
	/// @param     pnMaxCount [out] 得到自动曝光的最大调节次数
	/// @param     pnTarget [out] 得到自动曝光调节的目标值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetStatusEx(int nIndex, bool *pbStart, int *pnMaxCount, int *pnTarget);

	///-----------------------------------------------------------------------------
	///
    /// @brief     定义自动曝光操作结束后的回调函数
	/// @param     bSuccess [out] 传回自动曝光操作是否调节到用户设定的目标值（参考KSJ_AEStart函数），TRUE，表示自动曝光调节到达了目标值，FALSE，表示自动曝光超过用户设定的调节次数，没有达到目标值
    /// @param     nResult [out] 在自动曝光调节结束后，曝光值是多少（MS）
	/// @param     lpContext [out] 用户上下文指针，这个指针是用户调用KSJ_AESetCallback时传入的上下文指针
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用 不再推荐使用，请使用KSJ_AECALLBACKEX代替
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AECALLBACK)(bool bSuccess, int nResult, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     定义通过KSJ_AEStartEx启动的自动曝光操作的回调函数，当自动曝光进行每一次调节时，KSJ开发包会自动调用pfAECallbackEx用户指定的回调函数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfAECallback [in] 用户定义的自动曝光回调函数指针（参考KSJ_AECALLBACK函数的定义）
	/// @param     lpContext [in] 回调函数的上下文指针
    /// @return    参考返回状态码（KSJCode.H）
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
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用, 不再推荐使用，请使用KSJ_AEStartEx代替
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEStart(int nIndex, bool bStart, int nMaxCount, int nTarget);

	///-----------------------------------------------------------------------------
	///
    /// @brief     设置自动白平衡的参考区域，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nX [in] 相对于无缩放预览图像的左上角水平像素偏移
	/// @param     nY [in] 相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     nW [in] 相对于无缩放预览图像的自动曝光区域的宽度以像素为单位
	/// @param     nH [in] 相对于无缩放预览图像的自动曝光区域的高度以像素为单位
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBSetRegion(int nIndex, int nX, int nY, int nW, int nH);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     是否显示自动白平衡的参考区域
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bShow [in] 是否显示自动白平衡参考区域
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBShowRegion(int nIndex, bool bShow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取自动白平衡的参考区域及显示状态，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnX [out] 返回相对于无缩放预览图像的左上角水平像素偏移
	/// @param     pnY [out] 返回相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     pnW [out] 返回相对于无缩放预览图像的自动曝光区域的宽度以像素为单位
	/// @param     pnH [out] 返回相对于无缩放预览图像的自动曝光区域的高度以像素为单位
	/// @param     pbShow [out] 参考区域是否显示
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);

	/// 设置聚焦评估区域
	///-----------------------------------------------------------------------------
	///
    /// @brief     设置自动聚焦评估的参考区域，这个区域是相对预览图像的位置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nX [in] 相对于无缩放预览图像的左上角水平像素偏移
	/// @param     nY [in] 相对于无缩放预览图像的左上角垂直像素偏移
	/// @param     nW [in] 相对于无缩放预览图像的自动曝光区域的宽度以像素为单位
	/// @param     nH [in] 相对于无缩放预览图像的自动曝光区域的高度以像素为单位
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFSetRegion(int nIndex, int nX, int nY, int nW, int nH);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     是否显示自动聚焦的参考区域
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bShow [in] 是否显示自动聚焦参考区域
    /// @return    参考返回状态码（KSJCode.H）
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
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     定义自动聚焦评估操作结束后的回调函数
	/// @param     nValue [out] 聚焦评估值(0-10200)
	/// @param     lpContext [out] 用户上下文指针，这个指针是用户调用KSJ_AFSetCallback时传入的上下文指针
    /// @return    参考返回状态码（KSJCode.H）
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
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFSetCallback(int nIndex, KSJ_AFCALLBACK fpAFCallback, void *lpContext);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     开始或停止自动聚焦自动评估操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bStart [in] TRUE 开始自动聚焦评估计算，FALSE 终止或结束自动聚焦评估计算
    /// @return    参考返回状态码（KSJCode.H）
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
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECSetEnable ( int nIndex, bool bEnable  );
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取AEC功能是否开启
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] true AEC功能已经开启，false AEC功能已经关闭
    /// @return    参考返回状态码（KSJCode.H）
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
    /// @return    参考返回状态码（KSJCode.H）
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
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECGetRange ( int nIndex, unsigned short *pusMin, unsigned short *pusMax );
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到AEC的当前曝光行
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     usCur [out] 返回AEC当前值（曝光行）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECGetCur ( int nIndex, unsigned short *usCur  );

	///-----------------------------------------------------------------------------
	///
    /// @brief     开启或关闭AGC功能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] true 开启AGC功能，false 关闭AGC功能
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCSetEnable ( int nIndex, bool bEnable  );
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取AGC功能是否开启
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] true  AGC功能已经开启，false  AGC功能已经关闭
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetEnable ( int nIndex, bool *pbEnable  );

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置AGC的调节范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     usMin [in] AGC调节增益下限
	/// @param     usMax [in] AGC调节增益上限
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCSetRange ( int nIndex, unsigned short usMin,  unsigned short usMax  );
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取AGC的调节范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pusMin [out] 返回AGC调节增益下限
	/// @param     pusMax [out] 返回AGC调节增益上限
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetRange ( int nIndex, unsigned short *pusMin, unsigned short *pusMax );

	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到AGC的当前增益值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pusCur [out] 返回AGC当前增益值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetCur ( int nIndex, unsigned short *pusCur  );

#ifdef __cplusplus
}
#endif

#endif