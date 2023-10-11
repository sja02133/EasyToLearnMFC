
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "DrawCircles.h"
#include "ChildView.h"

#include "FormView_1.h"

CFormView* pFormview;

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
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
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

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// 연습 문제 01
	//dc.SelectStockObject(NULL_BRUSH);
	//POSITION pos = this->m_listCRect.GetHeadPosition();
	//while (pos) {
	//	auto rect = this->m_listCRect.GetNext(pos);
	//	dc.Ellipse(rect);
	//}
	// --
	// 
	// 연습 문제 02
	//dc.SelectStockObject(NULL_BRUSH);
	//POSITION pos = this->m_listCRect.GetHeadPosition();
	//POSITION colorPos = this->m_listColorChoice.GetHeadPosition();
	//while (pos) {
	//	CPen pen;
	//	pen.CreatePen(PS_SOLID, 1, this->m_listColorChoice.GetNext(colorPos) ? RGB(255,0,0) : RGB(0,0,255));
	//	auto rect = this->m_listCRect.GetNext(pos);
	//	dc.SelectObject(&pen);
	//	dc.Ellipse(rect);
	//}
	// --
	
	// 연습 문제 03
	//dc.SelectStockObject(NULL_BRUSH);
	//POSITION pos = this->m_listCRect.GetHeadPosition();
	//POSITION THREE_colorPos = this->m_list3ColorChoice.GetHeadPosition();
	//while (pos) {
	//	CPen pen;
	//	CRect client_rect;
	//	GetClientRect(&client_rect);
	//	CString str;
	//	str = _T("현재 선택 색상 : ");
	//	auto color = this->m_list3ColorChoice.GetNext(THREE_colorPos);
	//	switch (color) {
	//	case AFX_IDC_COLOR_RED:
	//		str += _T("빨강");
	//		pen.CreatePen(PS_SOLID, 1, RGB(255,0,0));
	//		break;
	//	case AFX_IDC_COLOR_GREEN:
	//		str += _T("초록");
	//		pen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	//		break;
	//	case AFX_IDC_COLOR_BLUE:
	//		str += _T("파랑");
	//		pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	//		break;
	//	}
	//	client_rect.right -= 20;
	//	client_rect.bottom -= 20;
	//	dc.DrawText(str, &client_rect, DT_LEFT);
	//	auto rect = this->m_listCRect.GetNext(pos);
	//	dc.SelectObject(&pen);
	//	dc.Ellipse(rect);
	//}
	// --

	// 연습 문제 08
	if (this->m_listPoint.GetSize() == 0)
		return;
	CPoint startPoint;
	dc.SelectStockObject(NULL_BRUSH);
	POSITION pos = this->m_listPoint.GetHeadPosition();
	auto b_point = this->m_listPoint.GetHead();
	dc.MoveTo(b_point);
	int count = 0;
	if (this->m_listPoint.GetSize()) {
		while (pos) {
			auto n_point = this->m_listPoint.GetNext(pos);
			dc.LineTo(n_point);
		}
	}
	// --

	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 실습 5-2
	SetCapture();
	// --

	//m_bDrawMode = TRUE;	//기존
	
	// 연습 문제 08
	if (m_b08)
		m_bDrawMode = FALSE;
	this->m_listPoint.AddTail(point);
	// --

	m_x1 = m_x2 = point.x;
	m_y1 = m_y2 = point.y;

	// 연습 문제 02
	this->m_bLButton = TRUE;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	

	// 기존
	//CClientDC dc(this);
	//dc.SelectStockObject(NULL_BRUSH);
	//dc.SetROP2(R2_COPYPEN);
	//m_x2 = point.x;
	//m_y2 = point.y;
	//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
	//m_bDrawMode = FALSE;
	//// 실습 5-2
	//::ReleaseCapture();
	// --

	// 연습 문제 01
	//this->m_listCRect.AddTail(CRect(m_x1, m_y1, m_x2, m_y2));
	//m_bDrawMode = FALSE;
	//::ReleaseCapture();
	//Invalidate();
	// --


	// 연습 문제 02
	//this->m_listCRect.AddTail(CRect(m_x1, m_y1, m_x2, m_y2));
	//BOOL choice = this->m_bLButton;
	//this->m_listColorChoice.AddTail(choice);
	//m_bDrawMode = FALSE;
	//::ReleaseCapture();
	//Invalidate();
	// --

	// 연습 문제 03
	//this->m_listCRect.AddTail(CRect(m_x1, m_y1, m_x2, m_y2));
	//this->m_list3ColorChoice.AddTail(this->m_choiceColor);
	//m_bDrawMode = FALSE;
	//::ReleaseCapture();
	//Invalidate();
	// --

	// 연습 문제 04
	//int radius = 0;
	//if (::GetKeyState(VK_SHIFT)) {
	//	abs(m_x1 - m_x2) < abs(m_y1 - m_y2) ? radius = abs(m_x1 - m_x2) : radius = abs(m_y1 - m_y2);
	//	if (m_x1 < m_x2) {
	//		// left -> right
	//		(m_y1 > m_y2) ? m_y2 = m_y1 + radius : m_y1 = m_y2 + radius;
	//	}
	//	else {
	//		//right -> left
	//		(m_y1 < m_y2) ? m_y2 = m_y1 + radius : m_y1 = m_y2 + radius;
	//	}
	//}
	//this->m_listCRect.AddTail(CRect(m_x1, m_y1, m_x2, m_y2));
	//this->m_list3ColorChoice.AddTail(this->m_choiceColor);
	//m_bDrawMode = FALSE;
	//::ReleaseCapture();
	//Invalidate();
	// --

	// 연습 문제 08
	this->m_listPoint.AddTail(point);
	this->m_bLButton = FALSE;
	//this->m_list3ColorChoice.AddTail(this->m_choiceColor);
	::ReleaseCapture();
	Invalidate();
	// --

	// --
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_bDrawMode) {
		// 기존
		//CClientDC dc(this);
		//dc.SelectStockObject(NULL_BRUSH);
		//dc.SetROP2(R2_NOT);
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		//dc.SetROP2(R2_NOT);
		//m_x2 = point.x;
		//m_y2 = point.y;
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		// --

		// 연습 문제 02
		//CClientDC dc(this);
		//dc.SelectStockObject(NULL_BRUSH);
		//dc.SetROP2(R2_NOT);
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		//dc.SetROP2(R2_NOT);
		//m_x2 = point.x;
		//m_y2 = point.y;
		//CPen pen;
		//pen.CreatePen(PS_SOLID, 1, this->m_bLButton ? RGB(255, 0, 0) : RGB(0, 0, 255));
		//dc.SelectObject(&pen);
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		// --

		// 연습 문제 03
		//CClientDC dc(this);
		//dc.SelectStockObject(NULL_BRUSH);
		//dc.SetROP2(R2_NOP);
		//CPen pen;
		//if (this->m_choiceColor == AFX_IDC_COLOR_RED)
		//	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		//else if (this->m_choiceColor == AFX_IDC_COLOR_BLUE)
		//	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		//else
		//	pen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		//dc.SelectObject(&pen);
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		//dc.SetROP2(R2_COPYPEN);
		//m_x2 = point.x;
		//m_y2 = point.y;
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		// --
	}
	else if (this->m_b08 && this->m_bLButton) {
		// 연습 문제 08
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_x2, m_y2);
		//dc.LineTo(m_x2, m_y2);
		dc.SetROP2(R2_NOT);
		m_x2 = point.x;
		m_y2 = point.y;
		dc.LineTo(point.x, point.y);
		this->m_listPoint.AddTail(point);
	}
	

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 실습 5-2
	SetCapture();
	// --

	m_bDrawMode = TRUE;
	m_x1 = m_x2 = point.x;
	m_y1 = m_y2 = point.y;

	// 연습 문제 02
	this->m_bLButton = FALSE;

	
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 연습 문제 02
	this->m_listCRect.AddTail(CRect(m_x1, m_y1, m_x2, m_y2));
	BOOL choice = this->m_bLButton;
	this->m_listColorChoice.AddTail(choice);
	m_bDrawMode = FALSE;
	::ReleaseCapture();
	Invalidate();
	// --
	CWnd::OnRButtonUp(nFlags, point);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	// 연습 문제 06
	POSITION pos = this->m_listCRect.GetTailPosition();
	
	// 연습 문제 07
	CRect rect;
	GetClientRect(&rect);
	this->m_ClientMaxX = rect.right;
	this->m_ClientMaxY = rect.bottom;
	int random_X1 = 0, random_X2 = 0, random_Y1 = 0, random_Y2 = 0;
	int random_Color = 0;
	// --

	switch (nChar) {
	case 'R':
	case 'r':
		this->m_choiceColor = AFX_IDC_COLOR_RED;
		break;
	case 'G':
	case 'g':
		this->m_choiceColor = AFX_IDC_COLOR_GREEN;
		break;
	case 'B':
	case 'b':
		this->m_choiceColor = AFX_IDC_COLOR_BLUE;
		break;
	case VK_SHIFT:
		this->m_bShift = TRUE;
		break;
	case VK_DELETE:
	{
		// 연습 문제 06
		if (this->m_listCRect.GetSize()) {
			this->m_listCRect.RemoveAt(pos);
			pos = this->m_list3ColorChoice.GetTailPosition();
			this->m_list3ColorChoice.RemoveAt(pos);
			Invalidate();
		}
		break;
	}
	case VK_INSERT:
		// 연습 문제 07
		srand((unsigned int)time(NULL));
		random_X1 = rand() % this->m_ClientMaxX;
		random_X2 = rand() % this->m_ClientMaxX;
		while (random_X1 == random_X2) {
			random_X2 = rand() % this->m_ClientMaxX;
		}
		random_Y1 = rand() % this->m_ClientMaxY;
		random_Y2 = rand() % this->m_ClientMaxY;
		while (random_Y1 == random_Y2) {
			random_Y2 = rand() % this->m_ClientMaxY;
		}
		
		random_Color = rand() % 3;

		rect.left = random_X1;
		rect.right = random_X2;
		rect.top = random_Y1;
		rect.bottom = random_Y2;
		this->m_listCRect.AddTail(rect);

		switch (random_Color) {
		case 0:
			random_Color = AFX_IDC_COLOR_RED;
			break;
		case 1:
			random_Color = AFX_IDC_COLOR_BLUE;
			break;
		case 2:
			random_Color = AFX_IDC_COLOR_GREEN;
			break;
		}
		this->m_list3ColorChoice.AddTail(random_Color);
		Invalidate();
		break;
	case VK_END:
		// 연습 문제 08, 을 위한 전용 모드로 변경
		this->m_b08 = !this->m_b08;
		break;
	}
	CDC* pDC = GetDC();
	drawText_3Color(pDC);

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CChildView::drawText_3Color(CDC* pDC)
{
	CRect rect;
	::GetClientRect(this->m_hWnd,&rect);
	CString str;
	str = _T("현재 선택 색상 : ");
	switch (this->m_choiceColor) {
	case AFX_IDC_COLOR_RED:
		str += _T("빨강");
		break;
	case AFX_IDC_COLOR_GREEN:
		str += _T("초록");
		break;
	case AFX_IDC_COLOR_BLUE:
		str += _T("파랑");
		break;
	}
	rect.right -= 20;
	rect.bottom -= 20;
	pDC->DrawText(str, &rect, DT_LEFT);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here


	return 0;
}
