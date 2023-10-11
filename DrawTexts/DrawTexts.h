
// DrawTexts.h : main header file for the DrawTexts application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawTextsApp:
// See DrawTexts.cpp for the implementation of this class
//

class CDrawTextsApp : public CWinApp
{
public:
	CDrawTextsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawTextsApp theApp;
