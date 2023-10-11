
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

#define COLOR_COUNT 3

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	BOOL m_bDrawMode = FALSE;
	int m_x1, m_y1, m_x2, m_y2;

	//���� ���� 01, �߰�
	CList<CRect, RECT&> m_listCRect;

	//���� ���� 02, ���� ����
	CList<BOOL, BOOL&> m_listColorChoice;	//��Ŭ�� : ����(TRUE), ��Ŭ�� : �Ķ�(FALSE)
	BOOL m_bLButton = FALSE;

	// ���� ���� 03, 3�� ����
	CList<int, int> m_list3ColorChoice;	//AFX_IDC_COLOR_RED,AFX_IDC_COLOR_GREEN,AFX_IDC_COLOR_BLUE ���
	int m_choiceColor = AFX_IDC_COLOR_RED;
	void drawText_3Color(CDC* pDC);

	// ���� ���� 04, shift Ű
	BOOL m_bShift = FALSE;

	//���� ���� 07, ȭ�� max ũ��
	int m_ClientMaxX = 0, m_ClientMaxY = 0;

	// ���� ���� 08, ���� ���� �Ǵ�
	BOOL m_b08 = FALSE;
	CList<CPoint, POINT&> m_listPoint;
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

