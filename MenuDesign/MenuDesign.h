
// MenuDesign.h : main header file for the MenuDesign application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMenuDesignApp:
// See MenuDesign.cpp for the implementation of this class
//

class CMenuDesignApp : public CWinApp
{
public:
	CMenuDesignApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMenuDesignApp theApp;
