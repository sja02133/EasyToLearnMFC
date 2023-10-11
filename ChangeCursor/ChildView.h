
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	// 연습 문제 13
	CPoint m_point;
	CRect m_rect;
	BOOL m_bSetCursor = FALSE;

	// 연습 문제 14
	BOOL m_bLBclicked = FALSE;
	CRect m_rectRgn;
	CPoint m_beforePoint;

	// 연습 문제 16
	BOOL m_bLBClickedRgn = FALSE;
	BOOL m_btCtrl = FALSE;
	CList<CRect, RECT&> m_listRect;
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
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

