#ifndef __KSJ_API_RECORD_H__
#define __KSJ_API_RECORD_H__

// #pragma message("Include KSJApiRecord.h") 

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
	/// @brief     Ԥ������״̬�£������Ƿ�������ֹͣ��Ƶ¼Ӱ��������Ƶ�������Ի����ڹ��û�ѡ����Ƶ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bStart [in] �Ƿ�����¼Ӱ�����Ϊfalse������������������
	/// @param     fRecordRate [in] ����¼Ӱ֡�٣����֡�ٴ���¼Ӱ�ļ��Ļط�֡��
	/// @param     pFileName [in] ¼Ӱ�ļ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStart(int nIndex, bool bStart, float fRecordRate, const TCHAR *pFileName);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     Ԥ������״̬�£������Ƿ�������ֹͣ��Ƶ¼Ӱ��������ѡ���Ƿ񵯳���Ƶ�������Ի����ڹ��û�ѡ����Ƶ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bStart [in] �Ƿ�����¼Ӱ�����Ϊfalse���������������
	/// @param     fRecordRate [in] ����¼Ӱ֡�٣����֡�ٴ���¼Ӱ�ļ��Ļط�֡��
	/// @param     pFileName [in] ¼Ӱ�ļ���
	/// @param     bShowCompossorSelection [in] �Ƿ񵯳���Ƶ�������Ի����û�ѡ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStartEx(int nIndex, bool bStart, float fRecordRate, const TCHAR *pFileName, bool bShowCompossorSelection);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �����Ƿ�������ֹͣ��Ƶ¼Ӱ�����ڿ���ͨ��KSJ_RecordAddOneFrame����������Ƶ֡���У�������ѡ���Ƿ񵯳���Ƶ�������Ի����ڹ��û�ѡ����Ƶ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bStart [in] �Ƿ�����¼Ӱ�����Ϊfalse���������������
	/// @param     fRecordRate [in] ����¼Ӱ֡�٣����֡�ٴ���¼Ӱ�ļ��Ļط�֡��
	/// @param     nWidth [in] ��Ƶ��ȣ����أ������ֵ��Ҫ��KSJ_RecordAddOneFrame������nWidth����һ��
	/// @param     nHeight [in] ��Ƶ�߶ȣ����أ������ֵ��Ҫ��KSJ_RecordAddOneFrame������nHeight����һ��
	/// @param     nBitCount [in] ��Ƶ������ȣ�8/24/32�������ֵ��Ҫ��KSJ_RecordAddOneFrame������nBitCount����һ��
	/// @param     pFileName [in] ¼Ӱ�ļ���
	/// @param     bShowCompossorSelection [in] �Ƿ񵯳���Ƶ�������Ի����û�ѡ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStartExEx(int nIndex, bool bStart, float fRecordRate, int nWidth, int nHeight, int nBitCount,  const TCHAR *pFileName, bool bShowCompossorSelection);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     ����Ƶ��֡������ӵ�¼Ӱ�ļ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pFrameData [in] ͼ������ָ��
	/// @param     nFrameNum [in] ͼ������Ƶ���е�֡���
	/// @param     nWidth [in] ͼ���ȣ����أ������ֵ��Ҫ��KSJ_ RecordStartExEx������nWidth����һ��
	/// @param     nHeight [in] ��Ƶ�߶ȣ����أ������ֵ��Ҫ��KSJ_ RecordStartExEx������nHeight����һ��
	/// @param     nBitCount [in] ��Ƶ������ȣ�8/24/32�������ֵ��Ҫ��KSJ_ RecordStartExEx������nBitCount����һ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordAddOneFrame(int nIndex, unsigned char *pFrameData, int nFrameNum, int nWidth, int nHeight, int nBitcount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �õ���ǰ¼Ӱ״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bStart [in] �����Ƿ�����¼Ӱ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStatusGet(int nIndex, bool *bStart);

#ifdef __cplusplus
}
#endif

#endif