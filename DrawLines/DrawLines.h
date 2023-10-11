
// DrawLines.h : main header file for the DrawLines application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawLinesApp:
// See DrawLines.cpp for the implementation of this class
//

class CDrawLinesApp : public CWinApp
{
public:
	CDrawLinesApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawLinesApp theApp;
