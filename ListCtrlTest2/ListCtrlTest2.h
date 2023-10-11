
// ListCtrlTest2.h : main header file for the ListCtrlTest2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CListCtrlTest2App:
// See ListCtrlTest2.cpp for the implementation of this class
//

class CListCtrlTest2App : public CWinApp
{
public:
	CListCtrlTest2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CListCtrlTest2App theApp;
