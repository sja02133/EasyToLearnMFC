
// FileIOTest.h : main header file for the FileIOTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFileIOTestApp:
// See FileIOTest.cpp for the implementation of this class
//

class CFileIOTestApp : public CWinApp
{
public:
	CFileIOTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFileIOTestApp theApp;
