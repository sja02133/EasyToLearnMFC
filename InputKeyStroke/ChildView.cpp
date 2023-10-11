
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "InputKeyStroke.h"
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
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
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
	
	if (m_bFill)
		dc.SelectStockObject(BLACK_BRUSH);

	dc.Ellipse(m_xPos - 20, m_yPos - 20, m_xPos + 20, m_yPos + 20);
	
	// 연습 문제 22
	this->m_listPoint.AddTail(CPoint(m_xPos, m_yPos));
	if (this->m_listPoint.GetSize()) {
		POSITION pos = this->m_listPoint.GetHeadPosition();
		BOOL checkFirst = TRUE;

		CPen pen(PS_DOT, 1, RGB(128, 128, 128));
		dc.SelectObject(&pen);
		while (pos) {
			auto point = this->m_listPoint.GetNext(pos);
			if (checkFirst == TRUE) {
				dc.MoveTo(point);
				checkFirst = FALSE;
			}
			else
				dc.LineTo(point);
		}
	}
	// --

	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_xMax = cx;
	m_yMax = cy;
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	// 기존
	//switch (nChar) {
	//case VK_LEFT:
	//	m_xPos -= 20;
	//	break;
	//case VK_RIGHT:
	//	m_xPos += 20;
	//	break;
	//case VK_UP:
	//	m_yPos -= 20;
	//	break;
	//case VK_DOWN:
	//	m_yPos += 20;
	//	break;
	//case VK_SPACE:
	//	m_bFill = !m_bFill;
	//	break;
	//}

	//m_xPos = min(max(20, m_xPos), m_xMax - 20);
	//m_yPos = min(max(20, m_yPos), m_yMax - 20);
	// --
	
	// 연습 문제 20
	//BOOL ctrlCheck = FALSE;
	//if (::GetKeyState(VK_CONTROL) < 0) {
	//	ctrlCheck = TRUE;
	//}
	//switch (nChar) {
	//case VK_LEFT:
	//	m_xPos -= 20;
	//	if (ctrlCheck == TRUE)
	//		m_xPos += 10;
	//	break;
	//case VK_RIGHT:
	//	m_xPos += 20;
	//	if (ctrlCheck == TRUE)
	//		m_xPos -= 10;
	//	break;
	//case VK_UP:
	//	m_yPos -= 20;
	//	if (ctrlCheck == TRUE)
	//		m_yPos += 10;
	//	break;
	//case VK_DOWN:
	//	m_yPos += 20;
	//	if (ctrlCheck == TRUE)
	//		m_yPos -= 10;
	//	break;
	//case VK_SPACE:
	//	m_bFill = !m_bFill;
	//	break;
	//}

	//m_xPos = min(max(20, m_xPos), m_xMax - 20);
	//m_yPos = min(max(20, m_yPos), m_yMax - 20);
	// -

	// 연습 문제 21
	//int value = 20;
	//BOOL ctrlCheck = FALSE;
	//if (::GetKeyState(VK_SHIFT) < 0) {
	//	ctrlCheck = TRUE;
	//}
	//switch (nChar) {
	//case VK_LEFT:
	//	m_xPos -= value;
	//	if (ctrlCheck == TRUE)
	//		m_xPos += value * 2;
	//	break;
	//case VK_RIGHT:
	//	m_xPos += value;
	//	if (ctrlCheck == TRUE)
	//		m_xPos -= value * 2;
	//	break;
	//case VK_UP:
	//	m_yPos -= value;
	//	if (ctrlCheck == TRUE)
	//		m_yPos += value * 2;
	//	break;
	//case VK_DOWN:
	//	m_yPos += value;
	//	if (ctrlCheck == TRUE)
	//		m_yPos -= value * 2;
	//	break;
	//case VK_SPACE:
	//	m_bFill = !m_bFill;
	//	break;
	//}

	//m_xPos = min(max(20, m_xPos), m_xMax - 20);
	//m_yPos = min(max(20, m_yPos), m_yMax - 20);
	// -

	// 연습 문제 22
	int value = 20;
	BOOL ctrlCheck = FALSE;
	if (::GetKeyState(VK_SHIFT) < 0) {
		ctrlCheck = TRUE;
	}
	switch (nChar) {
	case VK_LEFT:
		m_xPos -= value;
		if (ctrlCheck == TRUE)
			m_xPos += value * 2;
		break;
	case VK_RIGHT:
		m_xPos += value;
		if (ctrlCheck == TRUE)
			m_xPos -= value * 2;
		break;
	case VK_UP:
		m_yPos -= value;
		if (ctrlCheck == TRUE)
			m_yPos += value * 2;
		break;
	case VK_DOWN:
		m_yPos += value;
		if (ctrlCheck == TRUE)
			m_yPos -= value * 2;
		break;
	case VK_SPACE:
		this->m_bSpace = TRUE;
		//m_bFill = !m_bFill;
		//this->m_listPoint.AddTail(CPoint(m_xPos, m_yPos));
		break;
	}

	m_xPos = min(max(20, m_xPos), m_xMax - 20);
	m_yPos = min(max(20, m_yPos), m_yMax - 20);

	if (this->m_bSpace == TRUE) {
		this->m_listPoint.RemoveAll();
		this->m_bSpace = FALSE;
	}
		

	// -

	Invalidate();
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
