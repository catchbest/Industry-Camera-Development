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
    /// @brief     �����������У����������ֵ����������ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     btLow [in] �����������صıȽ���ֵ��Ĭ��20
	/// @param     btHigh [in] �����������صıȽ���ֵ��Ĭ��50
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSetThreshold(int nIndex, unsigned char btLow, unsigned char btHigh);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     ��ȡ�������У������ֵ����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbtLow [out] �����������صıȽ���ֵ
	/// @param     pbtHigh [out] �����������صıȽ���ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGetThreshold(int nIndex, unsigned char *pbtLow, unsigned char *pbtHigh);

    enum KSJ_THRESHOLD ///���㲹���㷨��ֵģʽѡ��
    { 
	    KSJ_THRESHOLD_LOW, ///����ֵģʽ��Ĭ�����ڵ���ֵΪ0x30�� �����ڵ���ֵΪ0x18
	    KSJ_THRESHOLD_HIGH ///����ֵ��Ĭ�����ڵ���ֵΪ0x18�� �����ڵ���ֵΪ0x0c������ֵ��ȸ���ֵ�Ի��������
    };
    
	///-----------------------------------------------------------------------------
	///
    /// @brief     �����������У����������ֵ����������ֵ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] �Ƿ���뻵�㲹���㷨
	/// @param     Threshold [in] ѡȡ����ֵ���ο�KSJ_THRESHOLD˵��
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionSet(int nIndex, bool bEnable, KSJ_THRESHOLD Threshold);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     ��ȡ�����ǰ�Ļ��㲹����Ϣ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [in] �����Ƿ���뻵�㲹���㷨
	/// @param     pThreshold [in] ���ص�ǰ���㲹���㷨��ѡȡ����ֵ��ֻ���֧��Ӳ������У�����豸��Ч
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_BadPixelCorrectionGet(int nIndex, bool *pbEnable, KSJ_THRESHOLD *pThreshold);

    ///-----------------------------------------------------------------------------
	///
    /// @brief     ��ȡ�Աȶȵ����÷�Χ��-128~128��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnMinContrast [out] ���ضԱȶ����õ���Сֵ
	/// @param     pnMaxContrast [out] ���ضԱȶ����õ����ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessContrastGetRange(int nIndex, int *pnMinContrast, int *pnMaxContrast);

	///-----------------------------------------------------------------------------
	///
    /// @brief     ��ȡ���Ͷȵ����÷�Χ��-128~128��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnMinSaturation [out] ȡ�ñ��Ͷ����õ���Сֵ
	/// @param     pnMaxSaturation [out] ȡ�ñ��Ͷ����õ����ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGetRange(int nIndex, int *pnMinSaturation, int *pnMaxSaturation);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     ����ͼ��ı��Ͷ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     nSaturation [in] ���Ͷ����õ�ֵ
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationSet(int nIndex, int nSaturation);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     ��ȡ������ͶȲ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pnStaturation [out] ����������Ͷ�
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_ProcessSaturationGet(int nIndex, int *pnStaturation);

    typedef enum//��ɫ����ö������
    {
	    KSJ_ALL_HUES,	///������ɫ
	    KSJ_RED_HUES,	///�����
	    KSJ_YELLOW_HUES,//�Ʒ���
	    KSJ_GREEN_HUES, ///�̷���
	    KSJ_CYAN_HUES,	///��ɫ����
	    KSJ_BLUE_HUES,	///������
	    KSJ_MAGENTA_HUES//Ʒ�����
    } KSJHueRange;

    ///-----------------------------------------------------------------------------
	///
    /// @brief     ���ø�����ɫ������ɫ�ȡ����Ͷȡ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     HueRange [in] Ҫ���õ���ɫ��������
	/// @param     nHue [in] ����ָ����ɫ������ɫ�ȣ�ȡֵ��Χ-180 ~ 180
	/// @param     nSaturation [in] ����ָ����ɫ�ı��Ͷȣ�ȡֵ��Χ-100 ~ 100
	/// @param     nLightness [in] ����ָ����ɫ���������ȣ�ȡֵ��Χ-100 ~ 100
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSet(int nIndex, KSJHueRange HueRange, int nHue, int nSaturation, int nLightness);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     ��ȡ������ɫ������ɫ�ȡ����Ͷȡ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     HueRange [in] Ҫ���õ���ɫ��������
	/// @param     pnHue [out] ��ȡָ����ɫ������ɫ��
	/// @param     pnSaturation [out] ��ȡָ����ɫ�ı��Ͷ�
	/// @param     pnLightness [out] ��ȡָ����ɫ����������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationGet(int nIndex, KSJHueRange HueRange, int *pnHue, int *pnSaturation, int *pnLightness);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     ʹ�ܻ�ر���ɫ�������ڹ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     bEnable [in] ture ������ɫ�������ڣ�false �ر���ɫ��������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_HueSaturationSetEnable(int nIndex, bool bEnable);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     ��ȡ��ɫ�������ڹ����Ƿ�ʹ��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pbEnable [out] ������ɫ�������ڹ����Ƿ�ʹ�ܣ�ture ������ɫ�������ڣ�false �ر���ɫ��������
    /// @return    �ο�����״̬�루KSJCode.H��
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HueSaturationGetEnable(int nIndex, bool *pbEnable);

#ifdef __cplusplus
}
#endif

#endif


