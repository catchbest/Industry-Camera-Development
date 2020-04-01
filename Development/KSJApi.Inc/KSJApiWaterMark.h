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

	enum KSJ_WATERMARKMODE //ˮӡģʽ
	{ 
		KSJ_WMM_TIMESTAMP, 
		KSJ_WMM_DISTINGUISH_EXTERNAL_TRIGGER, 
		KSJ_WMM_ANALYSIS_EXTERNAL_TRIGGER 
	};

	//-----------------------------------------------------------------------------
    // ������KSJ_WaterMarkSetMode
    // ���ܣ�����ˮӡģʽ���°汾ˮӡ�Ѿ���֧��ˮӡģʽ���ã�Ĭ��KSJ_WMM_TIMESTAMP��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       WaterMarkMode�����룬����ˮӡģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetMode(int nChannel, KSJ_WATERMARKMODE WaterMarkMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WaterMarkGetMode
    // ���ܣ���ȡˮӡģʽ���°汾ˮӡ�Ѿ���֧��ˮӡģʽ���ã�Ĭ��KSJ_WMM_TIMESTAMP��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pWaterMarkMode���������ȡ��ǰˮӡģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetMode(int nChannel, KSJ_WATERMARKMODE *pWaterMarkMode);

	//-----------------------------------------------------------------------------
    // ������KSJ_WaterMarkSetEnable
    // ���ܣ������Ƿ���ˮӡ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bEnable�����룬�Ƿ���ˮӡ���ܣ�true��ʾ������false��ʾ������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkSetEnable(int nChannel, bool bEnable);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WaterMarkGetEnable
    // ���ܣ���ȡ�Ƿ���ˮӡ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pWaterMarkMode���������ȡ��ǰˮӡģʽ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetEnable(int nChannel, bool *pbEnable);

	//-----------------------------------------------------------------------------
    // ������KSJ_WaterMarkGetInfo
    // ���ܣ���ȡˮӡ��Ϣ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pwId���������ȡ��ǰˮӡ��
	//       pdwTimestampLowPart���������ȡʱ����ĵ�4�ֽ�ֵ
	//       pdwTimestampHighPart���������ȡʱ����ĸ�4�ֽ�λֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetInfo(int nChannel, unsigned short *pwId, unsigned long *pdwTimestampLowPart, unsigned long *pdwTimestampHighPart);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_WaterMarkGetInfoEx
    // ���ܣ���ȡˮӡ��Ϣ�������ع�
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pwId���������ȡ��ǰˮӡ��
	//       pdwTimestampLowPart���������ȡʱ����ĵ�4�ֽ�ֵ
	//       pdwTimestampHighPart���������ȡʱ����ĸ�4�ֽ�λֵ
	//       pnExposure���������ȡ��ǰͼ����ع�ֵ
	//       pwGain���������ȡ��ǰͼ�������ֵ
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_WaterMarkGetInfoEx(int nChannel, unsigned int *pnId, unsigned long *pdwTimestampLowPart, unsigned long *pdwTimestampHighPart, unsigned int* pnExposure, unsigned short* pwGain);

#ifdef __cplusplus
}
#endif

#endif
