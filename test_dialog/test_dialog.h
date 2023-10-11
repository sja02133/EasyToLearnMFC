
// test_dialog.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CtestdialogApp:
// See test_dialog.cpp for the implementation of this class
//

class CtestdialogApp : public CWinApp
{
public:
	CtestdialogApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CtestdialogApp theApp;
