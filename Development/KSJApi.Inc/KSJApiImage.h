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

    //-----------------------------------------------------------------------------
    // 函数：KSJ_BadPixelCorrectionSetThreshold
    // 功能：设置软件坏点校正的相邻阈值及次相邻阈值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       btLow：输入，设置相邻像素的比较阈值，默认20
	//       btHigh：输入，设置相邻像素的比较阈值，默认50
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSetThreshold(int nChannel, unsigned char btLow, unsigned char btHigh);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_BadPixelCorrectionGetThreshold
    // 功能：获取软件坏点校正的阈值设置
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbtLow：输出，返回相邻像素的比较阈值
	//       pbtHigh：输出，返回相邻像素的比较阈值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGetThreshold(int nChannel, unsigned char *pbtLow, unsigned char *pbtHigh);

    enum KSJ_THRESHOLD //坏点补偿算法阈值模式选择
    { 
	    KSJ_THRESHOLD_LOW, //高阈值模式，默认相邻点阈值为0x30， 次相邻点阈值为0x18
	    KSJ_THRESHOLD_HIGH //低阈值，默认相邻点阈值为0x18， 次相邻点阈值为0x0c，低阈值会比高阈值对坏点更敏感
    };
    
	//-----------------------------------------------------------------------------
    // 函数：KSJ_BadPixelCorrectionSet
    // 功能：设置软件坏点校正的相邻阈值及次相邻阈值
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，是否加入坏点补偿算法
	//       Threshold：输入，选取的阈值，参考KSJ_THRESHOLD说明
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSet(int nChannel, bool bEnable, KSJ_THRESHOLD Threshold);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_BadPixelCorrectionGet
    // 功能：获取相机当前的坏点补偿信息
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbEnable：输入，返回是否加入坏点补偿算法
	//       pThreshold：输入，返回当前坏点补偿算法所选取的阈值，只针对支持硬件坏点校正的设备有效
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGet(int nChannel, bool *pbEnable, KSJ_THRESHOLD *pThreshold);

    //-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessContrastGetRange
    // 功能：获取对比度的设置范围（-128~128）
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnMinContrast：输出，返回对比度设置的最小值
	//       pnMaxContrast：输出，返回对比度设置的最大值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessContrastGetRange(int nChannel, int *pnMinContrast, int *pnMaxContrast);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessContrastSet
    // 功能：设置相机对比度参数
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nContrast：输入，对比度设置的值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessContrastSet(int nChannel, int nContrast);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessContrastGet
    // 功能：获取相机对比度参数
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnContrast：输出，返回对比度设置的最小值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessContrastGet(int nChannel, int *pnContrast);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessBrightnessGetRange
    // 功能：获取亮度的设置范围（-128~128）
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnMinBrightness：输出，取得亮度设置的最小值
	//       pnMaxBrightness：输出，取得亮度设置的最大值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessBrightnessGetRange(int nChannel, int *pnMinBrightness, int *pnMaxBrightness);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessBrightnessSet
    // 功能：设置相机的亮度
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nBrightness：输入，亮度设置的值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessBrightnessSet(int nChannel, int nBrightness);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessBrightnessGet
    // 功能：获取相机亮度参数
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnBrightness：输出，返回相机亮度
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessBrightnessGet(int nChannel, int *pnBrightness);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessSaturationGetRange
    // 功能：获取饱和度的设置范围（-128~128）
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnMinSaturation：输出，取得饱和度设置的最小值
	//       pnMaxSaturation：输出，取得饱和度设置的最大值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGetRange(int nChannel, int *pnMinSaturation, int *pnMaxSaturation);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessSaturationSet
    // 功能：设置图像的饱和度
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nSaturation：输入，饱和度设置的值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationSet(int nChannel, int nSaturation);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_ProcessSaturationGet
    // 功能：获取相机饱和度参数
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnStaturation：输出，返回相机饱和度
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGet(int nChannel, int *pnStaturation);

	//-----------------------------------------------------------------------------
    // 函数：KSJ_GammaGetRange
    // 功能：获取Gamma的设置范围（-9 - 9）
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnMinGamma：输出，取得Gamma设置的最小值
	//       pnMaxGamm：输出，取得Gamma设置的最大值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaGetRange(int nChannel, int *pnMinGamma, int *pnMaxGamm);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_GammaSetValue
    // 功能：设置Gamma
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       nValue：输入，Gamma设置的值
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaSetValue( int nChannel, int nValue );
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_GammaGetValue
    // 功能：获取Gamma
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pnValue：输出，返回Gamma
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaGetValue(int nChannel, int *pnValue);

    typedef enum//颜色分量枚举类型
    {
	    KSJ_ALL_HUES,	//整体颜色
	    KSJ_RED_HUES,	//红分量
	    KSJ_YELLOW_HUES,//黄分量
	    KSJ_GREEN_HUES, //绿分量
	    KSJ_CYAN_HUES,	//青色分量
	    KSJ_BLUE_HUES,	//蓝分量
	    KSJ_MAGENTA_HUES//品红分量
    } KSJHueRange;

    //-----------------------------------------------------------------------------
    // 函数：KSJ_HueSaturationSet
    // 功能：设置各个颜色分量的色度、饱和度、亮度
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       HueRange：输入，要设置的颜色分量类型
	//       nHue：输入，设置指定颜色分量的色度，取值范围-180 ~ 180
	//       nSaturation：输入，设置指定颜色的饱和度，取值范围-100 ~ 100
	//       nLightness：输入，设置指定颜色分量的亮度，取值范围-100 ~ 100
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSet(int nChannel, KSJHueRange HueRange, int nHue, int nSaturation, int nLightness);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_HueSaturationGet
    // 功能：获取各个颜色分量的色度、饱和度、亮度
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       HueRange：输入，要设置的颜色分量类型
	//       pnHue：输出，获取指定颜色分量的色度
	//       pnSaturation：输出，获取指定颜色的饱和度
	//       pnLightness：输出，获取指定颜色分量的亮度
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationGet(int nChannel, KSJHueRange HueRange, int *pnHue, int *pnSaturation, int *pnLightness);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_HueSaturationSetEnable
    // 功能：使能或关闭颜色分量调节功能
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       bEnable：输入，ture 开启颜色分量调节，false 关闭颜色分量调节
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSetEnable(int nChannel, bool bEnable);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_HueSaturationGetEnable
    // 功能：获取颜色分量调节功能是否使能
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pbEnable：输出，返回颜色分量调节功能是否使能，ture 开启颜色分量调节，false 关闭颜色分量调节
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HueSaturationGetEnable(int nChannel, bool *pbEnable);

#ifdef __cplusplus
}
#endif

#endif


