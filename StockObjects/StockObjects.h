
// StockObjects.h : main header file for the StockObjects application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CStockObjectsApp:
// See StockObjects.cpp for the implementation of this class
//

class CStockObjectsApp : public CWinApp
{
public:
	CStockObjectsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStockObjectsApp theApp;
