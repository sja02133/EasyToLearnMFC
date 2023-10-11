
// WorkerThread1.h : main header file for the WorkerThread1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CWorkerThread1App:
// See WorkerThread1.cpp for the implementation of this class
//

class CWorkerThread1App : public CWinApp
{
public:
	CWorkerThread1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWorkerThread1App theApp;
