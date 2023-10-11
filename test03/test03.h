
// test03.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Ctest03App:
// See test03.cpp for the implementation of this class
//

class Ctest03App : public CWinApp
{
public:
	Ctest03App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ctest03App theApp;
