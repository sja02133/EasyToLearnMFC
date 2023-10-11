
// ModalDialog2.h : main header file for the ModalDialog2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CModalDialog2App:
// See ModalDialog2.cpp for the implementation of this class
//

class CModalDialog2App : public CWinApp
{
public:
	CModalDialog2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CModalDialog2App theApp;
