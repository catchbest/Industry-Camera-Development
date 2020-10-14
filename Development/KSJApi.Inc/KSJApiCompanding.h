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
	/// Please KSJ_QueryFunction (KSJ_SUPPORT_LUT_DOWNLOAD ) to Get if support download LUT

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LutFileDownload
	/// @brief     以ktb文件形式，下载LUT查找表至相机（16bit to 8bit LUT）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pszKtbFile [in] .ktb文件路径；请通过KSJ_QueryFunction(KSJ_SUPPORT_LUT_DOWNLOAD)查询相机是否支持LUT；该LUT仅本次有效，相机断电以后，该查找表将会丢失。
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutFileDownload(int nIndex, const TCHAR *pszKtbFile);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LutDataDownload
	/// @brief     此函数可用于加载用户自定义的LUT查找表数据（16bit to 8bit LUT）
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pData [out] 指向查找表数据的指针
	/// @param     nBytes [in] 查找表数据个数，即pData指针指向的内存块的大小；该LUT仅本次有效，相机断电以后，该查找表将会丢失。
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutDataDownload(int nIndex, unsigned char *pData, int nBytes);
    
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LutSetEnable
	/// @brief     使能LUT查找表功能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     bEnable [in] 设置是否使LUT功能生效
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutSetEnable(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LutGetEnable
	/// @brief     获取LUT查找表是否使能
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pbEnable [out] 返回是否LUT功能已生效
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutGetEnable(int nIndex, bool *pbEnable);

	/// 灵敏度模式设置（使用截取8位方式）
	enum KSJ_SENSITIVITYMODE
	{
		KSJ_LOW = 0,     ///< 16bit数据截取有效位的最低8bit数据
		KSJ_MID,         ///< 16bit数据截取有效位的中低8bit数据
		KSJ_HIGH,        ///< 16bit数据截取有效位的中间8bit数据
		KSJ_HIGHER,      ///< 16bit数据截取有效位的中高8bit数据
		KSJ_HIGHEST      ///< 16bit数据截取有效位的最高8bit数据
	};
    
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SensitivitySetMode
	/// @brief     选择截位模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     SensitivityMode [in] 设置截位模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivitySetMode(int nIndex, KSJ_SENSITIVITYMODE SensitivityMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SensitivityGetMode
	/// @brief     获取当前的截位模式
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     pSensitivityMode [out] 获取当前截位模式
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJApiRetCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivityGetMode(int nIndex, KSJ_SENSITIVITYMODE *pSensitivityMode);

#ifdef __cplusplus
}
#endif

#endif