
// ListCtrlTest1.h : main header file for the ListCtrlTest1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CListCtrlTest1App:
// See ListCtrlTest1.cpp for the implementation of this class
//

class CListCtrlTest1App : public CWinApp
{
public:
	CListCtrlTest1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CListCtrlTest1App theApp;
