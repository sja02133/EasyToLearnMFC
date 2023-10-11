
// Progress.h : main header file for the Progress application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CProgressApp:
// See Progress.cpp for the implementation of this class
//

class CProgressApp : public CWinApp
{
public:
	CProgressApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProgressApp theApp;
