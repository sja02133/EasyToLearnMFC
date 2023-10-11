
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "ColorSelect.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_SYSCOMMAND()
	ON_COMMAND(ID_BUTTON_TURNONOFF, &CMainFrame::OnButtonTurnonoff)
	ON_COMMAND(ID_BUTTON_MINIMIZE, &CMainFrame::OnButtonMinimize)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_MINIMIZE, &CMainFrame::OnUpdateButtonMinimize)
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

	//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||	//기존
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||		// 연습 문제 14
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	// 기존
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	// --

	// 연습 문제 14
	m_wndToolBar.EnableDocking(CBRS_ALIGN_RIGHT);
	EnableDocking(CBRS_ALIGN_RIGHT);
	// --
	DockControlBar(&m_wndToolBar);

	CMenu menu1;
	menu1.CreateMenu();
	menu1.AppendMenu(MF_STRING, ID_COLOR_RED, _T("빨간색(&R)"));
	menu1.AppendMenu(MF_STRING, ID_COLOR_GREEN, _T("초록색(&G)"));
	menu1.AppendMenu(MF_STRING, ID_COLOR_BLUE, _T("파란색(&B)"));

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	pSysMenu->EnableMenuItem(SC_CLOSE, MF_GRAYED);
	pSysMenu->AppendMenu(MF_POPUP, (UINT)menu1.Detach(), _T("메뉴(&C)"));
	

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

void CMainFrame::OnColorBlue1()
{
	// TODO: Add your command handler code here

	CChildView& view = this->m_wndView;
	if (&view != nullptr) {
		view.m_color = RGB(0, 0, 255);
		view.Invalidate();
	}
}


void CMainFrame::OnUpdateColorBlue1(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CChildView& view = this->m_wndView;
	if (&view != nullptr) {
		pCmdUI->SetCheck(view.m_color == RGB(0, 0, 255));
	}
}


void CMainFrame::OnColorGreen1()
{
	// TODO: Add your command handler code here
	CChildView& view = this->m_wndView;
	if (&view != nullptr) {
		view.m_color = RGB(0, 255, 0);
		view.Invalidate();
	}
}


void CMainFrame::OnUpdateColorGreen1(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CChildView& view = this->m_wndView;
	if (&view != nullptr) {
		pCmdUI->SetCheck(view.m_color == RGB(0, 255, 0));
	}
}


void CMainFrame::OnColorRed1()
{
	// TODO: Add your command handler code here
	CChildView& view = this->m_wndView;
	if (&view != nullptr) {
		view.m_color = RGB(255, 0, 0);
		view.Invalidate();
	}
}


void CMainFrame::OnUpdateColorRed1(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CChildView& view = this->m_wndView;
	if (&view != nullptr) {
		pCmdUI->SetCheck(view.m_color == RGB(255, 0, 0));
	}
}

void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: Add your message handler code here and/or call default

	switch (nID) {
	case (WM_USER + 1):
	{
		
	}
		break;
	// 연습 문제 09
	case ID_COLOR_RED:
	case ID_COLOR_BLUE:
	case ID_COLOR_GREEN:
		m_wndView.OnCmdMsg(nID, 0, NULL, NULL);
		break;
	// --
	// 연습 문제 10
	case SC_MINIMIZE:
		this->ShowWindow(SC_MINIMIZE);
		break;
	// --
	}

	CFrameWnd::OnSysCommand(nID, lParam);
}

// 연습 문제 10
void CMainFrame::OnButtonTurnonoff()
{
	// TODO: Add your command handler code here
	CMenu* menu = GetMenu();
	CMenu* selectMenu;
	CString str1 = _T("전원 끄기");
	CString str2 = _T("전원 켜기");
	CString tempStr = _T("");
	BOOL checkStr = TRUE;	// TRUE : 전원 끄기, FALSE : 전원 켜기

	int pos = FindMenuItem(menu, str1);
	if (pos == -1) {
		checkStr = FALSE;
		pos = FindMenuItem(menu, str2);
		if (pos == -1)	//error
			return;
	}

	UINT id = menu->GetMenuItemID(pos);

	menu->ModifyMenu(pos, MF_BYPOSITION, id, checkStr ? str2 : str1);

	CDC* pDC = m_wndView.GetDC();
	CRect rect;
	GetClientRect(&rect);
	CBrush brush;
	switch (checkStr) {
	case TRUE:
		pDC->FillSolidRect(rect, RGB(220, 220, 220));
		break;
	case FALSE:
		pDC->FillSolidRect(rect, RGB(255, 255, 255));
		break;
	}
}

int CMainFrame::FindMenuItem(CMenu* Menu, LPCTSTR MenuString)
{
	int count = Menu->GetMenuItemCount();
	for (int i = 0; i < count; i++)
	{
		CString str;
		if (Menu->GetMenuString(i, str, MF_BYPOSITION) && (StrCmp(str, MenuString) == 0))
			return i;
	}
	return -1;
}
// --


// 연습 문제 13
void CMainFrame::OnButtonMinimize()
{
	// TODO: Add your command handler code here
	this->ShowWindow(SW_MINIMIZE);
}
// --

void CMainFrame::OnUpdateButtonMinimize(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
}
