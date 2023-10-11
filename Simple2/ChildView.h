
// ChildView.h : interface of the CChildView class
//


#pragma once

#define WM_TRAY_NOTIFICATION WM_APP + 1
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

	// 연습 문제 05
	CString delStr = _T("삭제");
	CString addStr = _T("추가");
	BOOL m_cBAdd = TRUE;
	BOOL m_bPtInRect = FALSE;
	CList<CRect, RECT&> m_listCRect;
	void add_rectangle(CPoint point);
	void del_rectangle(CPoint point);
	CRect m_rectRgn;
	// --

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	LRESULT OnTrayNotification(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	BOOL OnDrawRectangle();
	afx_msg void OnSyscommandTray();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

