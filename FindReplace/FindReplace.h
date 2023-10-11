
// FindReplace.h : main header file for the FindReplace application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFindReplaceApp:
// See FindReplace.cpp for the implementation of this class
//

class CFindReplaceApp : public CWinApp
{
public:
	CFindReplaceApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFindReplaceApp theApp;
