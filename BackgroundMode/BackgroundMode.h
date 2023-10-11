
// BackgroundMode.h : main header file for the BackgroundMode application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CBackgroundModeApp:
// See BackgroundMode.cpp for the implementation of this class
//

class CBackgroundModeApp : public CWinApp
{
public:
	CBackgroundModeApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBackgroundModeApp theApp;
