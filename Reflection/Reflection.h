
// Reflection.h : main header file for the Reflection application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CReflectionApp:
// See Reflection.cpp for the implementation of this class
//

class CReflectionApp : public CWinApp
{
public:
	CReflectionApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CReflectionApp theApp;
