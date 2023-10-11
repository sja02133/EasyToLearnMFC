
// DisableCloseButton.h : main header file for the DisableCloseButton application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDisableCloseButtonApp:
// See DisableCloseButton.cpp for the implementation of this class
//

class CDisableCloseButtonApp : public CWinApp
{
public:
	CDisableCloseButtonApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDisableCloseButtonApp theApp;
