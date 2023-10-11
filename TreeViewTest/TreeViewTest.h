
// TreeViewTest.h : main header file for the TreeViewTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTreeViewTestApp:
// See TreeViewTest.cpp for the implementation of this class
//

class CTreeViewTestApp : public CWinApp
{
public:
	CTreeViewTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTreeViewTestApp theApp;
