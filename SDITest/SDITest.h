
// SDITest.h : main header file for the SDITest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSDITestApp:
// See SDITest.cpp for the implementation of this class
//

class CSDITestApp : public CWinApp
{
public:
	CSDITestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDITestApp theApp;
