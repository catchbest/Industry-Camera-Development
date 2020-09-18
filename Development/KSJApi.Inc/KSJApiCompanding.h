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

    /// �ο������Ӽѹ�ҵ���API����˵���飨����ѹ��ƪ����
	/// Related API KSJ_GetADCResolution to Get Valid bits of 16bits
	/// Please KSJ_QueryFunction ( KSJ_SUPPORT_LUT_DOWNLOAD ) to Get if support download LUT
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LutFileDownload
    /// @brief     ��ktb�ļ���ʽ������LUT���ұ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pszKtbFile [in] .ktb�ļ�·��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutFileDownload(int nIndex, const TCHAR *pszKtbFile);
	
    ///-----------------------------------------------------------------------------
    /// @brief     KSJ_LutDataDownload
    /// @brief     �˺��������ڼ����û��Զ����LUT���ұ�����
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pData [out] ָ����ұ����ݵ�ָ��
	/// @param     nBytes [in] ���ұ����ݸ�������pDataָ��ָ����ڴ��Ĵ�С
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutDataDownload( int nIndex, unsigned char *pData, int nBytes   );
    
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LutSetEnable
    /// @brief     ʹ��LUT���ұ���
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] �����Ƿ�ʹLUT������Ч
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutSetEnable( int nIndex, bool bEnable   );

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LutGetEnable
    /// @brief     ��ȡLUT���ұ��Ƿ�ʹ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] �����Ƿ�LUT��������Ч
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutGetEnable( int nIndex, bool *pbEnable );

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GammaLutFileDownload
    /// @brief     ��ktb�ļ���ʽ������Gamma LUT���ұ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pszKtbFile [in] .ktb�ļ�·��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutFileDownload( int nIndex, const TCHAR *pszKtbFile );
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GammaLutDataDownload
    /// @brief     �����û��Զ����Gamma LUT���ұ�����
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pData [out] ָ����ұ����ݵ�ָ�룬ÿ��Ԫ��Ϊ˫�ֽ�
	/// @param     nWords [in] ���ұ����ݸ���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutDataDownload( int nIndex, unsigned short *pData, int nWords );
    
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GammaLutSetEnable
    /// @brief     ʹ��Gamma LUT���ұ���
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] �����Ƿ�ʹGamma LUT������Ч
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutSetEnable( int nIndex, bool bEnable   );
    
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GammaLutGetEnable
    /// @brief     ��ȡGamma LUT���ұ��Ƿ�ʹ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] �����Ƿ�Gamma LUT��������Ч
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_GammaLutGetEnable( int nIndex, bool *pbEnable );

    enum KSJ_SENSITIVITYMODE /// ������ģʽ���ã�ʹ�ý�ȡ8λ��ʽ��
    {
	    KSJ_LOW = 0, 
	    KSJ_MID, 
	    KSJ_HIGH, 
	    KSJ_HIGHER, 
	    KSJ_HIGHEST 
    };
    
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SensitivitySetMode
    /// @brief     ѡ���λģʽ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     SensitivityMode [in] ���ý�λģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivitySetMode(int nIndex, KSJ_SENSITIVITYMODE SensitivityMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SensitivityGetMode
    /// @brief     ѡ���λģʽ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pSensitivityMode [out] ��ȡ��ǰ��λģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivityGetMode(int nIndex, KSJ_SENSITIVITYMODE *pSensitivityMode);

#ifdef __cplusplus
}
#endif

#endif