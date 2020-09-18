#ifndef __KSJ_API_COMPANDING_H__
#define __KSJ_API_COMPANDING_H__

// #pragma message("Include KSJApiCompanding.h") 

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

    /// 参考“凯视佳工业相机API函数说明书（数据压扩篇）”
	/// Related API KSJ_GetADCResolution to Get Valid bits of 16bits
	/// Please KSJ_QueryFunction ( KSJ_SUPPORT_LUT_DOWNLOAD ) to Get if support download LUT
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LutFileDownload
    /// @brief     以ktb文件形式，下载LUT查找表至相机
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pszKtbFile [in] .ktb文件路径
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutFileDownload(int nIndex, const TCHAR *pszKtbFile);
	
    ///-----------------------------------------------------------------------------
    /// @brief     KSJ_LutDataDownload
    /// @brief     此函数可用于加载用户自定义的LUT查找表数据
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pData [out] 指向查找表数据的指针
	/// @param     nBytes [in] 查找表数据个数，即pData指针指向的内存块的大小
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutDataDownload( int nIndex, unsigned char *pData, int nBytes   );
    
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LutSetEnable
    /// @brief     使能LUT查找表功能
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 设置是否使LUT功能生效
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutSetEnable( int nIndex, bool bEnable   );

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LutGetEnable
    /// @brief     获取LUT查找表是否使能
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回是否LUT功能已生效
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutGetEnable( int nIndex, bool *pbEnable );

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GammaLutFileDownload
    /// @brief     以ktb文件形式，下载Gamma LUT查找表至相机
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pszKtbFile [in] .ktb文件路径
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutFileDownload( int nIndex, const TCHAR *pszKtbFile );
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GammaLutDataDownload
    /// @brief     加载用户自定义的Gamma LUT查找表数据
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pData [out] 指向查找表数据的指针，每个元素为双字节
	/// @param     nWords [in] 查找表数据个数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutDataDownload( int nIndex, unsigned short *pData, int nWords );
    
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GammaLutSetEnable
    /// @brief     使能Gamma LUT查找表功能
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     bEnable [in] 设置是否使Gamma LUT功能生效
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutSetEnable( int nIndex, bool bEnable   );
    
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GammaLutGetEnable
    /// @brief     获取Gamma LUT查找表是否使能
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pbEnable [out] 返回是否Gamma LUT功能已生效
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutGetEnable( int nIndex, bool *pbEnable );

    enum KSJ_SENSITIVITYMODE /// 灵敏度模式设置（使用截取8位方式）
    {
	    KSJ_LOW = 0, 
	    KSJ_MID, 
	    KSJ_HIGH, 
	    KSJ_HIGHER, 
	    KSJ_HIGHEST 
    };
    
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SensitivitySetMode
    /// @brief     选择截位模式
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     SensitivityMode [in] 设置截位模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivitySetMode(int nIndex, KSJ_SENSITIVITYMODE SensitivityMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SensitivityGetMode
    /// @brief     选择截位模式
    /// 参数：
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pSensitivityMode [out] 获取当前截位模式
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivityGetMode(int nIndex, KSJ_SENSITIVITYMODE *pSensitivityMode);

#ifdef __cplusplus
}
#endif

#endif