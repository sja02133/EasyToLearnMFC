
// Subclass.h : main header file for the Subclass application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSubclassApp:
// See Subclass.cpp for the implementation of this class
//

class CSubclassApp : public CWinApp
{
public:
	CSubclassApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSubclassApp theApp;
