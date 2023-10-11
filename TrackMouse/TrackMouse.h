
// TrackMouse.h : main header file for the TrackMouse application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTrackMouseApp:
// See TrackMouse.cpp for the implementation of this class
//

class CTrackMouseApp : public CWinApp
{
public:
	CTrackMouseApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTrackMouseApp theApp;
