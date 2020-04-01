#ifndef __KSJ_API_IO_H__
#define __KSJ_API_IO_H__

// #pragma message("Include KSJApiIo.h") 

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

	enum KSJ_SNAPBUTTONSTATUS //Snap功能引脚状态
	{ 
		KSJ_UP, 	//按键处于闭合状态
		KSJ_DOWN 	//按键处于开启状态
	};

	//-----------------------------------------------------------------------------
	// 函数：KSJ_SnapButtonStatus
	// 功能：读取Snap功能引脚状态
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pSnapButtonStatus：输出，返回Snap功能引脚状态, KSJ_SNAPBUTTONSTATUS类型
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SnapButtonStatus( int nChannel, KSJ_SNAPBUTTONSTATUS *pSnapButtonStatus );

	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioSetDirection
	// 功能：设置IO为输入或输出
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       btDirection：输入，按位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3，最多支持到BIT7
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioSetDirection( int nChannel, unsigned char btDirection );
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioGetDirection
	// 功能：设置IO为输入或输出
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pbtDirection：输出，返回IO是输入还是输出，按位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3，最多支持到BIT7
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioGetDirection( int nChannel, unsigned char *pbtDirection );

	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioSetStatus
	// 功能：对于输出引脚设置输出状态
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       btGpioStatus：输入，控制IO引脚输出状态，按位寻址
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioSetStatus   ( int nChannel, unsigned char btGpioStatus );
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioGetStatus
	// 功能：读取输入IO引脚状态
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pbtGpioStatus：输出，读取IO引脚输入状态，只有通过KSJ_GpioSetDirection 函数设置btDirection相应位设置为0的引脚才能通过此函数读取引脚输入状态
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioGetStatus   ( int nChannel, unsigned char *pbtGpioStatus );

	//-----------------------------------------------------------------------------
	// 函数：KSJ_FlashControlSet
	// 功能：设置闪光灯
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       bEnable：输入，是否使能闪光灯，true开启，false关闭
	//       bInvert：输入，是否翻转闪光灯信号
	//       nMode：输入，闪光灯模式，暂不支持
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashControlSet(int nChannel, bool bEnable, bool bInvert, int nMode);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_FlashControlGet
	// 功能：获取闪光灯状态
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pbEnable：输出，返回是否使能闪光灯，true开启，false关闭
	//       pbInvert：输出，返回是否闪光灯信号翻转
	//       pnMode：输出，返回闪光灯模式，暂不支持
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashControlGet(int nChannel, bool *pbEnable, bool *pbInvert, int *pnMode);

	//-----------------------------------------------------------------------------
	// 函数：KSJ_FlashEnableSet
	// 功能：设置闪光灯使能
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       bEnable：输入，是否使能闪光灯，true开启，false关闭
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashEnableSet(int nChannel, bool bEnable);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_FlashEnableGet
	// 功能：获取闪光灯使能
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pbEnable：输出，返回是否使能闪光灯，true开启，false关闭
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashEnableGet(int nChannel, bool *pbEnable);

	//-----------------------------------------------------------------------------
	// 函数：KSJ_FlashInvertSet
	// 功能：设置闪光灯信号翻转
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       bInvert：输入，是否翻转闪光灯信号
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashInvertSet(int nChannel, bool bInvert);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_FlashInvertGet
	// 功能：获取闪光灯信号翻转
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pbInvert：输出，返回是否闪光灯信号翻转
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashInvertGet(int nChannel, bool *pbInvert);

	enum KSJ_FLASHMODE//闪光灯模式（暂不支持）
	{
		KSJ_FM_TROW,
		KSJ_FM_SIMULTANEOUSEXPOSURE,
		KSJ_FM_SHUTTERWIDTH
	};
	KSJ_API  int __stdcall KSJ_FlashSetMode(int nChannel, KSJ_FLASHMODE FlashMode);//设置闪光灯模式（暂不支持）
	KSJ_API  int __stdcall KSJ_FlashGetMode(int nChannel, KSJ_FLASHMODE *pFlashMode);//获取闪光灯模式（暂不支持）

	// 如下函数只适用于YYO型号相机(帧存带光耦)
	// 通过查询功能调用如下函数
	// 注意：在外触发模式下，不可以设置为KSJ_GPIOIN_NORMAL，必须切换到非外触发模式时设置。
	// 在用户调用设置为外触发模式时，自动设置为KSJ_GPIOIN_EXTERNALTRIGGER。
	// KSJ_QueryFunction (KSJ_SUPPORT_GPIO_NORMAL)
	// When call KSJ_GpioSetDirection(, bit0 = 0 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_NORMAL)
	// When call KSJ_GpioSetDirection(, bit0 = 1 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_EXTERNALTRIGGER)
	enum KSJ_GPIOIN_MODE //外触发输入引脚工作模式
	{ 
		KSJ_GPIOIN_EXTERNALTRIGGER, //作为外触发引脚（默认）
		KSJ_GPIOIN_NORMAL			//作为普通输入引脚（同时也可以作为Snap功能引脚使用）
	};
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioInModeSet
	// 功能：设置外触发输入引脚的工作模式
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       GpioInMode：输入，设置外触发引脚的工作模式
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInModeSet(int nChannel, KSJ_GPIOIN_MODE GpioInMode);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioInModeGet
	// 功能：读取外触发输入引脚的工作模式
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pGpioInMode：输出，外触发引脚的当前工作模式
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInModeGet(int nChannel, KSJ_GPIOIN_MODE *pGpioInMode);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioInStatusGet
	// 功能：当外触发输入引脚作为KSJ_GPIOIN_NORMAL时，可以通过此函数进行读取输入状态
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pbtValue：输出，外触发引脚的当前工作模式
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInStatusGet(int nChannel, unsigned char *pbtValue);

	// 通过查询KSJ_SUPPORT_GPIO_NORMAL功能调用如下函数
	// When call KSJ_GpioSetDirection(, bit1 = 1 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_FLASH)
	// When call KSJ_GpioSetDirection(, bit1 = 0 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_NORMAL)
	// 
	enum KSJ_GPIOOUT_MODE	//闪光灯输出引脚工作模式
	{ 
		KSJ_GPIOOUT_FLASH, 	//作为闪光灯输出引脚（默认）
		KSJ_GPIOOUT_NORMAL 	//作为普通输出引脚，可以通过KSJ_GpioOutStatusSet或KSJ_GpioSetStatus函数控制
	};
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioOutModeSet
	// 功能：设置闪光灯输出引脚的工作模式
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       GpioOutMode：输入，设置闪光灯输入引脚的工作模式
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutModeSet(int nChannel, KSJ_GPIOOUT_MODE GpioOutMode);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioOutModeGet
	// 功能：获取当前IO的输出模式
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pGpioOutMode：输出，获取闪光灯输入引脚的工作模式
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutModeGet(int nChannel, KSJ_GPIOOUT_MODE *pGpioOutMode);

	// 注意：只有在KSJ_NORMAL_OUT模式下，才可以设置。
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioOutStatusSet
	// 功能：设置闪光灯输入引脚作为普通IO输出时的状态
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       btValue：输入，设置闪光灯输入引脚作为普通IO输出时的状态，按位寻址，bit0表示设置的输出状态，0为低电平，1为高电平
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutStatusSet(int nChannel, unsigned char btValue);

	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioFilterSet
	// 功能：设置外触发输入的滤波时长（微秒）
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       wFilterTimeUs：输入，设置滤波时长，当为0时，默认200ns滤波
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioFilterSet(int nChannel, unsigned short wFilterTimeUs);
	
	//-----------------------------------------------------------------------------
	// 函数：KSJ_GpioFilterGet
	// 功能：读取外触发输入的滤波时长
	// 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	//       pwFilterTimeUs：输出，返回滤波时长，当为0时，默认200ns滤波
	// 返回：参考返回状态码（KSJCode.H）
	// 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioFilterGet(int nChannel, unsigned short *pwFilterTimeUs);



#ifdef __cplusplus
}
#endif


#endif