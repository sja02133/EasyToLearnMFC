
// ColorSelect.h : main header file for the ColorSelect application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CColorSelectApp:
// See ColorSelect.cpp for the implementation of this class
//

class CColorSelectApp : public CWinApp
{
public:
	CColorSelectApp() noexcept;
// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	//afx_msg void OnColorBlue();
	//afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	//afx_msg void OnColorGreen();
	//afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	//afx_msg void OnColorRed();
	//afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
public:
	void OnColorBlue1();
	void OnUpdateColorBlue1(CCmdUI* pCmdUI);
	void OnColorGreen1();
	void OnUpdateColorGreen1(CCmdUI* pCmdUI);
	void OnColorRed1();
	void OnUpdateColorRed1(CCmdUI* pCmdUI);
};

extern CColorSelectApp theApp;
