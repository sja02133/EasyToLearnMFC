
// Regions.h : main header file for the Regions application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRegionsApp:
// See Regions.cpp for the implementation of this class
//

class CRegionsApp : public CWinApp
{
public:
	CRegionsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRegionsApp theApp;
