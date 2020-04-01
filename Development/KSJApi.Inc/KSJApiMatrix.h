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

	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalanceSet
    // ���ܣ����ð�ƽ��ģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       WbMode�����룬���õİ�ƽ��ģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceSet(int nChannel, KSJ_WB_MODE WbMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalanceGet
    // ���ܣ���ȡ��ǰ�İ�ƽ��ģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pWbMode����������������ƽ��ģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceGet(int nChannel, KSJ_WB_MODE *pWbMode);

	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalanceAutoSet
    // ���ܣ���������Զ���ƽ��Ĳο����أ���һ����ֵ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nPhi�����룬Ĭ��ֵΪ0���û�����Ķ�
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSet(int nChannel, int nPhi);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalanceAutoGet
    // ���ܣ���ȡ�Զ���ƽ�����ֵ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnPhi����������ص�ǰ����ֵ����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoGet(int nChannel, int *pnPhi);


	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalanceMatrixSet
    // ���ܣ��ֶ����ð�ƽ��У������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       fMatrix�����룬�������ð�ƽ��У������У������Ϊ1x3�����飬������R��G��B����������ϵ���ֱ�ΪfMatrix [0] ��fMatrix [1] ��fMatrix [2] 
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixSet(int nChannel, float fMatrix[3]);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalanceMatrixGet
    // ���ܣ���ȡ��ǰ�İ�ƽ��У������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       fMatrix����������ػ�ȡ�İ�ƽ�����ϵ����������R��G��B����������ϵ���ֱ�ΪfMatrix [0] ��fMatrix [1] ��fMatrix [2] 
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceMatrixGet(int nChannel, float fMatrix[3]);

	//-----------------------------------------------------------------------------
    // ������KSJ_WB_CALLBACK
    // ���ܣ���ƽ��ص��������Ͷ���
    // ������
    //       fMatrix��������ش����û��İ�ƽ��У������
	//       lpContext�� ������û�����KSJ_WhiteBalanceAutoSetCallBackʱ�����������ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK)(float fMatrix[3], void *lpContext);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalanceAutoSetCallBack
    // ���ܣ���ƽ��ص��������Ͷ���
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pfCallBack�����룬�Զ���ƽ��ص�����ָ��
	//       lpContext�� ���룬������ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBack(int nChannel, KSJ_WB_CALLBACK    pfCallBack, void *lpContext);      // The nPhi decide auto calculate Matrix.

	//-----------------------------------------------------------------------------
    // ������KSJ_WB_CALLBACK_EX
    // ���ܣ���ƽ��ص��������Ͷ���
    // ������
    //       fMatrixR��������ش����û��İ�ƽ���ɫУ��ֵ
	//       fMatrixG��������ش����û��İ�ƽ����ɫУ��ֵ
	//       fMatrixB��������ش����û��İ�ƽ����ɫУ��ֵ
	//       lpContext�� ������û�����KSJ_WhiteBalanceAutoSetCallBackʱ�����������ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	typedef void(__stdcall *KSJ_WB_CALLBACK_EX)(float fMatrixR, float fMatrixG, float fMatrixB, void *lpContext);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalanceAutoSetCallBackEx
    // ���ܣ����ð�ƽ��ص�����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pfCallBackEx�����룬�Զ���ƽ��ص�����ָ��
	//       lpContext�� ���룬������ָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalanceAutoSetCallBackEx(int nChannel, KSJ_WB_CALLBACK_EX pfCallBackEx, void *lpContext);

	enum KSJ_COLOR_TEMPRATURE //Ԥ���ƽ��
	{ 
		KSJ_CT_5000K, 
		KSJ_CT_6500K, 
		KSJ_CT_2800K 
	};
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalancePresettingSet
    // ���ܣ�ѡ��Ԥ����ֵ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       WbPresetting�����룬Ԥ��ɫ�°�ƽ�⣬���Ӽѹ�ҵ���Ԥ������ɫ���µİ�ƽ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingSet(int nChannel, KSJ_COLOR_TEMPRATURE WbPresetting);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WhiteBalancePresettingGet
    // ���ܣ���ȡ�����������ǰʹ�õ�Ԥ��ɫ�°�ƽ��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pWbPresetting���������ȡ�����������ǰʹ�õ�Ԥ��ɫ�°�ƽ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WhiteBalancePresettingGet(int nChannel, KSJ_COLOR_TEMPRATURE *pWbPresetting);

	enum KSJ_CCM_MODE//��ɫУ��ģʽö������
	{
		KSJ_CCM_DISABLE,
		KSJ_SCCM_PRESETTINGS,
		KSJ_SCCM_MANUAL,
		KSJ_HCCM_PRESETTINGS,
		KSJ_HCCM_MANUAL
	};

	//-----------------------------------------------------------------------------
    // ������KSJ_ColorCorrectionSet
    // ���ܣ�������ɫУ��ģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       CcmMode�����룬��ɫУ��ģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionSet(int nChannel, KSJ_CCM_MODE CcmMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_ColorCorrectionGet
    // ���ܣ���ȡ��ɫУ��ģʽ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pCcmMode���������ɫУ��ģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ColorCorrectionGet(int nChannel, KSJ_CCM_MODE *pCcmMode);

	//-----------------------------------------------------------------------------
    // ������KSJ_ColorCorrectionMatrixSet
    // ���ܣ��ֶ�������ɫУ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       fMatrix�����룬��ɫУ��ϵ������Ϊ3x3 float�͵ľ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixSet(int nChannel, float fMatrix[3][3]);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_ColorCorrectionMatrixGet
    // ���ܣ���ȡ��ǰ����ɫУ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       fMatrix�����룬��ɫУ��ϵ������Ϊ3x3 float�͵ľ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionMatrixGet(int nChannel, float fMatrix[3][3]);

	//-----------------------------------------------------------------------------
    // ������KSJ_ColorCorrectionPresettingSet
    // ���ܣ�������ɫУ����Ԥ����ֵ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       CcmPresetting�����룬Ԥ��ɫ����ɫУ�������Ӽѹ�ҵ���Ԥ������ɫ���µ���ɫУ������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingSet(int nChannel, KSJ_COLOR_TEMPRATURE CcmPresetting);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_ColorCorrectionPresettingGet
    // ���ܣ���ȡ��ǰѡ�����ɫУ��Ԥ����ֵ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pCcmPresetting���������ȡ�����������ǰʹ�õ�Ԥ��ɫ����ɫУ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------	
	KSJ_API  int __stdcall KSJ_ColorCorrectionPresettingGet(int nChannel, KSJ_COLOR_TEMPRATURE *pCcmPresetting);



#ifdef __cplusplus
}
#endif

#endif