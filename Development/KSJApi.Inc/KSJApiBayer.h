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

	/// Bayerģʽ
	enum KSJ_BAYERMODE
	{
		KSJ_BGGR_BGR24 = 0,    ///< BGGR����Rawͼת����24bit BGRͼ��
		KSJ_GRBG_BGR24,        ///< GRBG����Rawͼת����24bit BGRͼ��
		KSJ_RGGB_BGR24,        ///< RGGB����Rawͼת����24bit BGRͼ��
		KSJ_GBRG_BGR24,        ///< GBRG����Rawͼת����24bit BGRͼ��
		KSJ_BGGR_BGR24_FLIP,   ///< BGGR����Rawͼת����24bit BGRͼ������ֱ����
		KSJ_GRBG_BGR24_FLIP,   ///< GRBG����Rawͼת����24bit BGRͼ������ֱ����
		KSJ_RGGB_BGR24_FLIP,   ///< RGGB����Rawͼת����24bit BGRͼ������ֱ����
		KSJ_GBRG_BGR24_FLIP,   ///< GBRG����Rawͼת����24bit BGRͼ������ֱ����
		KSJ_BGGR_BGR32,        ///< BGGR����Rawͼת����32bit BGRͼ��
		KSJ_GRBG_BGR32,        ///< GRBG����Rawͼת����32bit BGRͼ��
		KSJ_RGGB_BGR32,        ///< RGGB����Rawͼת����32bit BGRͼ��
		KSJ_GBRG_BGR32,        ///< GBRG����Rawͼת����32bit BGRͼ��
		KSJ_BGGR_BGR32_FLIP,   ///< BGGR����Rawͼת����32bit BGRͼ������ֱ����
		KSJ_GRBG_BGR32_FLIP,   ///< GRBG����Rawͼת����32bit BGRͼ������ֱ����
		KSJ_RGGB_BGR32_FLIP,   ///< RGGB����Rawͼת����32bit BGRͼ������ֱ����
		KSJ_GBRG_BGR32_FLIP,   ///< GBRG����Rawͼת����32bit BGRͼ������ֱ����
		KSJ_BGGR_GRAY8,        ///< BGGR����Rawͼת���ɻҶ�ͼ��
		KSJ_GRBG_GRAY8,        ///< GRBG����Rawͼת���ɻҶ�ͼ��
		KSJ_RGGB_GRAY8,        ///< RGGB����Rawͼת���ɻҶ�ͼ��
		KSJ_GBRG_GRAY8,        ///< GBRG����Rawͼת���ɻҶ�ͼ��
		KSJ_BGGR_GRAY8_FLIP,   ///< BGGR����Rawͼת���ɻҶ�ͼ������ֱ����
		KSJ_GRBG_GRAY8_FLIP,   ///< GRBG����Rawͼת���ɻҶ�ͼ������ֱ����
		KSJ_RGGB_GRAY8_FLIP,   ///< RGGB����Rawͼת���ɻҶ�ͼ������ֱ����
		KSJ_GBRG_GRAY8_FLIP    ///< GBRG����Rawͼת���ɻҶ�ͼ������ֱ����
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BayerGetDefaultMode
	/// @brief     �õ���ǰ�����Ĭ��Bayerģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pBayerMode [out] ����Ĭ�ϵ�Bayerģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetDefaultMode(int nIndex, KSJ_BAYERMODE *pBayerMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BayerSetMode
	/// @brief     ����Rawͼת��RGBͼ���Bayerģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     BayerMode [in] ���õ�Bayerģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerSetMode(int nIndex, KSJ_BAYERMODE BayerMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BayerGetMode
	/// @brief     �õ���ǰ�����Bayerģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pBayerMode [out] ���ص�Bayerģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetMode(int nIndex, KSJ_BAYERMODE *pBayerMode);

	/// Bayer�任���˲�ģʽ 
	enum KSJ_FILTERMODE
	{
		KSJ_NEARESTNEIGHBOR,    ///< ���ڽ���
		KSJ_BILINEAR,           ///< ˫���Բ�ֵ��
		KSJ_SMOOTHHUE,          ///< ����ɫ��ת���ڲ巨
		KSJ_EDGESENSING,        ///< ��Ե��Ӧ�㷨
		KSJ_LAPLACIAN,          ///< ������˹��ֵ��
		KSJ_FASTBILINEAR        ///< ����˫���Բ�ֵ��
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_FilterSetMode
	/// @brief     ���ñ����˲�ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     FilterMode [in] ���õı����˲�ģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterSetMode(int nIndex, KSJ_FILTERMODE FilterMode);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_FilterGetMode
	/// @brief     �õ���ǰ�����Bayerģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pFilterMode [out] ���صı����˲�ģʽ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterGetMode(int nIndex, KSJ_FILTERMODE *pFilterMode);

#ifdef __cplusplus
}
#endif

#endif
