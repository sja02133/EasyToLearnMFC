
// HtmlViewTest.h : main header file for the HtmlViewTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CHtmlViewTestApp:
// See HtmlViewTest.cpp for the implementation of this class
//

class CHtmlViewTestApp : public CWinApp
{
public:
	CHtmlViewTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHtmlViewTestApp theApp;
