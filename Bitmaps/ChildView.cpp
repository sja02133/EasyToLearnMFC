
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Bitmaps.h"
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
	ON_WM_LBUTTONUP()
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

	
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP bmpInfo;
	bitmap.GetBitmap(&bmpInfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// 기존
	//dc.BitBlt(10, 10, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	//dc.StretchBlt(10, 100, bmpInfo.bmWidth * 4, bmpInfo.bmHeight * 2, &dcmem, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);

	//dcmem.Rectangle(5, 5, 15, 15);
	//dc.BitBlt(350, 10, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	//dc.StretchBlt(350, 100, bmpInfo.bmWidth * 4, bmpInfo.bmHeight * 2, &dcmem, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);
	// --

	//// 연습 문제 22
	//if (this->check_LButtonDown == FALSE)
	//{
	//	dc.BitBlt(10, 10, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	//}
	//else 
	//{
	//	CRect rect;
	//	GetClientRect(&rect);
	//	dc.StretchBlt(rect.left, rect.top, rect.right, rect.bottom, &dcmem, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);
	//}
	// --

	// 연습 문제 23
	if (this->check_LButtonDown == FALSE)
	{
		dc.BitBlt(10, 10, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	}
	else
	{
		CRect rect;
		GetClientRect(&rect);
		dc.StretchBlt(bmpInfo.bmWidth, bmpInfo.bmHeight, -bmpInfo.bmWidth, -bmpInfo.bmHeight, &dcmem, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);
	}
	// --



	// Do not call CWnd::OnPaint() for painting messages
}




void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->check_LButtonDown = TRUE;
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->check_LButtonDown = FALSE;
	Invalidate();
	CWnd::OnLButtonUp(nFlags, point);
}
