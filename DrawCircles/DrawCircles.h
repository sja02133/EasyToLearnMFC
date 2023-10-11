
// DrawCircles.h : main header file for the DrawCircles application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawCirclesApp:
// See DrawCircles.cpp for the implementation of this class
//

class CDrawCirclesApp : public CWinApp
{
public:
	CDrawCirclesApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawCirclesApp theApp;
