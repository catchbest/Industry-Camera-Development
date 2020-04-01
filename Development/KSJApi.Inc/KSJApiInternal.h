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

	// ���Ϳ���������ֽڷ���USBЭ��
	// MSB( IoBlockEx.uOffset ) = SETUPDAT[3], LSB( IoBlockEx.uOffset ) =  SETUPDAT[2] 
	// MSB( IoBlockEx.uIndex )  = SETUPDAT[5], LSB( IoBlockEx.uIndex )  =  SETUPDAT[4] 
	// MSB( IoBlockEx.uLength ) = SETUPDAT[7], LSB( IoBlockEx.uLength ) =  SETUPDAT[6] 
	// wValue  = uOffset
	// wIndex  = uIndex
	// wLength = uLength
#pragma pack ( 1 )
	typedef struct _tagUSBCmd
	{
		unsigned char  bmRequest;
		unsigned char  bRequest;
		unsigned short wValue;
		unsigned short wIndex;
		unsigned short wLength;					// ��ʾ���ͻ�������ݵĳ���
	}USBCMD, *PUSBCMD;
#pragma pack ( 8 )

	KSJ_API  int __stdcall KSJ_VendorCmd(int nChannel, PUSBCMD pUsbCmd, unsigned char *pBuf);

	// �ο������Ӽѹ�ҵ����ڲ�API����˵���顱
	// ���ζ�д�ֽ������벻����64�ֽ�
	KSJ_API  int __stdcall KSJ_WrSensorReg(int nChannel, unsigned char btRegAddress, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_RdSensorReg(int nChannel, unsigned char btRegAddress, unsigned short *pwValue);
	KSJ_API  int __stdcall KSJ_WrSensorRegX(int nChannel, unsigned short wRegAdress, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_RdSensorRegX(int nChannel, unsigned short wRegAdress, unsigned short *pwValue);
	KSJ_API  int __stdcall KSJ_FrameRestart(int nChannel); 	// ���ع�ı���޷�������Чʱ������ô˺�����
	KSJ_API  int __stdcall KSJ_WrFpgaReg(int nChannel, unsigned char btRegAddress, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_RdFpgaReg(int nChannel, unsigned char btRegAddress, unsigned short *pwValue);
	KSJ_API  int __stdcall KSJ_ResetFpga(int nChannel, bool bReset);
	KSJ_API  int __stdcall KSJ_WrFx2Sfr(int nChannel, unsigned short uRegAdress, unsigned char btValue);
	KSJ_API  int __stdcall KSJ_RdFx2Sfr(int nChannel, unsigned short uRegAdress, unsigned char *pbtValue);
	KSJ_API  int __stdcall KSJ_WrFx2Reg(int nChannel, unsigned short uRegAdress, unsigned char btValue);
	KSJ_API  int __stdcall KSJ_RdFx2Reg(int nChannel, unsigned short uRegAdress, unsigned char *pbtValue);
	KSJ_API  int __stdcall KSJ_ResetFx2(int nChannel, bool bReset);
	KSJ_API  int __stdcall KSJ_WrAD9923A(int nChannel, unsigned short wRegAddress, unsigned long dwValue);
	KSJ_API  int __stdcall KSJ_WrTMP101(int nChannel, unsigned char btRegAddress, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_RdTMP101(int nChannel, unsigned char btRegAddress, unsigned short *pwValue);

	KSJ_API  int __stdcall KSJ_ResetDevice( int nChannel );
    KSJ_API  int __stdcall KSJ_ReconnectDevice( int nChannel );
    KSJ_API  int __stdcall KSJ_ResetHost  ( int nChannel );
    KSJ_API  int __stdcall KSJ_SendPktEnd ( int nChannel );
	KSJ_API  int __stdcall KSJ_CancelIo(int nChannel);

	// ֻ�Ǽ򵥵Ĵ��豸�����豸�����Ѿ�������
	KSJ_API  int __stdcall KSJ_Open(int nChannel);
	// ֻ�Ǽ򵥵Ĺر��豸�����������Ѿ��������豸����
	KSJ_API  int __stdcall KSJ_Close(int nChannel);



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif