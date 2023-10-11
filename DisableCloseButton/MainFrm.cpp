
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "DisableCloseButton.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCMOUSEHOVER()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCLBUTTONDBLCLK()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

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
	if (!m_wndView.Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, nullptr))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
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



void CMainFrame::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (nHitTest == HTCLOSE) {
		MessageBox(_T("여기를 눌러도 종료할 수 없습니다."), _T("테스트"));
	}
	else
		CFrameWnd::OnNcLButtonDown(nHitTest, point);
}


void CMainFrame::OnNcMouseHover(UINT nFlags, CPoint point)
{
	// This feature requires Windows 2000 or greater.
	// The symbols _WIN32_WINNT and WINVER must be >= 0x0500.
	// TODO: Add your message handler code here and/or call default

	if (nFlags == HTCLOSE) {
		int kkk = 0;
	}

	CFrameWnd::OnNcMouseHover(nFlags, point);
}


void CMainFrame::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// 연습 문제 10
	if (nHitTest == HTCLOSE) {
		::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_NO));
	}
	// --

	CFrameWnd::OnNcMouseMove(nHitTest, point);
}


void CMainFrame::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 연습 문제 11
	//::ShowWindow(this->m_hWnd,SW_SHOWMINIMIZED );
	// --

	// 연습 문제 12
	int result =  MessageBox(_T("여기를 눌러도 종료할 수 없습니다."), _T("테스트"),MB_YESNO);
	int ddd = 0;
	switch (result)
	{
	case IDYES:
		::ShowWindow(this->m_hWnd,SW_SHOWMAXIMIZED);
		break;
	case IDNO:
		break;
	}
	return;
	// --
	CFrameWnd::OnNcLButtonDblClk(nHitTest, point);
}
