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

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����ȫ�ָ�λ��������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bGlobalReset [in] ����ȫ�ָ�λ����������Ч
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GlobalResetShutterSet(int nIndex, bool bGlobalReset);

	///-----------------------------------------------------------------------------
	///
	/// @brief     �õ�ȫ�ָ�λ��������״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbGlobalReset[out] ����ȫ�ָ�λ��������״ָ̬��
	/// @return    �ο�����״̬�루KSJCode.H��
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
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperStretchBmp(unsigned char *pData, int nWidth, int nHeight, int nBitCount, unsigned char *pStretchData, int nStretchWidth, int nStretchHeight);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_HelperGetBmpFileHeaderSize
    /// @brief     ����ͼ��ı�����ȵõ�BMPͼ����ļ�ͷ,��Ϣͷ,����ɫ���ܵ��ֽ���Ŀ
    /// ������
	/// @param     nBitCount [in] ͼ��ı������
    /// @param     pnTotalBytes [out] BMP���ļ�ͷ����Ϣͷ���Լ���ɫ������ֽ���
    /// @return    �ο�����״̬�루KSJCode.H��
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
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperGetBmpFileHeader(int nWidth, int nHeight, int nBitCount, void *pHeader);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureRgbDataToClipboard
    /// @brief     �ɼ�һ֡ͼ��ϵͳ�����壬��һ������ɼ�һ֡ͼ�񲢷ŵ�ϵͳ�ļ��а�
    /// ������
    /// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @return    �ο�����״̬�루KSJCode.H��
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
    /// @return    �ο�����״̬�루KSJCode.H��
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
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetFlatFieldCorrectionFieldOfView(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_MakeDarkFrame
    /// @brief     ��ȡ�ο���ͼ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nDarkFrames [in] �ɼ������ź�ͼ��ƽ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeDarkFrame(int nIndex, int nDarkFrames);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_MakeFlatFieldFrame
    /// @brief     ��ȡ�ο���ͼ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nFlatFieldFrames [in] �ɼ������Ű�ͼ��ƽ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_MakeFlatFieldFrame(int nIndex, int nFlatFieldFrames);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewSetFlatFieldCorrection
    /// @brief     ��Ԥ�����Ƿ����FFCУ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] Ϊtrueʱ����FFCУ��, falseʱ�ر�FFCУ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFlatFieldCorrection(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetFlatFieldCorrection
    /// @brief     ��ȡ��ǰԤ�����Ƿ����FFCУ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ����FFC����Ԥ����ʹ��״̬
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFlatFieldCorrection(int nIndex, bool *pbEnable);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureSetFlatFieldCorrection
    /// @brief     �Բɼ����Ƿ����FFCУ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] Ϊtrueʱ����FFCУ��, falseʱ�ر�FFCУ��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFlatFieldCorrection(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetFlatFieldCorrection
    /// @brief     ��ȡ�ɼ�ʱ�Ƿ����FFCУ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ����FFC���ڲɼ���ʹ��״̬
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFlatFieldCorrection(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_SaveFlatFieldCorrection
    /// @brief     ����FFC��ǰ�Ĳο�ֵ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pszFilePath [in] ������ļ���������·����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SaveFlatFieldCorrection(int nIndex, TCHAR *pszFilePath);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LoadFlatFieldCorrection
    /// @brief     ���ڼ�����KSJ_SaveFlatFieldCorrection�����FFC�ο���Ϣ�ļ�
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pszFilePath [in] ��Ҫ���ص�FFC�ο���Ϣ���ļ���������·����
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadFlatFieldCorrection(int nIndex, TCHAR *pszFilePath);


	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewSetCalibration
    /// @brief     ��Ԥ�����Ƿ���л����������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] Ϊtrueʱʱ�����������, falseʱ�رջ������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_PreviewGetCalibration
    /// @brief     ��ȡ��ǰԤ�����Ƿ���л����������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ���ػ����������Ԥ����ʹ��״̬
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetCalibration(int nIndex, bool *pbEnable);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureSetCalibration
    /// @brief     �Բɼ��Ƿ���л����������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] Ϊtrueʱʱ�����������, falseʱ�رջ������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetCalibration(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_CaptureGetCalibration
    /// @brief     ��ȡ�ɼ�ʱ�Ƿ���л����������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ���ػ���������ڲɼ���ʹ��״̬
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetCalibration(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
    /// @brief     KSJ_LoadCalibrationMapFile
    /// @brief     ���ڴ��ļ����ػ���У��������Ϣ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pszFilePath [in] ��Ҫ�����ػ���У���������ļ���������·����
    /// @return    �ο�����״̬�루KSJCode.H��
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
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetCalibrationMapMode(int nIndex, KSJ_MAPMODE MapMode);
	
	///-----------------------------------------------------------------------------
    /// @brief     KSJ_GetCalibrationMapMode
    /// @brief     ��ȡ����У��Ŀ��ֵ���㷽��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pMapMode [out] ��ǰ����У��Ŀ��ֵ�ļ��㷽��
    /// @return    �ο�����״̬�루KSJCode.H��
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
	/// @return    �ο�����״̬�루KSJCode.H��
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
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureRangeGet(int nIndex, int *pnMinValue, int *pnMaxValue);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����Ԥ�ع�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fPreExpTimeMs [in] ���õ�Ԥ�ع�ʱ��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeSet(int nIndex, float fPreExpTimeMs);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡԤ�ع�ʱ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfPreExpTimeMs[out] ����Ԥ�ع�ʱ���ָ��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeGet(int nIndex, float *pfPreExpTimeMs);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ����Ԥ�ع���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nPreExpLines [in] ���õ�Ԥ�ع���
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesSet(int nIndex, int nPreExpLines);

	///-----------------------------------------------------------------------------
	///
	/// @brief     ��ȡԤ�ع���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnPreExpLines[out] ����Ԥ�ع�ʱ���ָ��
	/// @return    �ο�����״̬�루KSJCode.H��
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesGet(int nIndex, int* pnPreExpLines);

#ifdef __cplusplus
}
#endif

#endif
