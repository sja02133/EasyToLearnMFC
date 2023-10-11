
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "DrawCircles_09.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_bCtrl = FALSE;
	m_bAlt = FALSE;
	m_bSpace = FALSE;

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_SYSKEYDOWN()
	ON_WM_KEYUP()
	ON_WM_SYSKEYUP()
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
	
	POSITION pos = this->m_listCRect.GetHeadPosition();

	while (pos) {
		auto rect = this->m_listCRect.GetNext(pos);
		dc.Ellipse(rect);
	}

	// Do not call CWnd::OnPaint() for painting messages
}

BOOL CChildView::change_listCRectSize(BOOL plusIsTrue,UINT value) {
	INT32 k = 0;
	if (!plusIsTrue)
		k = -(INT32)value;
	else
		k = (INT32)value;

	POSITION pos = this->m_listCRect.GetHeadPosition();
	CPoint mid;
	while (pos) {
		auto* rect = &this->m_listCRect.GetNext(pos);
		rect->right += k;
		rect->bottom += k;
	}
	return TRUE;
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 기존
	if ((!m_bCtrl && !m_bSpace) && (!m_bAlt && !m_bSpace)) {
		m_x2 = point.x;
		m_y2 = point.y;
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		this->m_listCRect.AddTail(CRect(m_x1, m_y1, m_x2, m_y2));
		m_bDrawMode = FALSE;
		Invalidate();
	}
	// 실습 5-2
	::ReleaseCapture();
	// --

	m_bDrawMode = FALSE;

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 실습 5-2
	SetCapture();
	// --

	m_x1 = m_x2 = point.x;
	m_y1 = m_y2 = point.y;
	
	if (m_bCtrl && m_bSpace) {
		change_listCRectSize(TRUE, 10);
		Invalidate();
	}
	else if (m_bAlt && m_bSpace) {
		change_listCRectSize(FALSE, 10);
		Invalidate();
	}
	else
		m_bDrawMode = TRUE;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_bDrawMode) {
		// 기존
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);
		dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		dc.SetROP2(R2_NOT);
		m_x2 = point.x;
		m_y2 = point.y;
		dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		// --
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_CONTROL:
		this->m_bCtrl = TRUE;
		break;
	case VK_SPACE:
		this->m_bSpace = TRUE;
		break;
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_MENU:
		this->m_bAlt = TRUE;
		break;
	case VK_SPACE:
		this->m_bSpace = TRUE;
		break;
	case VK_CONTROL:
		this->m_bCtrl = TRUE;
		break;
	}

	CWnd::OnSysKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar)
	{
	case VK_CONTROL:
		this->m_bCtrl = FALSE;
		break;
	case VK_SPACE:
		this->m_bSpace = FALSE;
		break;
	case VK_MENU:
		this->m_bAlt = FALSE;
		break;
	}
	CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}


void CChildView::OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case VK_MENU:
		this->m_bAlt = FALSE;
		break;
	case VK_SPACE:
		this->m_bSpace = FALSE;
		break;
	case VK_CONTROL:
		this->m_bCtrl = FALSE;
		break;
	}
	CWnd::OnSysKeyUp(nChar, nRepCnt, nFlags);
}
