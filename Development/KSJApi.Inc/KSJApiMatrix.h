#ifndef __KSJ_API_MATRIX_H__
#define __KSJ_API_MATRIX_H__

// #pragma message("Include KSJApiMatrix.h") 

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

	enum KSJ_WB_MODE//��ƽ��ģʽ
	{
		KSJ_WB_DISABLE,
		KSJ_SWB_PRESETTINGS,
		KSJ_SWB_AUTO_ONCE,
		KSJ_SWB_AUTO_CONITNUOUS,
		KSJ_SWB_MANUAL,
		KSJ_HWB_PRESETTINGS,
		KSJ_HWB_AUTO_ONCE,
		KSJ_HWB_AUTO_CONITNUOUS,
		KSJ_HWB_MANUAL
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���ð�ƽ��ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     WbMode [in] ���õİ�ƽ��ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceSet(int nIndex, KSJ_WB_MODE WbMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ǰ�İ�ƽ��ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pWbMode [out] ���������ƽ��ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceGet(int nIndex, KSJ_WB_MODE *pWbMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��������Զ���ƽ��Ĳο����أ���һ����ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nPhi [in] Ĭ��ֵΪ0���û�����Ķ�
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSet(int nIndex, int nPhi);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�Զ���ƽ�����ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnPhi [out] ���ص�ǰ����ֵ����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGet(int nIndex, int *pnPhi);


	///-----------------------------------------------------------------------------
    ///
    /// @brief     �ֶ����ð�ƽ��У������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fMatrix [in] �������ð�ƽ��У������У������Ϊ1x3�����飬������R��G��B����������ϵ���ֱ�ΪfMatrix [0] ��fMatrix [1] ��fMatrix [2] 
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixSet(int nIndex, float fMatrix[3]);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ǰ�İ�ƽ��У������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fMatrix [out] ���ػ�ȡ�İ�ƽ�����ϵ����������R��G��B����������ϵ���ֱ�ΪfMatrix [0] ��fMatrix [1] ��fMatrix [2] 
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixGet(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ƽ��ص��������Ͷ���
    /// @param     fMatrix [out] �ش����û��İ�ƽ��У������
	/// @param     lpContext [out] �û�����KSJ_WhiteBalanceAutoSetCallBackʱ�����������ָ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK)(float fMatrix[3], void *lpContext);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ƽ��ص��������Ͷ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pfCallBack [in] �Զ���ƽ��ص�����ָ��
	/// @param     lpContext [in] ������ָ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBack(int nIndex, KSJ_WB_CALLBACK    pfCallBack, void *lpContext);      /// The nPhi decide auto calculate Matrix.

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ƽ��ص��������Ͷ���
    /// @param     fMatrixR [out] �ش����û��İ�ƽ���ɫУ��ֵ
	/// @param     fMatrixG [out] �ش����û��İ�ƽ����ɫУ��ֵ
	/// @param     fMatrixB [out] �ش����û��İ�ƽ����ɫУ��ֵ
	/// @param     lpContext [out] �û�����KSJ_WhiteBalanceAutoSetCallBackʱ�����������ָ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK_EX)(float fMatrixR, float fMatrixG, float fMatrixB, void *lpContext);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ���ð�ƽ��ص�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pfCallBackEx [in] �Զ���ƽ��ص�����ָ��
	/// @param     lpContext [in] ������ָ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBackEx(int nIndex, KSJ_WB_CALLBACK_EX pfCallBackEx, void *lpContext);

	enum KSJ_COLOR_TEMPRATURE ///Ԥ���ƽ��
	{ 
		KSJ_CT_5000K, 
		KSJ_CT_6500K, 
		KSJ_CT_2800K 
	};
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ѡ��Ԥ����ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     WbPresetting [in] Ԥ��ɫ�°�ƽ�⣬���Ӽѹ�ҵ���Ԥ������ɫ���µİ�ƽ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingSet(int nIndex, KSJ_COLOR_TEMPRATURE WbPresetting);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ�����������ǰʹ�õ�Ԥ��ɫ�°�ƽ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pWbPresetting [out] ��ȡ�����������ǰʹ�õ�Ԥ��ɫ�°�ƽ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingGet(int nIndex, KSJ_COLOR_TEMPRATURE *pWbPresetting);

	enum KSJ_CCM_MODE//��ɫУ��ģʽö������
	{
		KSJ_CCM_DISABLE,
		KSJ_SCCM_PRESETTINGS,
		KSJ_SCCM_MANUAL,
		KSJ_HCCM_PRESETTINGS,
		KSJ_HCCM_MANUAL
	};

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ������ɫУ��ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     CcmMode [in] ��ɫУ��ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionSet(int nIndex, KSJ_CCM_MODE CcmMode);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ɫУ��ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pCcmMode [out] ��ɫУ��ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionGet(int nIndex, KSJ_CCM_MODE *pCcmMode);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     �ֶ�������ɫУ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fMatrix [in] ��ɫУ��ϵ������Ϊ3x3 float�͵ľ���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixSet(int nIndex, float fMatrix[3][3]);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ǰ����ɫУ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     fMatrix [in] ��ɫУ��ϵ������Ϊ3x3 float�͵ľ���
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixGet(int nIndex, float fMatrix[3][3]);

	///-----------------------------------------------------------------------------
    ///
    /// @brief     ������ɫУ����Ԥ����ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     CcmPresetting [in] Ԥ��ɫ����ɫУ�������Ӽѹ�ҵ���Ԥ������ɫ���µ���ɫУ������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingSet(int nIndex, KSJ_COLOR_TEMPRATURE CcmPresetting);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     ��ȡ��ǰѡ�����ɫУ��Ԥ����ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pCcmPresetting [out] ��ȡ�����������ǰʹ�õ�Ԥ��ɫ����ɫУ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingGet(int nIndex, KSJ_COLOR_TEMPRATURE *pCcmPresetting);



#ifdef __cplusplus
}
#endif

#endif