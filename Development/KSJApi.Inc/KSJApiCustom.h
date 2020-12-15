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

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  ���ͼ���ʽ��������Ҫֱ������ͼ��������ʽ��API�Զ����ɼ�����ͼ��ת������Ҫ�����ͼ���ʽ
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetImageFormat
	/// @brief     ����ͼ����������ݸ�ʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     ImageFormat [in] ͼ���ʽ����ο�KSJ_IMAGE_FORMAT�Ķ��壩
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetImageFormat(IN int nIndex, IN KSJ_IMAGE_FORMAT ImageFormat);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetImageFormat
	/// @brief     ���ͼ����������ݸ�ʽ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pImageFormat [out] ���ص�ǰ�����ͼ���ʽ����ο�KSJ_IMAGE_FORMAT�Ķ��壩
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetImageFormat(IN int nIndex, OUT KSJ_IMAGE_FORMAT *pImageFormat);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  ͼ��Ƭ���ܣ������Ƿ����ͼ��Ƭ
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetNegativeImageMode
	/// @brief     ����ͼ������ĸ�Ƭ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bNegative [in] ��Ƭ
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetNegativeImageMode(IN int nIndex, IN bool bNegative);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetNegativeImageMode
	/// @brief     ���ͼ���Ƿ�Ƭ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbNegative [out] ���ص�ǰ�����ͼ���Ƿ�Ƭ
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetNegativeImageMode(IN int nIndex, OUT bool* pbNegative);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  ȫ�ָ�λ�������ţ�����ȫ�ֿ����Ƿ�ʹ��
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  FFCУ����Ŀ�����������������ؼ䲻ͬ�������������Լ���·�Ļ�������ɵ����Ȳ����ȵ�����FFCУ�����̣�
    ///     1������ͨ��KSJ_SetFlatFieldCorrectionFieldOfView����FFC�Ĳο��ӳ�������ӳ����������Ĳɼ���Ԥ���ӳ������Ժ�ʹ��FFCʱ�������õ��ӳ�������FFC�Ĳο��ӳ�һ�£��ſ��Խ���У����
    ///     2���������������ʹ�ɼ���ͼ�񱣳�������
    ///     3����ס��ͷ����Ҫ�ù���룬����KSJ_MakeDarkFrame�ɼ�һ����ͼ��������ָ���ɼ������ţ��˺�������ƽ�����յõ�һ����ͼ��(�ò���Ǳ��룬������ɼ���ͼ����ô��ͼĬ��Ϊȫ��)��
    ///     4����Ҫ��ס��ͷ���ù��������룬��һ�Ű�ֽ������KSJ_MakeFlatFieldFrame�ɼ�һ��ͼ��������ָ���ɼ������ţ��˺�������ƽ�����յõ�һ����ֽͼ��
    ///     5������KSJ_PreviewSetFlatFieldCorrection��KSJ_CaptureSetFlatFieldCorrection���������������Ƿ���Ԥ�����л����ڲɼ�ͼ��ʱ������FFCУ������
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	/// Ԥ�ع����ã���Sensor��ͼ�ع�֮ǰ������ƻ���ǰ�ع�һ��ʱ�䣬����ͨ�����º������в��ԣ��ù��ܽ������������֧��
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureRangeGet
	/// @brief     �õ�Ԥ�ع�ʱ�䷶Χ
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnMinValue[out] ����Ԥ�ع�ʱ����Сֵָ�룬��λΪ�ع���
	/// @param     pnMaxValue[out] ����Ԥ�ع�ʱ�����ֵָ�룬��λΪ�ع���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureRangeGet(int nIndex, int *pnMinValue, int *pnMaxValue);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureTimeSet
	/// @brief     ����Ԥ�ع�ʱ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fPreExpTimeMs [in] ���õ�Ԥ�ع�ʱ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeSet(int nIndex, float fPreExpTimeMs);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureTimeGet
	/// @brief     ��ȡԤ�ع�ʱ��
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pfPreExpTimeMs[out] ����Ԥ�ع�ʱ���ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureTimeGet(int nIndex, float *pfPreExpTimeMs);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureLinesSet
	/// @brief     ����Ԥ�ع���
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nPreExpLines [in] ���õ�Ԥ�ع���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesSet(int nIndex, int nPreExpLines);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_PreExposureLinesGet
	/// @brief     ��ȡԤ�ع���
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnPreExpLines[out] ����Ԥ�ع�ʱ���ָ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreExposureLinesGet(int nIndex, int* pnPreExpLines);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  ����Ԥ��ͼ�񻺴�����Ĭ��Ԥ��������Ϊ4����ʹ��Ԥ�����ܵ�ʱ�������ã�ռ��ϵͳ�ڴ�
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SetBufferCount
	/// @brief     ����Ԥ��ͼ�񻺴������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nCount [in] ����Ԥ����������� 
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetBufferCount(int nIndex, int nCount);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GetBufferCount
	/// @brief     ��ȡԤ��ͼ�񻺴������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnCount [out] ����Ԥ����������� 
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetBufferCount(int nIndex, int* pnCount);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  ���֡���ɼ�ͼ�񣺶�����Ҫ�ɼ�ʵʱͼ���Ȱ������֡�����������գ�Ȼ���ڲɼ�ͼ��
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_CaptureRawDataAfterEmptyFrameBuffer
	/// @brief     ���֡���ɼ�һ֡ԭʼ��ڰ�ͼ������
    /// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRawData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSize�������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
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
	/// @brief     KSJ_CaptureRgbDataExAfterEmptyFrameBuffer
	/// @brief     ���֡���ɼ�һ֡8λԭʼ��Ҷ�ͼ���24��32λ��ɫ����ͼ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pRgbData [out] ���û������ڴ�ռ䣬���ڱ���ɼ����ݣ��ɼ�ͼ������سߴ����ͨ��KSJ_CaptureGetSizeEx�������
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
	/// @param     pnHeight [out] ����ͼ��ĸ߶ȣ����أ�
	/// @param     pnBitCount [out] ����ͼ���ÿ������λ����8��24��32������KSJ_PreviewSetMode��KSJ_BayerSetMode������Ӱ��
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureRgbDataExAfterEmptyFrameBuffer(int nIndex, unsigned char *pRgbData, int *pnWidth, int *pnHeight, int *pnBitCount);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  ���������ӳ�����������Ƿ�ƥ�䣺��鵱ǰ��FOV�Ƿ��ܹ�Ӧ�õ������
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CheckFieldOfView
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
	/// @attention �ú����û���⼴�����õ�FOV�Ƿ��ܹ����õ���ǰ����ϡ�
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CheckFieldOfView(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow);


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///  ���USB����״̬����������쳣�������޷���ͼ���ɼ�ͼ����������Բ鿴��ǰUSB����״̬
	///
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	enum KSJ_USBSPEED//���USB����״̬
	{
		USB_NOT_CONNECTED = 0x00,        ///USBͨ��ʧ��
		USB_FULL_SPEED,                  ///ȫ��USB
		USB_HIGH_SPEED,                  ///����USB
		USB_SUPER_SPEED                  ///USB3.0
	};

	///-----------------------------------------------------------------------------
	/// @brief     ��ȡUSBKSJ_GetUsbState
	/// @brief     ��ȡUSB����״̬
	/// ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pUSBSpeed [out] ���ص�ǰUSB����״̬����ο�KSJ_USBSPEED�Ķ��壩
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetUsbState(int nIndex, KSJ_USBSPEED* pUSBSpeed);

	KSJ_API  int __stdcall KSJ_CalibrationProgram(int nIndex, float fCoefficient[14]);
	KSJ_API  int __stdcall KSJ_CalibrationReadout(int nIndex, float fCoefficient[14]);

#ifdef __cplusplus
}
#endif

#endif
