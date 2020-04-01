#ifndef __KSJ_API_16BITS_H__
#define __KSJ_API_16BITS_H__

// #pragma message("Include KSJApi16Bits.h") 

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

	//-----------------------------------------------------------------------------
    // ������KSJ_GetADCResolution
    // ���ܣ���ȡͼ�񴫸�����ADCת�����ȣ�����λ����
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnADCResolution�� ���������ADCʱ�ı���λ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetADCResolution(int nChannel, int *pnADCResolution);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_SetData16Bits
    // ���ܣ����������16bitÿ�����ش������ݣ������������10bit����12bit���������Ǵ��������16bit���д��䣩
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnADCResolution�� ���룬Ϊtrueʱ����16bitԭʼ���ݴ���, falseʱ�����ã��ָ�8bitԭʼ���ݴ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetData16Bits(int nChannel, bool bEnable);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_GetData16Bits
    // ���ܣ��������ڻ�ȡ�豸�Ƿ���16bitԭʼ���ݴ���
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bEnable�� ���������ΪtrueʱΪ16bitԭʼ���ݴ���, falseʱΪĬ��8bitԭʼ���ݴ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetData16Bits(int nChannel, bool *bEnable);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureGetSizeExEx
    // ���ܣ��ú����õ��ɼ�ͼ��Ŀ�Ⱥ͸߶ȣ���λ�����أ���λͼ��ȣ�8��24��32����ÿ�������ı���λ��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pnWidth�� ��������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ؿ��
    //       pnHeight����������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ظ߶�
    //       pnBitCount����������ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
	//       nBitsPerSample�������nSamplesPerPixel = 1��3��4(�ֱ��ӦBitCount=8,24,32)
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSizeExEx(int nChannel, int *pnWidth, int *pnHeight, int *pnBitCount, int *nBitsPerSample);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_HelperSaveToTiff
    // ���ܣ���ȡͼ�񴫸�����ADCת�����ȣ�����λ����
    // ������
    //       pData�� ���룬ָ��ͼ�����ݵ��׵�ַָ��
	//       nWidth�� ���룬ͼ��Ŀ�ȣ����أ�
    //       nHeight�����룬ͼ��ĸ߶ȣ����أ�
    //       nBitPerSample�����룬����λ����nBitPerSample = 8 ��16���ֱ�Ϊ8bit��16bit����
	//       nSamplesPerPixel�����룬����λ����nBitPerSample = 8 ��16���ֱ�Ϊ8bit��16bit����
    //       pszFileName�����룬�����ļ���ȫ·������·��������ڣ�
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������������ʱ�̵���
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToTiff(unsigned char *pData, int nWidth, int nHeight, int nBitPerSample, int nSamplesPerPixel, const TCHAR *pszFileName);

#ifdef __cplusplus
}
#endif

#endif