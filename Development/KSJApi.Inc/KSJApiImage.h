#ifndef __KSJ_API_IMAGE_H__
#define __KSJ_API_IMAGE_H__

// #pragma message("Include KSJApiImage.h") 

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
	/// @brief     KSJ_BadPixelCorrectionSetThreshold
	/// @brief     �����������У����������ֵ����������ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     btLow [in] �����������صıȽ���ֵ��Ĭ��20
	/// @param     btHigh [in] �����������صıȽ���ֵ��Ĭ��50
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li ������������������صĲ�ֵ����btLow����������������������صĲ�ֵ����btHigh����ô�õ㽫����Ϊ�ǻ��㡣
	///          \li �����ý����������У����Ч�����Ӳ��֧�ֻ���У������ôʹ���ڲ�Ԥ��ֵ����Ӳ������У��������ִ���������У����
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSetThreshold(int nIndex, unsigned char btLow, unsigned char btHigh);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BadPixelCorrectionGetThreshold
	/// @brief     ��ȡ�������У������ֵ����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbtLow [out] �����������صıȽ���ֵ
	/// @param     pbtHigh [out] ���ش��������صıȽ���ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGetThreshold(int nIndex, unsigned char *pbtLow, unsigned char *pbtHigh);

	/// ��������ֵģʽ
	enum KSJ_THRESHOLD
	{
		KSJ_THRESHOLD_LOW,  ///< ����ֵģʽ
		KSJ_THRESHOLD_HIGH  ///< ����ֵģʽ
	};
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BadPixelCorrectionSet
	/// @brief     �����������У����������ֵ����������ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] �Ƿ���뻵�㲹���㷨
	/// @param     Threshold [in] ѡȡ����ֵ���ο�KSJ_THRESHOLD˵��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li ����У�����ü���ֵ���ã�����ֵ����˸���Ļ���
	///          \li ������Ӳ��֧�ֻ���У����Ӳ����ʹ�ö�Ӧ����ֵģʽ���л���У����
	///          \li ִ�иú����Ժ��������У����������ֵ����������ֵ������Ϊ�ڲ�Ԥ��ֵ�������Ҫʹ���Զ������ֵ����Ҫ�ڸú���֮�������ã�KSJ_BadPixelCorrectionSetThreshold()��
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSet(int nIndex, bool bEnable, KSJ_THRESHOLD Threshold);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_BadPixelCorrectionGet
	/// @brief     ��ȡ�����ǰ�Ļ��㲹����Ϣ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [in] �����Ƿ���뻵�㲹���㷨
	/// @param     pThreshold [in] ���ص�ǰ���㲹���㷨��ѡȡ����ֵģʽ��ֻ���֧��Ӳ������У�����豸��Ч
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGet(int nIndex, bool *pbEnable, KSJ_THRESHOLD *pThreshold);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ProcessSaturationGetRange
	/// @brief     ��ȡ���Ͷȵ����÷�Χ��-128~128��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnMinSaturation [out] ȡ�ñ��Ͷ����õ���Сֵ
	/// @param     pnMaxSaturation [out] ȡ�ñ��Ͷ����õ����ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessContrastGetRange(int nIndex, int *pnMinContrast, int *pnMaxContrast);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ProcessSaturationGetRange
	/// @brief     ��ȡ���Ͷȵ����÷�Χ��-128~128��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnMinSaturation [out] ȡ�ñ��Ͷ����õ���Сֵ
	/// @param     pnMaxSaturation [out] ȡ�ñ��Ͷ����õ����ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGetRange(int nIndex, int *pnMinSaturation, int *pnMaxSaturation);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ProcessSaturationSet
	/// @brief     ����ͼ��ı��Ͷ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nSaturation [in] ���Ͷ����õ�ֵ
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li ���㷨�����ִ�У����ܻ�Ӱ��ɼ�Ч�ʺ�Ԥ��֡��
	///          \li nSaturation = 0 ��ʾ�������Ͷȵ���
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationSet(int nIndex, int nSaturation);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_ProcessSaturationGet
	/// @brief     ��ȡ������ͶȲ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnStaturation [out] ����������Ͷ�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGet(int nIndex, int *pnStaturation);

	/// ��ɫ����ͨ��ö������
	typedef enum
	{
		KSJ_ALL_HUES,     ///< ����ͨ��������ͨ���ĵ���ֵ��Ҫ���ϸ�ͨ��ֵ
		KSJ_RED_HUES,     ///< ��ɫͨ��
		KSJ_YELLOW_HUES,  ///< ��ɫͨ��
		KSJ_GREEN_HUES,   ///< ��ɫͨ��
		KSJ_CYAN_HUES,    ///< ��ɫͨ��
		KSJ_BLUE_HUES,    ///< ��ɫͨ��
		KSJ_MAGENTA_HUES  ///< ���ɫͨ��
	} KSJHueRange;

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HueSaturationSet
	/// @brief     ���ø�����ɫ������ɫ�ȡ����Ͷȡ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     HueRange [in] Ҫ���õ���ɫ��������
	/// @param     nHue [in] ����ָ����ɫ������ɫ�ȣ�ȡֵ��Χ-180 ~ 180
	/// @param     nSaturation [in] ����ָ����ɫ�ı��Ͷȣ�ȡֵ��Χ-100 ~ 100
	/// @param     nLightness [in] ����ָ����ɫ���������ȣ�ȡֵ��Χ-100 ~ 100
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li ���㷨�����ִ�У����ܻ�Ӱ��RGB��ɫͼ��Ĳɼ�Ч�ʺ�Ԥ��֡��
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSet(int nIndex, KSJHueRange HueRange, int nHue, int nSaturation, int nLightness);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HueSaturationGet
	/// @brief     ��ȡ������ɫ������ɫ�ȡ����Ͷȡ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     HueRange [in] Ҫ���õ���ɫ��������
	/// @param     pnHue [out] ��ȡָ����ɫ������ɫ��
	/// @param     pnSaturation [out] ��ȡָ����ɫ�ı��Ͷ�
	/// @param     pnLightness [out] ��ȡָ����ɫ����������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationGet(int nIndex, KSJHueRange HueRange, int *pnHue, int *pnSaturation, int *pnLightness);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HueSaturationSetEnable
	/// @brief     ʹ�ܻ�ر���ɫ�������ڹ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] ture ������ɫ�������ڣ�false �ر���ɫ��������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSetEnable(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_HueSaturationGetEnable
	/// @brief     ��ȡ��ɫ�������ڹ����Ƿ�ʹ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] ������ɫ�������ڹ����Ƿ�ʹ�ܣ�ture ������ɫ�������ڣ�false �ر���ɫ��������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HueSaturationGetEnable(int nIndex, bool *pbEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SharpenParamSet
	/// @brief     ����ͼ���񻯲���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nKernelSize [in] ����ͼ���񻯼����˲��˴�С
	/// @param     nWeighted [in] ����ͼ���񻯼���Ȩ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li ���㷨�����ִ�У����ܻ�Ӱ��RGB��ɫͼ��Ĳɼ�Ч�ʺ�Ԥ��֡��
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SharpenParamSet(int nIndex, int nKernelSize, int nWeighted);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SharpenParamGet
	/// @brief     ��ȡͼ���񻯲���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnKernelSize [out] ��ȡͼ���񻯼����˲��˴�С
	/// @param     pnWeighted [out] ��ȡͼ���񻯼���Ȩ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SharpenParamGet(int nIndex, int* pnKernelSize, int* pnWeighted);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SharpenSetEnable
	/// @brief     ʹ�ܻ�ر�ͼ���񻯹���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     bEnable [in] ture ����ͼ���񻯹��ܣ�false �ر�ͼ���񻯹���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SharpenSetEnable(int nIndex, bool bEnable);

	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_SharpenGetEnable
	/// @brief     ͼ���񻯹����Ƿ�ʹ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbEnable [out] ����ͼ���񻯹����Ƿ�ʹ�ܣ�ture ����ͼ���񻯹��ܣ�false �ر�ͼ���񻯹���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SharpenGetEnable(int nIndex, bool *pbEnable);

#ifdef __cplusplus
}
#endif

#endif


