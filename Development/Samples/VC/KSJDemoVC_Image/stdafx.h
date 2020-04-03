
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions


#include <afxdisp.h>        // MFC Automation classes



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC support for ribbons and control bars

#include "OEM.H"
#include "../Common/KSJ_GS.H"

// 这个是需要包含的头文件设置，路径是相对于工程的相对路径
#include "../../../KSJApi.Inc/KSJApi.h"

// 这是需要链接的库文件设置，路径是相对于工程的相对路径
#ifdef _UNICODE

#ifdef _WIN64
#pragma comment( lib, "../../../KSJApi.Lib/x64/KSJApi64u.lib" )
#else
#pragma comment( lib, "../../../KSJApi.Lib/x86/KSJApiu.lib" )
#endif

#else

#ifdef _WIN64
#pragma comment( lib, "../../../KSJApi.Lib/x64/KSJApi64.lib" )
#else
#pragma comment( lib, "../../../KSJApi.Lib/x86/KSJApi.lib" )
#endif

#endif

typedef unsigned (WINAPI *PBEGINTHREADEX_FUNC)(LPVOID lpParam);
typedef unsigned *PBEGINTHREADEX_ID;


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


