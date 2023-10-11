
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
	CArray<TCHAR, TCHAR> m_str;

	// 연습 문제 23
	CList<int, int> m_listTabPos;

	// 연습 문제 24
	int caretPosX = 0, caretPosY = 0,before_caretPosX = 0;
	void setCaretXYPos();
	CList<int, int> m_listEnterPos;
	BOOL delCheck = FALSE;
	//
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
};

