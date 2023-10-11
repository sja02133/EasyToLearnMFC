
// SpinButton.h : main header file for the SpinButton application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSpinButtonApp:
// See SpinButton.cpp for the implementation of this class
//

class CSpinButtonApp : public CWinApp
{
public:
	CSpinButtonApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSpinButtonApp theApp;
