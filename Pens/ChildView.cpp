
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Pens.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	int nPenStyle[] = { PS_SOLID,PS_DASH,PS_DOT,PS_DASHDOT,PS_DASHDOTDOT,PS_NULL,PS_INSIDEFRAME };

	TCHAR* PenStyle[] = { _T("PS_SOLID"),_T("PS_DASH"),_T("PS_DOT"),_T("PS_DASHDOT"),_T("PS_DASHDOTDOT"),_T("PS_NULL"),_T("PS_INSIDEFRAME") };

	dc.SetTextAlign(TA_BASELINE);
	for (int i = 0; i < sizeof(nPenStyle) / sizeof(nPenStyle[0]); i++)
	{
		CPen pen(nPenStyle[i], 1, RGB(0, 0, 255));
		dc.SelectObject(&pen);
		dc.TextOut(50, 25 + i * 25, PenStyle[i], lstrlen(PenStyle[i]));
		dc.MoveTo(200, 25 + i * 25);
		dc.LineTo(500, 25 + i * 25);
	}

	// 기존
	//CPen blackPen(PS_SOLID, 1, RGB(0, 0, 0));
	//dc.SelectObject(&blackPen);
	//dc.Rectangle(50, 200, 150, 300);
	//CPen pen1(PS_SOLID, 20, RGB(255, 0, 0));
	//dc.SelectObject(&pen1);
	//dc.Ellipse(50, 200, 150, 300);

	//dc.SelectObject(&blackPen);
	//dc.Rectangle(250, 200, 350, 300);
	//CPen pen2(PS_INSIDEFRAME, 20, RGB(255, 0, 0));
	//dc.SelectObject(&pen2);
	//dc.Ellipse(250, 200, 350, 300);
	// --

	// 연습 문제 18
	CPen blackPen(this->m_penStyle, 1, RGB(0, 0, 0));
	dc.SelectObject(&blackPen);
	dc.Rectangle(50, 200, 150, 300);
	CPen pen1(this->m_penStyle, 20, RGB(255, 0, 0));
	dc.SelectObject(&pen1);
	dc.Ellipse(50, 200, 150, 300);

	dc.SelectObject(&blackPen);
	dc.Rectangle(250, 200, 350, 300);
	CPen pen2(this->m_penStyle, 20, RGB(255, 0, 0));
	dc.SelectObject(&pen2);
	dc.Ellipse(250, 200, 350, 300);
	// --

	// Do not call CWnd::OnPaint() for painting messages
}


// 연습 문제 18, 마우스 이벤트 추가
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->m_penStyle = PS_INSIDEFRAME;
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->m_penStyle = PS_SOLID;
	Invalidate();
	CWnd::OnRButtonDown(nFlags, point);
}
// --