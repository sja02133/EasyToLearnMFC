
// Pens.h : main header file for the Pens application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPensApp:
// See Pens.cpp for the implementation of this class
//

class CPensApp : public CWinApp
{
public:
	CPensApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPensApp theApp;
