
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "SDITest.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
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

	// 연습 문제 10
	WINDOWPLACEMENT place;
	CString set_str;
	set_str = theApp.GetProfileString(_T("String"), _T("WindowPlacement"));
	if (!set_str.IsEmpty()) {
		CString tempStr = _T("");
		::AfxExtractSubString(tempStr, set_str, 0, '|');
		place.flags = _ttoi64(tempStr);
		::AfxExtractSubString(tempStr, set_str, 1, '|');
		place.length = _ttoi64(tempStr);
		::AfxExtractSubString(tempStr, set_str, 2, '|');
		place.showCmd = _ttoi64(tempStr);
		::AfxExtractSubString(tempStr, set_str, 3, '|');
		place.ptMaxPosition.x = _ttoi(tempStr);
		::AfxExtractSubString(tempStr, set_str, 4, '|');
		place.ptMaxPosition.y = _ttoi(tempStr);
		::AfxExtractSubString(tempStr, set_str, 5, '|');
		place.ptMinPosition.x = _ttoi(tempStr);
		::AfxExtractSubString(tempStr, set_str, 6, '|');
		place.ptMinPosition.y = _ttoi(tempStr);
		::AfxExtractSubString(tempStr, set_str, 7, '|');
		place.rcNormalPosition.left = _ttoi(tempStr);
		::AfxExtractSubString(tempStr, set_str, 8, '|');
		place.rcNormalPosition.right = _ttoi(tempStr);
		::AfxExtractSubString(tempStr, set_str, 9, '|');
		place.rcNormalPosition.top = _ttoi(tempStr);
		::AfxExtractSubString(tempStr, set_str, 10, '|');
		place.rcNormalPosition.bottom = _ttoi(tempStr);

		::SetWindowPlacement(this->m_hWnd, &place);
	}
	// --

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

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


// 연습 문제 10
void CMainFrame::OnDestroy()
{
	CFrameWnd::OnDestroy();

	// TODO: Add your message handler code here

	WINDOWPLACEMENT place;

	::GetWindowPlacement(this->m_hWnd, &place);

	CString save_str;
	save_str.Format(_T("%u|%u|%u|%d|%d|%d|%d|%d|%d|%d|%d"), place.flags, place.length,place.showCmd,
		place.ptMaxPosition.x, place.ptMaxPosition.y, place.ptMinPosition.x, place.ptMinPosition.y,
		place.rcNormalPosition.left, place.rcNormalPosition.right, place.rcNormalPosition.top, place.rcNormalPosition.bottom);

	theApp.WriteProfileString(_T("String"), _T("WindowPlacement"), save_str);
}
// --
