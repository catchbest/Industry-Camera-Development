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
	/// Please KSJ_QueryFunction (KSJ_SUPPORT_LUT_DOWNLOAD ) to Get if support download LUT

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LutFileDownload
	/// @brief     ��ktb�ļ���ʽ������LUT���ұ��������16bit to 8bit LUT��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pszKtbFile [in] .ktb�ļ�·������ͨ��KSJ_QueryFunction(KSJ_SUPPORT_LUT_DOWNLOAD)��ѯ����Ƿ�֧��LUT����LUT��������Ч������ϵ��Ժ󣬸ò��ұ��ᶪʧ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutFileDownload(int nIndex, const TCHAR *pszKtbFile);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LutDataDownload
	/// @brief     �˺��������ڼ����û��Զ����LUT���ұ����ݣ�16bit to 8bit LUT��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pData [out] ָ����ұ����ݵ�ָ��
	/// @param     nBytes [in] ���ұ����ݸ�������pDataָ��ָ����ڴ��Ĵ�С����LUT��������Ч������ϵ��Ժ󣬸ò��ұ��ᶪʧ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutDataDownload(int nIndex, unsigned char *pData, int nBytes);
    
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LutSetEnable
	/// @brief     ʹ��LUT���ұ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] �����Ƿ�ʹLUT������Ч
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutSetEnable(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_LutGetEnable
	/// @brief     ��ȡLUT���ұ��Ƿ�ʹ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] �����Ƿ�LUT��������Ч
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_LutGetEnable(int nIndex, bool *pbEnable);

	/// ������ģʽ���ã�ʹ�ý�ȡ8λ��ʽ��
	enum KSJ_SENSITIVITYMODE
	{
		KSJ_LOW = 0,     ///< 16bit���ݽ�ȡ��Чλ�����8bit����
		KSJ_MID,         ///< 16bit���ݽ�ȡ��Чλ���е�8bit����
		KSJ_HIGH,        ///< 16bit���ݽ�ȡ��Чλ���м�8bit����
		KSJ_HIGHER,      ///< 16bit���ݽ�ȡ��Чλ���и�8bit����
		KSJ_HIGHEST      ///< 16bit���ݽ�ȡ��Чλ�����8bit����
	};
    
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SensitivitySetMode
	/// @brief     ѡ���λģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     SensitivityMode [in] ���ý�λģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivitySetMode(int nIndex, KSJ_SENSITIVITYMODE SensitivityMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SensitivityGetMode
	/// @brief     ��ȡ��ǰ�Ľ�λģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pSensitivityMode [out] ��ȡ��ǰ��λģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_SensitivityGetMode(int nIndex, KSJ_SENSITIVITYMODE *pSensitivityMode);

#ifdef __cplusplus
}
#endif

#endif