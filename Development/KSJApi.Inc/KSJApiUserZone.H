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

	//-----------------------------------------------------------------------------
    // 函数：KSJ_EEPROMTypeGet
    // 功能：获取相机所使用的存储器芯片类型
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       pType：输出，返回相机所使用的EEPROM型号
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_EEPROMTypeGet( int nChannel, KSJ_EEPROM_TYPE *pType );

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WrEEPROM
    // 功能：对使用EEPROM型号为24LC64，24LC128的设备进行写入数据操作
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       uRomAdress：输入，要写入的设备ROM地址
	//       btValue：输入，要写入ROM地址的数据
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROM( int nChannel, unsigned short uRomAdress, unsigned char btValue   );
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_RdEEPROM
    // 功能：对使用EEPROM型号为24LC64，24LC128的设备进行读取数据操作
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       uRomAdress：输出，要读取的设备ROM地址
	//       pbtValue：输出，返回给调用者uRomAdress地址的数据
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROM( int nChannel, unsigned short uRomAdress, unsigned char *pbtValue );

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WrEEPROMEx
    // 功能：对使用EEPROM型号为24LC1024的设备进行写入数据操作
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       ulRomAdress：输入，要写入的设备ROM地址
	//       btValue：输入，要写入ROM地址的数据
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROMEx( int nChannel, unsigned long ulRomAdress, unsigned char btValue   );
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_RdEEPROMEx
    // 功能：对使用EEPROM型号为24LC1024的设备进行读写数据操作
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       ulRomAdress：输出，要读取的设备ROM地址
	//       pbtValue：输出，返回给调用者uRomAdress地址的数据
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROMEx( int nChannel, unsigned long ulRomAdress, unsigned char *pbtValue );

	//-----------------------------------------------------------------------------
    // 函数：KSJ_WrEEPROMExEx
    // 功能：对使用EEPROM型号为24LC1024的设备进行写入数据操作
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       ulRomAdress：输入，要写入的设备ROM地址
	//       pData：输入，要写入ROM地址的数据
	//       nBytes：输入，要写入数据的字节数
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WrEEPROMExEx(int nChannel, unsigned long ulRomAdress, unsigned char *pData, int nBytes);
	
	//-----------------------------------------------------------------------------
    // 函数：KSJ_RdEEPROMExEx
    // 功能：对使用EEPROM型号为24LC1024的设备进行读写数据操作
    // 参数：
	//       nChannel： 输入，设备索引（从0开始，最大索引数为:连接到主机的设备数目减一）
    //       ulRomAdress：输入，要读取的设备ROM地址
	//       nBytes：输入，要读数据的字节数
	//       pData：输出，返回给调用者ulRomAdress地址开始的nBytes字节数据
    // 返回：参考返回状态码（KSJCode.H）
    // 说明：调用KSJ_Init函数初始化后调用
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RdEEPROMExEx(int nChannel, unsigned long ulRomAdress, int nBytes, unsigned char *pData);


#ifdef __cplusplus
}
#endif

#endif
