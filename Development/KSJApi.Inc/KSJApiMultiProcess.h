#ifndef __KSJ_API_MULTI_PROCESS_H__
#define __KSJ_API_MULTI_PROCESS_H__

// #pragma message("Include KSJApiMultiProcess.h") 

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
    // ������KSJ_DeviceClose
    // ���ܣ��ر�ָ���������豸��������ر�ָ���������ô�ڶ�������ǲ��ܲ�����̨�����
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceClose(int nIndex);

	enum KSJ_DEVICESTATUS { KSJ_DS_CLOSE, KSJ_DS_OPEN };//�豸�ڵ�ǰ�����еĿ����ر�״̬��ö������
	
	//-----------------------------------------------------------------------------
    // ������KSJ_DeviceGetStatus
    // ���ܣ���ȡ�豸�ڵ�ǰ�����еĿ����ر�״̬
    // ������
	//       nIndex�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pDs�� �������ȡ����ڵ�ǰ�����еĿ����ر�״̬
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetStatus(int nIndex, KSJ_DEVICESTATUS *pDs);



#ifdef __cplusplus
}
#endif

#endif