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
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaGetRange(int nIndex, int *pnMinGamma, int *pnMaxGamm);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����Gamma
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nValue [in] Gamma���õ�ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaSetValue(int nIndex, int nValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡGamma
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnValue [out] ����Gamma
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaGetValue(int nIndex, int *pnValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��������ԱȶȲ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nContrast [in] �Աȶ����õ�ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessContrastSet(int nIndex, int nContrast);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ����ԱȶȲ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnContrast [out] ���ضԱȶ����õ���Сֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
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
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessGetRange(int nIndex, int *pnMinBrightness, int *pnMaxBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �������������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nBrightness [in] �������õ�ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessSet(int nIndex, int nBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ������Ȳ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnBrightness [out] �����������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ProcessBrightnessGet(int nIndex, int *pnBrightness);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �Ƿ��ȡ��ʱ��ָ��豸
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bRecover [in] ��ȡ��ʱ���Ƿ�ָ��豸,true�ָ�,false���ָ�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetRecover(int nIndex, bool bRecover);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ��ǰ���ڳ�ʱ�ָ�������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbRecover [out] ��ȡ���ö�ȡ��ʱ���Ƿ�ָ��豸,true�ָ�,false���ָ�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
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
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
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
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
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
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
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
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
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
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
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

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����ͨ��KSJ_AEStartEx�������Զ��ع�����Ļص����������Զ��ع����ÿһ�ε���ʱ��KSJ���������Զ�����pfAECallbackEx�û�ָ���Ļص�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfAECallback [in] �û�������Զ��ع�ص�����ָ�루�ο�KSJ_AECALLBACK�����Ķ��壩
	/// @param     lpContext [in] �ص�������������ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������, �����Ƽ�ʹ�ã���ʹ��KSJ_AESetCallbackEx����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetCallback(int nIndex, KSJ_AECALLBACK pfAECallback, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����������Զ��ع����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bStart [in] �趨�����ڼ��ξͽ�����������û����õĴ������ع����û�дﵽ�û��趨��Ŀ��ֵ���ص���������ʾ�Զ��ع�ʧ��
	/// @param     nMaxCount [in] TRUE ��ʼ�Զ��ع���ڣ�FALSE ��ֹ������Զ��ع����
	/// @param     nTarget [in] ���ڵ���Ŀ������ֵ��0-255��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������, �����Ƽ�ʹ�ã���ʹ��KSJ_AEStartEx����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEStart(int nIndex, bool bStart, int nMaxCount, int nTarget);

	/// ���þ۽���������
	///-----------------------------------------------------------------------------
	///
	/// @brief     �����Զ��۽������Ĳο�����������������Ԥ��ͼ���λ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nX [in] �����������Ԥ��ͼ������Ͻ�ˮƽ����ƫ��
	/// @param     nY [in] �����������Ԥ��ͼ������ϽǴ�ֱ����ƫ��
	/// @param     nW [in] �����������Ԥ��ͼ����Զ��ع�����Ŀ��������Ϊ��λ
	/// @param     nH [in] �����������Ԥ��ͼ����Զ��ع�����ĸ߶�������Ϊ��λ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFSetRegion(int nIndex, int nX, int nY, int nW, int nH);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �Ƿ���ʾ�Զ��۽��Ĳο�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bShow [in] �Ƿ���ʾ�Զ��۽��ο�����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFShowRegion(int nIndex, bool bShow);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ�Զ��۽��Ĳο�������ʾ״̬��������������Ԥ��ͼ���λ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnX [out] ���������������Ԥ��ͼ������Ͻ�ˮƽ����ƫ��
	/// @param     pnY [out] ���������������Ԥ��ͼ������ϽǴ�ֱ����ƫ��
	/// @param     pnW [out] ���������������Ԥ��ͼ����Զ��ع�����Ŀ��������Ϊ��λ
	/// @param     pnH [out] ���������������Ԥ��ͼ����Զ��ع�����ĸ߶�������Ϊ��λ
	/// @param     pbShow [out] �ο������Ƿ���ʾ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �����Զ��۽���������������Ļص�����
	/// @param     nValue [out] �۽�����ֵ(0-10200)
	/// @param     lpContext [out] �û�������ָ�룬���ָ�����û�����KSJ_AFSetCallbackʱ�����������ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AFCALLBACK)(int nValue, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �����Զ��۽�����ֵ���������Ļص�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fpAFCallback [in] �û�������Զ��۽������ص�����ָ�루�ο�KSJ_AFCALLBACK�����Ķ��壩
	/// @param     lpContext [in] �ص�������������ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFSetCallback(int nIndex, KSJ_AFCALLBACK fpAFCallback, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ʼ��ֹͣ�Զ��۽��Զ���������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bStart [in] TRUE ��ʼ�Զ��۽��������㣬FALSE ��ֹ������Զ��۽���������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AFStart(int nIndex, bool bStart);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// Ӳ���Զ��ع�
	///-----------------------------------------------------------------------------
	///
	/// @brief     ������ر�AEC����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] true ����AEC���ܣ�false �ر�AEC����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECSetEnable ( int nIndex, bool bEnable  );

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡAEC�����Ƿ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] true AEC�����Ѿ�������false AEC�����Ѿ��ر�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECGetEnable ( int nIndex, bool *pbEnable  );

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����AEC�ĵ��ڷ�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     usMin [in] AEC�������ޣ��ع��У�
	/// @param     usMax [in] AEC�������ޣ��ع��У�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECSetRange ( int nIndex, unsigned short usMin,  unsigned short usMax  );

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡAEC�ĵ��ڷ�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pusMin [out] ����AEC�������ޣ��ع��У�
	/// @param     pusMax [out] ����AEC�������ޣ��ع��У�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECGetRange(int nIndex, unsigned short *pusMin, unsigned short *pusMax);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �õ�AEC�ĵ�ǰ�ع���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     usCur [out] ����AEC��ǰֵ���ع��У�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AECGetCur(int nIndex, unsigned short *usCur);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ������ر�AGC����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] true ����AGC���ܣ�false �ر�AGC����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCSetEnable(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡAGC�����Ƿ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] true  AGC�����Ѿ�������false  AGC�����Ѿ��ر�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetEnable(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����AGC�ĵ��ڷ�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     usMin [in] AGC������������
	/// @param     usMax [in] AGC������������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCSetRange(int nIndex, unsigned short usMin, unsigned short usMax);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡAGC�ĵ��ڷ�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pusMin [out] ����AGC������������
	/// @param     pusMax [out] ����AGC������������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetRange(int nIndex, unsigned short *pusMin, unsigned short *pusMax);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �õ�AGC�ĵ�ǰ����ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pusCur [out] ����AGC��ǰ����ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AGCGetCur(int nIndex, unsigned short *pusCur);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GammaLutFileDownload
	/// @brief     ��ktb�ļ���ʽ������Gamma LUT���ұ������
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pszKtbFile [in] .ktb�ļ�·��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaLutFileDownload(int nIndex, const TCHAR *pszKtbFile );

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GammaLutDataDownload
	/// @brief     �����û��Զ����Gamma LUT���ұ�����
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pData [out] ָ����ұ����ݵ�ָ�룬ÿ��Ԫ��Ϊ˫�ֽ�
	/// @param     nWords [in] ���ұ����ݸ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaLutDataDownload(int nIndex, unsigned short *pData, int nWords );

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GammaLutSetEnable
	/// @brief     ʹ��Gamma LUT���ұ���
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] �����Ƿ�ʹGamma LUT������Ч
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaLutSetEnable(int nIndex, bool bEnable   );

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GammaLutGetEnable
	/// @brief     ��ȡGamma LUT���ұ��Ƿ�ʹ��
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] �����Ƿ�Gamma LUT��������Ч
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GammaLutGetEnable(int nIndex, bool *pbEnable);


	enum KSJ_WATERMARKMODE ///ˮӡģʽ
	{ 
		KSJ_WMM_TIMESTAMP, 
		KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, 
		KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER 
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����ˮӡģʽ���°汾ˮӡ�Ѿ���֧��ˮӡģʽ���ã�Ĭ��KSJ_WMM_TIMESTAMP��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     WaterMarkMode [in] ����ˮӡģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetMode(int nIndex, KSJ_WATERMARKMODE WaterMarkMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡˮӡģʽ���°汾ˮӡ�Ѿ���֧��ˮӡģʽ���ã�Ĭ��KSJ_WMM_TIMESTAMP��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pWaterMarkMode [out] ��ȡ��ǰˮӡģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetMode(int nIndex, KSJ_WATERMARKMODE *pWaterMarkMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetErrorInfo
	/// @brief     ��ô������ϸ��Ϣ�ַ���
	/// @param     nErrorNo [in] ����������, ��ο� KSJCode.h �д�����Ķ��塣
	/// @param     pszErrorInfo[out] �������������Ϣ�ַ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetErrorInfo(IN int nErrorNo, OUT TCHAR pszErrorInfo[256]);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetFrameRate
	/// @brief     ��ȡ֡��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fFrameRate [out] ���ص�ǰ��Ƶ����֡��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRate(int nIndex, float *fFrameRate);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ��ͣʱ����һ֡ͼ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pData [out] ���û��ṩ���������򣬺������÷��غ󣬴�����ᱻ�����ͣʱ��ͼ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedData(int nIndex, unsigned char *pData);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewPause
	/// @brief     ��ͣ�������Ƶ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bPause   [in] true ��ͣ��Ƶ����false ������Ƶ�� 
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewPause(int nIndex, bool bPause);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ��ͣʱ����һ֡ͼ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pData [out] ���û��ṩ���������򣬺������÷��غ󣬴�����ᱻ�����ͣʱ��ͼ������
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
	/// @param     pnHeight[out] ����ͼ��ĸ߶ȣ����أ�
	/// @param     pnBitCount[out] ����ͼ���ÿ������λ����8��24��32��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedDataEx(int nIndex, unsigned char *pData, int *pnWidth, int *pnHeight, int *pnBitCount);

	/// Preview Mode
	enum KSJ_PREVIEWMODE// ö��������ƵԤ��ģʽ
	{
		PM_RAWDATA, ///Ԥ��ԭʼ���ݣ����ںڰ��豸����������ΪPM_RAWDATA
		PM_RGBDATA  ///Ԥ��24λ��32λ��ɫ���ݣ���Bayerģʽ������
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ�豸Ĭ�ϵ�Ԥ��ģʽ
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pPreviewMode   [out] ��ȡ���Ĭ�ϵ�Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewSetMode
	/// @brief     ������Ƶ��Ϊԭʼ�ɼ����ݻ���RGB 24λ��32λ��ɫ���ݸ�ʽ��һ���û���������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     PreviewMode [in] ���õ�Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetMode(int nIndex, KSJ_PREVIEWMODE PreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetMode
	/// @brief     ��ȡ����ĵ�ǰԤ��ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pPreviewMode   [out] ��ȡ��ǰ��Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreviewSetCalibration
	/// @brief     ��Ԥ�����Ƿ���л����������
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] Ϊtrueʱʱ�����������, falseʱ�رջ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreviewGetCalibration
	/// @brief     ��ȡ��ǰԤ�����Ƿ���л����������
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] ���ػ����������Ԥ����ʹ��״̬
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetCalibration(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureSetCalibration
	/// @brief     �Բɼ��Ƿ���л����������
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] Ϊtrueʱʱ�����������, falseʱ�رջ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureGetCalibration
	/// @brief     ��ȡ�ɼ�ʱ�Ƿ���л����������
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] ���ػ���������ڲɼ���ʹ��״̬
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetCalibration(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LoadCalibrationMapFile
	/// @brief     ���ڴ��ļ����ػ���У��������Ϣ
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pszFilePath [in] ��Ҫ�����ػ���У���������ļ���������·����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadCalibrationMapFile(int nIndex, const TCHAR *pszFilePath);

	enum KSJ_MAPMODE ///���Ӽѹ�ҵ�������У��Ŀ��ֵ���㷽ʽ����
	{
		KSJ_MM_NEARESTNEIGHBOR,
		KSJ_MM_BILINEAR
	};

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SetCalibrationMapMode
	/// @brief     ���û���У��Ŀ��ֵ���㷽��
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     MapMode [in] ���û���У��Ŀ��ֵ���㷽��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetCalibrationMapMode(int nIndex, KSJ_MAPMODE MapMode);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GetCalibrationMapMode
	/// @brief     ��ȡ����У��Ŀ��ֵ���㷽��
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pMapMode [out] ��ǰ����У��Ŀ��ֵ�ļ��㷽��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetCalibrationMapMode(int nIndex, KSJ_MAPMODE *pMapMode);


	enum KSJ_SNAPBUTTONSTATUS ///Snap��������״̬
	{
		KSJ_UP, 	///�������ڱպ�״̬
		KSJ_DOWN 	///�������ڿ���״̬
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡSnap��������״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pSnapButtonStatus [out] ����Snap��������״̬, KSJ_SNAPBUTTONSTATUS����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SnapButtonStatus(int nIndex, KSJ_SNAPBUTTONSTATUS *pSnapButtonStatus);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HelperStretchBmp
	/// @brief     ��pData(���ΪnWidth, �߶�ΪnHeight, ����λ��ΪnBitCount)��ͼ����������Ϊ���ΪnStretchWidh, �߶�ΪnStretchHeight�����ݲ���䵽�û������pStretchData������,����λ������
	/// ������
	/// @param     pData [in] ����ͼ�������ָ��
	/// @param     nWidth [in] ����ͼ��Ŀ��
	/// @param     nHeight [in] ����ͼ��ĸ߶�
	/// @param     nBitCount [in] ����ͼ��ı������
	/// @param     pStretchData [out] ���ͼ�񱣴��ڴ��ַָ��
	/// @param     nStretchWidth [out] ���ͼ��Ŀ��
	/// @param     nStretchHeight [out] ���ͼ��ĸ߶�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperStretchBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char *pStretchData, int nStretchWidth, int nStretchHeight);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HelperGetBmpFileHeaderSize
	/// @brief     ����ͼ��ı�����ȵõ�BMPͼ����ļ�ͷ,��Ϣͷ,����ɫ���ܵ��ֽ���Ŀ
	/// ������
	/// @param     nBitCount [in] ͼ��ı������
	/// @param     pnTotalBytes [out] BMP���ļ�ͷ����Ϣͷ���Լ���ɫ������ֽ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeaderSize(int nBitCount, int *pnTotalBytes);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HelperGetBmpFileHeader
	/// @brief     �õ�BMPͼ����ļ�ͷ����Ϣͷ
	/// ������
	/// @param     nWidth [in] ͼ��Ŀ��
	/// @param     nHeight [in] ͼ��ĸ߶�
	/// @param     nBitCount [in] ͼ��ı������
	/// @param     pHeader [out] BMP���ļ�ͷ����Ϣͷ���ݱ���ĵ�ַָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, void *pHeader);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureRgbDataToClipboard
	/// @brief     �ɼ�һ֡ͼ��ϵͳ�����壬��һ������ɼ�һ֡ͼ�񲢷ŵ�ϵͳ�ļ��а�
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataToClipboard(int nIndex);

	KSJ_API  int __stdcall KSJ_GammaLutInfoProgram(int nIndex, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_GammaLutInfoReadout(int nIndex, unsigned short *pValue);

	KSJ_API  int __stdcall KSJ_GammaLutFileProgram(int nIndex, TCHAR *pszFile);
	KSJ_API  int __stdcall KSJ_GammaLutDataProgram(int nIndex, unsigned short *pData, int nWords);
	KSJ_API  int __stdcall KSJ_GammaLutDataReadout(int nIndex, unsigned short *pData, int *pnWords);

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