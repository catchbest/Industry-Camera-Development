#ifndef  __KSJ_GLOBAL_STRING_H__
#define  __KSJ_GLOBAL_STRING_H__

#ifdef KSJAPI_EXPORTS
#include <Windows.h>
#include <tchar.h>
#else
#include <SDKDDKVer.h>
#include <afxwin.h>         // MFC core and standard components
#endif


extern const TCHAR  *g_szDeviceType[];
extern const int     g_nDeviceType;

extern const TCHAR  *g_szParam[];
extern const int     g_nParam;

extern const TCHAR  *g_szRomType[];
extern const int     g_nRomType;

extern const TCHAR  *g_szBayerMode[];
extern const int     g_nBayerMode;

extern const TCHAR  *g_szFovSkipItems[];
extern const int     g_nFovSkipItems;

extern const TCHAR  *g_szTriggerMode[];
extern const int     g_nTriggerMode;

extern const TCHAR  *g_szTriggerMethod[];
extern const int     g_nTriggerMethod;

extern const TCHAR  *g_szSensitivity[];
extern const int     g_nSensitivity;

extern const TCHAR  *g_szBadPixelThreshold[];
extern const int     g_nBadPixelThreshold;

extern const TCHAR  *g_szCCMPresettings[];
extern const int     g_nCCMPresettings;

extern const TCHAR  *g_szWBMode[];
extern const int     g_nWBMode;

extern const TCHAR  *g_szHWBMode[];
extern const int     g_nHWBMode;

extern const TCHAR  *g_szCCMMode[];
extern const int     g_nCCMMode;

extern const TCHAR  *g_szHCCMMode[];
extern const int     g_nHCCMMode;

extern const TCHAR  *g_szFlashMode[];
extern const int     g_nFlashMode;

extern const TCHAR  *g_szSensorMode[];
extern const int     g_nSensorMode;

extern const TCHAR  *g_szWaterMarkMode[];
extern const int     g_nWaterMarkMode;

extern const TCHAR   *g_szFunction[];
extern const int     g_nFunction;

extern const TCHAR   *g_szFunctionDesc[];

extern const TCHAR   *g_szGpioDirection[];
extern const int     g_nGpioDirection;
extern const TCHAR   *g_szGpioStatus[];
extern const int     g_nGpioStatus;

extern const TCHAR   *g_szAEStatus[];

extern const TCHAR  *g_szBayerFilter[];
extern const int     g_nBayerFilter;


extern const TCHAR  *g_szBayerMode1[];
extern const int     g_nBayerMode1;

extern const TCHAR  *g_szMapMode[];
extern const int     g_nMapMode;

#endif