#ifndef __KSJ_API_TRIGGER_MODE_H__
#define __KSJ_API_TRIGGER_MODE_H__

// #pragma message("Include KSJApiTriggerMode.h") 

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

	enum KSJ_TRIGGERMODE//���Ӽѹ�ҵ�����������ģʽ
	{
		KSJ_TRIGGER_INTERNAL,
		KSJ_TRIGGER_EXTERNAL,
		KSJ_TRIGGER_SOFTWARE,
		KSJ_TRIGGER_FIXFRAMERATE,
		KSJ_TRIGGER_HIGHLOWFIXFRAMERATE
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����������ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     TriggerMode [in] ��Ҫ���õ��������ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeSet(int nIndex, KSJ_TRIGGERMODE TriggerMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ǰ����Ĵ�������ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     TriggerMode [out] �õ���ǰ����Ĺ���ģʽ����ο�KSJ_TRIGGERMODE��˵��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeGet(int nIndex, KSJ_TRIGGERMODE *pTriggerMode);

	enum KSJ_TRIGGERSTATUS//���֡���״̬
	{
		KSJ_NO,
		KSJ_HAVE
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�������״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pTriggerStatus [out] �õ���ǰ����İ弶�������Ƿ���ͼ�����ݿɹ���ȡ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerStatusGet(int nIndex, KSJ_TRIGGERSTATUS *pTriggerStatus);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���֡���е�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_EmptyFrameBuffer(int nIndex);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���֡���ɼ�һ֡ԭʼ��ڰ�ͼ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRawData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize�������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawDataAfterEmptyFrameBuffer(int nIndex, unsigned char *pRawData);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureRgbDataAfterEmptyFrameBuffer
    /// @brief     ���֡���ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRgbData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���֡���ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRgbData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
    /// @param     pnHeight [out] ����ͼ��ĸ߶ȣ����أ�
    /// @param     pnBitCount [out] ����ͼ���ÿ������λ����8��24��32������KSJ_PreviewSetMode��KSJ_BayerSetMode������Ӱ��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataExAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ����Ĺ̶�֡�����÷�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pfRateMin [out] �̶�֡���ܹ����õ���Сֵ
	/// @param     pfRateMax [out] �̶�֡���ܹ����õ����ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateRang(int nIndex, float* pfRateMin, float* pfRateMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���������Ϊ�̶�֡�ʴ���ģʽ���߸ߵ͵�ƽ��Ч�̶�֡�ʴ���ģʽʱ,��������Ĺ̶�֡��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fFrameRate [in] ���ù̶�֡�ʣ�֡ÿ�룩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFixedFrameRateEx(int nIndex, float fFrameRate);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �õ���ǰ�̶�֡�ٵ�״̬��Ϣ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pfFrameRate [out] �õ���ǰ���õĹ̶�֡�ʣ�֡ÿ�룩
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateEx(int nIndex, float *pfFrameRate);

	enum KSJ_TRIGGERMETHOD//�ⴥ���Ĵ�������
	{
		KSJ_TRIGGER_FALLINGEDGE,
		KSJ_TRIGGER_RISINGEDGE,
		KSJ_TRIGGER_HIGHLEVEL,
		KSJ_TRIGGER_LOWLEVEL
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����ⴥ���Ĵ�������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     TriggerMethod [in] �����ⴥ��ģʽʱ,��������������ο�KSJ_TRIGGERMETHOD��˵��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodSet(int nIndex, KSJ_TRIGGERMETHOD  TriggerMethod);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �õ���ǰ������õ��ⴥ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pTriggerMethod [out] �õ���ǰ������õ��ⴥ������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodGet(int nIndex, KSJ_TRIGGERMETHOD *pTriggerMethod);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�ⴥ����ʱ��ʱ�䷶Χ����������Ϊ100uS��Ҳ���ǻ�ȡ��ֵ����100usΪʵ�ʵ�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     wMin [out] �ⴥ����ʱ����С����ֵ�����ֵ����100usΪʵ�ʵ�ʱ��
	/// @param     wMax [out] �ⴥ����ʱ���������ֵ�����ֵ����100usΪʵ�ʵ�ʱ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����ⴥ���Ĵ�������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     wDelay [in] ������ʱʱ�䣬���ֵ����100usΪʵ�ʵ�ʱ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelaySet(int nIndex, unsigned short wDelay);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�û����õ��ⴥ����ʱʱ�䣬��λΪ100us
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pwDelay [out] ��ȡ���ⴥ����ʱʱ�䣬��λΪ100us
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGet(int nIndex, unsigned short *pwDelay);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���ó�ʱʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     dwTimeOut [in] ���ó�ʱʱ��,��λΪ����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetTimeOut(int nIndex, unsigned long dwTimeOut);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ʱʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pdwTimeOut [out] ��ȡ��ȡһ֡ͼ��ĳ�ʱʱ�䣬��λΪ����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetTimeOut(int nIndex, unsigned long *pdwTimeOut);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�ⴥ����Ƶ��Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fMin [out] ��Ƶ����Сֵ��ĿǰΪ1
	/// @param     fMax [out] ��Ƶ�����ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGetRange(int nIndex, float * fMin, float *fMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����ⴥ����Ƶ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fPeriodCount [in] �����ⴥ����Ƶֵ��Ŀǰ��������Ч����СֵΪ1
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodSet(int nIndex, float fPeriodCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�ⴥ����Ƶ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfPeriodCount [out] ��ǰ���ⴥ����Ƶֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGet(int nIndex, float* pfPeriodCount);

	enum KSJ_STARTENDMODE//�����ʼ�����ɼ���������ģʽ
	{
		KSJ_SEMODE_CONTINUE,	///���һֱ���ڿ�ʼ״̬����ʱ�ȴ�ͼ�񴥷��źŲ��ɼ�ͼ��
		KSJ_SEMODE_RISINGEDGE,	///��������Ϊ��ʼ�źţ��ɼ��̶�֡����ֹͣ����KSJ_CaptureMultiLineSet�����趨��
		KSJ_SEMODE_FALLINGEDGE, ///�½�����Ϊ��ʼ�źţ��ɼ��̶�֡����ֹͣ����KSJ_CaptureMultiLineSet�����趨��
		KSJ_SEMODE_HIGHLEVEL,	///�ߵ�ƽ��Ч���ߵ�ƽ��ʱ�������ʼ����ɼ�ͼ��״̬
		KSJ_SEMODE_LOWLEVEL,	///�͵�ƽ��Ч���͵�ƽ��ʱ�������ʼ����ɼ�ͼ��״̬
		KSJ_SEMODE_SOFTWARE,	///�����������Ŀ�ʼ�����ɼ��������ɼ��̶�֡����ֹͣ����KSJ_CaptureMultiLineSet�����趨��
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���������ʼ�����ɼ������Ŀ���ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     SeMode [in] �����ʼ�����ɼ������Ŀ���ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeSet(int nIndex, KSJ_STARTENDMODE SeMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��������ʼ�����ɼ������Ŀ���ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pSeMode [out] ��ǰ�����ʼ�����ɼ������Ŀ���ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeGet(int nIndex, KSJ_STARTENDMODE* pSeMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�����ʼ��ʱ���÷�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     wMin [out] �����ʼ��С�ӳ�
	/// @param     wMax [out] �����ʼ����ӳ�
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���������ʼ��ʱ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wDelay [in] �����ʼ�ӳ�ֵ����λΪ�ź���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelaySet(int nIndex, unsigned short wDelay);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�����ʼ��ʱ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pwDelay [out] ��ǰ�����ʼ�ӳ�ֵ����λΪ�ź���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGet(int nIndex, unsigned short *pwDelay);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�����ʼ�����ź��˲���Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     wMin [out] ��С�˲�ֵ����λ��΢��
	/// @param     wMax [out] ����˲�ֵ����λ��΢��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���������ʼ�����ź��˲�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wFilter [in] �ź��˲�ֵ����λ��΢��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterSet(int nIndex, unsigned short wFilter);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�����ʼ�����ź��˲�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pwFilter [out] ��ǰ�ź��˲�ֵ����λ��΢��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterGet(int nIndex, unsigned short *pwFilter);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ֡�������÷�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     wMin [out] ��С֡����
	/// @param     wMax [out] ���֡����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���òɼ�֡����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wMultiLine [in] ���õĲɼ�֡����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineSet(int nIndex, unsigned short wMultiLine);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���òɼ�֡����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pwMultiLine [out] ��ǰ���õĲɼ�֡����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineGet(int nIndex, unsigned short *pwMultiLine);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ������������ʼ�ɼ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSoftwareStart(int nIndex);

#ifdef __cplusplus
}
#endif

#endif