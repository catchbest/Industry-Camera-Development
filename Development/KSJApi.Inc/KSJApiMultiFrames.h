#ifndef __KSJ_API_MULTI_FRAMES_H__
#define __KSJ_API_MULTI_FRAMES_H__

// #pragma message("Include KSJApiMultiFrames.h") 

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
	/// @brief     KSJ_CaptureSetFieldOfViewEx
	/// @brief     ���ö�֡ƴ��ʱ��Ԥ���ӳ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nColStart [in] �ɼ�ʱƴ�ӵĵ���֡��Ч�������������Ĭ�������������ˮƽ������ʼλ��
	/// @param     nRowStart [in] �ɼ�ʱƴ�ӵĵ���֡��Ч����������������Ĭ�ϳ�������Ĵ�ֱ����ʼλ��
	/// @param     nColSize [in] �ɼ�ʱƴ�ӵĵ���֡��Ч���������ˮƽ������
	/// @param     nRowSize [in] �ɼ�ʱƴ�ӵĵ���֡��Ч��������Ĵ�ֱ����
	/// @param     AmCol [in] �ɼ�ʱƴ�ӵĵ���֡�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     AmRow [in] �ɼ�ʱ��ƴ�ӵĵ���֡����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     wMultiFrameNum [in] ���õ��βɼ���ƴ��֡��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li ���ö�֡wMultiFrameNum>1ʱ���ڴ��������������ɼ�һ��ͼ��ͻ᷵��wMultiFrameNum֡ͼ����ɵ�ƴ֡���ݣ�������ⴥ�����߹̶�֡�ʣ���Ҫ��wMultiFrameNum�������ź�֮�󣬲ɼ������ŷ���һ��ƴ֡��
	///          \li ��֡��������������������ʱ���Զ�ƴ��wMultiFrameNum��ͼ���һ������ͼ��
	///          \li ������ò�����Ч������wMultiFrameNum̫��������֡���治����API�Զ���ʹ����ӽ��Ĳ���������������ã��������óɹ��Ժ���Ҫͨ��KSJ_CaptureGetFieldOfViewEx��ȡʵ����Ч�Ĳ�����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewSetFieldOfViewEx(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetFieldOfViewEx
	/// @brief     ��ȡԤ���Ķ�֡ƴ����Ϣ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [out] ������ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnRowStart [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnColSize [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч����ˮƽ������
	/// @param     pnRowSize [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч����ֱ����
	/// @param     pColAddressMode [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pRowAddressMode [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pwMultiFrameNum [out] ���زɼ���ƴ��֡��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_PreviewGetFieldOfViewEx(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureSetFieldOfViewEx
	/// @brief     ���ö�֡ƴ��ʱ�Ĳɼ��ӳ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     nColStart [in] �ɼ�ʱƴ�ӵĵ���֡��Ч�������������Ĭ�������������ˮƽ������ʼλ��
	/// @param     nRowStart [in] �ɼ�ʱƴ�ӵĵ���֡��Ч����������������Ĭ�ϳ�������Ĵ�ֱ����ʼλ��
	/// @param     nColSize [in] �ɼ�ʱƴ�ӵĵ���֡��Ч���������ˮƽ������
	/// @param     nRowSize [in] �ɼ�ʱƴ�ӵĵ���֡��Ч��������Ĵ�ֱ����
	/// @param     AmCol [in] �ɼ�ʱƴ�ӵĵ���֡�����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     AmRow [in] �ɼ�ʱ��ƴ�ӵĵ���֡����Ч���������г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     wMultiFrameNum [in] ���õ��βɼ���ƴ��֡��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///          \li ���ö�֡wMultiFrameNum>1ʱ���ڴ��������������ɼ�һ��ͼ��ͻ᷵��wMultiFrameNum֡ͼ����ɵ�ƴ֡���ݣ�������ⴥ�����߹̶�֡�ʣ���Ҫ��wMultiFrameNum�������ź�֮�󣬲ɼ������ŷ���һ��ƴ֡��
	///          \li ��֡��������������������ʱ���Զ�ƴ��wMultiFrameNum��ͼ���һ������ͼ��
	///          \li ������ò�����Ч������wMultiFrameNum̫��������֡���治����API�Զ���ʹ����ӽ��Ĳ���������������ã��������óɹ��Ժ���Ҫͨ��KSJ_CaptureGetFieldOfViewEx��ȡʵ����Ч�Ĳ�����
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureSetFieldOfViewEx(int nIndex, int nColStart, int nRowStart, int nColSize, int nRowSize, KSJ_ADDRESSMODE AmCol, KSJ_ADDRESSMODE AmRow, unsigned short wMultiFrameNum);
	
	///-----------------------------------------------------------------------------
	///
	/// @brief     KSJ_CaptureGetFieldOfViewEx
	/// @brief     ��ȡ�ɼ��Ķ�֡ƴ����Ϣ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pnColStart [out] ������ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnRowStart [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч������ʼ��λ��
	/// @param     pnColSize [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч����ˮƽ������
	/// @param     pnRowSize [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч����ֱ����
	/// @param     pColAddressMode [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pRowAddressMode [out] ����ƴ�ӵĵ���֡ͼ��й�оƬ�ɼ�ʱ����й����Ч�����г��ģʽ����ο�KSJ_ADDRESSMODE�Ķ��壩
	/// @param     pwMultiFrameNum [out] ���زɼ���ƴ��֡��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJApiRetCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_CaptureGetFieldOfViewEx(int nIndex, int *pnColStart, int *pnRowStart, int *pnColSize, int *pnRowSize, KSJ_ADDRESSMODE *pColAddressMode, KSJ_ADDRESSMODE *pRowAddressMode, unsigned short *pwMultiFrameNum);


#ifdef __cplusplus
}
#endif

#endif