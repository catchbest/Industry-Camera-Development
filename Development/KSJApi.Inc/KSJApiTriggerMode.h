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

	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerModeSet
    // 功能：设置相机工作模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       TriggerMode：输入，需要设置的相机工作模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeSet(int nChannel, KSJ_TRIGGERMODE TriggerMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerModeGet
    // 功能：获取当前相机的触发工作模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       TriggerMode：输出，得到当前相机的工作模式，请参考KSJ_TRIGGERMODE的说明
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeGet(int nChannel, KSJ_TRIGGERMODE *pTriggerMode);

	enum KSJ_TRIGGERSTATUS//相机帧存的状态
	{
		KSJ_NO,
		KSJ_HAVE
	};

	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerStatusGet
    // 功能：读取相机缓存状态
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pTriggerStatus：输出，得到当前相机的板级缓存中是否有图像数据可供读取
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerStatusGet(int nChannel, KSJ_TRIGGERSTATUS *pTriggerStatus);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_EmptyFrameBuffer
    // 功能：清空帧存中的数据
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_EmptyFrameBuffer(int nChannel);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureRawDataAfterEmptyFrameBuffer
    // 功能：清空帧存后采集一帧原始或黑白图像数据
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pRawData： 输出，由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSize函数获得
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	KSJ_API  int __stdcall KSJ_CaptureRawDataAfterEmptyFrameBuffer(int nChannel, unsigned char *pRawData);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureRgbDataAfterEmptyFrameBuffer
    // 功能：清空帧存后采集一帧8位原始或灰度图像或24，32位彩色数据图像
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pRgbData： 输出，由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataAfterEmptyFrameBuffer(int nChannel, unsigned char *pRgbData);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureRgbDataExAfterEmptyFrameBuffer
    // 功能：清空帧存后采集一帧8位原始或灰度图像或24，32位彩色数据图像
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pRgbData： 输出，由用户分配内存空间，用于保存采集数据，采集图像的像素尺寸可以通过KSJ_CaptureGetSizeEx函数获得
	//       pnWidth： 输出，返回图像的宽度（像素）
    //       pnHeight：输出，返回图像的高度（像素）
    //       pnBitCount：输出，返回图像的每个像素位数（8，24或32），由KSJ_PreviewSetMode和KSJ_BayerSetMode的设置影响
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataExAfterEmptyFrameBuffer(int nChannel, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_GetFixedFrameRateRang
    // 功能：获取相机的固定帧率设置范围
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pfRateMin：输出，固定帧率能够设置的最小值
	//       pfRateMax：输出，固定帧率能够设置的最大值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateRang(int nChannel, float* pfRateMin, float* pfRateMax);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_SetFixedFrameRateEx
    // 功能：当相机设置为固定帧率触发模式或者高低电平有效固定帧率触发模式时,设置相机的固定帧率
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       fFrameRate：输入，设置固定帧率（帧每秒）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFixedFrameRateEx(int nChannel, float fFrameRate);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_GetFixedFrameRateEx
    // 功能：得到当前固定帧速的状态信息
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pfFrameRate：输出，得到当前设置的固定帧率（帧每秒）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateEx(int nChannel, float *pfFrameRate);

	enum KSJ_TRIGGERMETHOD//外触发的触发条件
	{
		KSJ_TRIGGER_FALLINGEDGE,
		KSJ_TRIGGER_RISINGEDGE,
		KSJ_TRIGGER_HIGHLEVEL,
		KSJ_TRIGGER_LOWLEVEL
	};
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerMethodSet
    // 功能：设置外触发的触发条件
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       TriggerMethod：输入，设置外触发模式时,触发的条件，请参看KSJ_TRIGGERMETHOD的说明
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodSet(int nChannel, KSJ_TRIGGERMETHOD  TriggerMethod);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerMethodGet
    // 功能：得到当前相机设置的外触发条件
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pTriggerMethod：输出，得到当前相机设置的外触发条件
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodGet(int nChannel, KSJ_TRIGGERMETHOD *pTriggerMethod);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerDelayGetRange
    // 功能：获取外触发延时的时间范围，计数步长为100uS，也就是获取的值乘以100us为实际的时间
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       wMin：输出，外触发延时的最小设置值，这个值乘以100us为实际的时间
	//       wMax：输出，外触发延时的最大设置值，这个值乘以100us为实际的时间
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGetRange(int nChannel, unsigned short *wMin, unsigned short *wMax);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerDelaySet
    // 功能：设置外触发的触发条件
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       wDelay：输入，设置延时时间，这个值乘以100us为实际的时间
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelaySet(int nChannel, unsigned short wDelay);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerDelayGet
    // 功能：获取用户设置的外触发延时时间，单位为100us
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pwDelay：输出，获取的外触发延时时间，单位为100us
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGet(int nChannel, unsigned short *pwDelay);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureSetTimeOut
    // 功能：设置超时时间
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       dwTimeOut：输入，设置超时时间,单位为毫秒
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetTimeOut(int nChannel, unsigned long dwTimeOut);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureGetTimeOut
    // 功能：获取超时时间
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pdwTimeOut：输出，获取读取一帧图像的超时时间，单位为毫秒
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetTimeOut(int nChannel, unsigned long *pdwTimeOut);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureSetRecover
    // 功能：是否读取超时后恢复设备
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bRecover：输入，读取超时后是否恢复设备,true恢复,false不恢复
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetRecover(int nChannel, bool bRecover);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureGetRecover
    // 功能：获取当前关于超时恢复的设置
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbRecover：输出，获取设置读取超时后是否恢复设备,true恢复,false不恢复
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetRecover(int nChannel, bool *pbRecover);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureSetTimeOutEx
    // 功能：同时设置超时时间及超时后是否恢复设备
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       dwTimeOut：输入，设置超时时间,单位为毫秒
    //       bRecover：输入，读取超时后是否恢复设备,true恢复,false不恢复
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetTimeOutEx(int nChannel, unsigned long dwTimeOut, bool bRecover);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureGetTimeOutEx
    // 功能：获取关于超时和恢复的设置
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pdwTimeOut：输出，获取读取一帧图像的超时时间，单位为毫秒
    //       pbRecover：输出，获取设置读取超时后是否恢复设备,true恢复,false不恢复
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetTimeOutEx(int nChannel, unsigned long *pdwTimeOut, bool *pbRecover);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerSignalPeriodGetRange
    // 功能：获取外触发分频范围
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       fMin：输出，分频的最小值，目前为1
	//       fMax：输出，分频的最大值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGetRange(int nChannel, float * fMin, float *fMax);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerSignalPeriodSet
    // 功能：设置外触发分频
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       fPeriodCount：输入，设置外触发分频值，目前仅整数有效，最小值为1
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodSet(int nChannel, float fPeriodCount);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_TriggerSignalPeriodGet
    // 功能：获取外触发分频
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pfPeriodCount：输出，当前的外触发分频值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGet(int nChannel, float* pfPeriodCount);

	enum KSJ_STARTENDMODE//相机开始结束采集工作控制模式
	{
		KSJ_SEMODE_CONTINUE,	//相机一直处于开始状态，随时等待图像触发信号并采集图像
		KSJ_SEMODE_RISINGEDGE,	//上升沿作为开始信号，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
		KSJ_SEMODE_FALLINGEDGE, //下降沿作为开始信号，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
		KSJ_SEMODE_HIGHLEVEL,	//高电平有效，高电平的时候相机开始进入采集图像状态
		KSJ_SEMODE_LOWLEVEL,	//低电平有效，低电平的时候相机开始进入采集图像状态
		KSJ_SEMODE_SOFTWARE,	//软件控制相机的开始结束采集工作，采集固定帧数后停止（由KSJ_CaptureMultiLineSet函数设定）
	};
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_StartEndModeSet
    // 功能：设置相机开始结束采集工作的控制模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       SeMode：输入，相机开始结束采集工作的控制模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeSet(int nChannel, KSJ_STARTENDMODE SeMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_StartEndModeGet
    // 功能：获得相机开始结束采集工作的控制模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pSeMode：输出，当前相机开始结束采集工作的控制模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeGet(int nChannel, KSJ_STARTENDMODE* pSeMode);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureStartDelayGetRange
    // 功能：获取相机开始延时设置范围
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       wMin：输出，相机开始最小延迟
	//       wMax：输出，相机开始最大延迟
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGetRange(int nChannel, unsigned short *wMin, unsigned short *wMax);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureStartDelaySet
    // 功能：设置相机开始延时
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       wDelay：输入，相机开始延迟值，单位为信号数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelaySet(int nChannel, unsigned short wDelay);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureStartDelayGet
    // 功能：获取相机开始延时
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pwDelay：输出，当前相机开始延迟值，单位为信号数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGet(int nChannel, unsigned short *pwDelay);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureStartFilterRange
    // 功能：获取相机开始结束信号滤波范围
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       wMin：输出，最小滤波值，单位：微秒
	//       wMax：输出，最大滤波值，单位：微秒
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterRange(int nChannel, unsigned short *wMin, unsigned short *wMax);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureStartFilterSet
    // 功能：设置相机开始结束信号滤波
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       wFilter：输入，信号滤波值，单位：微秒
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterSet(int nChannel, unsigned short wFilter);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureStartFilterGet
    // 功能：获取相机开始结束信号滤波
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pwFilter：输出，当前信号滤波值，单位：微秒
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterGet(int nChannel, unsigned short *pwFilter);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureMultiLineRange
    // 功能：获取帧数量设置范围
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       wMin：输出，最小帧数量
	//       wMax：输出，最大帧数量
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineRange(int nChannel, unsigned short *wMin, unsigned short *wMax);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureMultiLineSet
    // 功能：设置采集帧数量
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       wMultiLine：输入，设置的采集帧数量
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineSet(int nChannel, unsigned short wMultiLine);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureMultiLineGet
    // 功能：设置采集帧数量
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pwMultiLine：输出，当前设置的采集帧数量
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineGet(int nChannel, unsigned short *pwMultiLine);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_CaptureSoftwareStart
    // 功能：软件控制相机开始采集工作
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSoftwareStart(int nChannel);

#ifdef __cplusplus
}
#endif

#endif