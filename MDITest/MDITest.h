
// MDITest.h : main header file for the MDITest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMDITestApp:
// See MDITest.cpp for the implementation of this class
//

class CMDITestApp : public CWinApp
{
public:
	CMDITestApp() noexcept;

	//CList<CDocTemplate, CDocTemplate> m_list_doctemplate;

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDITestApp theApp;
