#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


class CKSJDemoVCApp : public CWinApp
{
public:
	CKSJDemoVCApp();

public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CKSJDemoVCApp theApp;

// 更改1
// 更改2
// 更改3
// 更改4
