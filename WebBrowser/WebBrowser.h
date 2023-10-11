
// WebBrowser.h : main header file for the WebBrowser application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CWebBrowserApp:
// See WebBrowser.cpp for the implementation of this class
//

class CWebBrowserApp : public CWinApp
{
public:
	CWebBrowserApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWebBrowserApp theApp;
