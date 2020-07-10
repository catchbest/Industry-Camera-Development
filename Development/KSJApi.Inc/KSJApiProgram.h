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
	// 参考“凯视佳工业相机内部API函数说明书（初始化厂商读写区域篇）”
	// Program and Modify Serials
	KSJ_API  int __stdcall KSJ_SetSerials(int nIndex, unsigned char btSerials);
	KSJ_API  int __stdcall KSJ_GetSerials(int nIndex, unsigned char *pbtSerials);

	KSJ_API  int __stdcall KSJ_WorkingModeProgram(int nIndex, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_WorkingModeReadout(int nIndex, unsigned short *pValue);

	KSJ_API  int __stdcall KSJ_WorkingModeExProgram(int nIndex, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_WorkingModeExReadout(int nIndex, unsigned short *pValue);

	KSJ_API  int __stdcall KSJ_ColorModeProgram(int nIndex, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_ColorModeReadout(int nIndex, unsigned short *pValue);

	KSJ_API  int __stdcall KSJ_SerialsDescProgram(int nIndex, unsigned char btDesc[16]);
	KSJ_API  int __stdcall KSJ_SerialsDescReadout(int nIndex, unsigned char btDesc[16]);

	KSJ_API  int __stdcall KSJ_LutInfoProgram(int nIndex, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_LutInfoReadout(int nIndex, unsigned short *pValue);

	KSJ_API  int __stdcall KSJ_GammaLutInfoProgram(int nIndex, unsigned short wValue);
	KSJ_API  int __stdcall KSJ_GammaLutInfoReadout(int nIndex, unsigned short *pValue);

	KSJ_API  int __stdcall KSJ_HWBMatrixProgram(int nIndex, float fMatrix[3]);
	KSJ_API  int __stdcall KSJ_HWBMatrixReadout(int nIndex, float fMatrix[3]);
	KSJ_API  int __stdcall KSJ_HWBMatrixUpload(int nIndex, float fMatrix[3]);

	KSJ_API  int __stdcall KSJ_HCCMMatrixProgram(int nIndex, float fMatrix[3][3]);
	KSJ_API  int __stdcall KSJ_HCCMMatrixReadout(int nIndex, float fMatrix[3][3]);
	KSJ_API  int __stdcall KSJ_HCCMMatrixUpload(int nIndex, float fMatrix[3][3]);

	KSJ_API  int __stdcall KSJ_LutFileProgram(int nIndex, TCHAR *pszFile);
	KSJ_API  int __stdcall KSJ_LutDataProgram(int nIndex, unsigned char *pData, int nBytes);
	KSJ_API  int __stdcall KSJ_LutDataReadout(int nIndex, unsigned char *pData, int *pnBytes);

	KSJ_API  int __stdcall KSJ_GammaLutFileProgram(int nIndex, TCHAR *pszFile);
	KSJ_API  int __stdcall KSJ_GammaLutDataProgram(int nIndex, unsigned short *pData, int nWords);
	KSJ_API  int __stdcall KSJ_GammaLutDataReadout(int nIndex, unsigned short *pData, int *pnWords);

	KSJ_API  int __stdcall KSJ_CalibrationProgram(int nIndex, float fCoefficient[14]);
	KSJ_API  int __stdcall KSJ_CalibrationReadout(int nIndex, float fCoefficient[14]);

	KSJ_API  int __stdcall KSJ_ParamProgram(int nIndex);          // 将目前的主要参数保存至相机，再次重启KSJApi库时会自动加载并设置
	KSJ_API  int __stdcall KSJ_LoadParamFromCamera(int nIndex);   // 将目前保存至相机的主要参数加载并设置
	KSJ_API  int __stdcall KSJ_ParamErase(int nIndex);            // 清除目前保存至相机的主要参数（预览视场、采集视场、曝光、增益）

	KSJ_API  int __stdcall KSJ_SaveParamToFile(int nIndex, TCHAR *pszFile);
	KSJ_API  int __stdcall KSJ_LoadParamFromFile(int nIndex, TCHAR *pszFile);

#ifdef __cplusplus
}
#endif

#endif