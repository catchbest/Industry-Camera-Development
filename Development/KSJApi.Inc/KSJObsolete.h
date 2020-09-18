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

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡGamma�����÷�Χ��-9 - 9��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnMinGamma [out] ȡ��Gamma���õ���Сֵ
	/// @param     pnMaxGamm [out] ȡ��Gamma���õ����ֵ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaGetRange(int nIndex, int *pnMinGamma, int *pnMaxGamm);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����Gamma
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nValue [in] Gamma���õ�ֵ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaSetValue(int nIndex, int nValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡGamma
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnValue [out] ����Gamma
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaGetValue(int nIndex, int *pnValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��������ԱȶȲ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nContrast [in] �Աȶ����õ�ֵ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessContrastSet(int nIndex, int nContrast);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ����ԱȶȲ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnContrast [out] ���ضԱȶ����õ���Сֵ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessContrastGet(int nIndex, int *pnContrast);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ���ȵ����÷�Χ��-128~128��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnMinBrightness [out] ȡ���������õ���Сֵ
	/// @param     pnMaxBrightness [out] ȡ���������õ����ֵ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessGetRange(int nIndex, int *pnMinBrightness, int *pnMaxBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �������������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nBrightness [in] �������õ�ֵ
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessSet(int nIndex, int nBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ������Ȳ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnBrightness [out] �����������
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessGet(int nIndex, int *pnBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �Ƿ��ȡ��ʱ��ָ��豸
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bRecover [in] ��ȡ��ʱ���Ƿ�ָ��豸,true�ָ�,false���ָ�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetRecover(int nIndex, bool bRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ��ǰ���ڳ�ʱ�ָ�������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbRecover [out] ��ȡ���ö�ȡ��ʱ���Ƿ�ָ��豸,true�ָ�,false���ָ�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetRecover(int nIndex, bool *pbRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ͬʱ���ó�ʱʱ�估��ʱ���Ƿ�ָ��豸
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     dwTimeOut [in] ���ó�ʱʱ��,��λΪ����
	/// @param     bRecover [in] ��ȡ��ʱ���Ƿ�ָ��豸,true�ָ�,false���ָ�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetTimeOutEx(int nIndex, unsigned long dwTimeOut, bool bRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ���ڳ�ʱ�ͻָ�������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pdwTimeOut [out] ��ȡ��ȡһ֡ͼ��ĳ�ʱʱ�䣬��λΪ����
	/// @param     pbRecover [out] ��ȡ���ö�ȡ��ʱ���Ƿ�ָ��豸,true�ָ�,false���ָ�
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetTimeOutEx(int nIndex, unsigned long *pdwTimeOut, bool *pbRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �����Զ��ع����������Ļص�����
	/// @param     bSuccess [out] �����Զ���ƽ������Ƿ���ڵ��û��趨��Ŀ��ֵ���ο�KSJ_AEStart��������TRUE����ʾ�Զ���ƽ����ڵ�����Ŀ��ֵ��FALSE����ʾ�Զ���ƽ�ⳬ���û��趨�ĵ��ڴ�����û�дﵽĿ��ֵ
	/// @param     nValueR [out] ���Զ���ƽ����ڽ����󣬺����������ֵ
	/// @param     nValueG [out] ���Զ���ƽ����ڽ����������������ֵ
	/// @param     nValueB [out] ���Զ���ƽ����ڽ����������������ֵ
	/// @param     lpContext [out] �û�������ָ�룬���ָ�����û�����KSJ_AWBSetCallbackʱ�����������ָ��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ������ã������Ƽ�ʹ��, ����KSJApiMatrix.h�ں���
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AWBCALLBACK)(bool bSuccess, int nValueR, int nValueG, int nValueB, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �����Զ���ƽ�����������Ļص����������Զ��ع����ʱ��KSJ���������Զ�����pfAWBCallback�û�ָ���Ļص�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fpAWBCallback [in] �û�������Զ���ƽ��ص�����ָ�루�ο�KSJ_AWBCALLBACK�����Ķ��壩
	/// @param     lpContext [in] �ص�������������ָ��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ������ã������Ƽ�ʹ��, ����KSJApiMatrix.h�ں���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBSetCallback(int nIndex, KSJ_AWBCALLBACK fpAWBCallback, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����������Զ��ع����
	/// @param     bSuccess [out] �����Զ���ƽ������Ƿ���ڵ��û��趨��Ŀ��ֵ���ο�KSJ_AEStart��������TRUE����ʾ�Զ���ƽ����ڵ�����Ŀ��ֵ��FALSE����ʾ�Զ���ƽ�ⳬ���û��趨�ĵ��ڴ�����û�дﵽĿ��ֵ
	/// @param     bStart [in] TRUE ��ʼ�Զ���ƽ����ڣ�FALSE ��ֹ������Զ���ƽ�����
	/// @param     nMaxCount [out] �趨�����ڼ��ξͽ�����������û����õĴ����ڰ�ƽ�����û�дﵽ�û��趨��Ŀ��ֵ���ص���������ʾ�Զ���ƽ��ʧ��
	/// @param     nRTarget [out] ���ڵ���Ŀ������ֵ��0-255��
	/// @param     nGTarget [out] ���ڵ���Ŀ���̷���ֵ��0-255��
	/// @param     nBTarget [out] ���ڵ���Ŀ��������ֵ��0-255��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ������ã������Ƽ�ʹ��, ����KSJApiMatrix.h�ں���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBStart(int nIndex, bool bStart, int nMaxCount, int nRTarget, int nGTarget, int nBTarget);


	/// �򿪻�ر�GammaУ������Ӱ��Ԥ����Ӱ��ɼ�
	KSJ_API  int __stdcall KSJ_GammaOn(int nIndex, bool bOn);    /// Not Support Now.


	// ���ù̶�֡��(ͨ������sensor�Ĵ���,ʹsensor����̶�֡��)��ֻ��MUC36C/M(MGYY)��MU3E130C/M(CGYY)֧��
	// V4.0.86.12�汾��ʼ��bEnable������Ч��ͨ���û�����KSJ_TRIGGER_FIXFRAMERATEģʽ�������Ƿ�ʹ�ܡ�
	KSJ_API  int __stdcall KSJ_SetFixedFrameRate(int nIndex, bool bEnable, float fFrameRate);
	KSJ_API  int __stdcall KSJ_GetFixedFrameRate(int nIndex, bool *pbEnable, float *pfFrameRate);

	// ������ź������ʵ������������ʱ���ã��ݲ�֧�֣�
	KSJ_API  int __stdcall KSJ_StrobeDelaySet(int nIndex, unsigned short wDelay);
	KSJ_API  int __stdcall KSJ_StrobeDelayGet(int nIndex, unsigned short *pwDelay);
	KSJ_API  int __stdcall KSJ_StrobeDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);


	// ����ͼ�񴫸����Ĺ�����ʽ���ݲ�֧�֣�
	enum KSJ_SENSORMODE { KSJ_SM_TRIGGER_MODE, KSJ_SM_FREERUN_MODE, KSJ_SM_GRR_MODE };
	KSJ_API  int __stdcall KSJ_SensorModeSet(int nIndex, KSJ_SENSORMODE SensorMode);
	KSJ_API  int __stdcall KSJ_SensorModeGet(int nIndex, KSJ_SENSORMODE *SensorMode);

	///////////////////////////////////////////////Color Correction////////////////////////////////////////////////////////////////
	typedef void(__stdcall *KSJ_CCCALLBACK)(bool bSuccess, int nRShift, int nGShift, int nBShift, void *lpContext);

	// ���º���Ϊ�����ɫУ��
	KSJ_API  int __stdcall KSJ_ColorCorrectSetCallback( int nIndex, KSJ_CCCALLBACK fpCCCallback, void *lpContext );

	enum KSJ_COLORCORRECT { KSJ_CC_NONE, KSJ_CC_SHIFTRGB, KSJ_CC_EQRGB, KSJ_CC_EQALL, KSJ_CC_WB };
	KSJ_API  int __stdcall KSJ_ColorCorrectSet  ( int nIndex, KSJ_COLORCORRECT ColorCorrect, int nRTarget, int nGTarget, int nBTarget );
	KSJ_API  int __stdcall KSJ_ColorCorrectGet  ( int nIndex, KSJ_COLORCORRECT *pColorCorrect );
	KSJ_API  int __stdcall KSJ_ColorCorrectGetEx( int nIndex, KSJ_COLORCORRECT *pColorCorrect, int *pnRTarget, int *pnGTarget, int *pnBTarget );

	KSJ_API  int __stdcall KSJ_ColorCorrectTableSave( int nIndex, const TCHAR *pszFileName );
	KSJ_API  int __stdcall KSJ_ColorCorrectTableLoad( int nIndex, const TCHAR *pszFileName );
	KSJ_API  int __stdcall KSJ_IsColorCorrectTableLoad( int nIndex, bool *bLoad );

	// KSJ_IR ����ƣ� KSJ_UV ����ƣ�KSJ_VI �ɼ����
	enum KSJ_LED { KSJ_IR = 0, KSJ_UV, KSJ_VI };
	// KSJ_ON ������KSJ_OFF �ƹ�
	enum KSJ_LEDSTATUS { KSJ_OFF = 0, KSJ_ON };

	// ���õƵ�״̬
	KSJ_API  int __stdcall KSJ_LedSetStatus( int nIndex, KSJ_LED Led, KSJ_LEDSTATUS LedStatus );
	KSJ_API  int __stdcall KSJ_LedGetStatus( int nIndex, KSJ_LED Led, KSJ_LEDSTATUS *pLedStatus );


	enum KSJ_FLASHMODE//�����ģʽ���ݲ�֧�֣�
	{
		KSJ_FM_TROW,
		KSJ_FM_SIMULTANEOUSEXPOSURE,
		KSJ_FM_SHUTTERWIDTH
	};
	KSJ_API  int __stdcall KSJ_FlashSetMode(int nIndex, KSJ_FLASHMODE FlashMode);//���������ģʽ���ݲ�֧�֣�
	KSJ_API  int __stdcall KSJ_FlashGetMode(int nIndex, KSJ_FLASHMODE *pFlashMode);//��ȡ�����ģʽ���ݲ�֧�֣�

#if 0

KSJ_API  int __stdcall KSJ_IsSupportLUT( int nIndex );                      /// Use KSJ_QueryFunction
KSJ_API  int __stdcall KSJ_EnableLUT( int nIndex, bool bEnable );           /// Use KSJ_LutSetEnable
KSJ_API  int __stdcall KSJ_IsEnableLUT( int nIndex, bool *pbEnable );       /// Use KSJ_LutGetEnable


// ���������ʹ��������ұ�д�뵽24LC1024��LUT_BASE_ADDRESSΪ��ַ��ulOffsetAddressΪƫ�Ƶĵ�ַ��
KSJ_API  int __stdcall KSJ_ReadLUT ( int nIndex, unsigned short usOffsetAddress, int nBytes, unsigned char *pData   );
// nBytes���벻����64�ֽڣ�usOffsetAddress ��0��ʼ��
KSJ_API  int __stdcall KSJ_WriteLUT( int nIndex, unsigned short usOffsetAddress, unsigned char *pData, int nBytes  );

// ����Ӱ���
// �����Ҫͨ�����Ӽ�ר�õ�Ӱ������ɹ�������, �˺�������ݲ��ұ�Ĳ�ͬ���ͽ�����Ӧ�ļ���
// ����12bit->8bit����10bit->8bitӳ���, �⺯����������16bit���ݴ���ģʽʱ,ͨ��Ӱ��֮�������ʾ���˹�����PC�˼�����ɡ�
KSJ_API  int __stdcall KSJ_LoadMapTableFile( int nIndex, bool bLoad, const TCHAR *pszTableName );    /// Use KSJ_LutFileDownload
/*
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetOnce( int nIndex, bool bOnce );               /// You should call KSJ_WhiteBalanceSetEnable after call this function.
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetContinuous( int nIndex, bool bContinuous );   /// You should call KSJ_WhiteBalanceSetEnable after call this function.

KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGetOnce( int nIndex, bool *pbOnce );             /// You should call KSJ_WhiteBalanceSetEnable after call this function.
KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGetContinuous( int nIndex, bool *pbContinuous );

KSJ_API  int __stdcall KSJ_WhiteBalanceSetEnable( int nIndex, bool bEnable );
KSJ_API  int __stdcall KSJ_WhiteBalanceGetEnable( int nIndex, bool *pbEnable );
*/

// ��ƽ���������ɫУ������
//enum KSJ_COLORCORRECTION { KSJCC_NONE = 0, KSJCC_WARMLIGHT, KSJCC_COOLLIGHT, KSJCC_SUNLIGHT, KSJCC_OV, KSJCC_KODAK };
//KSJ_API  int __stdcall KSJ_ColorCorrectionSet( int nIndex, KSJ_COLORCORRECTION  ColorCorrect  );
//KSJ_API  int __stdcall KSJ_ColorCorrectionGet( int nIndex, KSJ_COLORCORRECTION *pColorCorrect );


// KSJ_API  int __stdcall KSJ_ColorCorrectionSetEnable( int nIndex, bool bEnable );
// KSJ_API  int __stdcall KSJ_ColorCorrectionGetEnable( int nIndex, bool *pbEnable );


#endif
#ifdef __cplusplus
}
#endif

#endif