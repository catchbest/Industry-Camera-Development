#ifndef __KSJ_API_A_H__
#define __KSJ_API_A_H__

// #pragma message("Include KSJApiInternal.h") 

#include "KSJApiUserZone.h"


#ifdef KSJAPI_EXPORTS
    #define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
	#define KSJ_API
#else
    #define KSJ_API __declspec(dllimport)
#endif

/*-----------------------------------------------------------------------------------------------------
	Supper Command for Internal only. 
  ====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif

	/// 发送控制命令，各字节符合USB协议
	/// MSB( IoBlockEx.uOffset ) = SETUPDAT[3], LSB( IoBlockEx.uOffset ) =  SETUPDAT[2] 
	/// MSB( IoBlockEx.uIndex )  = SETUPDAT[5], LSB( IoBlockEx.uIndex )  =  SETUPDAT[4] 
	/// MSB( IoBlockEx.uLength ) = SETUPDAT[7], LSB( IoBlockEx.uLength ) =  SETUPDAT[6] 
	/// wValue  = uOffset
	/// wIndex  = uIndex
	/// wLength = uLength
#pragma pack ( 1 )
	typedef struct _tagUSBCmd
	{
		unsigned char  bmRequest;
		unsigned char  bRequest;
		unsigned short wValue;
		unsigned short wIndex;
		unsigned short wLength;					/// 表示发送或接受数据的长度
	}USBCMD, *PUSBCMD;
#pragma pack ( 8 )

	KSJ_API  int __stdcall KSJ_VendorCmd(int nIndex, PUSBCMD pUsbCmd, unsigned char *pBuf);

	/// 参考“凯视佳工业相机内部API函数说明书”
	/// 单次读写字节数必须不大于64字节
	KSJ_API  int __stdcall KSJ_WrSensorReg(int nIndex, unsigned char btRegAddress, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_RdSensorReg(int nIndex, unsigned char btRegAddress, unsigned short *pwValue);
	KSJ_API  int __stdcall KSJ_WrSensorRegX(int nIndex, unsigned short wRegAdress, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_RdSensorRegX(int nIndex, unsigned short wRegAdress, unsigned short *pwValue);
	KSJ_API  int __stdcall KSJ_FrameRestart(int nIndex); 	/// 当曝光改变后无法立刻生效时，需调用此函数。
	KSJ_API  int __stdcall KSJ_WrFpgaReg(int nIndex, unsigned char btRegAddress, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_RdFpgaReg(int nIndex, unsigned char btRegAddress, unsigned short *pwValue);
	KSJ_API  int __stdcall KSJ_ResetFpga(int nIndex, bool bReset);
	KSJ_API  int __stdcall KSJ_WrFx2Sfr(int nIndex, unsigned short uRegAdress, unsigned char btValue);
	KSJ_API  int __stdcall KSJ_RdFx2Sfr(int nIndex, unsigned short uRegAdress, unsigned char *pbtValue);
	KSJ_API  int __stdcall KSJ_WrFx2Reg(int nIndex, unsigned short uRegAdress, unsigned char btValue);
	KSJ_API  int __stdcall KSJ_RdFx2Reg(int nIndex, unsigned short uRegAdress, unsigned char *pbtValue);
	KSJ_API  int __stdcall KSJ_ResetFx2(int nIndex, bool bReset);
	KSJ_API  int __stdcall KSJ_WrAD9923A(int nIndex, unsigned short wRegAddress, unsigned long dwValue);
	KSJ_API  int __stdcall KSJ_WrTMP101(int nIndex, unsigned char btRegAddress, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_RdTMP101(int nIndex, unsigned char btRegAddress, unsigned short *pwValue);

	KSJ_API  int __stdcall KSJ_ResetDevice( int nIndex );
    KSJ_API  int __stdcall KSJ_ReconnectDevice( int nIndex );
    KSJ_API  int __stdcall KSJ_ResetHost( int nIndex );
    KSJ_API  int __stdcall KSJ_SendPktEnd( int nIndex );
	KSJ_API  int __stdcall KSJ_CancelIo(int nIndex);

	/// 只是简单的打开设备，此设备必须已经创建。
	KSJ_API  int __stdcall KSJ_Open(int nIndex);
	/// 只是简单的关闭设备，不会销毁已经创建的设备对象。
	KSJ_API  int __stdcall KSJ_Close(int nIndex);

	KSJ_API  int __stdcall KSJ_ClearFeature(int nIndex);
	KSJ_API  int __stdcall KSJ_ResetPipe(int nIndex);
	KSJ_API  int __stdcall KSJ_UsbHostResetDevice(int nIndex);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif