
// Simple2.h : main header file for the Simple2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSimple2App:
// See Simple2.cpp for the implementation of this class
//

class CSimple2App : public CWinApp
{
public:
	CSimple2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSimple2App theApp;
