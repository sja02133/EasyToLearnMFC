
// ShowCursorPos.h : main header file for the ShowCursorPos application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CShowCursorPosApp:
// See ShowCursorPos.cpp for the implementation of this class
//

class CShowCursorPosApp : public CWinApp
{
public:
	CShowCursorPosApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CShowCursorPosApp theApp;
