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

	enum KSJ_IMAGE_FORMAT
	{
		KSJ_IF_RAW8 = 0,
		KSJ_IF_GRAY8,
		KSJ_IF_RGB24,
		KSJ_IF_RGB32,
		KSJ_IF_BGR24,
		KSJ_IF_BGR32,
		KSJ_IF_RAW16,
		KSJ_IF_GRAY16,
		KSJ_IF_RGB48,
		KSJ_IF_RGB64,
		KSJ_IF_BGR48,
		KSJ_IF_BGR64,
	};

	KSJ_API  int __stdcall KSJ_SetImageFormat(IN int nIndex, IN KSJ_IMAGE_FORMAT ImageFormat);
	KSJ_API  int __stdcall KSJ_GetImageFormat(IN int nIndex, OUT KSJ_IMAGE_FORMAT *pImageFormat);

	////////////////////////////////////////////Capture/////////////////////////////////
	///-----------------------------------------------------------------------------
	///
	/// @brief     ���������ӳ�����������Ƿ�ƥ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [in] Ҫ����ˮƽ������ʼλ��
	/// @param     pnRowStart [in] Ҫ���Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [in] Ҫ����ˮƽ������
	/// @param     pnRowSize [in] Ҫ���Ĵ�ֱ����
	/// @param     AmCol [in] Ҫ������Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     AmRow [in] Ҫ������Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @return    �ο�����1��ʾƥ�䣬����ƥ��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CheckFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����ȫ�ָ�λ��������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bGlobalReset [in] ����ȫ�ָ�λ����������Ч
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GlobalResetShutterSet(int nIndex, bool bGlobalReset);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �õ�ȫ�ָ�λ��������״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbGlobalReset[out] ����ȫ�ָ�λ��������״ָ̬��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GlobalResetShutterGet(int nIndex, bool* pbGlobalReset);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_HelperStretchBmp
    /// @brief     ��pData(���ΪnWidth, �߶�ΪnHeight, ����λ��ΪnBitCount)��ͼ����������Ϊ���ΪnStretchWidh, �߶�ΪnStretchHeight�����ݲ���䵽�û������pStretchData������,����λ������
    /// ������
	/// @param     pData [in] ����ͼ�������ָ��
    /// @param     nWidth [in] ����ͼ��Ŀ��
    /// @param     nHeight [in] ����ͼ��ĸ߶�
    /// @param     nBitCount [in] ����ͼ��ı������
	/// @param     pStretchData [out] ���ͼ�񱣴��ڴ��ַָ��
    /// @param     nStretchWidth [out] ���ͼ��Ŀ��
    /// @param     nStretchHeight [out] ���ͼ��ĸ߶�
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperStretchBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char *pStretchData, int nStretchWidth, int nStretchHeight);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_HelperGetBmpFileHeaderSize
    /// @brief     ����ͼ��ı�����ȵõ�BMPͼ����ļ�ͷ,��Ϣͷ,����ɫ���ܵ��ֽ���Ŀ
    /// ������
	/// @param     nBitCount [in] ͼ��ı������
    /// @param     pnTotalBytes [out] BMP���ļ�ͷ����Ϣͷ���Լ���ɫ������ֽ���
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeaderSize(int nBitCount, int *pnTotalBytes);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_HelperGetBmpFileHeader
    /// @brief     �õ�BMPͼ����ļ�ͷ����Ϣͷ
    /// ������
	/// @param     nWidth [in] ͼ��Ŀ��
    /// @param     nHeight [in] ͼ��ĸ߶�
    /// @param     nBitCount [in] ͼ��ı������
    /// @param     pHeader [out] BMP���ļ�ͷ����Ϣͷ���ݱ���ĵ�ַָ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, void *pHeader);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureRgbDataToClipboard
    /// @brief     �ɼ�һ֡ͼ��ϵͳ�����壬��һ������ɼ�һ֡ͼ�񲢷ŵ�ϵͳ�ļ��а�
    /// ������
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataToClipboard(int nIndex);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SetFlatFieldCorrectionFieldOfView
    /// @brief     ����FFCУ���ο��ӳ�
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nColStart [in] У���ӳ���ˮƽ������ʼλ��
    /// @param     nRowStart [in] У���ӳ��Ĵ�ֱ����ʼλ��
	/// @param     nColSize [in] У���ӳ���ˮƽ������
    /// @param     nRowSize [in] У���ӳ��Ĵ�ֱ������
    /// @param     AmCol [in] У���ӳ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     AmRow [in] У���ӳ��г��ģʽ����ο������Ӽѹ�ҵ���API����˵����-����ƪ��KSJ_ADDRESSMODE�Ķ��壩
	/// @param     wMultiFrameNum [in] У���ӳ�ƴ��֡��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetFlatFieldCorrectionFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GetFlatFieldCorrectionFieldOfView
    /// @brief     ����FFCУ���ο��ӳ�
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [out] ����У���ӳ���ˮƽ������ʼλ��
    /// @param     pnRowStart [out] ����У���ӳ��Ĵ�ֱ����ʼλ��
	/// @param     pnColSize [out] ����У���ӳ���ˮƽ������
    /// @param     pnRowSize [out] ����У���ӳ��Ĵ�ֱ������
    /// @param     pColAddressMode [out] ����У���ӳ��г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pRowAddressMode [out] ����У���ӳ��г��ģʽ����ο������Ӽѹ�ҵ���API����˵����-����ƪ��KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pwMultiFrameNum [out] ����У���ӳ�ƴ��֡��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFlatFieldCorrectionFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_MakeDarkFrame
    /// @brief     ��ȡ�ο���ͼ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nDarkFrames [in] �ɼ������ź�ͼ��ƽ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeDarkFrame(int nIndex, int nDarkFrames);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_MakeFlatFieldFrame
    /// @brief     ��ȡ�ο���ͼ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nFlatFieldFrames [in] �ɼ������Ű�ͼ��ƽ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeFlatFieldFrame(int nIndex, int nFlatFieldFrames);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewSetFlatFieldCorrection
    /// @brief     ��Ԥ�����Ƿ����FFCУ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] Ϊtrueʱ����FFCУ��, falseʱ�ر�FFCУ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFlatFieldCorrection(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetFlatFieldCorrection
    /// @brief     ��ȡ��ǰԤ�����Ƿ����FFCУ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ����FFC����Ԥ����ʹ��״̬
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFlatFieldCorrection(int nIndex, bool *pbEnable);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureSetFlatFieldCorrection
    /// @brief     �Բɼ����Ƿ����FFCУ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] Ϊtrueʱ����FFCУ��, falseʱ�ر�FFCУ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFlatFieldCorrection(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetFlatFieldCorrection
    /// @brief     ��ȡ�ɼ�ʱ�Ƿ����FFCУ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ����FFC���ڲɼ���ʹ��״̬
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFlatFieldCorrection(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SaveFlatFieldCorrection
    /// @brief     ����FFC��ǰ�Ĳο�ֵ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pszFilePath [in] ������ļ���������·����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SaveFlatFieldCorrection(int nIndex, TCHAR *pszFilePath);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LoadFlatFieldCorrection
    /// @brief     ���ڼ�����KSJ_SaveFlatFieldCorrection�����FFC�ο���Ϣ�ļ�
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pszFilePath [in] ��Ҫ���ص�FFC�ο���Ϣ���ļ���������·����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadFlatFieldCorrection(int nIndex, TCHAR *pszFilePath);


	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewSetCalibration
    /// @brief     ��Ԥ�����Ƿ���л����������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] Ϊtrueʱʱ�����������, falseʱ�رջ������
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetCalibration
    /// @brief     ��ȡ��ǰԤ�����Ƿ���л����������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ���ػ����������Ԥ����ʹ��״̬
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetCalibration(int nIndex, bool *pbEnable);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureSetCalibration
    /// @brief     �Բɼ��Ƿ���л����������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] Ϊtrueʱʱ�����������, falseʱ�رջ������
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureGetCalibration
    /// @brief     ��ȡ�ɼ�ʱ�Ƿ���л����������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ���ػ���������ڲɼ���ʹ��״̬
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetCalibration(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LoadCalibrationMapFile
    /// @brief     ���ڴ��ļ����ػ���У��������Ϣ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pszFilePath [in] ��Ҫ�����ػ���У���������ļ���������·����
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadCalibrationMapFile(int nIndex, const TCHAR *pszFilePath);

	enum KSJ_MAPMODE ///���Ӽѹ�ҵ�������У��Ŀ��ֵ���㷽ʽ����
	{
		KSJ_MM_NEARESTNEIGHBOR,
		KSJ_MM_BILINEAR
	};

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SetCalibrationMapMode
    /// @brief     ���û���У��Ŀ��ֵ���㷽��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     MapMode [in] ���û���У��Ŀ��ֵ���㷽��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetCalibrationMapMode(int nIndex, KSJ_MAPMODE MapMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GetCalibrationMapMode
    /// @brief     ��ȡ����У��Ŀ��ֵ���㷽��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pMapMode [out] ��ǰ����У��Ŀ��ֵ�ļ��㷽��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetCalibrationMapMode(int nIndex, KSJ_MAPMODE *pMapMode);


	enum KSJ_SNAPBUTTONSTATUS ///Snap��������״̬
	{
		KSJ_UP, 	///�������ڱպ�״̬
		KSJ_DOWN 	///�������ڿ���״̬
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡSnap��������״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pSnapButtonStatus [out] ����Snap��������״̬, KSJ_SNAPBUTTONSTATUS����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SnapButtonStatus(int nIndex, KSJ_SNAPBUTTONSTATUS *pSnapButtonStatus);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �õ�Ԥ�ع�ʱ�䷶Χ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnMinValue[out] ����Ԥ�ع�ʱ����Сֵָ�룬��λΪ�ع���
	/// @param     pnMaxValue[out] ����Ԥ�ع�ʱ�����ֵָ�룬��λΪ�ع���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureRangeGet(int nIndex, int *pnMinValue, int *pnMaxValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����Ԥ�ع�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fPreExpTimeMs [in] ���õ�Ԥ�ع�ʱ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeSet(int nIndex, float fPreExpTimeMs);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡԤ�ع�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfPreExpTimeMs[out] ����Ԥ�ع�ʱ���ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeGet(int nIndex, float *pfPreExpTimeMs);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����Ԥ�ع���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nPreExpLines [in] ���õ�Ԥ�ع���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesSet(int nIndex, int nPreExpLines);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡԤ�ع���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnPreExpLines[out] ����Ԥ�ع�ʱ���ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesGet(int nIndex, int* pnPreExpLines);

	/// Preview Mode
	enum KSJ_PREVIEWMODE// ö��������ƵԤ��ģʽ
	{
		PM_RAWDATA, ///Ԥ��ԭʼ���ݣ����ںڰ��豸����������ΪPM_RAWDATA
		PM_RGBDATA  ///Ԥ��24λ��32λ��ɫ���ݣ���Bayerģʽ������
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ�豸Ĭ�ϵ�Ԥ��ģʽ
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pPreviewMode   [out] ��ȡ���Ĭ�ϵ�Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetDefaultMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewSetMode
	/// @brief     ������Ƶ��Ϊԭʼ�ɼ����ݻ���RGB 24λ��32λ��ɫ���ݸ�ʽ��һ���û���������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     PreviewMode [in] ���õ�Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetMode(int nIndex, KSJ_PREVIEWMODE PreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetMode
	/// @brief     ��ȡ����ĵ�ǰԤ��ģʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pPreviewMode   [out] ��ȡ��ǰ��Ԥ��ģʽ���ο�KSJ_PREVIEWMODE���壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetMode(int nIndex, KSJ_PREVIEWMODE *pPreviewMode);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewGetFrameRate
	/// @brief     ��ȡ֡��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fFrameRate [out] ���ص�ǰ��Ƶ����֡��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFrameRate(int nIndex, float *fFrameRate);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ��ͣʱ����һ֡ͼ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pData [out] ���û��ṩ���������򣬺������÷��غ󣬴�����ᱻ�����ͣʱ��ͼ������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedData(int nIndex, unsigned char *pData);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_PreviewPause
	/// @brief     ��ͣ�������Ƶ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bPause   [in] true ��ͣ��Ƶ����false ������Ƶ�� 
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewPause(int nIndex, bool bPause);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡ��ͣʱ����һ֡ͼ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pData [out] ���û��ṩ���������򣬺������÷��غ󣬴�����ᱻ�����ͣʱ��ͼ������
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
	/// @param     pnHeight[out] ����ͼ��ĸ߶ȣ����أ�
	/// @param     pnBitCount[out] ����ͼ���ÿ������λ����8��24��32��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetPausedDataEx(int nIndex, unsigned char *pData, int *pnWidth, int *pnHeight, int *pnBitCount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����Ԥ��ͼ�񻺴������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nCount [in] ����Ԥ����������� 
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetBufferCount(int nIndex, int nCount);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡԤ��ͼ�񻺴������
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnCount [out] ����Ԥ����������� 
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetBufferCount(int nIndex, int* pnCount);

	enum KSJ_USBSPEED//���USB����״̬
	{
		USB_NOT_CONNECTED = 0x00,        ///USBͨ��ʧ��
		USB_FULL_SPEED,                  ///ȫ��USB
		USB_HIGH_SPEED,                  ///����USB
		USB_SUPER_SPEED                  ///USB3.0
	};

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡUSB����״̬
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pUSBSpeed [out] ���ص�ǰUSB����״̬ 
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetUsbState(int nIndex, KSJ_USBSPEED* pUSBSpeed);




	///-----------------------------------------------------------------------------
	///
	/// @brief     ���֡���ɼ�һ֡ԭʼ��ڰ�ͼ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRawData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize�������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRawDataAfterEmptyFrameBuffer(int nIndex, unsigned char *pRawData);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureRgbDataAfterEmptyFrameBuffer
	/// @brief     ���֡���ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRgbData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ���֡���ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRgbData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
	/// @param     pnHeight [out] ����ͼ��ĸ߶ȣ����أ�
	/// @param     pnBitCount [out] ����ͼ���ÿ������λ����8��24��32������KSJ_PreviewSetMode��KSJ_BayerSetMode������Ӱ��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataExAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);

#ifdef __cplusplus
}
#endif

#endif
