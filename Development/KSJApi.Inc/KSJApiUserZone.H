#ifndef __KSJ_API_USER_ZONE_H__
#define __KSJ_API_USER_ZONE_H__

// #pragma message("Include KSJApiUserZone.h") 

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 参考“凯视佳工业相机内部API函数说明书（用户读写区域篇）”
	enum KSJ_EEPROM_TYPE { KSJ_24LC64, KSJ_24LC1024, KSJ_24LC128 };//EEPROM型号的枚举类型定义

	///-----------------------------------------------------------------------------
    ///
    /// @brief     获取相机所使用的存储器芯片类型
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pType [out] 返回相机所使用的EEPROM型号
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_EEPROMTypeGet( int nIndex, KSJ_EEPROM_TYPE *pType);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     对使用EEPROM型号为24LC64，24LC128的设备进行写入数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     uRomAdress [in] 要写入的设备ROM地址
	/// @param     btValue [in] 要写入ROM地址的数据
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROM( int nIndex, unsigned short uRomAdress, unsigned char btValue);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     对使用EEPROM型号为24LC64，24LC128的设备进行读取数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     uRomAdress [out] 要读取的设备ROM地址
	/// @param     pbtValue [out] 返回给调用者uRomAdress地址的数据
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROM( int nIndex, unsigned short uRomAdress, unsigned char *pbtValue);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     对使用EEPROM型号为24LC1024的设备进行写入数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     ulRomAdress [in] 要写入的设备ROM地址
	/// @param     btValue [in] 要写入ROM地址的数据
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROMEx( int nIndex, unsigned long ulRomAdress, unsigned char btValue);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     对使用EEPROM型号为24LC1024的设备进行读写数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     ulRomAdress [out] 要读取的设备ROM地址
	/// @param     pbtValue [out] 返回给调用者uRomAdress地址的数据
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROMEx( int nIndex, unsigned long ulRomAdress, unsigned char *pbtValue);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     对使用EEPROM型号为24LC1024的设备进行写入数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     ulRomAdress [in] 要写入的设备ROM地址
	/// @param     pData [in] 要写入ROM地址的数据
	/// @param     nBytes [in] 要写入数据的字节数
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROMExEx(int nIndex, unsigned long ulRomAdress, unsigned char *pData, int nBytes);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     对使用EEPROM型号为24LC1024的设备进行读写数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     ulRomAdress [in] 要读取的设备ROM地址
	/// @param     nBytes [in] 要读数据的字节数
	/// @param     pData [out] 返回给调用者ulRomAdress地址开始的nBytes字节数据
    /// @return    参考返回状态码（KSJCode.H）
    /// @attention 调用KSJ_Init函数初始化后调用
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROMExEx(int nIndex, unsigned long ulRomAdress, int nBytes, unsigned char *pData);


#ifdef __cplusplus
}
#endif

#endif
