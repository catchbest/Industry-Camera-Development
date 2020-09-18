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
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     设置IO为输入或输出
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     btDirection [in] 按位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3，最多支持到BIT7
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioSetDirection( int nIndex, unsigned char btDirection );
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     设置IO为输入或输出
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbtDirection [out] 返回IO是输入还是[out] 按位寻址，BIT0对应GPIO0, BIT1对应GPIO1, BIT2对应GPIO2, BIT3对应GPIO3，最多支持到BIT7
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioGetDirection( int nIndex, unsigned char *pbtDirection );

	///-----------------------------------------------------------------------------
	///
	/// @brief     对于输出引脚设置输出状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     btGpioStatus [in] 控制IO引脚输出状态，按位寻址
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioSetStatus( int nIndex, unsigned char btGpioStatus );
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     读取输入IO引脚状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbtGpioStatus [out] 读取IO引脚输入状态，只有通过KSJ_GpioSetDirection 函数设置btDirection相应位设置为0的引脚才能通过此函数读取引脚输入状态
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioGetStatus( int nIndex, unsigned char *pbtGpioStatus );

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置闪光灯
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] 是否使能闪光灯，true开启，false关闭
	/// @param     bInvert [in] 是否翻转闪光灯信号
	/// @param     nMode [in] 闪光灯模式，暂不支持
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashControlSet(int nIndex, bool bEnable, bool bInvert, int nMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     获取闪光灯状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] 返回是否使能闪光灯，true开启，false关闭
	/// @param     pbInvert [out] 返回是否闪光灯信号翻转
	/// @param     pnMode [out] 返回闪光灯模式，暂不支持
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashControlGet(int nIndex, bool *pbEnable, bool *pbInvert, int *pnMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置闪光灯使能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] 是否使能闪光灯，true开启，false关闭
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashEnableSet(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     获取闪光灯使能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] 返回是否使能闪光灯，true开启，false关闭
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashEnableGet(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置闪光灯信号翻转
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bInvert [in] 是否翻转闪光灯信号
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashInvertSet(int nIndex, bool bInvert);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     获取闪光灯信号翻转
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbInvert [out] 返回是否闪光灯信号翻转
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_FlashInvertGet(int nIndex, bool *pbInvert);

	/// 如下函数只适用于YYO型号相机(帧存带光耦)
	/// 通过查询功能调用如下函数
	/// 注意：在外触发模式下，不可以设置为KSJ_GPIOIN_NORMAL，必须切换到非外触发模式时设置。
	/// 在用户调用设置为外触发模式时，自动设置为KSJ_GPIOIN_EXTERNALTRIGGER。
	/// KSJ_QueryFunction (KSJ_SUPPORT_GPIO_NORMAL)
	/// When call KSJ_GpioSetDirection(, bit0 = 0 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_NORMAL)
	/// When call KSJ_GpioSetDirection(, bit0 = 1 ) == KSJ_GpioInModeSet(, KSJ_GPIOIN_EXTERNALTRIGGER)
	enum KSJ_GPIOIN_MODE ///外触发输入引脚工作模式
	{ 
		KSJ_GPIOIN_EXTERNALTRIGGER, ///作为外触发引脚（默认）
		KSJ_GPIOIN_NORMAL			///作为普通输入引脚（同时也可以作为Snap功能引脚使用）
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     设置外触发输入引脚的工作模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     GpioInMode [in] 设置外触发引脚的工作模式
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInModeSet(int nIndex, KSJ_GPIOIN_MODE GpioInMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     读取外触发输入引脚的工作模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pGpioInMode [out] 外触发引脚的当前工作模式
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInModeGet(int nIndex, KSJ_GPIOIN_MODE *pGpioInMode);
	
	///-----------------------------------------------------------------------------
	/// @brief     当外触发输入引脚作为KSJ_GPIOIN_NORMAL时，可以通过此函数进行读取输入状态
	/// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbtValue [out] 外触发引脚的当前工作模式
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioInStatusGet(int nIndex, unsigned char *pbtValue);

	/// 通过查询KSJ_SUPPORT_GPIO_NORMAL功能调用如下函数
	/// When call KSJ_GpioSetDirection(, bit1 = 1 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_FLASH)
	/// When call KSJ_GpioSetDirection(, bit1 = 0 ) == KSJ_GpioOutModeSet(, KSJ_GPIOOUT_NORMAL)
	/// 
	enum KSJ_GPIOOUT_MODE	///闪光灯输出引脚工作模式
	{ 
		KSJ_GPIOOUT_FLASH, 	///作为闪光灯输出引脚（默认）
		KSJ_GPIOOUT_NORMAL 	///作为普通输出引脚，可以通过KSJ_GpioOutStatusSet或KSJ_GpioSetStatus函数控制
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     设置闪光灯输出引脚的工作模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     GpioOutMode [in] 设置闪光灯输入引脚的工作模式
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutModeSet(int nIndex, KSJ_GPIOOUT_MODE GpioOutMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     获取当前IO的输出模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pGpioOutMode [out] 获取闪光灯输入引脚的工作模式
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutModeGet(int nIndex, KSJ_GPIOOUT_MODE *pGpioOutMode);

	/// 注意：只有在KSJ_NORMAL_OUT模式下，才可以设置。
	///-----------------------------------------------------------------------------
	///
	/// @brief     设置闪光灯输入引脚作为普通IO输出时的状态
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     btValue [in] 设置闪光灯输入引脚作为普通IO输出时的状态，按位寻址，bit0表示设置的输出状态，0为低电平，1为高电平
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioOutStatusSet(int nIndex, unsigned char btValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     设置外触发输入的滤波时长（微秒）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     wFilterTimeUs [in] 设置滤波时长，当为0时，默认200ns滤波
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioFilterSet(int nIndex, unsigned short wFilterTimeUs);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     读取外触发输入的滤波时长
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pwFilterTimeUs [out] 返回滤波时长，当为0时，默认200ns滤波
	/// @return    参考返回状态码（KSJCode.H）
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GpioFilterGet(int nIndex, unsigned short *pwFilterTimeUs);



#ifdef __cplusplus
}
#endif


#endif