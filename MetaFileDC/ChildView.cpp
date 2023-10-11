
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "MetaFileDC.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	// 기존
	//CMetaFileDC dc;
	//dc.CreateEnhanced(NULL, _T("C:\\Users\\KDY\\source\\STUDY\\MetaFileDC\\hello.emf"), NULL, NULL);
	//dc.Rectangle(0, 0, 10, 10);
	//dc.Ellipse(1, 1, 9, 9);
	//m_hmf = dc.CloseEnhanced();
	// --

	// 연습 문제 08
	BOOL check = this->m_metaDC.CreateEnhanced(NULL, _T("Output.emf"), NULL, NULL);
	this->m_metaDC.Rectangle(0, 0, 10, 10);
	this->m_metaDC.Ellipse(1, 1, 9, 9);
	m_hmf = this->m_metaDC.CloseEnhanced();
	// --
}

CChildView::~CChildView()
{
//	CloseEnhMetaFile(m_hmf);
	m_hmf = this->m_metaDC.CloseEnhanced();
	::DeleteEnhMetaFile(m_hmf);
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
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
	
	// 연습 문제 06
	//POSITION pos = this->m_LButtonPointList.GetHeadPosition();
	//CRect rect;
	//while (pos) {
	//	auto point = this->m_LButtonPointList.GetNext(pos);
	//	rect.SetRect(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	//	dc.PlayMetaFile(m_hmf, &rect);
	//}
	//pos = this->m_RButtonPointList.GetHeadPosition();
	//while (pos) {
	//	auto point = this->m_RButtonPointList.GetNext(pos);
	//	rect.SetRect(point.x - 50, point.y - 20, point.x + 50, point.y + 20);
	//	dc.PlayMetaFile(m_hmf, &rect);
	//}
	// --

	// 연습 문제 06
	POSITION pos = this->m_ButtonPointRect.GetHeadPosition();
	while (pos) {
		auto rect = this->m_ButtonPointRect.GetNext(pos);
		dc.PlayMetaFile(m_hmf, &rect);
	}
	// --

	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CRect rect(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	//dc.PlayMetaFile(m_hmf,&rect); // 기존

	// 연습문제 06
	//this->m_LButtonPointList.AddTail(point);
	//Invalidate();
	// --

	// 연습 문제 07
	this->m_ButtonPointRect.AddTail(rect);
	Invalidate();
	// --
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CRect rect(point.x - 50, point.y - 20, point.x + 50, point.y + 20);
	dc.PlayMetaFile(m_hmf, &rect);	//기존

	// 연습문제 06
	//this->m_RButtonPointList.AddTail(point);
	//Invalidate();
	// --

	// 연습 문제 07
	this->m_ButtonPointRect.AddTail(rect);
	Invalidate();
	// --

	CWnd::OnRButtonDown(nFlags, point);
}
