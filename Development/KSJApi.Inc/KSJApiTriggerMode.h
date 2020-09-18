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

	enum KSJ_TRIGGERMODE//凯视佳工业相机触发工作模式
	{
		KSJ_TRIGGER_INTERNAL,
		KSJ_TRIGGER_EXTERNAL,
		KSJ_TRIGGER_SOFTWARE,
		KSJ_TRIGGER_FIXFRAMERATE,
		KSJ_TRIGGER_HIGHLOWFIXFRAMERATE
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置相机工作模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     TriggerMode [in] 需要设置的相机工作模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeSet(int nIndex, KSJ_TRIGGERMODE TriggerMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取当前相机的触发工作模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     TriggerMode [out] 得到当前相机的工作模式，请参考KSJ_TRIGGERMODE的说明
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeGet(int nIndex, KSJ_TRIGGERMODE *pTriggerMode);

	enum KSJ_TRIGGERSTATUS//相机帧存的状态
	{
		KSJ_NO,
		KSJ_HAVE
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     读取相机缓存状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pTriggerStatus [out] 得到当前相机的板级缓存中是否有图像数据可供读取
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerStatusGet(int nIndex, KSJ_TRIGGERSTATUS *pTriggerStatus);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     清空帧存中的数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_EmptyFrameBuffer(int nIndex);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     清空帧存后采集一帧原始或黑白图像数据
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRawData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize函数获得
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawDataAfterEmptyFrameBuffer(int nIndex, unsigned char *pRawData);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureRgbDataAfterEmptyFrameBuffer
    /// @brief     清空帧存后采集一帧8位原始或灰度图像或24，32位彩色数据图像
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     清空帧存后采集一帧8位原始或灰度图像或24，32位彩色数据图像
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pRgbData [out] 由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
	/// @param     pnWidth [out] 返回图像的宽度（像素）
    /// @param     pnHeight [out] 返回图像的高度（像素）
    /// @param     pnBitCount [out] 返回图像的每个像素位数（8，24或32），由KSJ_PreviewSetMode和KSJ_BayerSetMode的设置影响
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataExAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机的固定帧率设置范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfRateMin [out] 固定帧率能够设置的最小值
	/// @param     pfRateMax [out] 固定帧率能够设置的最大值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateRang(int nIndex, float* pfRateMin, float* pfRateMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     当相机设置为固定帧率触发模式或者高低电平有效固定帧率触发模式时,设置相机的固定帧率
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fFrameRate [in] 设置固定帧率（帧每秒）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFixedFrameRateEx(int nIndex, float fFrameRate);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到当前固定帧速的状态信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pfFrameRate [out] 得到当前设置的固定帧率（帧每秒）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateEx(int nIndex, float *pfFrameRate);

	enum KSJ_TRIGGERMETHOD//外触发的触发条件
	{
		KSJ_TRIGGER_FALLINGEDGE,
		KSJ_TRIGGER_RISINGEDGE,
		KSJ_TRIGGER_HIGHLEVEL,
		KSJ_TRIGGER_LOWLEVEL
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置外触发的触发条件
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     TriggerMethod [in] 设置外触发模式时,触发的条件，请参看KSJ_TRIGGERMETHOD的说明
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodSet(int nIndex, KSJ_TRIGGERMETHOD  TriggerMethod);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     得到当前相机设置的外触发条件
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pTriggerMethod [out] 得到当前相机设置的外触发条件
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodGet(int nIndex, KSJ_TRIGGERMETHOD *pTriggerMethod);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取外触发延时的时间范围，计数步长为100uS，也就是获取的值乘以100us为实际的时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     wMin [out] 外触发延时的最小设置值，这个值乘以100us为实际的时间
	/// @param     wMax [out] 外触发延时的最大设置值，这个值乘以100us为实际的时间
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置外触发的触发条件
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     wDelay [in] 设置延时时间，这个值乘以100us为实际的时间
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelaySet(int nIndex, unsigned short wDelay);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取用户设置的外触发延时时间，单位为100us
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pwDelay [out] 获取的外触发延时时间，单位为100us
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGet(int nIndex, unsigned short *pwDelay);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置超时时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     dwTimeOut [in] 设置超时时间,单位为毫秒
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetTimeOut(int nIndex, unsigned long dwTimeOut);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取超时时间
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pdwTimeOut [out] 获取读取一帧图像的超时时间，单位为毫秒
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetTimeOut(int nIndex, unsigned long *pdwTimeOut);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取外触发分频范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     fMin [out] 分频的最小值，目前为1
	/// @param     fMax [out] 分频的最大值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGetRange(int nIndex, float * fMin, float *fMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置外触发分频
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     fPeriodCount [in] 设置外触发分频值，目前仅整数有效，最小值为1
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodSet(int nIndex, float fPeriodCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取外触发分频
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pfPeriodCount [out] 当前的外触发分频值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGet(int nIndex, float* pfPeriodCount);

	enum KSJ_STARTENDMODE//相机开始结束采集工作控制模式
	{
		KSJ_SEMODE_CONTINUE,	///相机一直处于开始状态，随时等待图像触发信号并采集图像
		KSJ_SEMODE_RISINGEDGE,	///上升沿作为开始信号，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
		KSJ_SEMODE_FALLINGEDGE, ///下降沿作为开始信号，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
		KSJ_SEMODE_HIGHLEVEL,	///高电平有效，高电平的时候相机开始进入采集图像状态
		KSJ_SEMODE_LOWLEVEL,	///低电平有效，低电平的时候相机开始进入采集图像状态
		KSJ_SEMODE_SOFTWARE,	///软件控制相机的开始结束采集工作，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置相机开始结束采集工作的控制模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     SeMode [in] 相机开始结束采集工作的控制模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeSet(int nIndex, KSJ_STARTENDMODE SeMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获得相机开始结束采集工作的控制模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pSeMode [out] 当前相机开始结束采集工作的控制模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeGet(int nIndex, KSJ_STARTENDMODE* pSeMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机开始延时设置范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     wMin [out] 相机开始最小延迟
	/// @param     wMax [out] 相机开始最大延迟
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置相机开始延时
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wDelay [in] 相机开始延迟值，单位为信号数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelaySet(int nIndex, unsigned short wDelay);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机开始延时
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pwDelay [out] 当前相机开始延迟值，单位为信号数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGet(int nIndex, unsigned short *pwDelay);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机开始结束信号滤波范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     wMin [out] 最小滤波值，单位：微秒
	/// @param     wMax [out] 最大滤波值，单位：微秒
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置相机开始结束信号滤波
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wFilter [in] 信号滤波值，单位：微秒
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterSet(int nIndex, unsigned short wFilter);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机开始结束信号滤波
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pwFilter [out] 当前信号滤波值，单位：微秒
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterGet(int nIndex, unsigned short *pwFilter);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取帧数量设置范围
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     wMin [out] 最小帧数量
	/// @param     wMax [out] 最大帧数量
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置采集帧数量
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wMultiLine [in] 设置的采集帧数量
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineSet(int nIndex, unsigned short wMultiLine);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置采集帧数量
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pwMultiLine [out] 当前设置的采集帧数量
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineGet(int nIndex, unsigned short *pwMultiLine);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     软件控制相机开始采集工作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSoftwareStart(int nIndex);

#ifdef __cplusplus
}
#endif

#endif