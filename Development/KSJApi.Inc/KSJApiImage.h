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
    /// @brief     设置软件坏点校正的相邻阈值及次相邻阈值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     btLow [in] 设置相邻像素的比较阈值，默认20
	/// @param     btHigh [in] 设置相邻像素的比较阈值，默认50
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSetThreshold(int nIndex, unsigned char btLow, unsigned char btHigh);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     获取软件坏点校正的阈值设置
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbtLow [out] 返回相邻像素的比较阈值
	/// @param     pbtHigh [out] 返回相邻像素的比较阈值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGetThreshold(int nIndex, unsigned char *pbtLow, unsigned char *pbtHigh);

    enum KSJ_THRESHOLD ///坏点补偿算法阈值模式选择
    { 
	    KSJ_THRESHOLD_LOW, ///高阈值模式，默认相邻点阈值为0x30， 次相邻点阈值为0x18
	    KSJ_THRESHOLD_HIGH ///低阈值，默认相邻点阈值为0x18， 次相邻点阈值为0x0c，低阈值会比高阈值对坏点更敏感
    };
    
	///-----------------------------------------------------------------------------
	///
    /// @brief     设置软件坏点校正的相邻阈值及次相邻阈值
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 是否加入坏点补偿算法
	/// @param     Threshold [in] 选取的阈值，参考KSJ_THRESHOLD说明
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSet(int nIndex, bool bEnable, KSJ_THRESHOLD Threshold);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     获取相机当前的坏点补偿信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [in] 返回是否加入坏点补偿算法
	/// @param     pThreshold [in] 返回当前坏点补偿算法所选取的阈值，只针对支持硬件坏点校正的设备有效
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGet(int nIndex, bool *pbEnable, KSJ_THRESHOLD *pThreshold);

    ///-----------------------------------------------------------------------------
	///
    /// @brief     获取对比度的设置范围（-128~128）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnMinContrast [out] 返回对比度设置的最小值
	/// @param     pnMaxContrast [out] 返回对比度设置的最大值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessContrastGetRange(int nIndex, int *pnMinContrast, int *pnMaxContrast);

	///-----------------------------------------------------------------------------
	///
    /// @brief     获取饱和度的设置范围（-128~128）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnMinSaturation [out] 取得饱和度设置的最小值
	/// @param     pnMaxSaturation [out] 取得饱和度设置的最大值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGetRange(int nIndex, int *pnMinSaturation, int *pnMaxSaturation);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     设置图像的饱和度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     nSaturation [in] 饱和度设置的值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationSet(int nIndex, int nSaturation);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     获取相机饱和度参数
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pnStaturation [out] 返回相机饱和度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGet(int nIndex, int *pnStaturation);

    typedef enum//颜色分量枚举类型
    {
	    KSJ_ALL_HUES,	///整体颜色
	    KSJ_RED_HUES,	///红分量
	    KSJ_YELLOW_HUES,//黄分量
	    KSJ_GREEN_HUES, ///绿分量
	    KSJ_CYAN_HUES,	///青色分量
	    KSJ_BLUE_HUES,	///蓝分量
	    KSJ_MAGENTA_HUES//品红分量
    } KSJHueRange;

    ///-----------------------------------------------------------------------------
	///
    /// @brief     设置各个颜色分量的色度、饱和度、亮度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     HueRange [in] 要设置的颜色分量类型
	/// @param     nHue [in] 设置指定颜色分量的色度，取值范围-180 ~ 180
	/// @param     nSaturation [in] 设置指定颜色的饱和度，取值范围-100 ~ 100
	/// @param     nLightness [in] 设置指定颜色分量的亮度，取值范围-100 ~ 100
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSet(int nIndex, KSJHueRange HueRange, int nHue, int nSaturation, int nLightness);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     获取各个颜色分量的色度、饱和度、亮度
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     HueRange [in] 要设置的颜色分量类型
	/// @param     pnHue [out] 获取指定颜色分量的色度
	/// @param     pnSaturation [out] 获取指定颜色的饱和度
	/// @param     pnLightness [out] 获取指定颜色分量的亮度
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationGet(int nIndex, KSJHueRange HueRange, int *pnHue, int *pnSaturation, int *pnLightness);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     使能或关闭颜色分量调节功能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] ture 开启颜色分量调节，false 关闭颜色分量调节
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSetEnable(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     获取颜色分量调节功能是否使能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回颜色分量调节功能是否使能，ture 开启颜色分量调节，false 关闭颜色分量调节
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HueSaturationGetEnable(int nIndex, bool *pbEnable);

#ifdef __cplusplus
}
#endif

#endif


