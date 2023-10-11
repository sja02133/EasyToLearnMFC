
// EditCtrl.h : main header file for the EditCtrl application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CEditCtrlApp:
// See EditCtrl.cpp for the implementation of this class
//

class CEditCtrlApp : public CWinApp
{
public:
	CEditCtrlApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEditCtrlApp theApp;
