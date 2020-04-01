#ifndef __KSJ_API_STREAM_H__
#define __KSJ_API_STREAM_H__

// #pragma message("Include KSJApiBase.h") 

#ifdef KSJAPI_EXPORTS
#define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
#define KSJ_API
#else
#define KSJ_API __declspec(dllimport)
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifdef __cplusplus
extern "C"{
#endif

	//-----------------------------------------------------------------------------
    // ������KSJ_IsSupportStreamMode
    // ���ܣ��鿴����Ƿ�֧����ģʽ
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbSupport�� ������Ƿ�֧����ģʽ��true֧�֣�false��֧��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_IsSupportStreamMode(int nIndex, bool* pbSupport);

	//-----------------------------------------------------------------------------
    // ������KSJ_StreamIsStart
    // ���ܣ��鿴����Ƿ�����ģʽ
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbStart�� ������Ƿ�������ģʽ��true������falseδ����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamIsStart(int nIndex, bool* pbStart);

	//-----------------------------------------------------------------------------
    // ������KSJ_StreamStart
    // ���ܣ�������ģʽ
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamStart(int nIndex);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_StreamStop
    // ���ܣ��ر���ģʽ
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamStop(int nIndex);

	//-----------------------------------------------------------------------------
    // ������KSJ_StreamReadRawData
    // ���ܣ������������ģʽʱ���ɼ�һ֡ԭʼ��ڰ�ͼ������
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pRawData����������û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize��KSJ_CaptureGetSizeEx�������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRawData(int nIndex, unsigned char *pRawData);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_StreamReadRawData
    // ���ܣ������������ģʽʱ���ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pRgbData����������û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize��KSJ_CaptureGetSizeEx�������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRgbData(int nIndex, unsigned char *pRgbData);

	//-----------------------------------------------------------------------------
    // ������KSJ_StreamReadRawDataEx
    // ���ܣ������������ģʽʱ���ɼ�һ֡ԭʼ��ڰ�ͼ������
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pRawData����������û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize��KSJ_CaptureGetSizeEx�������
	//       pDataSize�� ���������ʵ��ͼ�����ݵĴ�С
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRawDataEx(int nIndex, unsigned char *pRawData, unsigned int* pDataSize);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_StreamReadRgbDataEx
    // ���ܣ������������ģʽʱ���ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
    // ������
    //       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pRgbData����������û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize��KSJ_CaptureGetSizeEx�������
	//       pDataSize�� ���������ʵ��ͼ�����ݵĴ�С
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_StreamReadRgbDataEx(int nIndex, unsigned char *pRgbData, unsigned int* pDataSize);

#ifdef __cplusplus
}
#endif

#endif
