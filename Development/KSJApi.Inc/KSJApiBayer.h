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

	enum KSJ_BAYERMODE ///贝尔模式
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

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_BayerGetDefaultMode
    /// @brief     得到当前相机的默认Bayer模式
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pBayerMode [out] 返回默认的Bayer模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetDefaultMode(int nIndex, KSJ_BAYERMODE *pBayerMode);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_BayerSetMode
    /// @brief     设置Bayer模式，同时影响采集和预览
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     BayerMode [in] 设置的贝尔模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerSetMode(int nIndex, KSJ_BAYERMODE BayerMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_BayerGetMode
    /// @brief     得到当前相机的Bayer模式
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pBayerMode [out] 返回的Bayer模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetMode(int nIndex, KSJ_BAYERMODE *pBayerMode);

	enum KSJ_FILTERMODE//贝尔滤波模式
	{
		KSJ_NEARESTNEIGHBOR,
		KSJ_BILINEAR,
		KSJ_SMOOTHHUE,
		KSJ_EDGESENSING,
		KSJ_LAPLACIAN,
		KSJ_FASTBILINEAR
	};

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_FilterSetMode
    /// @brief     设置贝尔滤波模式，同时影响采集和预览
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     FilterMode [in] 设置的贝尔滤波模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterSetMode(int nIndex, KSJ_FILTERMODE FilterMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_FilterGetMode
    /// @brief     得到当前相机的Bayer模式
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pFilterMode [out] 返回的贝尔滤波模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterGetMode(int nIndex, KSJ_FILTERMODE *pFilterMode);

#ifdef __cplusplus
}
#endif

#endif
