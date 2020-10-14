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

	/// Bayer模式
	enum KSJ_BAYERMODE
	{
		KSJ_BGGR_BGR24 = 0,    ///< BGGR排列Raw图转换成24bit BGR图像
		KSJ_GRBG_BGR24,        ///< GRBG排列Raw图转换成24bit BGR图像
		KSJ_RGGB_BGR24,        ///< RGGB排列Raw图转换成24bit BGR图像
		KSJ_GBRG_BGR24,        ///< GBRG排列Raw图转换成24bit BGR图像
		KSJ_BGGR_BGR24_FLIP,   ///< BGGR排列Raw图转换成24bit BGR图像并做垂直镜像
		KSJ_GRBG_BGR24_FLIP,   ///< GRBG排列Raw图转换成24bit BGR图像并做垂直镜像
		KSJ_RGGB_BGR24_FLIP,   ///< RGGB排列Raw图转换成24bit BGR图像并做垂直镜像
		KSJ_GBRG_BGR24_FLIP,   ///< GBRG排列Raw图转换成24bit BGR图像并做垂直镜像
		KSJ_BGGR_BGR32,        ///< BGGR排列Raw图转换成32bit BGR图像
		KSJ_GRBG_BGR32,        ///< GRBG排列Raw图转换成32bit BGR图像
		KSJ_RGGB_BGR32,        ///< RGGB排列Raw图转换成32bit BGR图像
		KSJ_GBRG_BGR32,        ///< GBRG排列Raw图转换成32bit BGR图像
		KSJ_BGGR_BGR32_FLIP,   ///< BGGR排列Raw图转换成32bit BGR图像并做垂直镜像
		KSJ_GRBG_BGR32_FLIP,   ///< GRBG排列Raw图转换成32bit BGR图像并做垂直镜像
		KSJ_RGGB_BGR32_FLIP,   ///< RGGB排列Raw图转换成32bit BGR图像并做垂直镜像
		KSJ_GBRG_BGR32_FLIP,   ///< GBRG排列Raw图转换成32bit BGR图像并做垂直镜像
		KSJ_BGGR_GRAY8,        ///< BGGR排列Raw图转换成灰度图像
		KSJ_GRBG_GRAY8,        ///< GRBG排列Raw图转换成灰度图像
		KSJ_RGGB_GRAY8,        ///< RGGB排列Raw图转换成灰度图像
		KSJ_GBRG_GRAY8,        ///< GBRG排列Raw图转换成灰度图像
		KSJ_BGGR_GRAY8_FLIP,   ///< BGGR排列Raw图转换成灰度图像并做垂直镜像
		KSJ_GRBG_GRAY8_FLIP,   ///< GRBG排列Raw图转换成灰度图像并做垂直镜像
		KSJ_RGGB_GRAY8_FLIP,   ///< RGGB排列Raw图转换成灰度图像并做垂直镜像
		KSJ_GBRG_GRAY8_FLIP    ///< GBRG排列Raw图转换成灰度图像并做垂直镜像
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BayerGetDefaultMode
	/// @brief     得到当前相机的默认Bayer模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pBayerMode [out] 返回默认的Bayer模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetDefaultMode(int nIndex, KSJ_BAYERMODE *pBayerMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BayerSetMode
	/// @brief     设置Raw图转换RGB图像的Bayer模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     BayerMode [in] 设置的Bayer模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerSetMode(int nIndex, KSJ_BAYERMODE BayerMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BayerGetMode
	/// @brief     得到当前相机的Bayer模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pBayerMode [out] 返回的Bayer模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetMode(int nIndex, KSJ_BAYERMODE *pBayerMode);

	/// Bayer变换的滤波模式 
	enum KSJ_FILTERMODE
	{
		KSJ_NEARESTNEIGHBOR,    ///< 最邻近法
		KSJ_BILINEAR,           ///< 双线性插值法
		KSJ_SMOOTHHUE,          ///< 均匀色调转变内插法
		KSJ_EDGESENSING,        ///< 边缘感应算法
		KSJ_LAPLACIAN,          ///< 拉普拉斯插值法
		KSJ_FASTBILINEAR        ///< 快速双线性插值法
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_FilterSetMode
	/// @brief     设置贝尔滤波模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     FilterMode [in] 设置的贝尔滤波模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterSetMode(int nIndex, KSJ_FILTERMODE FilterMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_FilterGetMode
	/// @brief     得到当前相机的Bayer模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pFilterMode [out] 返回的贝尔滤波模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterGetMode(int nIndex, KSJ_FILTERMODE *pFilterMode);

#ifdef __cplusplus
}
#endif

#endif
