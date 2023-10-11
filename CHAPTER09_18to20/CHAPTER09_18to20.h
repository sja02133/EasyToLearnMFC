
// CHAPTER09_18to20.h : main header file for the CHAPTER09_18to20 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCHAPTER0918to20App:
// See CHAPTER09_18to20.cpp for the implementation of this class
//

class CCHAPTER0918to20App : public CWinApp
{
public:
	CCHAPTER0918to20App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCHAPTER0918to20App theApp;
