
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "StockObjects.h"
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
		::LoadCursor(nullptr, IDC_ARROW), nullptr, nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	// 기존
	//CRect rect;
	//GetClientRect(&rect);
	//CBrush brush(HS_CROSS, RGB(0, 255, 0));
	//dc.SelectObject(&brush);
	//dc.Rectangle(&rect);

	//dc.SelectStockObject(BLACK_PEN);
	//dc.SelectStockObject(NULL_BRUSH);
	//dc.Ellipse(100, 50, 200, 200);

	//dc.SelectStockObject(NULL_PEN);
	//dc.SelectStockObject(LTGRAY_BRUSH);
	//POINT points[] = { {250,50},{450,150},{300,200},{250,150} };
	//dc.Polygon(points, 4);
	// --

	// 연습 문제 21
	CRect rect;
	GetClientRect(&rect);
	CBrush brush(HS_CROSS, RGB(0, 255, 0));
	
	dc.SelectStockObject(DEVICE_DEFAULT_FONT);
	
	dc.SelectObject(&brush);
	dc.Rectangle(&rect);
	dc.TextOutW(rect.right / 2, rect.bottom / 2, _T("사각형"));

	dc.SelectStockObject(SYSTEM_FIXED_FONT);
	dc.SelectStockObject(NULL_BRUSH);
	
	CRect rect2;
	rect2.left = 100;
	rect2.top = 50;
	rect2.right = 200;
	rect2.bottom = 200;
	dc.Ellipse(rect2);

	

	//dc.TextOut(rect2.right / 2, rect2.bottom / 2, _T("원"));
	dc.DrawText(_T("원"), CRect(CPoint(100, 50), CPoint(200, 200)), DT_TOP | DT_CENTER);

	dc.SelectStockObject(NULL_PEN);
	dc.SelectStockObject(LTGRAY_BRUSH);
	POINT points[] = { {250,50},{450,150},{300,200},{250,150} };
	dc.Polygon(points, 4);
	// --
	
	// Do not call CWnd::OnPaint() for painting messages
}

