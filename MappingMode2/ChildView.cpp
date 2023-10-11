
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "MappingMode2.h"
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

	CRect rect;
	GetClientRect(&rect);

	dc.SetMapMode(MM_ISOTROPIC); // 기존
	
	// 연습 문제 16
	if (this->m_choice_mapMode == 0) {
		this->m_choice_mapMode = MM_ISOTROPIC;
	}
	dc.SetMapMode(this->m_choice_mapMode);
	// --
	dc.SetWindowExt(100, 100);
	dc.SetViewportExt(rect.Width(),rect.Height());
	dc.RoundRect(0, 0, 100, 100, 50, 50);
	dc.DrawEdge(CRect(20, 20, 80, 80), BDR_SUNKENINNER | BDR_RAISEDOUTER, BF_RECT);
	// Do not call CWnd::OnPaint() for painting messages
}

// 연습 문제 16, 마우스 이벤트 추가
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->m_choice_mapMode = MM_ISOTROPIC;
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->m_choice_mapMode = MM_ANISOTROPIC;
	Invalidate();
	CWnd::OnRButtonDown(nFlags, point);
}
// --
