#ifndef __KSJ_API_BAYER_H__
#define __KSJ_API_BAYER_H__

// #pragma message("Include KSJApiBayer.h") 

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

	enum KSJ_BAYERMODE ///����ģʽ
	{
		KSJ_BGGR_BGR24 = 0, 
		KSJ_GRBG_BGR24, 
		KSJ_RGGB_BGR24,
		KSJ_GBRG_BGR24,
		KSJ_BGGR_BGR24_FLIP, 
		KSJ_GRBG_BGR24_FLIP, 
		KSJ_RGGB_BGR24_FLIP, 
		KSJ_GBRG_BGR24_FLIP,
		KSJ_BGGR_BGR32, 
		KSJ_GRBG_BGR32,
		KSJ_RGGB_BGR32,
		KSJ_GBRG_BGR32, 
		KSJ_BGGR_BGR32_FLIP, 
		KSJ_GRBG_BGR32_FLIP, 
		KSJ_RGGB_BGR32_FLIP, 
		KSJ_GBRG_BGR32_FLIP,
		KSJ_BGGR_GRAY8, 
		KSJ_GRBG_GRAY8, 
		KSJ_RGGB_GRAY8, 
		KSJ_GBRG_GRAY8, 
		KSJ_BGGR_GRAY8_FLIP, 
		KSJ_GRBG_GRAY8_FLIP,
		KSJ_RGGB_GRAY8_FLIP, 
		KSJ_GBRG_GRAY8_FLIP
	};

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_BayerGetDefaultMode
    /// @brief     �õ���ǰ�����Ĭ��Bayerģʽ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pBayerMode [out] ����Ĭ�ϵ�Bayerģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetDefaultMode(int nIndex, KSJ_BAYERMODE *pBayerMode);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_BayerSetMode
    /// @brief     ����Bayerģʽ��ͬʱӰ��ɼ���Ԥ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     BayerMode [in] ���õı���ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerSetMode(int nIndex, KSJ_BAYERMODE BayerMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_BayerGetMode
    /// @brief     �õ���ǰ�����Bayerģʽ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pBayerMode [out] ���ص�Bayerģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetMode(int nIndex, KSJ_BAYERMODE *pBayerMode);

	enum KSJ_FILTERMODE//�����˲�ģʽ
	{
		KSJ_NEARESTNEIGHBOR,
		KSJ_BILINEAR,
		KSJ_SMOOTHHUE,
		KSJ_EDGESENSING,
		KSJ_LAPLACIAN,
		KSJ_FASTBILINEAR
	};

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_FilterSetMode
    /// @brief     ���ñ����˲�ģʽ��ͬʱӰ��ɼ���Ԥ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     FilterMode [in] ���õı����˲�ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterSetMode(int nIndex, KSJ_FILTERMODE FilterMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_FilterGetMode
    /// @brief     �õ���ǰ�����Bayerģʽ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pFilterMode [out] ���صı����˲�ģʽ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterGetMode(int nIndex, KSJ_FILTERMODE *pFilterMode);

#ifdef __cplusplus
}
#endif

#endif
