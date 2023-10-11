
// MainFrm.h : interface of the CMainFrame class
//

#pragma once
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame() noexcept;
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
public:
	CChildView    m_wndView;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

public:
	void OnColorBlue1();
	void OnUpdateColorBlue1(CCmdUI* pCmdUI);
	void OnColorGreen1();
	void OnUpdateColorGreen1(CCmdUI* pCmdUI);
	void OnColorRed1();
	void OnUpdateColorRed1(CCmdUI* pCmdUI);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnButtonTurnonoff();

	// 연습 문제 10
	int FindMenuItem(CMenu* Menu, LPCTSTR MenuString);
	afx_msg void OnButtonMinimize();
	afx_msg void OnUpdateButtonMinimize(CCmdUI* pCmdUI);
};


