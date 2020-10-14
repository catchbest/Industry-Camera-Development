#ifndef __KSJ_API_CALLBACK_H__
#define __KSJ_API_CALLBACK_H__

// #pragma message("Include KSJApiCallback.h") 

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
    /// @brief     KSJ_PREVIEWCALLBACK
    /// @brief     �ص�����ָ�������
    /// @param     pImageData [out] Ԥ��ͼ�������ָ��
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
    /// @param     pnHeight [out] ����ͼ��ĸ߶ȣ����أ�
    /// @param     pnBitCount [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
	/// @param     lpContext [out] �û������������ָ�룬���ָ������û�����KSJ_PreviewSetCallback����ʱ����lpContext��ָ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	///
	///-----------------------------------------------------------------------------
	typedef void(CALLBACK *KSJ_PREVIEWCALLBACK)(unsigned char *pImageData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_PreviewSetCallback
    /// @brief     ����Ԥ���ص�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pfPreviewCallback [in] �ص�����ָ��
	/// @param     lpContext [out] �û������������ָ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ������á�
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_PreviewSetCallback( int nIndex, KSJ_PREVIEWCALLBACK pfPreviewCallback, void *lpContext );

    ///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_PREVIEWCALLBACKEX
    /// @brief     �ص�����ָ�������
	/// @param     hDC [out] KSJApi�ⴴ�����ڴ�DC��Ԥ��ͼ���Ѿ���Ϊ�豸�޹�λͼ��ѡ���DC���豸����������У��û�����ʹ�ô�DC������GDI�����ڴ�DC���豸����������ϻ�����Ҫ�����ʾ������
    /// @param     pImageData [out] Ԥ��ͼ�������ָ��
	/// @param     pnWidth [out] ����ͼ��Ŀ�ȣ����أ�
    /// @param     pnHeight [out] ����ͼ��ĸ߶ȣ����أ�
    /// @param     pnBitCount [out] ���ص�ǰ�ӳ�ģʽ�����µ�ʵ�ʲɼ�ͼ���λͼ���
	/// @param     lpContext [out] �û������������ָ�룬���ָ������û�����KSJ_PreviewSetCallback����ʱ����lpContext��ָ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	///
	///-----------------------------------------------------------------------------
    typedef void(CALLBACK *KSJ_PREVIEWCALLBACKEX)(HDC  hDC, unsigned char *pImageData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	
	///-----------------------------------------------------------------------------
	///
    /// @brief     KSJ_PreviewSetCallbackEx
    /// @brief     ����Ԥ���ص�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
    /// @param     pfPreviewCallbackEx [in] �ص�����ָ��
	/// @param     lpContext [out] �û������������ָ��
    /// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
    /// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
    KSJ_API  int __stdcall KSJ_PreviewSetCallbackEx( int nIndex, KSJ_PREVIEWCALLBACKEX pfPreviewCallbackEx, void *lpContext );


#ifdef __cplusplus
}
#endif

#endif