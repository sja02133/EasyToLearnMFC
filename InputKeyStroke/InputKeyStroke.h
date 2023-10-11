
// InputKeyStroke.h : main header file for the InputKeyStroke application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CInputKeyStrokeApp:
// See InputKeyStroke.cpp for the implementation of this class
//

class CInputKeyStrokeApp : public CWinApp
{
public:
	CInputKeyStrokeApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CInputKeyStrokeApp theApp;
