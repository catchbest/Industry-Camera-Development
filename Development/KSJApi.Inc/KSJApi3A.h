#ifndef __KSJ_API_3A_H__
#define __KSJ_API_3A_H__

// #pragma message("Include KSJApi3A.h") 

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

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetRegion
	/// @brief     �����Զ��ع�Ĳο�����������������Ԥ��ͼ���λ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nX [in] �����������Ԥ��ͼ������Ͻ�ˮƽ����ƫ��
	/// @param     nY [in] �����������Ԥ��ͼ������ϽǴ�ֱ����ƫ��
	/// @param     nW [in] �����������Ԥ��ͼ����Զ��ع�����Ŀ�ȣ�������Ϊ��λ
	/// @param     nH [in] �����������Ԥ��ͼ����Զ��ع�����ĸ߶ȣ�������Ϊ��λ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetRegion(int nIndex, int nX, int nY, int nW, int nH);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEGetRegion
	/// @brief     ��ȡ�Զ��ع�Ĳο�������ʾ״̬��������������Ԥ��ͼ���λ��
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
	KSJ_API  int __stdcall KSJ_AEGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEShowRegion
    /// @brief     �����Ƿ�Ԥ��ʱ��ʾ�Զ��ع�Ĳο�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bShow [in] �Ƿ���ʾ�Զ��ع�ο�����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEShowRegion(int nIndex, bool bShow);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetPeakAveRatio
	/// @brief     �����Զ��ع��ֵ���ص�ͳ�Ʊ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fRatio [in] ���õķ�ֵ���ʣ���Χ0��1
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ����룬��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li �Զ��ع�ͳ����������ֵ��ʱ��������ֵ���أ�255����������ֵ���ԣ�1+fRatio���ı��ʲ���ͳ��
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetPeakAveRatio(int nIndex, float fRatio);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEGetPeakAveRatio
	/// @brief     ��ȡ�Զ��ع��ֵ���ص�ͳ�Ʊ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfRatio [out] �����Զ��ع��ֵ���ص�ͳ�Ʊ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetPeakAveRatio(int nIndex, float *pfRatio);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetExposureTimeRange
	/// @brief     �����Զ��ع�ĵ��ڷ�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fMinExpMs [in] �����Զ��ع�������ޣ���λ������
	/// @param     fMaxExpMs [in] �����Զ��ع�������ޣ���λ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li �����Զ��ع�ʱ���ع�ֵ�������������Χ���е���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetExposureTimeRange(int nIndex, float fMinExpMs,   float fMaxExpMs);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEGetExposureTimeRange
	/// @brief     ��ȡ�Զ��ع�ĵ��ڷ�Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfMinExpMs [in] �����Զ��ع�������ޣ���λ������
	/// @param     pfMaxExpMs [in] �����Զ��ع�������ޣ���λ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetExposureTimeRange(int nIndex, float *pfMinExpMs, float *pfMaxExpMs);

	/// �Զ��ع����㷵��״̬
	enum KSJ_AE_STATUS
	{
		KSJ_AE_ONCE_SUCCESS = 0, 			///< ���ε��ڳɹ�
		KSJ_AE_ONCE_FAIL_MAX_COUNT, 		///< ���ε���ʧ�ܣ�ʧ��ԭ��ﵽ�����ڴ���
		KSJ_AE_ONCE_FAIL_WAVE, 				///< ���ε���ʧ�ܣ�ʧ��ԭ�����������
		KSJ_AE_ONCE_FAIL_OVER_RANGE, 		///< ���ε���ʧ�ܣ�ʧ��ԭ���عⳬ�����÷�Χ
		KSJ_AE_DOING, 						///< ���ε�����ɣ��������µ��ع�ʱ��
		KSJ_AE_CONTINUE_SUCCESS,			///< �������ڳɹ�����ǰ�ﵽ��Ŀ��ֵ
		KSJ_AE_CONTINUE_FAIL_WAVE, 			///< ��������ʧ�ܣ�ʧ��ԭ�����������
		KSJ_AE_CONTINUE_FAIL_OVER_RANGE 	///< ��������ʧ�ܣ�ʧ��ԭ���عⳬ�����÷�Χ
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AECALLBACKEX
	/// @brief     �Զ��ع�ص���������
	/// @param     Status [out] ��ǰ�Զ��ع������״̬���ο�KSJ_AE_STATUS˵����
	/// @param     nExpsoureTimeMs [out] ���Զ��ع���ڽ����󣬵�ǰ���ع�ֵ����λ������
	/// @param     lpContext [out] �û�������ָ�룬���ָ�����û�����KSJ_AESetCallbackExʱ�����������ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AECALLBACKEX)( KSJ_AE_STATUS Status, int nExpsoureTimeMs, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetCallbackEx
	/// @brief     �����Զ��ع�����Ļص�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfAECallbackEx [in] �û�������Զ��ع�ص�����ָ��
	/// @param     lpContext [in] �ص�������������ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li �Զ��ع����һ���ع����в�����ʱ�����Զ�����pfAECallbackEx�û�ָ���Ļص�����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetCallbackEx(int nIndex, KSJ_AECALLBACKEX pfAECallbackEx, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AESetMaxCount
	/// @brief     �����Զ��ع����������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nMaxCount [in] �����Զ��ع����������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li �Զ��ع�������nMaxCountָ�����������
	///          \li �����Ҫ�Զ��ع��������У�������nMaxCountΪ-1
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetMaxCount(int nIndex, int  nMaxCount);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEStartEx
	/// @brief     ����������Զ��ع����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bStart [in] true ��ʼ�Զ��ع���ڣ�false ��ֹ������Զ��ع����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AESetTarget(int nIndex, int  nTarget);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AEGetStatusEx
	/// @brief     �õ��Զ��ع������״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbStart [out] �õ��Զ��ع⵱ǰ�Ƿ�����
	/// @param     pnMaxCount [out] �õ��Զ��ع�������ڴ���
	/// @param     pnTarget [out] �õ��Զ��ع���ڵ�Ŀ��ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEStartEx(int nIndex, bool bStart);

	///-----------------------------------------------------------------------------
	///
    /// @brief     �õ��Զ��ع������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbStart [out] �õ�KSJ_AEStartEx�Ƿ�����
	/// @param     pnMaxCount [out] �õ��Զ��ع�������ڴ���
	/// @param     pnTarget [out] �õ��Զ��ع���ڵ�Ŀ��ֵ
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AEGetStatusEx(int nIndex, bool *pbStart, int *pnMaxCount, int *pnTarget);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AWBSetRegion
	/// @brief     �����Զ���ƽ��Ĳο�����������������Ԥ��ͼ���λ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nX [in] �����������Ԥ��ͼ������Ͻ�ˮƽ����ƫ��
	/// @param     nY [in] �����������Ԥ��ͼ������ϽǴ�ֱ����ƫ��
	/// @param     nW [in] �����������Ԥ��ͼ����Զ��ع�����Ŀ�ȣ�������Ϊ��λ
	/// @param     nH [in] �����������Ԥ��ͼ����Զ��ع�����ĸ߶ȣ�������Ϊ��λ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_AECALLBACK)(bool bSuccess, int nResult, void *lpContext);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AWBSetRegion
	/// @brief     �����Զ���ƽ��Ĳο�����������������Ԥ��ͼ���λ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nX [in] �����������Ԥ��ͼ������Ͻ�ˮƽ����ƫ��
	/// @param     nY [in] �����������Ԥ��ͼ������ϽǴ�ֱ����ƫ��
	/// @param     nW [in] �����������Ԥ��ͼ����Զ��ع�����Ŀ�ȣ�������Ϊ��λ
	/// @param     nH [in] �����������Ԥ��ͼ����Զ��ع�����ĸ߶ȣ�������Ϊ��λ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBSetRegion(int nIndex, int nX, int nY, int nW, int nH);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_AWBShowRegion
    /// @brief     ����Ԥ��ʱ�Ƿ���ʾ�Զ���ƽ��Ĳο�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bShow [in] �Ƿ���ʾ�Զ���ƽ��ο�����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBShowRegion(int nIndex, bool bShow);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_AWBGetRegion
	/// @brief     ��ȡ�Զ���ƽ��Ĳο�������ʾ״̬��������������Ԥ��ͼ���λ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnX [out] ���������������Ԥ��ͼ������Ͻ�ˮƽ����ƫ��
	/// @param     pnY [out] ���������������Ԥ��ͼ������ϽǴ�ֱ����ƫ��
	/// @param     pnW [out] ���������������Ԥ��ͼ����Զ��ع�����Ŀ�ȣ�������Ϊ��λ
	/// @param     pnH [out] ���������������Ԥ��ͼ����Զ��ع�����ĸ߶ȣ�������Ϊ��λ
	/// @param     pbShow [out] �ο������Ƿ���ʾ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_AWBGetRegion(int nIndex, int *pnX, int *pnY, int *pnW, int *pnH, bool *pbShow);

#ifdef __cplusplus
}
#endif

#endif