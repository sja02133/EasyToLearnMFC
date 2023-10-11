
// WorkerThread2.h : main header file for the WorkerThread2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CWorkerThread2App:
// See WorkerThread2.cpp for the implementation of this class
//

class CWorkerThread2App : public CWinApp
{
public:
	CWorkerThread2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWorkerThread2App theApp;
