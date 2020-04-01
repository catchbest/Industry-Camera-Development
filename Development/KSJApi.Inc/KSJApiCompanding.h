#ifndef __KSJ_API_COMPANDING_H__
#define __KSJ_API_COMPANDING_H__

// #pragma message("Include KSJApiCompanding.h") 

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

    // �ο������Ӽѹ�ҵ���API����˵���飨����ѹ��ƪ����
	// Related API KSJ_GetADCResolution to Get Valid bits of 16bits
	// Please KSJ_QueryFunction ( KSJ_SUPPORT_LUT_DOWNLOAD ) to Get if support download LUT
	
	//-----------------------------------------------------------------------------
    // ������KSJ_LutFileDownload
    // ���ܣ���ktb�ļ���ʽ������LUT���ұ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pszKtbFile�����룬.ktb�ļ�·��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutFileDownload(int nChannel, const TCHAR *pszKtbFile);
	
    //-----------------------------------------------------------------------------
    // ������KSJ_LutDataDownload
    // ���ܣ��˺��������ڼ����û��Զ����LUT���ұ�����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pData�������ָ����ұ����ݵ�ָ��
	//       nBytes�����룬���ұ����ݸ�������pDataָ��ָ����ڴ��Ĵ�С
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutDataDownload( int nChannel, unsigned char *pData, int nBytes   );
    
	//-----------------------------------------------------------------------------
    // ������KSJ_LutSetEnable
    // ���ܣ�ʹ��LUT���ұ���
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bEnable�����룬�����Ƿ�ʹLUT������Ч
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutSetEnable( int nChannel, bool bEnable   );

	//-----------------------------------------------------------------------------
    // ������KSJ_LutGetEnable
    // ���ܣ���ȡLUT���ұ��Ƿ�ʹ��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbEnable������������Ƿ�LUT��������Ч
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutGetEnable( int nChannel, bool *pbEnable );

	//-----------------------------------------------------------------------------
    // ������KSJ_GammaLutFileDownload
    // ���ܣ���ktb�ļ���ʽ������Gamma LUT���ұ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pszKtbFile�����룬.ktb�ļ�·��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutFileDownload( int nChannel, const TCHAR *pszKtbFile );
	
	//-----------------------------------------------------------------------------
    // ������KSJ_GammaLutDataDownload
    // ���ܣ������û��Զ����Gamma LUT���ұ�����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pData�������ָ����ұ����ݵ�ָ�룬ÿ��Ԫ��Ϊ˫�ֽ�
	//       nWords�����룬���ұ����ݸ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutDataDownload( int nChannel, unsigned short *pData, int nWords );
    
	//-----------------------------------------------------------------------------
    // ������KSJ_GammaLutSetEnable
    // ���ܣ�ʹ��Gamma LUT���ұ���
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bEnable�����룬�����Ƿ�ʹGamma LUT������Ч
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutSetEnable( int nChannel, bool bEnable   );
    
	//-----------------------------------------------------------------------------
    // ������KSJ_GammaLutGetEnable
    // ���ܣ���ȡGamma LUT���ұ��Ƿ�ʹ��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbEnable������������Ƿ�Gamma LUT��������Ч
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutGetEnable( int nChannel, bool *pbEnable );

    enum KSJ_SENSITIVITYMODE // ������ģʽ���ã�ʹ�ý�ȡ8λ��ʽ��
    {
	    KSJ_LOW = 0, 
	    KSJ_MID, 
	    KSJ_HIGH, 
	    KSJ_HIGHER, 
	    KSJ_HIGHEST 
    };
    
	//-----------------------------------------------------------------------------
    // ������KSJ_SensitivitySetMode
    // ���ܣ�ѡ���λģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       SensitivityMode�����룬���ý�λģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivitySetMode(int nChannel, KSJ_SENSITIVITYMODE SensitivityMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_SensitivityGetMode
    // ���ܣ�ѡ���λģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pSensitivityMode���������ȡ��ǰ��λģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivityGetMode(int nChannel, KSJ_SENSITIVITYMODE *pSensitivityMode);

#ifdef __cplusplus
}
#endif

#endif