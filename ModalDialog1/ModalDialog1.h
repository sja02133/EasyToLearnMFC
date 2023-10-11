
// ModalDialog1.h : main header file for the ModalDialog1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CModalDialog1App:
// See ModalDialog1.cpp for the implementation of this class
//

class CModalDialog1App : public CWinApp
{
public:
	CModalDialog1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CModalDialog1App theApp;
