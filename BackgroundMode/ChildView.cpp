
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "BackgroundMode.h"
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
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
	//	::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr); // 기존
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), (HBRUSH)GetStockObject(GRAY_BRUSH), nullptr);	//chapter 04

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

	//기존
	//dc.SetBkMode(OPAQUE);
	//dc.TextOut(100, 50, CString(" OPAQUE 모드 [1]"));

	//dc.SetBkMode(TRANSPARENT);
	//dc.TextOut(100, 100, CString(" TRANSPARENT 모드"));

	//dc.SetBkMode(OPAQUE);
	//dc.SetBkColor(RGB(0, 255, 0));
	//dc.TextOut(100, 150, CString(" OPAQUE 모드 [2]"));
	// --

	// 연습 문제 17
	dc.SetBkMode(this->m_choice_BkMode);
	dc.TextOut(100, 50, CString(" OPAQUE 모드 [1]"));

	dc.TextOut(100, 100, CString(" TRANSPARENT 모드"));

	dc.SetBkColor(RGB(0, 255, 0));
	dc.TextOut(100, 150, CString(" OPAQUE 모드 [2]"));
	// --

	// Do not call CWnd::OnPaint() for painting messages
}

// 연습 문제 17, 마우스 이벤트 추가
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->m_choice_BkMode = OPAQUE;
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->m_choice_BkMode = TRANSPARENT;
	Invalidate();
	CWnd::OnRButtonDown(nFlags, point);
}
// --