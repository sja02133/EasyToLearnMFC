
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "PaintDC.h"
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
	//dc.Rectangle(0, 0, 200, 100); // 기존
	//dc.Ellipse(200, 100, 500, 200); // 기존
	//연습문제 01
	//CRect rect(0, 0, 200, 100);
	//dc.Rectangle(rect);
	//rect.SetRect(200, 100, 500, 200);
	//dc.Ellipse(rect);
	// --

	// 연습문제 02
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(0, 0, 200, 100);
	dc.Ellipse(rect);
	// --

	// Do not call CWnd::OnPaint() for painting messages
}

