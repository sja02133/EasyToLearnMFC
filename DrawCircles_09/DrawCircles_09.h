
// DrawCircles_09.h : main header file for the DrawCircles_09 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawCircles09App:
// See DrawCircles_09.cpp for the implementation of this class
//

class CDrawCircles09App : public CWinApp
{
public:
	CDrawCircles09App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawCircles09App theApp;
