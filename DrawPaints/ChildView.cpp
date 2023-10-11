
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "DrawPaints.h"
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
	ON_WM_CREATE()
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

BOOL check = FALSE;

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	// 기존
	//for (int x = 0; x < 256; x++) {
	//	for (int y = 0; y < 256; y++) {
	//		dc.SetPixelV(x, y, RGB(x, y, 0));
	//	}
	//}
	// --

	// 연습 문제 10
	CBitmap* bitmap = new CBitmap;
	CDC* pDC = GetDC();
	bitmap->CreateCompatibleBitmap(pDC,256,256);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(bitmap);

	for (int x = 0; x < 256; x++) {
		for (int y = 0; y < 256; y++) {
			memDC.SetPixelV(x, y, RGB(x, y, 0));
		}
	}
	BITMAP bmpInfo;
	bitmap->GetBitmap(&bmpInfo);

	pDC->BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &memDC, 0, 0, SRCCOPY);
	bitmap->DeleteObject();
	ReleaseDC(pDC);
	// --
	


	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	// 연습 문제 09
	CClientDC dc(this);
	COLORREF color;
	color = ::GetPixel(dc, point.x, point.y);
	CString str;
	str.Format(_T("R:%d, G:%d, B:%d"), GetRValue(color), GetGValue(color), GetBValue(color));
	MessageBox(str, _T("DrawPoints"), MB_OK | MB_ICONWARNING);
	// --




	CWnd::OnLButtonDown(nFlags, point);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}
