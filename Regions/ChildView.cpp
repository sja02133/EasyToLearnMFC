
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Regions.h"
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
	CRgn rgn1, rgn2, rgn3;
	rgn1.CreateRectRgn(0, 0, 1, 1);
	rgn2.CreateRectRgn(10, 10, 100, 100);
	rgn3.CreateEllipticRgn(50, 50, 200, 200);	
	rgn1.CombineRgn(&rgn2, &rgn3, RGN_XOR);
	
	CBrush brush(RGB(0, 0, 255));
	dc.FillRgn(&rgn1, &brush);

	// 연습 문제 24, 기존에서 추가
	rgn1.CombineRgn(&rgn2, &rgn3, RGN_AND);
	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(255, 0, 0));
	dc.FillRgn(&rgn1, &brush);
	// Do not call CWnd::OnPaint() for painting messages
}

