
// UIThread.h : main header file for the UIThread application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CUIThreadApp:
// See UIThread.cpp for the implementation of this class
//

class CUIThreadApp : public CWinApp
{
public:
	CUIThreadApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUIThreadApp theApp;
