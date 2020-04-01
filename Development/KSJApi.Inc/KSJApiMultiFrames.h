#ifndef __KSJ_API_MULTI_FRAMES_H__
#define __KSJ_API_MULTI_FRAMES_H__

// #pragma message("Include KSJApiMultiFrames.h") 

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
    // ������KSJ_PreviewSetFieldOfViewEx
    // ���ܣ����ö�֡ƴ��ʱ��Ԥ���ӳ�
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nColStart�� ���룬Ԥ��ʱƴ�ӵĵ���֡��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    //       nRowStart�����룬Ԥ��ʱƴ�ӵĵ���֡��Ч����������������Ĭ�ϳ�������Ĵ�ֱ����ʼλ��
	//       nColSize�� ���룬Ԥ��ʱƴ�ӵĵ���֡��Ч���������ˮƽ������
    //       nRowSize�����룬Ԥ��ʱƴ�ӵĵ���֡��Ч��������Ĵ�ֱ����
	//       AmCol�� ���룬Ԥ��ʱƴ�ӵĵ���֡�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       AmRow�����룬Ԥ��ʱ��ƴ�ӵĵ���֡����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	//       wMultiFrameNum�����룬����ͼ��й�оƬԤ��ʱ����й����Ч����ֱ����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfViewEx(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetFieldOfViewEx
    // ���ܣ���ȡԤ���Ķ�֡ƴ����Ϣ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� �����������ƴ�ӵĵ���֡ͼ��й�оƬԤ��ʱ����й����Ч������ʼ��λ��
    //       pnRowStart�����������ƴ�ӵĵ���֡ͼ��й�оƬԤ��ʱ����й����Ч������ʼ��λ��
	//       pnColSize�� ���������ƴ�ӵĵ���֡ͼ��й�оƬԤ��ʱ����й����Ч����ˮƽ������
    //       pnRowSize�����������ƴ�ӵĵ���֡ͼ��й�оƬԤ��ʱ����й����Ч����ֱ����
	//       pColAddressMode�� ���������ƴ�ӵĵ���֡ͼ��й�оƬԤ��ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       pRowAddressMode�����������ƴ�ӵĵ���֡ͼ��й�оƬԤ��ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	//       pwMultiFrameNum�����������Ԥ����ƴ��֡��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfViewEx(int nChannel, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureSetFieldOfViewEx
    // ���ܣ����ö�֡ƴ��ʱ�Ĳɼ��ӳ�
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nColStart�� ���룬�ɼ�ʱƴ�ӵĵ���֡��Ч�������������Ĭ�������������ˮƽ������ʼλ��
    //       nRowStart�����룬�ɼ�ʱƴ�ӵĵ���֡��Ч����������������Ĭ�ϳ�������Ĵ�ֱ����ʼλ��
	//       nColSize�� ���룬�ɼ�ʱƴ�ӵĵ���֡��Ч���������ˮƽ������
    //       nRowSize�����룬�ɼ�ʱƴ�ӵĵ���֡��Ч��������Ĵ�ֱ����
	//       AmCol�� ���룬�ɼ�ʱƴ�ӵĵ���֡�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       AmRow�����룬�ɼ�ʱ��ƴ�ӵĵ���֡����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	//       wMultiFrameNum�����룬����ͼ��й�оƬ�ɼ�ʱ����й����Ч����ֱ����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfViewEx(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureGetFieldOfViewEx
    // ���ܣ���ȡ�ɼ��Ķ�֡ƴ����Ϣ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnColStart�� �����������ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
    //       pnRowStart�����������ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	//       pnColSize�� ���������ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч����ˮƽ������
    //       pnRowSize�����������ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч����ֱ����
	//       pColAddressMode�� ���������ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
    //       pRowAddressMode�����������ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	//       pwMultiFrameNum����������زɼ���ƴ��֡��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfViewEx(int nChannel, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);


#ifdef __cplusplus
}
#endif

#endif