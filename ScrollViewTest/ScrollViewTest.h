
// ScrollViewTest.h : main header file for the ScrollViewTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CScrollViewTestApp:
// See ScrollViewTest.cpp for the implementation of this class
//

class CScrollViewTestApp : public CWinApp
{
public:
	CScrollViewTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CScrollViewTestApp theApp;
