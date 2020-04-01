#ifndef __KSJ_API_CALLBACK_H__
#define __KSJ_API_CALLBACK_H__

// #pragma message("Include KSJApiCallback.h") 

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
    // ������KSJ_PREVIEWCALLBACK
    // ���ܣ��ص�����ָ�������
    // ������
    //       pImageData�������Ԥ��ͼ�������ָ��
	//       pnWidth�� ���������ͼ��Ŀ�ȣ����أ�
    //       pnHeight�����������ͼ��ĸ߶ȣ����أ�
    //       pnBitCount����������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
	//       lpContext�� ������û������������ָ�룬���ָ������û�����KSJ_PreviewSetCallback����ʱ����lpContext��ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	typedef void(CALLBACK *KSJ_PREVIEWCALLBACK)(unsigned char *pImageData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewSetCallback
    // ���ܣ�����Ԥ���ص�����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pfPreviewCallback�����룬�ص�����ָ��
	//       lpContext�� ������û������������ָ�룬���ָ������û�����KSJ_PreviewSetCallback����ʱ����lpContext��ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_PreviewSetCallback( int nChannel, KSJ_PREVIEWCALLBACK pfPreviewCallback, void *lpContext );

    //-----------------------------------------------------------------------------
    // ������KSJ_PREVIEWCALLBACKEX
    // ���ܣ��ص�����ָ�������
    // ������
	//       hDC�������KSJApi�ⴴ�����ڴ�DC,Ԥ��ͼ���Ѿ���Ϊ�豸�޹�λͼ��ѡ���DC���豸����������У��û�����ʹ�ô�DC������GDI�����ڴ�DC���豸����������ϻ���
    //       pImageData�������Ԥ��ͼ�������ָ��
	//       pnWidth�� ���������ͼ��Ŀ�ȣ����أ�
    //       pnHeight�����������ͼ��ĸ߶ȣ����أ�
    //       pnBitCount����������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
	//       lpContext�� ������û������������ָ�룬���ָ������û�����KSJ_PreviewSetCallback����ʱ����lpContext��ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
    typedef void(CALLBACK *KSJ_PREVIEWCALLBACKEX)(HDC  hDC, unsigned char *pImageData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewSetCallbackEx
    // ���ܣ�����Ԥ���ص�����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pfPreviewCallbackEx�����룬�ص�����ָ��
	//       lpContext�� ������û������������ָ�룬���ָ������û�����KSJ_PreviewSetCallback����ʱ����lpContext��ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_PreviewSetCallbackEx( int nChannel, KSJ_PREVIEWCALLBACKEX pfPreviewCallbackEx, void *lpContext );


#ifdef __cplusplus
}
#endif

#endif