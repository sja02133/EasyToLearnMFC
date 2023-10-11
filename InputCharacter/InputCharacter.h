
// InputCharacter.h : main header file for the InputCharacter application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CInputCharacterApp:
// See InputCharacter.cpp for the implementation of this class
//

class CInputCharacterApp : public CWinApp
{
public:
	CInputCharacterApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CInputCharacterApp theApp;
