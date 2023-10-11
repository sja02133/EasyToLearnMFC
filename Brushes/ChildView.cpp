
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Brushes.h"
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
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
	//	::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr); // 기존
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), nullptr, nullptr); // 연습 문제 20
	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	// 기존
	//CBrush brush1(RGB(255, 0, 0));
	//dc.SelectObject(&brush1);
	//dc.Rectangle(50, 50, 200, 200);

	//CBrush brush2(HS_DIAGCROSS, RGB(255, 0, 0));
	//dc.SelectObject(&brush2);
	//dc.Ellipse(250,50,400,200);

	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_BITMAP1);
	//CBrush brush3(&bitmap);
	//dc.SelectObject(&brush3);
	//dc.RoundRect(450, 50, 600, 200, 50, 50);
	// --

	// 연습 문제 19
	//CRect rect;
	//GetClientRect(&rect);

	//CBrush brush(HS_DIAGCROSS, RGB(255, 0, 0));
	//dc.SelectObject(&brush);

	//CPen pen(PS_NULL, 0, RGB(255,0,0));
	//dc.SelectObject(&pen);
	//dc.Rectangle(rect);
	// --

	// 연습 문제 20
	CRect rect;
	GetClientRect(&rect);
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush bkBrush(&bitmap);
	dc.SelectObject(&bkBrush);
	dc.Rectangle(rect);

	CBrush brush1(RGB(255, 0, 0));
	dc.SelectObject(&brush1);
	dc.Rectangle(50, 50, 200, 200);

	CBrush brush2(HS_DIAGCROSS, RGB(255, 0, 0));
	dc.SelectObject(&brush2);
	dc.Ellipse(250,50,400,200);

	CBrush brush3;
	brush3.CreatePatternBrush(&bitmap);
	dc.SelectObject(&brush3);
	dc.RoundRect(450, 50, 600, 200, 50, 50);
	// --

	// Do not call CWnd::OnPaint() for painting messages
}

