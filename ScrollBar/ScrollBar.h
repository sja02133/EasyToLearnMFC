
// ScrollBar.h : main header file for the ScrollBar application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CScrollBarApp:
// See ScrollBar.cpp for the implementation of this class
//

class CScrollBarApp : public CWinApp
{
public:
	CScrollBarApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CScrollBarApp theApp;
