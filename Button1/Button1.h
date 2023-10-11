
// Button1.h : main header file for the Button1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CButton1App:
// See Button1.cpp for the implementation of this class
//

class CButton1App : public CWinApp
{
public:
	CButton1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CButton1App theApp;
