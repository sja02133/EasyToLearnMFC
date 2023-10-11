
// PaintDC.h : main header file for the PaintDC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPaintDCApp:
// See PaintDC.cpp for the implementation of this class
//

class CPaintDCApp : public CWinApp
{
public:
	CPaintDCApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPaintDCApp theApp;
