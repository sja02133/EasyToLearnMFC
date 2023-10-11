
// InputSaveLoad.h : main header file for the InputSaveLoad application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CInputSaveLoadApp:
// See InputSaveLoad.cpp for the implementation of this class
//

class CInputSaveLoadApp : public CWinApp
{
public:
	CInputSaveLoadApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CInputSaveLoadApp theApp;
