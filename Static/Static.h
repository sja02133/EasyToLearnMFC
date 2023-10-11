
// Static.h : main header file for the Static application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CStaticApp:
// See Static.cpp for the implementation of this class
//

class CStaticApp : public CWinApp
{
public:
	CStaticApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStaticApp theApp;
