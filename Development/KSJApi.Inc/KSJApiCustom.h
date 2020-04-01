#ifndef __KSJ_API_CUSTOM_H__
#define __KSJ_API_CUSTOM_H__

// #pragma message("Include KSJApiCustom.h") 

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
    // ������KSJ_HelperStretchBmp
    // ���ܣ���pData(���ΪnWidth, �߶�ΪnHeight, ����λ��ΪnBitCount)��ͼ����������Ϊ���ΪnStretchWidh, �߶�ΪnStretchHeight�����ݲ���䵽�û������pStretchData������,����λ������
    // ������
	//       pData�� ���룬����ͼ�������ָ��
    //       nWidth�� ���룬����ͼ��Ŀ��
    //       nHeight�����룬����ͼ��ĸ߶�
    //       nBitCount�����룬����ͼ��ı������
	//       pStretchData�� ��������ͼ�񱣴��ڴ��ַָ��
    //       nStretchWidth�� ��������ͼ��Ŀ��
    //       nStretchHeight����������ͼ��ĸ߶�
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperStretchBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char *pStretchData, int nStretchWidth, int nStretchHeight);

	//-----------------------------------------------------------------------------
    // ������KSJ_HelperGetBmpFileHeaderSize
    // ���ܣ�����ͼ��ı�����ȵõ�BMPͼ����ļ�ͷ,��Ϣͷ,����ɫ���ܵ��ֽ���Ŀ
    // ������
	//       nBitCount�� ���룬ͼ��ı������
    //       pnTotalBytes�������BMP���ļ�ͷ����Ϣͷ���Լ���ɫ������ֽ���
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeaderSize(int nBitCount, int *pnTotalBytes);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_HelperGetBmpFileHeader
    // ���ܣ��õ�BMPͼ����ļ�ͷ����Ϣͷ
    // ������
	//       nWidth�� ���룬ͼ��Ŀ��
    //       nHeight�����룬ͼ��ĸ߶�
    //       nBitCount�����룬ͼ��ı������
    //       pHeader�������BMP���ļ�ͷ����Ϣͷ���ݱ���ĵ�ַָ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, void *pHeader);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureRgbDataToClipboard
    // ���ܣ��ɼ�һ֡ͼ��ϵͳ�����壬��һ������ɼ�һ֡ͼ�񲢷ŵ�ϵͳ�ļ��а�
    // ������
    //       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataToClipboard(int nChannel);

	//-----------------------------------------------------------------------------
    // ������KSJ_SetFlatFieldCorrectionFieldOfView
    // ���ܣ�����FFCУ���ο��ӳ�
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       nColStart�� ���룬У���ӳ���ˮƽ������ʼλ��
    //       nRowStart�����룬У���ӳ��Ĵ�ֱ����ʼλ��
	//       nColSize�����룬У���ӳ���ˮƽ������
    //       nRowSize�����룬У���ӳ��Ĵ�ֱ������
    //       AmCol�����룬У���ӳ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	//       AmRow�����룬У���ӳ��г��ģʽ����ο������Ӽѹ�ҵ���API����˵����-����ƪ��KSJ_ADDRESSMODE�Ķ��壩
	//       wMultiFrameNum�����룬У���ӳ�ƴ��֡��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFlatFieldCorrectionFieldOfView(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);

	//-----------------------------------------------------------------------------
    // ������KSJ_GetFlatFieldCorrectionFieldOfView
    // ���ܣ�����FFCУ���ο��ӳ�
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	//       pnColStart�� ���������У���ӳ���ˮƽ������ʼλ��
    //       pnRowStart�����������У���ӳ��Ĵ�ֱ����ʼλ��
	//       pnColSize�����������У���ӳ���ˮƽ������
    //       pnRowSize�����������У���ӳ��Ĵ�ֱ������
    //       pColAddressMode�����������У���ӳ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	//       pRowAddressMode�����������У���ӳ��г��ģʽ����ο������Ӽѹ�ҵ���API����˵����-����ƪ��KSJ_ADDRESSMODE�Ķ��壩
	//       pwMultiFrameNum�����������У���ӳ�ƴ��֡��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFlatFieldCorrectionFieldOfView(int nChannel, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);

	//-----------------------------------------------------------------------------
    // ������KSJ_MakeDarkFrame
    // ���ܣ���ȡ�ο���ͼ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nDarkFrames�����룬�ɼ������ź�ͼ��ƽ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeDarkFrame(int nChannel, int nDarkFrames);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_MakeFlatFieldFrame
    // ���ܣ���ȡ�ο���ͼ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       nFlatFieldFrames�����룬�ɼ������Ű�ͼ��ƽ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeFlatFieldFrame(int nChannel, int nFlatFieldFrames);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewSetFlatFieldCorrection
    // ���ܣ���Ԥ�����Ƿ����FFCУ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bEnable�����룬Ϊtrueʱ����FFCУ��, falseʱ�ر�FFCУ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFlatFieldCorrection(int nChannel, bool bEnable);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetFlatFieldCorrection
    // ���ܣ���ȡ��ǰԤ�����Ƿ����FFCУ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbEnable�����������FFC����Ԥ����ʹ��״̬
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFlatFieldCorrection(int nChannel, bool *pbEnable);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureSetFlatFieldCorrection
    // ���ܣ��Բɼ����Ƿ����FFCУ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bEnable�����룬Ϊtrueʱ����FFCУ��, falseʱ�ر�FFCУ��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFlatFieldCorrection(int nChannel, bool bEnable);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetFlatFieldCorrection
    // ���ܣ���ȡ�ɼ�ʱ�Ƿ����FFCУ������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbEnable�����������FFC���ڲɼ���ʹ��״̬
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFlatFieldCorrection(int nChannel, bool *pbEnable);

	//-----------------------------------------------------------------------------
    // ������KSJ_SaveFlatFieldCorrection
    // ���ܣ�����FFC��ǰ�Ĳο�ֵ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pszFilePath�����룬������ļ���������·����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SaveFlatFieldCorrection(int nChannel, TCHAR *pszFilePath);

	//-----------------------------------------------------------------------------
    // ������KSJ_LoadFlatFieldCorrection
    // ���ܣ����ڼ�����KSJ_SaveFlatFieldCorrection�����FFC�ο���Ϣ�ļ�
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pszFilePath�����룬��Ҫ���ص�FFC�ο���Ϣ���ļ���������·����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadFlatFieldCorrection(int nChannel, TCHAR *pszFilePath);


	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewSetCalibration
    // ���ܣ���Ԥ�����Ƿ���л����������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bEnable�����룬Ϊtrueʱʱ�����������, falseʱ�رջ������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetCalibration(int nChannel, bool bEnable);

	//-----------------------------------------------------------------------------
    // ������KSJ_PreviewGetCalibration
    // ���ܣ���ȡ��ǰԤ�����Ƿ���л����������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbEnable����������ػ����������Ԥ����ʹ��״̬
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetCalibration(int nChannel, bool *pbEnable);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureSetCalibration
    // ���ܣ��Բɼ��Ƿ���л����������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       bEnable�����룬Ϊtrueʱʱ�����������, falseʱ�رջ������
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetCalibration(int nChannel, bool bEnable);

	//-----------------------------------------------------------------------------
    // ������KSJ_CaptureGetCalibration
    // ���ܣ���ȡ�ɼ�ʱ�Ƿ���л����������
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pbEnable����������ػ���������ڲɼ���ʹ��״̬
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetCalibration(int nChannel, bool *pbEnable);

	//-----------------------------------------------------------------------------
    // ������KSJ_LoadCalibrationMapFile
    // ���ܣ����ڴ��ļ����ػ���У��������Ϣ
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pszFilePath�����룬��Ҫ�����ػ���У���������ļ���������·����
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadCalibrationMapFile(int nChannel, const TCHAR *pszFilePath);

	enum KSJ_MAPMODE //���Ӽѹ�ҵ�������У��Ŀ��ֵ���㷽ʽ����
	{
		KSJ_MM_NEARESTNEIGHBOR,
		KSJ_MM_BILINEAR
	};

	//-----------------------------------------------------------------------------
    // ������KSJ_SetCalibrationMapMode
    // ���ܣ����û���У��Ŀ��ֵ���㷽��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       MapMode�����룬���û���У��Ŀ��ֵ���㷽��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetCalibrationMapMode(int nChannel, KSJ_MAPMODE MapMode);
	
	//-----------------------------------------------------------------------------
    // ������KSJ_GetCalibrationMapMode
    // ���ܣ���ȡ����У��Ŀ��ֵ���㷽��
    // ������
	//       nChannel�� ���룬�豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    //       pMapMode���������ǰ����У��Ŀ��ֵ�ļ��㷽��
    // ���أ��ο�����״̬�루KSJCode.H��
    // ˵��������KSJ_Init������ʼ�������
	//-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetCalibrationMapMode(int nChannel, KSJ_MAPMODE *pMapMode);

#ifdef __cplusplus
}
#endif

#endif
