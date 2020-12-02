#ifndef __KSJ_API_IMAGE_H__
#define __KSJ_API_IMAGE_H__

// #pragma message("Include KSJApiImage.h") 

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
	/// @brief     KSJ_BadPixelCorrectionSetThreshold
	/// @brief     设置软件坏点校正的相邻阈值及次相邻阈值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     btLow [in] 设置相邻像素的比较阈值，默认20
	/// @param     btHigh [in] 设置相邻像素的比较阈值，默认50
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 如果该像素与相邻像素的差值大于btLow，并且它与次相邻相邻像素的差值大于btHigh，那么该点将被认为是坏点。
	///          \li 该设置仅对软件坏点校正生效，如果硬件支持怀点校正，那么使用内部预设值进行硬件坏点校正，不会执行软件坏点校正。
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSetThreshold(int nIndex, unsigned char btLow, unsigned char btHigh);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BadPixelCorrectionGetThreshold
	/// @brief     获取软件坏点校正的阈值设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbtLow [out] 返回相邻像素的比较阈值
	/// @param     pbtHigh [out] 返回次相邻像素的比较阈值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGetThreshold(int nIndex, unsigned char *pbtLow, unsigned char *pbtHigh);

	/// 坏点检测阈值模式
	enum KSJ_THRESHOLD
	{
		KSJ_THRESHOLD_LOW,  ///< 低阈值模式
		KSJ_THRESHOLD_HIGH  ///< 高阈值模式
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BadPixelCorrectionSet
	/// @brief     设置软件坏点校正的相邻阈值及次相邻阈值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] 是否加入坏点补偿算法
	/// @param     Threshold [in] 选取的阈值，参考KSJ_THRESHOLD说明
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 坏点校正设置及阈值设置，低阈值会过滤更多的坏点
	///          \li 如果相机硬件支持坏点校正，硬件将使用对应的阈值模式进行坏点校正。
	///          \li 执行该函数以后，软件坏点校正的相邻阈值及次相邻阈值将更新为内部预设值，如果需要使用自定义的阈值，需要在该函数之后，再设置（KSJ_BadPixelCorrectionSetThreshold()）
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSet(int nIndex, bool bEnable, KSJ_THRESHOLD Threshold);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BadPixelCorrectionGet
	/// @brief     获取相机当前的坏点补偿信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [in] 返回是否加入坏点补偿算法
	/// @param     pThreshold [in] 返回当前坏点补偿算法所选取的阈值模式，只针对支持硬件坏点校正的设备有效
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGet(int nIndex, bool *pbEnable, KSJ_THRESHOLD *pThreshold);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ProcessSaturationGetRange
	/// @brief     获取饱和度的设置范围（-128~128）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnMinSaturation [out] 取得饱和度设置的最小值
	/// @param     pnMaxSaturation [out] 取得饱和度设置的最大值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessContrastGetRange(int nIndex, int *pnMinContrast, int *pnMaxContrast);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ProcessSaturationGetRange
	/// @brief     获取饱和度的设置范围（-128~128）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnMinSaturation [out] 取得饱和度设置的最小值
	/// @param     pnMaxSaturation [out] 取得饱和度设置的最大值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGetRange(int nIndex, int *pnMinSaturation, int *pnMaxSaturation);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ProcessSaturationSet
	/// @brief     设置图像的饱和度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nSaturation [in] 饱和度设置的值
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 该算法由软件执行，可能会影响采集效率和预览帧率
	///          \li nSaturation = 0 表示不做饱和度调整
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationSet(int nIndex, int nSaturation);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ProcessSaturationGet
	/// @brief     获取相机饱和度参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnStaturation [out] 返回相机饱和度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGet(int nIndex, int *pnStaturation);

	/// 颜色分量通道枚举类型
	typedef enum
	{
		KSJ_ALL_HUES,     ///< 基础通道，所有通道的调节值需要加上该通道值
		KSJ_RED_HUES,     ///< 红色通道
		KSJ_YELLOW_HUES,  ///< 黄色通道
		KSJ_GREEN_HUES,   ///< 绿色通道
		KSJ_CYAN_HUES,    ///< 青色通道
		KSJ_BLUE_HUES,    ///< 蓝色通道
		KSJ_MAGENTA_HUES  ///< 洋红色通道
	} KSJHueRange;

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HueSaturationSet
	/// @brief     设置各个颜色分量的色度、饱和度、亮度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     HueRange [in] 要设置的颜色分量类型
	/// @param     nHue [in] 设置指定颜色分量的色度，取值范围-180 ~ 180
	/// @param     nSaturation [in] 设置指定颜色的饱和度，取值范围-100 ~ 100
	/// @param     nLightness [in] 设置指定颜色分量的亮度，取值范围-100 ~ 100
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 该算法由软件执行，可能会影响RGB彩色图像的采集效率和预览帧率
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSet(int nIndex, KSJHueRange HueRange, int nHue, int nSaturation, int nLightness);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HueSaturationGet
	/// @brief     获取各个颜色分量的色度、饱和度、亮度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     HueRange [in] 要设置的颜色分量类型
	/// @param     pnHue [out] 获取指定颜色分量的色度
	/// @param     pnSaturation [out] 获取指定颜色的饱和度
	/// @param     pnLightness [out] 获取指定颜色分量的亮度
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationGet(int nIndex, KSJHueRange HueRange, int *pnHue, int *pnSaturation, int *pnLightness);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HueSaturationSetEnable
	/// @brief     使能或关闭颜色分量调节功能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] ture 开启颜色分量调节，false 关闭颜色分量调节
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSetEnable(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HueSaturationGetEnable
	/// @brief     获取颜色分量调节功能是否使能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] 返回颜色分量调节功能是否使能，ture 开启颜色分量调节，false 关闭颜色分量调节
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HueSaturationGetEnable(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SharpenParamSet
	/// @brief     设置图像锐化参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     nKernelSize [in] 设置图像锐化计算滤波核大小
	/// @param     nWeighted [in] 设置图像锐化计算权重
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///          \li 该算法由软件执行，可能会影响RGB彩色图像的采集效率和预览帧率
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SharpenParamSet(int nIndex, int nKernelSize, int nWeighted);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SharpenParamGet
	/// @brief     获取图像锐化参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pnKernelSize [out] 获取图像锐化计算滤波核大小
	/// @param     pnWeighted [out] 获取图像锐化计算权重
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SharpenParamGet(int nIndex, int* pnKernelSize, int* pnWeighted);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SharpenSetEnable
	/// @brief     使能或关闭图像锐化功能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] ture 开启图像锐化功能，false 关闭图像锐化功能
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SharpenSetEnable(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SharpenGetEnable
	/// @brief     图像锐化功能是否使能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] 返回图像锐化功能是否使能，ture 开启图像锐化功能，false 关闭图像锐化功能
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SharpenGetEnable(int nIndex, bool *pbEnable);

#ifdef __cplusplus
}
#endif

#endif


