#ifndef __KSJ_API_WATER_MARK__H__
#define __KSJ_API_WATER_MARK__H__

// #pragma message("Include KSJApiWaterMark.h") 

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

	enum KSJ_WATERMARKMODE ///ˮӡģʽ
	{ 
		KSJ_WMM_TIMESTAMP, 
		KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, 
		KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER 
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ����ˮӡģʽ���°汾ˮӡ�Ѿ���֧��ˮӡģʽ���ã�Ĭ��KSJ_WMM_TIMESTAMP��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     WaterMarkMode [in] ����ˮӡģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetMode(int nIndex, KSJ_WATERMARKMODE WaterMarkMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡˮӡģʽ���°汾ˮӡ�Ѿ���֧��ˮӡģʽ���ã�Ĭ��KSJ_WMM_TIMESTAMP��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pWaterMarkMode [out] ��ȡ��ǰˮӡģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetMode(int nIndex, KSJ_WATERMARKMODE *pWaterMarkMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     �����Ƿ���ˮӡ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] �Ƿ���ˮӡ���ܣ�true��ʾ������false��ʾ������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetEnable(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�Ƿ���ˮӡ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pWaterMarkMode [out] ��ȡ��ǰˮӡģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetEnable(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡˮӡ��Ϣ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pwId [out] ��ȡ��ǰˮӡ��
	/// @param     pdwTimestampLowPart [out] ��ȡʱ����ĵ�4�ֽ�ֵ
	/// @param     pdwTimestampHighPart [out] ��ȡʱ����ĸ�4�ֽ�λֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetInfo(int nIndex, unsigned short *pwId, unsigned long *pdwTimestampLowPart, unsigned long *pdwTimestampHighPart);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡˮӡ��Ϣ�������ع�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pwId [out] ��ȡ��ǰˮӡ��
	/// @param     pdwTimestampLowPart [out] ��ȡʱ����ĵ�4�ֽ�ֵ
	/// @param     pdwTimestampHighPart [out] ��ȡʱ����ĸ�4�ֽ�λֵ
	/// @param     pnExposure [out] ��ȡ��ǰͼ����ع�ֵ
	/// @param     pwGain [out] ��ȡ��ǰͼ�������ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetInfoEx(int nIndex, unsigned int *pnId, unsigned long *pdwTimestampLowPart, unsigned long *pdwTimestampHighPart, unsigned int* pnExposure, unsigned short* pwGain);

#ifdef __cplusplus
}
#endif

#endif
