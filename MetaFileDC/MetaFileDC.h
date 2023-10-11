
// MetaFileDC.h : main header file for the MetaFileDC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMetaFileDCApp:
// See MetaFileDC.cpp for the implementation of this class
//

class CMetaFileDCApp : public CWinApp
{
public:
	CMetaFileDCApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMetaFileDCApp theApp;
