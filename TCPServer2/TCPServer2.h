
// TCPServer2.h : main header file for the TCPServer2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTCPServer2App:
// See TCPServer2.cpp for the implementation of this class
//

class CTCPServer2App : public CWinApp
{
public:
	CTCPServer2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTCPServer2App theApp;
