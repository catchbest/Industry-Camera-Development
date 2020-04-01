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

	enum KSJ_BAYERMODE //����ģʽ
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

	//-----------------------------------------------------------------------------
    // ������KSJ_BayerGetDefaultMode
    // ���ܣ��õ���ǰ�����Ĭ��Bayerģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pBayerMode�����������Ĭ�ϵ�Bayerģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetDefaultMode(int nChannel, KSJ_BAYERMODE *pBayerMode);

	//-----------------------------------------------------------------------------
    // ������KSJ_BayerSetMode
    // ���ܣ�����Bayerģʽ��ͬʱӰ��ɼ���Ԥ��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       BayerMode�����룬���õı���ģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerSetMode(int nChannel, KSJ_BAYERMODE BayerMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_BayerGetMode
    // ���ܣ��õ���ǰ�����Bayerģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pBayerMode����������ص�Bayerģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_BayerGetMode(int nChannel, KSJ_BAYERMODE *pBayerMode);

	enum KSJ_FILTERMODE//�����˲�ģʽ
	{
		KSJ_NEARESTNEIGHBOR,
		KSJ_BILINEAR,
		KSJ_SMOOTHHUE,
		KSJ_EDGESENSING,
		KSJ_LAPLACIAN,
		KSJ_FASTBILINEAR
	};

	//-----------------------------------------------------------------------------
    // ������KSJ_FilterSetMode
    // ���ܣ����ñ����˲�ģʽ��ͬʱӰ��ɼ���Ԥ��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       FilterMode�����룬���õı����˲�ģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterSetMode(int nChannel, KSJ_FILTERMODE FilterMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_FilterGetMode
    // ���ܣ��õ���ǰ�����Bayerģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pFilterMode����������صı����˲�ģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API   int __stdcall KSJ_FilterGetMode(int nChannel, KSJ_FILTERMODE *pFilterMode);

#ifdef __cplusplus
}
#endif

#endif
