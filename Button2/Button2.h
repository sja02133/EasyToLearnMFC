
// Button2.h : main header file for the Button2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CButton2App:
// See Button2.cpp for the implementation of this class
//

class CButton2App : public CWinApp
{
public:
	CButton2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CButton2App theApp;
