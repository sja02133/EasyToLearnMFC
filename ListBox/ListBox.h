
// ListBox.h : main header file for the ListBox application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CListBoxApp:
// See ListBox.cpp for the implementation of this class
//

class CListBoxApp : public CWinApp
{
public:
	CListBoxApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CListBoxApp theApp;
