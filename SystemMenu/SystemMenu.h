
// SystemMenu.h : main header file for the SystemMenu application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSystemMenuApp:
// See SystemMenu.cpp for the implementation of this class
//

class CSystemMenuApp : public CWinApp
{
public:
	CSystemMenuApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSystemMenuApp theApp;
