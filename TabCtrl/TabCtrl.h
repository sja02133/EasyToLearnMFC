
// TabCtrl.h : main header file for the TabCtrl application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTabCtrlApp:
// See TabCtrl.cpp for the implementation of this class
//

class CTabCtrlApp : public CWinApp
{
public:
	CTabCtrlApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTabCtrlApp theApp;
