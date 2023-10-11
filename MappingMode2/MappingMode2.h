
// MappingMode2.h : main header file for the MappingMode2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMappingMode2App:
// See MappingMode2.cpp for the implementation of this class
//

class CMappingMode2App : public CWinApp
{
public:
	CMappingMode2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMappingMode2App theApp;
