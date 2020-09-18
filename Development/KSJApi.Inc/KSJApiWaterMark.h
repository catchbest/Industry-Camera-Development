#ifndef __KSJ_API_WATER_MARK__H__
#define __KSJ_API_WATER_MARK__H__

// #pragma message("Include KSJApiWaterMark.h") 

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

	enum KSJ_WATERMARKMODE ///水印模式
	{ 
		KSJ_WMM_TIMESTAMP, 
		KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, 
		KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER 
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置水印模式（新版本水印已经不支持水印模式设置，默认KSJ_WMM_TIMESTAMP）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     WaterMarkMode [in] 设置水印模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetMode(int nIndex, KSJ_WATERMARKMODE WaterMarkMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取水印模式（新版本水印已经不支持水印模式设置，默认KSJ_WMM_TIMESTAMP）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pWaterMarkMode [out] 获取当前水印模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetMode(int nIndex, KSJ_WATERMARKMODE *pWaterMarkMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     设置是否开启水印
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 是否开启水印功能，true表示开启，false表示不开启
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetEnable(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取是否开启水印
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pWaterMarkMode [out] 获取当前水印模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetEnable(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取水印信息
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pwId [out] 获取当前水印号
	/// @param     pdwTimestampLowPart [out] 获取时间戳的低4字节值
	/// @param     pdwTimestampHighPart [out] 获取时间戳的高4字节位值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetInfo(int nIndex, unsigned short *pwId, unsigned long *pdwTimestampLowPart, unsigned long *pdwTimestampHighPart);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取水印信息和增益曝光
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pwId [out] 获取当前水印号
	/// @param     pdwTimestampLowPart [out] 获取时间戳的低4字节值
	/// @param     pdwTimestampHighPart [out] 获取时间戳的高4字节位值
	/// @param     pnExposure [out] 获取当前图像的曝光值
	/// @param     pwGain [out] 获取当前图像的增益值
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetInfoEx(int nIndex, unsigned int *pnId, unsigned long *pdwTimestampLowPart, unsigned long *pdwTimestampHighPart, unsigned int* pnExposure, unsigned short* pwGain);

#ifdef __cplusplus
}
#endif

#endif
