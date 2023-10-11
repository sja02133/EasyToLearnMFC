
// ImageList.h : main header file for the ImageList application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CImageListApp:
// See ImageList.cpp for the implementation of this class
//

class CImageListApp : public CWinApp
{
public:
	CImageListApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CImageListApp theApp;
