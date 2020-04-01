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

	//-----------------------------------------------------------------------------
    // ������KSJ_RecordStart
    // ���ܣ�Ԥ������״̬�£������Ƿ������ֹͣ��Ƶ¼Ӱ��������Ƶ�������Ի����ڹ��û�ѡ����Ƶ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bStart�����룬�Ƿ����¼Ӱ�����Ϊfalse������������������
	//       fRecordRate�����룬����¼Ӱ֡�٣����֡�ٴ���¼Ӱ�ļ��Ļط�֡��
	//       pFileName�����룬¼Ӱ�ļ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStart(int nChannel, bool bStart, float fRecordRate, const TCHAR *pFileName);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_RecordStartEx
    // ���ܣ�Ԥ������״̬�£������Ƿ������ֹͣ��Ƶ¼Ӱ��������ѡ���Ƿ񵯳���Ƶ�������Ի����ڹ��û�ѡ����Ƶ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bStart�����룬�Ƿ����¼Ӱ�����Ϊfalse���������������
	//       fRecordRate�����룬����¼Ӱ֡�٣����֡�ٴ���¼Ӱ�ļ��Ļط�֡��
	//       pFileName�����룬¼Ӱ�ļ���
	//       bShowCompossorSelection�����룬�Ƿ񵯳���Ƶ�������Ի����û�ѡ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStartEx(int nChannel, bool bStart, float fRecordRate, const TCHAR *pFileName, bool bShowCompossorSelection);

	//-----------------------------------------------------------------------------
    // ������KSJ_RecordStartExEx
    // ���ܣ������Ƿ������ֹͣ��Ƶ¼Ӱ�����ڿ���ͨ��KSJ_RecordAddOneFrame����������Ƶ֡���У�������ѡ���Ƿ񵯳���Ƶ�������Ի����ڹ��û�ѡ����Ƶ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bStart�����룬�Ƿ����¼Ӱ�����Ϊfalse���������������
	//       fRecordRate�����룬����¼Ӱ֡�٣����֡�ٴ���¼Ӱ�ļ��Ļط�֡��
	//       nWidth�� ���룬��Ƶ��ȣ����أ������ֵ��Ҫ��KSJ_RecordAddOneFrame������nWidth����һ��
    //       nHeight�����룬��Ƶ�߶ȣ����أ������ֵ��Ҫ��KSJ_RecordAddOneFrame������nHeight����һ��
    //       nBitCount�����룬��Ƶ������ȣ�8/24/32�������ֵ��Ҫ��KSJ_RecordAddOneFrame������nBitCount����һ��
	//       pFileName�����룬¼Ӱ�ļ���
	//       bShowCompossorSelection�����룬�Ƿ񵯳���Ƶ�������Ի����û�ѡ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStartExEx(int nChannel, bool bStart, float fRecordRate, int nWidth, int nHeight, int nBitCount,  const TCHAR *pFileName, bool bShowCompossorSelection);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_RecordAddOneFrame
    // ���ܣ�����Ƶ��֡������ӵ�¼Ӱ�ļ���
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pFrameData�����룬ͼ������ָ��
	//       nFrameNum�����룬ͼ������Ƶ���е�֡���
	//       nWidth�� ���룬ͼ���ȣ����أ������ֵ��Ҫ��KSJ_ RecordStartExEx������nWidth����һ��
    //       nHeight�����룬��Ƶ�߶ȣ����أ������ֵ��Ҫ��KSJ_ RecordStartExEx������nHeight����һ��
    //       nBitCount�����룬��Ƶ������ȣ�8/24/32�������ֵ��Ҫ��KSJ_ RecordStartExEx������nBitCount����һ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordAddOneFrame(int nChannel, unsigned char *pFrameData, int nFrameNum, int nWidth, int nHeight, int nBitcount);

	//-----------------------------------------------------------------------------
    // ������KSJ_RecordStatusGet
    // ���ܣ��õ���ǰ¼Ӱ״̬
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bStart�����룬�����Ƿ�����¼Ӱ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_RecordStatusGet(int nChannel, bool *bStart);

#ifdef __cplusplus
}
#endif

#endif