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

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetADCResolution
	/// @brief     ��ȡͼ�񴫸�����ADCת�����ȣ�����λ����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnADCResolution [out] ����ADCʱ�ı���λ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetADCResolution(int nIndex, int *pnADCResolution);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SetData16Bits
	/// @brief     ��������Ƿ���16bit��ʽ�������ݣ������������10bit����12bit���������Ǵ��������8bit����16bit���д��䣩
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] Ϊtrueʱ������ÿ�����ص�ԭʼ���ݴ������λ��Ϊ16bit��Ϊfalseʱ������ÿ�����ص�ԭʼ���ݴ������λ��Ϊ8bit
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///           \li �����10bit����12bit����ʱ��ת��16bit�����ʱ�򣬸�λ��0����λ��Ч��
	///
	///----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetData16Bits(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_GetData16Bits
	/// @brief     �������ڻ�ȡ�豸�Ƿ���16bitԭʼ���ݴ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [out] Ϊtrueʱ��ÿ�����ص�ԭʼ���ݴ������λ��Ϊ16bit��Ϊfalseʱ��ÿ�����ص�ԭʼ���ݴ������λ��Ϊ8bit
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetData16Bits(int nIndex, bool *bEnable);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetSizeExEx
	/// @brief     �ú����õ��ɼ�ͼ��Ŀ�Ⱥ͸߶ȣ���λ�����أ���λͼ��ȣ�8��24��32����ÿ�������ı���λ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnWidth [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ؿ��
	/// @param     pnHeight [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ������ظ߶�
	/// @param     pnBitCount [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
	/// @param     nBitsPerSample [out] ����λ����nBitPerSample = 8 ��16���ֱ�Ϊ8bit��16bit����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetSizeExEx(int nIndex, int *pnWidth, int *pnHeight, int *pnBitCount, int *nBitsPerSample);
	
	///-----------------------------------------------------------------------------
    ///
    /// @brief     KSJ_HelperSaveToTiff
    /// @brief     ��ͼ�񱣴�ΪTiff��ʽͼ���ļ�
    /// @param     pData [in] ָ��ͼ�����ݵ��׵�ַָ��
	/// @param     nWidth [in] ͼ��Ŀ�ȣ����أ�
    /// @param     nHeight [in] ͼ��ĸ߶ȣ����أ�
    /// @param     nBitPerSample [in] ����λ����nBitPerSample = 8 ��16���ֱ�Ϊ8bit��16bit����
	/// @param     nSamplesPerPixel [in] ��ʾÿ�������м��������㣬nSamplesPerPixel = 1��3��4(�ֱ��ӦBitCount=8,24,32)
    /// @param     pszFileName [in] �����ļ���ȫ·������·��������ڣ�
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����������ʱ�̵���
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HelperSaveToTiff(unsigned char *pData, int nWidth, int nHeight, int nBitPerSample, int nSamplesPerPixel, const TCHAR *pszFileName);

#ifdef __cplusplus
}
#endif

#endif