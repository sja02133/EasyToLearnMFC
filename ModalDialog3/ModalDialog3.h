
// ModalDialog3.h : main header file for the ModalDialog3 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CModalDialog3App:
// See ModalDialog3.cpp for the implementation of this class
//

class CModalDialog3App : public CWinApp
{
public:
	CModalDialog3App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CModalDialog3App theApp;
