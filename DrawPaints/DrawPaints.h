
// DrawPaints.h : main header file for the DrawPaints application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawPaintsApp:
// See DrawPaints.cpp for the implementation of this class
//

class CDrawPaintsApp : public CWinApp
{
public:
	CDrawPaintsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawPaintsApp theApp;
