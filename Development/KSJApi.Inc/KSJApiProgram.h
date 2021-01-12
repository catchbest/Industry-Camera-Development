#ifndef __KSJ_API_PROGRAM_H__
#define __KSJ_API_PROGRAM_H__

// #pragma message("Include KSJApiProgram.h") 

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
	/// �ο������Ӽѹ�ҵ����ڲ�API����˵���飨��ʼ�����̶�д����ƪ����
	/// 
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SetSerials
	/// @brief     ����������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     btSerials [in] ��������õ���ǰ���
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	/// @attention ��ż�KSJ_DeviceGetInformation/KSJ_DeviceGetInformationEx����ȡ��pnSerials
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SetSerials(int nIndex, unsigned char btSerials);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_GetSerials
	/// @brief     ��ȡ������
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pbtSerials [out] ����������
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	/// @attention ��ż�KSJ_DeviceGetInformation/KSJ_DeviceGetInformationEx����ȡ��pnSerials
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_GetSerials(int nIndex, unsigned char *pbtSerials);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SerialsDescReadout
	/// @brief     ��ȡ���Ψһ���к�SN
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     btDesc [out] �������Ψһ���к�SN
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	/// @attention Ψһ���к�SN��Ϊ�����Ψһ�ţ���Ӳ��������SNһ�£�Ϊ8�����ַ�����
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SerialsDescReadout(int nIndex, unsigned char btDesc[16]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HardwareVersionReadout
	/// @brief     ��ȡ�����Ӳ���汾��
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     btDesc [out] ���������Ӳ���汾��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HardwareVersionReadout(int nIndex, unsigned char btVersion[16]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutInfoProgram
	/// @brief     ����LUT��Ϣ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     wValue [in] LUT��Ϣ����LUT���С��LUT bytes size����Ӧ��Ϊ2^10��2^12����2^14
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutInfoProgram(int nIndex, unsigned short wValue);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutInfoReadout
	/// @brief     ��ȡLUT��Ϣ
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pValue [out] ����LUT��Ϣ����LUT���С��LUT bytes size����Ӧ��Ϊ2^10��2^12����2^14
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutInfoReadout(int nIndex, unsigned short *pValue);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HWBMatrixProgram
	/// @brief     ����Ӳ����ƽ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fMatrix [in] Ӳ����ƽ�����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HWBMatrixProgram(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HWBMatrixReadout
	/// @brief     ��ȡӲ����ƽ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fMatrix [out] ��ǰӲ�������Ĭ�ϰ�ƽ�����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HWBMatrixReadout(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HWBMatrixUpload
	/// @brief     ��ȡ��ǰӲ��ִ�а�ƽ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fMatrix [out] ��ǰӲ������ͼ��ʹ�õİ�ƽ�����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	/// @attention ��KSJ_HWBMatrixReadout���������ǻ�ȡĬ�ϵİ�ƽ��������ú����ǵ�ǰ�İ�ƽ���������Ӳ��������ƽ��ʱ�������ƽ������Ǳ仯��
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HWBMatrixUpload(int nIndex, float fMatrix[3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HCCMMatrixProgram
	/// @brief     ����Ӳ��CCM����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fMatrix [in] Ӳ��CCM����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HCCMMatrixProgram(int nIndex, float fMatrix[3][3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HCCMMatrixReadout
	/// @brief     ��ȡӲ��CCM����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fMatrix [out] ��ǰӲ�������Ĭ��CCM����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_HCCMMatrixReadout(int nIndex, float fMatrix[3][3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_HCCMMatrixUpload
	/// @brief     ��ȡ��ǰӲ��ִ��CCM����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     fMatrix [out] ��ǰӲ������ͼ��ʹ�õ�CCM����
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	/// @attention ��KSJ_HCCMMatrixReadout���������ǻ�ȡĬ�ϵ�CCM�������ú����ǵ�ǰ��CCM��������Ӳ������CCMʱ�����CCM�����Ǳ仯��
	KSJ_API  int __stdcall KSJ_HCCMMatrixUpload(int nIndex, float fMatrix[3][3]);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutFileProgram
	/// @brief     ��LUT���ݴ��ļ����ص�Ӳ����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pszFile [in] LUT�ļ�·��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutFileProgram(int nIndex, TCHAR *pszFile);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutDataProgram
	/// @brief     ��LUT�������ص�Ӳ����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pData [in] LUT����
	/// @param     nBytes [in] LUT���ݴ�С����λ���ֽ�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutDataProgram(int nIndex, unsigned char *pData, int nBytes);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LutDataReadout
	/// @brief     ��ȡ���LUT����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pData [out] LUT�����ڴ��ַ����Ҫ��ǰ����
	/// @param     nBytes [out] ����LUT���ݴ�С����λ���ֽ�
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LutDataReadout(int nIndex, unsigned char *pData, int *pnBytes);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_ParamProgram
	/// @brief     ����ǰ��������ò������浽�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	/// @attention ��������Ժ�����ϵ������ӣ���������󣬻��Զ�������Щ������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ParamProgram(int nIndex);          /// ��Ŀǰ����Ҫ����������������ٴ�����KSJApi��ʱ���Զ����ز�����

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LoadParamFromCamera
	/// @brief     ����ǰ��������ò����ָ�������������е�״̬
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	/// @attention �ڵ�����������У������Ҫ���ص���������״̬������ִ�иú���
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadParamFromCamera(int nIndex);   /// ��Ŀǰ�������������Ҫ�������ز�����

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_ParamErase
	/// @brief	   ��������������ڵĲ���
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	/// @attention ����ִ�иú�������������ϵ罫��ָ�����������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_ParamErase(int nIndex);            /// ���Ŀǰ�������������Ҫ������Ԥ���ӳ����ɼ��ӳ����ع⡢���棩

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_SaveParamToFile
	/// @brief     ����ǰ��������ò������浽һ���ļ�
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pszFile [in] ����������ļ�·��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_SaveParamToFile(int nIndex, TCHAR *pszFile);

	///-----------------------------------------------------------------------------
	/// @brief     KSJ_LoadParamFromFile
	/// @brief     ��һ�������ļ����õ���ǰ�����
	/// @param     nIndex [in] �豸��������0��ʼ�����������Ϊ:���ӵ��������豸��Ŀ��һ��
	/// @param     pszFile [in] ����������ļ�·��
	/// @return    �ɹ����� RET_SUCCESS(0)�����򷵻ط�0ֵ�Ĵ�����, ��ο� KSJCode.h �д�����Ķ��塣
	/// @attention ����KSJ_Init������ʼ�������
	///-----------------------------------------------------------------------------
	KSJ_API  int __stdcall KSJ_LoadParamFromFile(int nIndex, TCHAR *pszFile);

#ifdef __cplusplus
}
#endif

#endif