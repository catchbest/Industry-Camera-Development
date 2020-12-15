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

	/// �������ģʽ����
	enum KSJ_TRIGGERMODE
	{
		KSJ_TRIGGER_INTERNAL,             /// �ڴ���ģʽ��Free run����ģʽ����������Բɼ�ͼ���ʱ�򣬱���֡����Ϊ�յ�ʱ�򣬾ʹ�Sensor�ɼ�ͼ��
		KSJ_TRIGGER_EXTERNAL,             /// �ⴥ��ģʽ����������յ��ⴥ���źŵ�ʱ�򣬴�Sensor�ɼ�ͼ��������ʱ��֡�����ڵ�ͼ��û�б����ߣ��ͻᶪ֡��
		KSJ_TRIGGER_SOFTWARE,             /// ����ģʽ����Capture��ʱ�򣬴������ȥSensor�ɼ�ͼ���ϴ���
		KSJ_TRIGGER_FIXFRAMERATE,         /// �̶�֡��ģʽ������Զ����趨��֡�ʴ�Sensor�ɼ�ͼ������ϲ�APP���ܹ���ʱ��ȡ���ݣ����ܻ���ɶ�֡��
		KSJ_TRIGGER_HIGHLOWFIXFRAMERATE   /// �ߵ͵�ƽ�̶�֡��ģʽ���������ã����ⴥ���ź���Ϊ��/�͵�ƽʱ������Զ����趨��֡�ʴ�Sensor�ɼ�ͼ������ϲ�APP���ܹ���ʱ��ȡ���ݣ����ܻ���ɶ�֡��
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerModeSet
	/// @brief     ��������Ĵ�������ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     TriggerMode [in] ��Ҫ���õ��������ģʽ����ο�KSJ_TRIGGERMODE��˵��
	/// @return    �ɹ�����RET_SUCCESS����֧�ֵĴ���ģʽ������RET_NOTSUPPORT����������ο���״̬�루KSJCode.h��
	/// @attention ����KSJ_Init������ʼ������á�
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeSet(int nIndex, KSJ_TRIGGERMODE TriggerMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerModeGet
	/// @brief     ��ȡ��ǰ����Ĵ�������ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     TriggerMode [out] �õ���ǰ����Ĺ���ģʽ����ο�KSJ_TRIGGERMODE��˵��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerModeGet(int nIndex, KSJ_TRIGGERMODE *pTriggerMode);

	/// �������״̬
	enum KSJ_TRIGGERSTATUS
	{
		KSJ_NO,   ///< ����Ϊ��
		KSJ_HAVE  ///< ����ǿ�
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerStatusGet
	/// @brief     ��ȡ�������״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pTriggerStatus [out] �õ���ǰ����İ弶�������Ƿ���ͼ�����ݿɹ���ȡ��KSJ_HAVE��ʾ��1�����߶��ͼ�񱣴���֡����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣����֧�ָù��ܵ����������RET_NOTSUPPORT
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerStatusGet(int nIndex, KSJ_TRIGGERSTATUS *pTriggerStatus);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_EmptyFrameBuffer
	/// @brief     ���֡���е�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣����ģʽ�£� ��֧����ջ��棬����RET_NOTSUPPORT
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_EmptyFrameBuffer(int nIndex);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ����Ĺ̶�֡�����÷�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pfRateMin [out] �̶�֡���ܹ����õ���Сֵ
	/// @param     pfRateMax [out] �̶�֡���ܹ����õ����ֵ
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateRang(int nIndex, float* pfRateMin, float* pfRateMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���������Ϊ�̶�֡�ʴ���ģʽ���߸ߵ͵�ƽ��Ч�̶�֡�ʴ���ģʽʱ,��������Ĺ̶�֡��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fFrameRate [in] ���ù̶�֡�ʣ�֡ÿ�룩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ������ã�ֻ���ڴ���ģʽ����Ϊ�������Ϊ�̶�֡�ʴ���ģʽ���߸ߵ͵�ƽ��Ч�̶�֡�ʴ���ģʽʱ�����ܹ����øú��������򷵻�RET_NOTSUPPORT
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFixedFrameRateEx(int nIndex, float fFrameRate);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetFixedFrameRateEx
	/// @brief     �õ���ǰ���õĹ̶�֡��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfFrameRate [out] �õ���ǰ���õĹ̶�֡�ʣ�֡ÿ�룩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFixedFrameRateEx(int nIndex, float *pfFrameRate);
	
	/// �ⴥ���ź�����
	enum KSJ_TRIGGERMETHOD
	{
		KSJ_TRIGGER_FALLINGEDGE,    ///< �����أ�ÿһ���ⴥ���ź������ش���һ��ͼ��ɼ� 
		KSJ_TRIGGER_RISINGEDGE,     ///< �½��أ�ÿһ���ⴥ���ź��½��ش���һ��ͼ��ɼ� 
		KSJ_TRIGGER_HIGHLEVEL,      ///< �ߵ�ƽ���ⴥ���źŴ��ڸߵ�ƽ��ʱ�����������Freerun��ʽ�����ɼ�ͼ�� 
		KSJ_TRIGGER_LOWLEVEL        ///< �͵�ƽ���ⴥ���źŴ��ڵ͵�ƽ��ʱ�����������Freerun��ʽ�����ɼ�ͼ��
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerMethodSet
	/// @brief     �����ⴥ���Ĵ�������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     TriggerMethod [in] �����ⴥ��ģʽʱ,��������������ο�KSJ_TRIGGERMETHOD��˵��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodSet(int nIndex, KSJ_TRIGGERMETHOD  TriggerMethod);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerMethodGet
	/// @brief     �õ���ǰ������õ��ⴥ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pTriggerMethod [out] �õ���ǰ������õ��ⴥ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerMethodGet(int nIndex, KSJ_TRIGGERMETHOD *pTriggerMethod);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerDelayGetRange
	/// @brief     ��ȡ�ⴥ����ʱ��ʱ�䷶Χ����������Ϊ100uS��Ҳ���ǻ�ȡ��ֵ����100usΪʵ�ʵ�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wMin [out] �ⴥ����ʱ����С����ֵ�����ֵ����100usΪʵ�ʵ�ʱ��
	/// @param     wMax [out] �ⴥ����ʱ���������ֵ�����ֵ����100usΪʵ�ʵ�ʱ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ������ã���ʾ����յ��ⴥ���ź�֮�󣬻��ӳ�����趨��ʱ���ٴ�Sensor�ɼ�ͼ��
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerDelaySet
	/// @brief     �����ⴥ����ʱʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wDelay [in] ������ʱʱ�䣬���ֵ����100usΪʵ�ʵ�ʱ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelaySet(int nIndex, unsigned short wDelay);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_TriggerDelayGet
	/// @brief     ��ȡ�û����õ��ⴥ����ʱʱ�䣬��λΪ100us
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pwDelay [out] ��ȡ���ⴥ����ʱʱ�䣬��λΪ100us
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerDelayGet(int nIndex, unsigned short *pwDelay);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureSetTimeOut
	/// @brief     ���ó�ʱʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     dwTimeOut [in] ���ó�ʱʱ��,��λΪ����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ������ã����òɼ�ͼ��KSJ_CaptureRgbData�ȣ��ĳ�ʱʱ�䣬�ⴥ��ʱ�����ʱ����ô����ⴥ�����ܵ����ʱ����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetTimeOut(int nIndex, unsigned long dwTimeOut);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetTimeOut
	/// @brief     ��ȡ��ʱʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pdwTimeOut [out] ��ȡ��ȡһ֡ͼ��ĳ�ʱʱ�䣬��λΪ����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetTimeOut(int nIndex, unsigned long *pdwTimeOut);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_TriggerSignalPeriodGetRange
    /// @brief     ��ȡ�ⴥ����Ƶ��Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fMin [out] ��Ƶ����Сֵ��ĿǰΪ1
	/// @param     fMax [out] ��Ƶ�����ֵ
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGetRange(int nIndex, float * fMin, float *fMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_TriggerSignalPeriodSet
    /// @brief     �����ⴥ����Ƶ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fPeriodCount [in] �����ⴥ����Ƶֵ��Ŀǰ��������Ч����СֵΪ1
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
    ///           \li �����������������ֵ���������ⴥ���źŴ����ɼ�һ֡ͼ�񣺱������ó�2����ô�����ⴥ���źŲɼ�һ֡ͼ��
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodSet(int nIndex, float fPeriodCount);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_TriggerSignalPeriodGet
    /// @brief     ��ȡ�ⴥ����Ƶ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfPeriodCount [out] ��ǰ���ⴥ����Ƶֵ
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_TriggerSignalPeriodGet(int nIndex, float* pfPeriodCount);

	/// �����ʼ�����ɼ���������ģʽ
	enum KSJ_STARTENDMODE
	{
		KSJ_SEMODE_CONTINUE,	///< ���һֱ���ڿ�ʼ״̬����ʱ�ȴ�ͼ�񴥷��źŲ��ɼ�ͼ��
		KSJ_SEMODE_RISINGEDGE,	///< ��������Ϊ��ʼ�źţ��ɼ��̶�֡����ֹͣ����KSJ_CaptureMultiLineSet�����趨��
		KSJ_SEMODE_FALLINGEDGE, ///< �½�����Ϊ��ʼ�źţ��ɼ��̶�֡����ֹͣ����KSJ_CaptureMultiLineSet�����趨��
		KSJ_SEMODE_HIGHLEVEL,	///< �ߵ�ƽ��Ч���ߵ�ƽ��ʱ�������ʼ����ɼ�ͼ��״̬
		KSJ_SEMODE_LOWLEVEL,	///< �͵�ƽ��Ч���͵�ƽ��ʱ�������ʼ����ɼ�ͼ��״̬
		KSJ_SEMODE_SOFTWARE,	///< �����������Ŀ�ʼ�����ɼ��������ɼ��̶�֡����ֹͣ����KSJ_CaptureMultiLineSet�����趨��
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_StartEndModeSet
    /// @brief     ���������ʼ�����ɼ������Ŀ���ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     SeMode [in] �����ʼ�����ɼ������Ŀ���ģʽ����ο�KSJ_STARTENDMODE�Ķ���
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeSet(int nIndex, KSJ_STARTENDMODE SeMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_StartEndModeGet
    /// @brief     ��������ʼ�����ɼ������Ŀ���ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pSeMode [out] ��ǰ�����ʼ�����ɼ������Ŀ���ģʽ
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StartEndModeGet(int nIndex, KSJ_STARTENDMODE* pSeMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartDelayGetRange
    /// @brief     ��ȡ�����ʼ��ʱ���÷�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     wMin [out] �����ʼ��С�ӳ�
	/// @param     wMax [out] �����ʼ����ӳ�
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGetRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartDelaySet
    /// @brief     ���������ʼ��ʱ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wDelay [in] �����ʼ�ӳ�ֵ����λΪ�ź���
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelaySet(int nIndex, unsigned short wDelay);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartDelayGet
    /// @brief     ��ȡ�����ʼ��ʱ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pwDelay [out] ��ǰ�����ʼ�ӳ�ֵ����λΪ�ź���
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartDelayGet(int nIndex, unsigned short *pwDelay);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartFilterRange
    /// @brief     ��ȡ�����ʼ�����ź��˲���Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     wMin [out] ��С�˲�ֵ����λ��΢��
	/// @param     wMax [out] ����˲�ֵ����λ��΢��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartFilterSet
    /// @brief     ���������ʼ�����ź��˲�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wFilter [in] �ź��˲�ֵ����λ��΢��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterSet(int nIndex, unsigned short wFilter);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureStartFilterGet
    /// @brief     ��ȡ�����ʼ�����ź��˲�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pwFilter [out] ��ǰ�ź��˲�ֵ����λ��΢��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureStartFilterGet(int nIndex, unsigned short *pwFilter);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureMultiLineRange
    /// @brief     ��ȡ֡�������÷�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     wMin [out] ��С֡����
	/// @param     wMax [out] ���֡����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineRange(int nIndex, unsigned short *wMin, unsigned short *wMax);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureMultiLineSet
    /// @brief     ���òɼ�֡����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wMultiLine [in] ���õĲɼ�֡����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineSet(int nIndex, unsigned short wMultiLine);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureMultiLineGet
    /// @brief     ���òɼ�֡����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pwMultiLine [out] ��ǰ���õĲɼ�֡����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureMultiLineGet(int nIndex, unsigned short *pwMultiLine);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_CaptureSoftwareStart
    /// @brief     ������������ʼ�ɼ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
    ///          \li �����������ģʽ����ΪKSJ_SEMODE_SOFTWARE��ʱ�򣬸ú�����Ч��ִ�иú����Ժ��������ɼ�ģʽ��ֱ���ɼ��㹻MultiLine֮�����.
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSoftwareStart(int nIndex);

#ifdef __cplusplus
}
#endif

#endif