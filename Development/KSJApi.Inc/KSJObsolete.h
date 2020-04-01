#ifndef __KSJ_API_OBSOLETE_H__
#define __KSJ_API_OBSOLETE_H__

// #pragma message("Include KSJApiObsolete.h") 


#ifdef KSJAPI_EXPORTS
    #define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
	#define KSJ_API
#else
    #define KSJ_API __declspec(dllimport)
#endif

// Ϊ�˱��ֶ��Ͽͻ����õļ����ԣ�����ļ��еĺ�������ǰ�汾����ģ������°汾����Ȼ�������������Ѿ����Ƽ�ʹ�õĺ�����
// ������һЩ�����������������������Ҳ��Щ�����Ѿ�����֧�֡�
#ifdef __cplusplus
extern "C"{
#endif

	// �򿪻�ر�GammaУ������Ӱ��Ԥ����Ӱ��ɼ�
	KSJ_API  int __stdcall KSJ_GammaOn(int nChannel, bool bOn);    // Not Support Now.


// ���ù̶�֡��(ͨ������sensor�Ĵ���,ʹsensor����̶�֡��)��ֻ��MUC36C/M(MGYY)��MU3E130C/M(CGYY)֧��
// V4.0.86.12�汾��ʼ��bEnable������Ч��ͨ���û�����KSJ_TRIGGER_FIXFRAMERATEģʽ�������Ƿ�ʹ�ܡ�
KSJ_API  int __stdcall KSJ_SetFixedFrameRate(int nChannel, bool bEnable, float fFrameRate);
KSJ_API  int __stdcall KSJ_GetFixedFrameRate(int nChannel, bool *pbEnable, float *pfFrameRate);

// ������ź������ʵ������������ʱ���ã��ݲ�֧�֣�
KSJ_API  int __stdcall KSJ_StrobeDelaySet(int nChannel, unsigned short wDelay);
KSJ_API  int __stdcall KSJ_StrobeDelayGet(int nChannel, unsigned short *pwDelay);
KSJ_API  int __stdcall KSJ_StrobeDelayGetRange(int nChannel, unsigned short *wMin, unsigned short *wMax);


// ����ͼ�񴫸����Ĺ�����ʽ���ݲ�֧�֣�
enum KSJ_SENSORMODE { KSJ_SM_TRIGGER_MODE, KSJ_SM_FREERUN_MODE, KSJ_SM_GRR_MODE };
KSJ_API  int __stdcall KSJ_SensorModeSet(int nChannel, KSJ_SENSORMODE SensorMode);
KSJ_API  int __stdcall KSJ_SensorModeGet(int nChannel, KSJ_SENSORMODE *SensorMode);

///////////////////////////////////////////////Color Correction////////////////////////////////////////////////////////////////
typedef void(__stdcall *KSJ_CCCALLBACK)(bool bSuccess, int nRShift, int nGShift, int nBShift, void *lpContext);

// ���º���Ϊ�����ɫУ��
KSJ_API  int __stdcall KSJ_ColorCorrectSetCallback( int nChannel, KSJ_CCCALLBACK fpCCCallback, void *lpContext );

enum KSJ_COLORCORRECT { KSJ_CC_NONE, KSJ_CC_SHIFTRGB, KSJ_CC_EQRGB, KSJ_CC_EQALL, KSJ_CC_WB };
KSJ_API  int __stdcall KSJ_ColorCorrectSet  ( int nChannel, KSJ_COLORCORRECT ColorCorrect, int nRTarget, int nGTarget, int nBTarget );
KSJ_API  int __stdcall KSJ_ColorCorrectGet  ( int nChannel, KSJ_COLORCORRECT *pColorCorrect );
KSJ_API  int __stdcall KSJ_ColorCorrectGetEx( int nChannel, KSJ_COLORCORRECT *pColorCorrect, int *pnRTarget, int *pnGTarget, int *pnBTarget );

KSJ_API  int __stdcall KSJ_ColorCorrectTableSave( int nChannel, const TCHAR *pszFileName );
KSJ_API  int __stdcall KSJ_ColorCorrectTableLoad( int nChannel, const TCHAR *pszFileName );
KSJ_API  int __stdcall KSJ_IsColorCorrectTableLoad( int nChannel, bool *bLoad );

// KSJ_IR ����ƣ� KSJ_UV ����ƣ�KSJ_VI �ɼ����
enum KSJ_LED { KSJ_IR = 0, KSJ_UV, KSJ_VI };
// KSJ_ON ������KSJ_OFF �ƹ�
enum KSJ_LEDSTATUS { KSJ_OFF = 0, KSJ_ON };

// ���õƵ�״̬
KSJ_API  int __stdcall KSJ_LedSetStatus( int nChannel, KSJ_LED Led, KSJ_LEDSTATUS LedStatus );
KSJ_API  int __stdcall KSJ_LedGetStatus( int nChannel, KSJ_LED Led, KSJ_LEDSTATUS *pLedStatus );


#if 0

KSJ_API  int __stdcall KSJ_IsSupportLUT( int nChannel );                      // Use KSJ_QueryFunction
KSJ_API  int __stdcall KSJ_EnableLUT( int nChannel, bool bEnable );           // Use KSJ_LutSetEnable
KSJ_API  int __stdcall KSJ_IsEnableLUT( int nChannel, bool *pbEnable );       // Use KSJ_LutGetEnable


// ���������ʹ��������ұ�д�뵽24LC1024��LUT_BASE_ADDRESSΪ��ַ��ulOffsetAddressΪƫ�Ƶĵ�ַ��
KSJ_API  int __stdcall KSJ_ReadLUT ( int nChannel, unsigned short usOffsetAddress, int nBytes, unsigned char *pData   );
// nBytes���벻����64�ֽڣ�usOffsetAddress ��0��ʼ��
KSJ_API  int __stdcall KSJ_WriteLUT( int nChannel, unsigned short usOffsetAddress, unsigned char *pData, int nBytes  );

// ����Ӱ���
// �����Ҫͨ�����Ӽ�ר�õ�Ӱ������ɹ�������, �˺�������ݲ��ұ�Ĳ�ͬ���ͽ�����Ӧ�ļ���
// ����12bit->8bit����10bit->8bitӳ���, �⺯����������16bit���ݴ���ģʽʱ,ͨ��Ӱ��֮�������ʾ���˹�����PC�˼�����ɡ�
KSJ_API  int __stdcall KSJ_LoadMapTableFile( int nChannel, bool bLoad, const TCHAR *pszTableName );    // Use KSJ_LutFileDownload
/*
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetOnce( int nChannel, bool bOnce );               // You should call KSJ_WhiteBalanceSetEnable after call this function.
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetContinuous( int nChannel, bool bContinuous );   // You should call KSJ_WhiteBalanceSetEnable after call this function.

KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGetOnce( int nChannel, bool *pbOnce );             // You should call KSJ_WhiteBalanceSetEnable after call this function.
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGetContinuous( int nChannel, bool *pbContinuous );

KSJ_API  int __stdcall KSJ_WhiteBalanceSetEnable( int nChannel, bool bEnable );
KSJ_API  int __stdcall KSJ_WhiteBalanceGetEnable( int nChannel, bool *pbEnable );
*/

// ��ƽ���������ɫУ������
//enum KSJ_COLORCORRECTION { KSJCC_NONE = 0, KSJCC_WARMLIGHT, KSJCC_COOLLIGHT, KSJCC_SUNLIGHT, KSJCC_OV, KSJCC_KODAK };
//KSJ_API  int __stdcall KSJ_ColorCorrectionSet( int nChannel, KSJ_COLORCORRECTION  ColorCorrect  );
//KSJ_API  int __stdcall KSJ_ColorCorrectionGet( int nChannel, KSJ_COLORCORRECTION *pColorCorrect );


// KSJ_API  int __stdcall KSJ_ColorCorrectionSetEnable( int nChannel, bool bEnable );
// KSJ_API  int __stdcall KSJ_ColorCorrectionGetEnable( int nChannel, bool *pbEnable );


#endif
#ifdef __cplusplus
}
#endif

#endif