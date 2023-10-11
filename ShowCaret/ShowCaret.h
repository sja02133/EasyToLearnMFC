
// ShowCaret.h : main header file for the ShowCaret application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CShowCaretApp:
// See ShowCaret.cpp for the implementation of this class
//

class CShowCaretApp : public CWinApp
{
public:
	CShowCaretApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CShowCaretApp theApp;
