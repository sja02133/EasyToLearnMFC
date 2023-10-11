
// OptimizeScroll.h : main header file for the OptimizeScroll application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// COptimizeScrollApp:
// See OptimizeScroll.cpp for the implementation of this class
//

class COptimizeScrollApp : public CWinApp
{
public:
	COptimizeScrollApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COptimizeScrollApp theApp;
