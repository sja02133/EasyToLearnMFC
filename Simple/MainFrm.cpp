
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "Simple.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

//chapter 03 연습문제 01
// 윈도우 타이틀(리소스 뷰 -> String Table -> String Table -> IDR_MAINFRAME 의 value를 "간단한 MFC 프로그램"으로 변경


IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW,
	CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, nullptr))	
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style |= WS_POPUPWINDOW | WS_CAPTION | WS_OVERLAPPEDWINDOW;	//연습문제 08

	//cs.style &= ~WS_SYSMENU;	//연습문제 04
	cs.style &= ~WS_MINIMIZEBOX & ~WS_MAXIMIZEBOX;	//연습문제 05

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;

	//cs.dwExStyle |= WS_EX_TOPMOST;

	cs.lpszClass = AfxRegisterWndClass(0);

	//연습문제 06 
	cs.x = 100;
	cs.y = 200;
	// --

	//연습문제 07
	cs.cx = 1024;
	cs.cy = 768;
	// --

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


void CMainFrame::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CRect rect;
	::GetWindowRect(m_hWnd, &rect);
	//연습 문제 17, 크기, 위치 저장
	this->size.x = rect.Size().cx;
	this->size.y = rect.Size().cy;
	this->position.x = rect.left;
	this->position.y = rect.bottom;
	// --
	CFrameWnd::OnClose();
}


void CMainFrame::OnDestroy()
{
	CFrameWnd::OnDestroy();

	// TODO: Add your message handler code here
	int kkk = 0;
}
