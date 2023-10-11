
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "DrawLines.h"
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
	CRect rect;
	GetClientRect(&rect);

	// 기존
	//dc.MoveTo(0, rect.bottom / 2);
	//dc.LineTo(rect.right, rect.bottom / 2);
	//dc.MoveTo(rect.right / 2, 0);
	//dc.LineTo(rect.right / 2, rect.bottom);

	//POINT point[] = { {rect.right / 2,0},{rect.right,rect.bottom / 2},{rect.right / 2,rect.bottom},{0,rect.bottom / 2},{rect.right / 2,0} };
	//dc.Polyline(point, 5);
	// --

	// 연습 문제 11
	//dc.MoveTo(rect.left, rect.bottom / 2);
	//dc.LineTo(rect.right, rect.bottom / 2);
	//dc.MoveTo(rect.right / 2, rect.top);
	//dc.LineTo(rect.right / 2, rect.bottom);
	//dc.MoveTo(0, rect.bottom);
	//int margin = 0;
	//int xPos, yPos;
	//for (double i = 0; i < 720.01; i+=0.01) {
	//	double value = cos(i * M_PI / 180);
	//	value += 1.0;
	//	yPos = value / 2 * rect.bottom + margin / 2;
	//	xPos = i / 720.0 * rect.right + margin / 2;
	//	CPoint point(xPos, yPos);
	//	m_pointArray.Add(point);
	//}
	//dc.Polyline(m_pointArray.GetData(), m_pointArray.GetSize());
	// --

	// 연습 문제 12
	dc.MoveTo(0, rect.bottom / 2);
	dc.LineTo(rect.right, rect.bottom / 2);
	dc.MoveTo(rect.right / 2, 0);
	dc.LineTo(rect.right / 2, rect.bottom);
	POINT point[] = { {rect.right / 2,0},{rect.right,rect.bottom / 2},{rect.right / 2,rect.bottom},{0,rect.bottom / 2},{rect.right / 2,0} };
	dc.Polyline(point, 5);

	dc.SetMapMode(MM_LOMETRIC);
	CSize size = dc.GetWindowExt();
	CRect rect1(CPoint(0, 0), size);

	CPen pen,*pOldPen;
	pen.CreatePen(PS_SOLID, 8, RGB(0, 0, 0));
	pOldPen = dc.SelectObject(&pen);

	double bottomChange = 0.06;
	dc.Rectangle(rect1.left, rect1.top, rect1.right * 10,(-1) * (rect1.bottom * bottomChange));
	dc.MoveTo(0, 0);
	for (int i = 0; i < rect1.right * 10; i+= 10) {
		if (i == 0) {
			CString str;
			str.Format(_T("%d"), i);
			dc.TextOut(i + 10, (-1) * (rect1.bottom * bottomChange) / 2 + 60, str);
		}
		if (i % 10 == 0) {
			dc.SelectObject(pOldPen);
			dc.MoveTo(i, 0);
			dc.LineTo(i,(-1) * (rect1.bottom * bottomChange) / 8);
		}
		if (i % 50 == 0) {
			dc.SelectObject(pOldPen);
			dc.MoveTo(i, 0);
			dc.LineTo(i, (-1) * (rect1.bottom * bottomChange) / 4);
		}
		if (i % 100 == 0) {
			dc.SelectObject(&pen);
			dc.MoveTo(i, 0);
			dc.LineTo(i, (-1) * (rect1.bottom * bottomChange) / 2);
			CString str;
			str.Format(_T("%d"), i / 100);
			dc.TextOut(i - 30, (-1) * (rect1.bottom * bottomChange) / 2 + 60,str);
		}
	}
	dc.SelectObject(pOldPen);
	// --

	// Do not call CWnd::OnPaint() for painting messages
}

