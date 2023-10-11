
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
	int m_xPos = 60, m_yPos = 60;	// ������ ���� ��ġ
	int m_xMax, m_yMax;	// Ŭ���̾�Ʈ ���� ũ��
	BOOL m_bFill = FALSE;

	// ���� ���� 22
	CList<CPoint, POINT&> m_listPoint;
	BOOL m_bSpace = FALSE;
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
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

