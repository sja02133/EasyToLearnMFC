
// Bitmaps.h : main header file for the Bitmaps application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CBitmapsApp:
// See Bitmaps.cpp for the implementation of this class
//

class CBitmapsApp : public CWinApp
{
public:
	CBitmapsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBitmapsApp theApp;
