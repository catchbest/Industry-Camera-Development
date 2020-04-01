#ifndef __KSJ_API_BAYER_H__
#define __KSJ_API_BAYER_H__

// #pragma message("Include KSJApiBayer.h") 

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

	enum KSJ_BAYERMODE //贝尔模式
	{
		KSJ_BGGR_BGR24 = 0, 
		KSJ_GRBG_BGR24, 
		KSJ_RGGB_BGR24,
		KSJ_GBRG_BGR24,
		KSJ_BGGR_BGR24_FLIP, 
		KSJ_GRBG_BGR24_FLIP, 
		KSJ_RGGB_BGR24_FLIP, 
		KSJ_GBRG_BGR24_FLIP,
		KSJ_BGGR_BGR32, 
		KSJ_GRBG_BGR32,
		KSJ_RGGB_BGR32,
		KSJ_GBRG_BGR32, 
		KSJ_BGGR_BGR32_FLIP, 
		KSJ_GRBG_BGR32_FLIP, 
		KSJ_RGGB_BGR32_FLIP, 
		KSJ_GBRG_BGR32_FLIP,
		KSJ_BGGR_GRAY8, 
		KSJ_GRBG_GRAY8, 
		KSJ_RGGB_GRAY8, 
		KSJ_GBRG_GRAY8, 
		KSJ_BGGR_GRAY8_FLIP, 
		KSJ_GRBG_GRAY8_FLIP,
		KSJ_RGGB_GRAY8_FLIP, 
		KSJ_GBRG_GRAY8_FLIP
	};

	//-----------------------------------------------------------------------------
    // 函数：KSJ_BayerGetDefaultMode
    // 功能：得到当前相机的默认Bayer模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pBayerMode：输出，返回默认的Bayer模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetDefaultMode(int nChannel, KSJ_BAYERMODE *pBayerMode);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_BayerSetMode
    // 功能：设置Bayer模式，同时影响采集和预览
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       BayerMode：输入，设置的贝尔模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerSetMode(int nChannel, KSJ_BAYERMODE BayerMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_BayerGetMode
    // 功能：得到当前相机的Bayer模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pBayerMode：输出，返回的Bayer模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetMode(int nChannel, KSJ_BAYERMODE *pBayerMode);

	enum KSJ_FILTERMODE//贝尔滤波模式
	{
		KSJ_NEARESTNEIGHBOR,
		KSJ_BILINEAR,
		KSJ_SMOOTHHUE,
		KSJ_EDGESENSING,
		KSJ_LAPLACIAN,
		KSJ_FASTBILINEAR
	};

	//-----------------------------------------------------------------------------
    // 函数：KSJ_FilterSetMode
    // 功能：设置贝尔滤波模式，同时影响采集和预览
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       FilterMode：输入，设置的贝尔滤波模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterSetMode(int nChannel, KSJ_FILTERMODE FilterMode);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_FilterGetMode
    // 功能：得到当前相机的Bayer模式
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pFilterMode：输出，返回的贝尔滤波模式
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterGetMode(int nChannel, KSJ_FILTERMODE *pFilterMode);

#ifdef __cplusplus
}
#endif

#endif
