
// Splitter.h : main header file for the Splitter application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSplitterApp:
// See Splitter.cpp for the implementation of this class
//

class CSplitterApp : public CWinApp
{
public:
	CSplitterApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSplitterApp theApp;
