
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

	//연습 문제 01, 추가
	CList<CRect, RECT&> m_listCRect;

	//연습 문제 02, 색상 저장
	CList<BOOL, BOOL&> m_listColorChoice;	//좌클릭 : 빨강(TRUE), 우클릭 : 파랑(FALSE)
	BOOL m_bLButton = FALSE;

	// 연습 문제 03, 3색 저장
	CList<int, int> m_list3ColorChoice;	//AFX_IDC_COLOR_RED,AFX_IDC_COLOR_GREEN,AFX_IDC_COLOR_BLUE 사용
	int m_choiceColor = AFX_IDC_COLOR_RED;
	void drawText_3Color(CDC* pDC);

	// 연습 문제 04, shift 키
	BOOL m_bShift = FALSE;

	//연습 문제 07, 화면 max 크기
	int m_ClientMaxX = 0, m_ClientMaxY = 0;

	// 연습 문제 08, 전용 모드로 판단
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

