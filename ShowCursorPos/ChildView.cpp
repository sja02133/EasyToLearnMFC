
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "ShowCursorPos.h"
#include "ChildView.h"

#include "MainFrm.h"

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
	ON_WM_MOUSEMOVE()
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
	
	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CString str;
	str.Format(_T("(%4d,%4d)"), point.x, point.y);
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	//pMainFrame->m_wndStatusBar.SetPaneText(1, str);	// 기존
	pMainFrame->m_wndStatusBar.SetPaneText(2, str);	// 연습 문제 16

	// 연습 문제 17
	ClientToScreen(&point);
	str.Format(_T("(%4d,%4d)"), point.x, point.y);
	pMainFrame->m_wndStatusBar.SetPaneText(3, str);
	// --

	CWnd::OnMouseMove(nFlags, point);
}
