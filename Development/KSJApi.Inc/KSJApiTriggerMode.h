#ifndef __KSJ_API_TRIGGER_MODE_H__
#define __KSJ_API_TRIGGER_MODE_H__

// #pragma message("Include KSJApiTriggerMode.h") 

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

	/// 相机触发模式类型
	enum KSJ_TRIGGERMODE
	{
		KSJ_TRIGGER_INTERNAL,             /// 内触发模式：Free run运行模式，当相机可以采集图像的时候，比如帧缓存为空的时候，就从Sensor采集图像。
		KSJ_TRIGGER_EXTERNAL,             /// 外触发模式：当相机接收到外触发信号的时候，从Sensor采集图像；如果这个时候帧缓存内的图像没有被读走，就会丢帧。
		KSJ_TRIGGER_SOFTWARE,             /// 软触发模式：在Capture的时候，触发相机去Sensor采集图像并上传。
		KSJ_TRIGGER_FIXFRAMERATE,         /// 固定帧率模式：相机自动以设定的帧率从Sensor采集图像；如果上层APP不能够及时读取数据，可能会造成丢帧。
		KSJ_TRIGGER_HIGHLOWFIXFRAMERATE   /// 高低电平固定帧率模式：根据设置，当外触发信号线为高/低电平时，相机自动以设定的帧率从Sensor采集图像；如果上层APP不能够及时读取数据，可能会造成丢帧。
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerModeSet
	/// @brief     设置相机的触发工作模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     TriggerMode [in] 需要设置的相机工作模式，请参考KSJ_TRIGGERMODE的说明
	/// @return    成功返回RET_SUCCESS；不支持的触发模式，返回RET_NOTSUPPORT；其他错误参考回状态码（KSJCode.h）
	/// @attention 调用KSJ_Init函数初始化后调用。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeSet(int nIndex, KSJ_TRIGGERMODE TriggerMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerModeGet
	/// @brief     获取当前相机的触发工作模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     TriggerMode [out] 得到当前相机的工作模式，请参考KSJ_TRIGGERMODE的说明
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeGet(int nIndex, KSJ_TRIGGERMODE *pTriggerMode);

	/// 相机缓存状态
	enum KSJ_TRIGGERSTATUS
	{
		KSJ_NO,   ///< 缓存为空
		KSJ_HAVE  ///< 缓存非空
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerStatusGet
	/// @brief     读取相机缓存状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pTriggerStatus [out] 得到当前相机的板级缓存中是否有图像数据可供读取，KSJ_HAVE表示有1个或者多个图像保存在帧缓存
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。；不支持该功能的相机，返回RET_NOTSUPPORT
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerStatusGet(int nIndex, KSJ_TRIGGERSTATUS *pTriggerStatus);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_EmptyFrameBuffer
	/// @brief     清空帧存中的数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。软触发模式下， 不支持清空缓存，返回RET_NOTSUPPORT
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_EmptyFrameBuffer(int nIndex);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机的固定帧率设置范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfRateMin [out] 固定帧率能够设置的最小值
	/// @param     pfRateMax [out] 固定帧率能够设置的最大值
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateRang(int nIndex, float* pfRateMin, float* pfRateMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     当相机设置为固定帧率触发模式或者高低电平有效固定帧率触发模式时,设置相机的固定帧率
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fFrameRate [in] 设置固定帧率（帧每秒）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用；只有在触发模式设置为相机设置为固定帧率触发模式或者高低电平有效固定帧率触发模式时，才能够调用该函数，否则返回RET_NOTSUPPORT
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFixedFrameRateEx(int nIndex, float fFrameRate);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetFixedFrameRateEx
	/// @brief     得到当前设置的固定帧率
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfFrameRate [out] 得到当前设置的固定帧率（帧每秒）
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateEx(int nIndex, float *pfFrameRate);
	
	/// 外触发信号条件
	enum KSJ_TRIGGERMETHOD
	{
		KSJ_TRIGGER_FALLINGEDGE,    ///< 上升沿，每一个外触发信号上升沿触发一次图像采集 
		KSJ_TRIGGER_RISINGEDGE,     ///< 下降沿，每一个外触发信号下降沿触发一次图像采集 
		KSJ_TRIGGER_HIGHLEVEL,      ///< 高电平，外触发信号处于高电平的时候，相机将会以Freerun方式持续采集图像 
		KSJ_TRIGGER_LOWLEVEL        ///< 低电平，外触发信号处于低电平的时候，相机将会以Freerun方式持续采集图像
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerMethodSet
	/// @brief     设置外触发的触发条件
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     TriggerMethod [in] 设置外触发模式时,触发的条件，请参看KSJ_TRIGGERMETHOD的说明
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodSet(int nIndex, KSJ_TRIGGERMETHOD  TriggerMethod);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerMethodGet
	/// @brief     得到当前相机设置的外触发条件
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pTriggerMethod [out] 得到当前相机设置的外触发条件
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodGet(int nIndex, KSJ_TRIGGERMETHOD *pTriggerMethod);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerDelayGetRange
	/// @brief     获取外触发延时的时间范围，计数步长为100uS，也就是获取的值乘以100us为实际的时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wMin [out] 外触发延时的最小设置值，这个值乘以100us为实际的时间
	/// @param     wMax [out] 外触发延时的最大设置值，这个值乘以100us为实际的时间
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用；表示相机收到外触发信号之后，会延迟这个设定的时间再从Sensor采集图像
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerDelaySet
	/// @brief     设置外触发延时时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wDelay [in] 设置延时时间，这个值乘以100us为实际的时间
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelaySet(int nIndex, unsigned short wDelay);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerDelayGet
	/// @brief     获取用户设置的外触发延时时间，单位为100us
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pwDelay [out] 获取的外触发延时时间，单位为100us
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGet(int nIndex, unsigned short *pwDelay);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureSetTimeOut
	/// @brief     设置超时时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     dwTimeOut [in] 设置超时时间,单位为毫秒
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用；设置采集图像（KSJ_CaptureRgbData等）的超时时间，外触发时，这个时间最好大于外触发可能的最大时间间隔
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetTimeOut(int nIndex, unsigned long dwTimeOut);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetTimeOut
	/// @brief     获取超时时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pdwTimeOut [out] 获取读取一帧图像的超时时间，单位为毫秒
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetTimeOut(int nIndex, unsigned long *pdwTimeOut);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_TriggerSignalPeriodGetRange
    /// @brief     获取外触发分频范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fMin [out] 分频的最小值，目前为1
	/// @param     fMax [out] 分频的最大值
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGetRange(int nIndex, float * fMin, float *fMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_TriggerSignalPeriodSet
    /// @brief     设置外触发分频
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fPeriodCount [in] 设置外触发分频值，目前仅整数有效，最小值为1
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
    ///           \li 相机将会根据这个设置值决定几个外触发信号触发采集一帧图像：比如设置成2，那么两个外触发信号采集一帧图像。
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodSet(int nIndex, float fPeriodCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_TriggerSignalPeriodGet
    /// @brief     获取外触发分频
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfPeriodCount [out] 当前的外触发分频值
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGet(int nIndex, float* pfPeriodCount);

	/// 相机开始结束采集工作控制模式
	enum KSJ_STARTENDMODE
	{
		KSJ_SEMODE_CONTINUE,	///< 相机一直处于开始状态，随时等待图像触发信号并采集图像
		KSJ_SEMODE_RISINGEDGE,	///< 上升沿作为开始信号，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
		KSJ_SEMODE_FALLINGEDGE, ///< 下降沿作为开始信号，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
		KSJ_SEMODE_HIGHLEVEL,	///< 高电平有效，高电平的时候相机开始进入采集图像状态
		KSJ_SEMODE_LOWLEVEL,	///< 低电平有效，低电平的时候相机开始进入采集图像状态
		KSJ_SEMODE_SOFTWARE,	///< 软件控制相机的开始结束采集工作，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_StartEndModeSet
    /// @brief     设置相机开始结束采集工作的控制模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     SeMode [in] 相机开始结束采集工作的控制模式，请参考KSJ_STARTENDMODE的定义
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeSet(int nIndex, KSJ_STARTENDMODE SeMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_StartEndModeGet
    /// @brief     获得相机开始结束采集工作的控制模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pSeMode [out] 当前相机开始结束采集工作的控制模式
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeGet(int nIndex, KSJ_STARTENDMODE* pSeMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartDelayGetRange
    /// @brief     获取相机开始延时设置范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     wMin [out] 相机开始最小延迟
	/// @param     wMax [out] 相机开始最大延迟
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartDelaySet
    /// @brief     设置相机开始延时
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wDelay [in] 相机开始延迟值，单位为信号数
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelaySet(int nIndex, unsigned short wDelay);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartDelayGet
    /// @brief     获取相机开始延时
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pwDelay [out] 当前相机开始延迟值，单位为信号数
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGet(int nIndex, unsigned short *pwDelay);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartFilterRange
    /// @brief     获取相机开始结束信号滤波范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     wMin [out] 最小滤波值，单位：微秒
	/// @param     wMax [out] 最大滤波值，单位：微秒
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartFilterSet
    /// @brief     设置相机开始结束信号滤波
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wFilter [in] 信号滤波值，单位：微秒
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterSet(int nIndex, unsigned short wFilter);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartFilterGet
    /// @brief     获取相机开始结束信号滤波
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pwFilter [out] 当前信号滤波值，单位：微秒
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterGet(int nIndex, unsigned short *pwFilter);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureMultiLineRange
    /// @brief     获取帧数量设置范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     wMin [out] 最小帧数量
	/// @param     wMax [out] 最大帧数量
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureMultiLineSet
    /// @brief     设置采集帧数量
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wMultiLine [in] 设置的采集帧数量
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineSet(int nIndex, unsigned short wMultiLine);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureMultiLineGet
    /// @brief     设置采集帧数量
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pwMultiLine [out] 当前设置的采集帧数量
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineGet(int nIndex, unsigned short *pwMultiLine);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureSoftwareStart
    /// @brief     软件控制相机开始采集工作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
    ///          \li 相机开启结束模式设置为KSJ_SEMODE_SOFTWARE的时候，该函数有效，执行该函数以后，相机进入采集模式，直到采集足够MultiLine之后结束.
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSoftwareStart(int nIndex);

#ifdef __cplusplus
}
#endif

#endif