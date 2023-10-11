
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "TrackMouse.h"
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
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
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
	
	// 연습 문제 17
	CRect rect;
	GetClientRect(&rect);
	COLORREF color;
	if (m_bMouseIn) {
		color = RGB(255, 255, 0);
	}
	else {
		color = RGB(255, 255, 255);
	}
	dc.FillSolidRect(&rect, color);

	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_bMouseIn == FALSE) {
		// 기존
		//TRACKMOUSEEVENT tme;
		//tme.cbSize = sizeof(tme);
		//tme.dwFlags = TME_LEAVE;
		//tme.hwndTrack = this->m_hWnd;
		//tme.dwHoverTime = HOVER_DEFAULT;
		//::TrackMouseEvent(&tme);

		//CWnd* pMainWnd = AfxGetMainWnd();
		//CRect rect;
		//pMainWnd->GetWindowRect(&rect);
		//rect.right = rect.left + 300;
		//rect.bottom = rect.top + 150;
		//pMainWnd->MoveWindow(&rect);
		// --

		m_bMouseIn = TRUE;

		// 연습 문제 17
		//TRACKMOUSEEVENT tme;
		//tme.cbSize = sizeof(tme);
		//tme.dwFlags = TME_LEAVE;
		//tme.hwndTrack = this->m_hWnd;
		//tme.dwHoverTime = HOVER_DEFAULT;
		//::TrackMouseEvent(&tme);

		//Invalidate();
		// --

		// 연습 문제 18
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = this->m_hWnd;
		tme.dwHoverTime = HOVER_DEFAULT;
		::TrackMouseEvent(&tme);

		CWnd* pMainWnd = AfxGetMainWnd();
		CRect rect;
		pMainWnd->GetWindowRect(&rect);
		rect.right = rect.left + 1020;
		rect.bottom = rect.top + 768;
		pMainWnd->MoveWindow(&rect);

		Invalidate();
		// --
		
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default
	if (m_bMouseIn == TRUE) {
		m_bMouseIn = FALSE;

		// 기존
		//CWnd* pMainWnd = AfxGetMainWnd();
		//CRect rect;
		//pMainWnd->GetWindowRect(&rect);
		//rect.right = rect.left + 200;
		//rect.bottom = rect.top + 100;
		//pMainWnd->MoveWindow(&rect);
		// --

		// 연습 문제 17
		//Invalidate();
		// --
		
		// 연습 문제 18
		CWnd* pMainWnd = AfxGetMainWnd();
		CRect rect;
		pMainWnd->GetWindowRect(&rect);
		rect.right = rect.left + 640;
		rect.bottom = rect.top + 480;
		pMainWnd->MoveWindow(&rect);
		// --

	}
	
	
	

	CWnd::OnMouseLeave();
}
