
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "Simple2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_MESSAGE(WM_TRAY_NOTIFICATION, CChildView::OnTrayNotification)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_POS, OnUpdatePos)
	ON_WM_SYSCOMMAND()
//	ON_WM_NOTIFYFORMAT()
ON_WM_MENUSELECT()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_POS,	// 연습 문제 15
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

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
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
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	// 기존
	//CMenu menuMain;
	//menuMain.CreateMenu();

	//CMenu menuPopup;
	//menuPopup.CreatePopupMenu();

	//menuPopup.AppendMenu(MF_STRING, 201, _T("빨간색(&R)"));
	//menuPopup.AppendMenu(MF_STRING, 202, _T("초록색(&G)"));
	//menuPopup.AppendMenu(MF_STRING, 203, _T("파란색(&B)"));

	//CMenu Popup1;
	//Popup1.CreatePopupMenu();
	//Popup1.AppendMenu(MF_STRING, 301, _T("1"));
	//Popup1.AppendMenu(MF_STRING, 302, _T("2"));
	//Popup1.AppendMenu(MF_STRING, 303, _T("3"));
	//Popup1.AppendMenu(MF_STRING, 304, _T("4"));

	//CMenu Popup2;
	//Popup2.CreatePopupMenu();
	//Popup2.AppendMenu(MF_STRING|MF_CHECKED, 201, _T("항목&1"));
	//Popup2.AppendMenu(MF_POPUP, (UINT)Popup1.Detach(), _T("항목&2"));
	//Popup2.AppendMenu(MF_STRING, 203, _T("항목&3"));
	//
	//CMenu* pTopLevel = GetMenu();
	//pTopLevel->AppendMenu(MF_POPUP, (UINT)Popup2.Detach(), _T("테스트(&T)"));

	////menuMain.AppendMenu(MF_POPUP, (UINT)menuPopup.Detach(), _T("색상(&C)"));

	////SetMenu(&menuMain);
	////menuMain.Detach();
	// --

	// 연습 문제 02
	//CMenu menuMain;
	//menuMain.CreateMenu();

	//CMenu menuPopup;
	//menuPopup.CreatePopupMenu();

	//menuPopup.AppendMenu(MF_STRING, 201, _T("빨간색(&R)"));
	//menuPopup.AppendMenu(MF_STRING, 202, _T("초록색(&G)"));
	//menuPopup.AppendMenu(MF_STRING, 203, _T("파란색(&B)"));

	//menuMain.AppendMenu(MF_POPUP, (UINT)menuPopup.Detach(), _T("색상(&C)"));

	//SetMenu(&menuMain);
	//menuMain.Detach();
	// --
	
	// 연습 문제 03
	//CMenu Popup1;
	//Popup1.CreatePopupMenu();
	//Popup1.AppendMenu(MF_STRING, 301, _T("1"));
	//Popup1.AppendMenu(MF_STRING, 302, _T("2"));
	//Popup1.AppendMenu(MF_STRING, 303, _T("3"));
	//Popup1.AppendMenu(MF_STRING, 304, _T("4"));

	//CMenu Popup2;
	//Popup2.CreatePopupMenu();
	//Popup2.AppendMenu(MF_STRING|MF_CHECKED, 201, _T("항목&1"));
	//Popup2.AppendMenu(MF_POPUP, (UINT)Popup1.Detach(), _T("항목&2"));
	//Popup2.AppendMenu(MF_STRING, 203, _T("항목&3"));


	//CMenu* pTopLevel = GetMenu();
	////pTopLevel->AppendMenu(MF_POPUP, (UINT)Popup2.Detach(), _T("테스트(&T)"));
	//
	//CString str = _T("&File");
	//int targetPos = 0;
	//for (int i = 0; i < pTopLevel->GetMenuItemCount(); i++) {
	//	CString tempStr = _T("");
	//	if (pTopLevel->GetMenuString(i, tempStr, MF_BYPOSITION) && (str == tempStr)) {
	//		targetPos = i;
	//		pTopLevel = GetMenu()->GetSubMenu(i);
	//	}
	//}
	//pTopLevel->InsertMenu(0, MF_BYPOSITION| MF_POPUP,(UINT)Popup2.Detach(), _T("테스트(&T)"));
	//
	//DrawMenuBar();
	// --

	// 연습 문제 04
	CMenu* sysMenu = GetSystemMenu(FALSE);

	int sysMenuCount = sysMenu->GetMenuItemCount();
	
	UINT nTrayMenuID = IDM_SYSCOMMAND_TRAY;

	sysMenu->InsertMenu(sysMenuCount - 1,MF_BYPOSITION | MF_STRING, nTrayMenuID, _T("[트레이 아이콘]"));

	NOTIFYICONDATA nid;
	::ZeroMemory(&nid, sizeof(nid));
	nid.cbSize = sizeof(nid);
	nid.uID = 0;
	nid.hWnd = GetSafeHwnd();

	nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	nid.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	lstrcpy(nid.szTip, _T("내 트레이"));
	nid.uCallbackMessage = WM_TRAY_NOTIFICATION;

	BOOL bRet = ::Shell_NotifyIcon(NIM_ADD, &nid);
	int kkk = 0;
	// --
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



void CMainFrame::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: Add your message handler code here and/or call default
	if (nID == IDM_SYSCOMMAND_TRAY) {
		ShowWindow(SW_HIDE);
	}

	CFrameWnd::OnSysCommand(nID, lParam);
}


//UINT CMainFrame::OnNotifyFormat(CWnd* pWnd, UINT nCommand)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	return CFrameWnd::OnNotifyFormat(pWnd, nCommand);
//}


void CMainFrame::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu)
{
	CFrameWnd::OnMenuSelect(nItemID, nFlags, hSysMenu);

	// TODO: Add your message handler code here
}

// 연습 문제 15
void CMainFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CString str;
	str.Format(_T("(%4d,%4d)"), point.x, point.y);
	this->m_wndStatusBar.SetPaneText(1, str);

	CFrameWnd::OnMouseMove(nFlags, point);
}

void CMainFrame::OnUpdatePos(CCmdUI* pCmdUI)
{
	// TODO: Add your implementation code here.

	pCmdUI->Enable();
}
// --