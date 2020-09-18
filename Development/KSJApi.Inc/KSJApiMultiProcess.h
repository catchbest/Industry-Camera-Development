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

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ָ���������豸
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceOpen(int nIndex);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     �ر�ָ���������豸��������ر�ָ���������ô�ڶ�������ǲ��ܲ�����̨�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceClose(int nIndex);

	enum KSJ_DEVICESTATUS { KSJ_DS_CLOSE, KSJ_DS_OPEN };//�豸�ڵ�ǰ�����еĿ����ر�״̬��ö������
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�豸�ڵ�ǰ�����еĿ����ر�״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pDs [out] ��ȡ����ڵ�ǰ�����еĿ����ر�״̬
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_DeviceGetStatus(int nIndex, KSJ_DEVICESTATUS *pDs);



#ifdef __cplusplus
}
#endif

#endif