
// test_sdi.h : main header file for the test_sdi application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CtestsdiApp:
// See test_sdi.cpp for the implementation of this class
//

class CtestsdiApp : public CWinApp
{
public:
	CtestsdiApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CtestsdiApp theApp;
