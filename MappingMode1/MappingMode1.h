
// MappingMode1.h : main header file for the MappingMode1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMappingMode1App:
// See MappingMode1.cpp for the implementation of this class
//

class CMappingMode1App : public CWinApp
{
public:
	CMappingMode1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMappingMode1App theApp;
