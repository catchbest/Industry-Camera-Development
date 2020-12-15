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
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// 相机存储空间用户读写：相机内部预留了一定的存储空间，您可以根据需要保存自己的信息
	/// 必须要注意的是：写数据的时候，必须限定在用户区域，如果写入其它区域，可能会造成相机运行异常，甚至无法使用必须返厂维修
	/// 各个EEPROM类型的用户区域为：
	/// KSJ_24LC64:   0x1EE0-0x1FDF   为用户读写预留的空间
	/// KSJ_24LC128:  0x3DE0-0x3FDF   为用户读写预留的空间
	/// KSJ_24LC1024: 0x3FBE0-0x3FFDF 为用户读写预留的空间
	/// 参考“凯视佳工业相机内部API函数说明书（用户读写区域篇）”
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	enum KSJ_EEPROM_TYPE { KSJ_24LC64, KSJ_24LC1024, KSJ_24LC128 }; /// EEPROM型号的枚举类型定义

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_EEPROMTypeGet
    /// @brief     获取相机所使用的存储器芯片类型
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     pType [out] 返回相机所使用的EEPROM型号
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_EEPROMTypeGet( int nIndex, KSJ_EEPROM_TYPE *pType);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_WrEEPROM
    /// @brief     对使用EEPROM型号为24LC64，24LC128的设备进行写入数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     uRomAdress [in] 要写入的设备ROM地址
	/// @param     btValue [in] 要写入ROM地址的数据
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROM( int nIndex, unsigned short uRomAdress, unsigned char btValue);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_RdEEPROM
    /// @brief     对使用EEPROM型号为24LC64，24LC128的设备进行读取数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     uRomAdress [out] 要读取的设备ROM地址
	/// @param     pbtValue [out] 返回给调用者uRomAdress地址的数据
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROM( int nIndex, unsigned short uRomAdress, unsigned char *pbtValue);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_WrEEPROMEx
    /// @brief     对使用EEPROM型号为24LC1024的设备进行写入数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     ulRomAdress [in] 要写入的设备ROM地址
	/// @param     btValue [in] 要写入ROM地址的数据
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROMEx( int nIndex, unsigned long ulRomAdress, unsigned char btValue);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_RdEEPROMEx
    /// @brief     对使用EEPROM型号为24LC1024的设备进行读写数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     ulRomAdress [out] 要读取的设备ROM地址
	/// @param     pbtValue [out] 返回给调用者uRomAdress地址的数据
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROMEx( int nIndex, unsigned long ulRomAdress, unsigned char *pbtValue);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_WrEEPROMExEx
    /// @brief     对使用EEPROM型号为24LC1024的设备进行写入数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     ulRomAdress [in] 要写入的设备ROM地址
	/// @param     pData [in] 要写入ROM地址的数据
	/// @param     nBytes [in] 要写入数据的字节数
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
    /// @attention 为了安全建议使用KSJ_WrEEPROMExExSafe代替
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROMExEx(int nIndex, unsigned long ulRomAdress, unsigned char *pData, int nBytes);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_RdEEPROMExEx
    /// @brief     对使用EEPROM型号为24LC1024的设备进行读写数据操作
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    /// @param     ulRomAdress [in] 要读取的设备ROM地址
	/// @param     nBytes [in] 要读数据的字节数
	/// @param     pData [out] 返回给调用者ulRomAdress地址开始的nBytes字节数据
    /// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
    /// @attention 调用KSJ_Init函数初始化后调用
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROMExEx(int nIndex, unsigned long ulRomAdress, int nBytes, unsigned char *pData);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_WrEEPROMExExSafe
	/// @brief     对使用EEPROM型号为24LC1024的设备进行写入数据操作，对存储区域做了限制
	/// @param     nIndex [in] 设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
	/// @param     ulRomAdress [in] 要写入的设备ROM地址
	/// @param     pData [in] 要写入ROM地址的数据
	/// @param     nBytes [in] 要写入数据的字节数
	/// @return    成功返回 RET_SUCCESS(0)。否则返回非0值的错误码, 请参考 KSJCode.h 中错误码的定义。
	/// @attention 调用KSJ_Init函数初始化后调用
	/// @attention 该函数对存储区域做了限制，不会造成写入非用户区域而造成相机出现问题
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROMExExSafe(int nChannel, unsigned long ulRomAdress, unsigned char *pData, int nBytes);

#ifdef __cplusplus
}
#endif

#endif
