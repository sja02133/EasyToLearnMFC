
// ListViewTest.h : main header file for the ListViewTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CListViewTestApp:
// See ListViewTest.cpp for the implementation of this class
//

class CListViewTestApp : public CWinApp
{
public:
	CListViewTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CListViewTestApp theApp;
