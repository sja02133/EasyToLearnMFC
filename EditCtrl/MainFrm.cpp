
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "EditCtrl.h"

#include "MainFrm.h"

#include "EditCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_READONLY, &CMainFrame::OnViewReadonly)
	ON_UPDATE_COMMAND_UI(ID_VIEW_READONLY, &CMainFrame::OnUpdateViewReadonly)
	ON_COMMAND(ID_EDIT_UNDO, &CMainFrame::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CMainFrame::OnUpdateEditUndo)
	ON_COMMAND(ID_EDIT_CUT, &CMainFrame::OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CMainFrame::OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_COPY, &CMainFrame::OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &CMainFrame::OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CMainFrame::OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &CMainFrame::OnUpdateEditPaste)
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


// 연습 문제 11
void CMainFrame::OnViewReadonly()
{
	// TODO: Add your command handler code here
	CEditCtrlView* view = (CEditCtrlView*)GetActiveView();
	view->m_bReadOnly = !view->m_bReadOnly;
	view->Invalidate();
	
}

void CMainFrame::OnUpdateViewReadonly(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CEditCtrlView* view = (CEditCtrlView*)GetActiveView();
	pCmdUI->SetCheck(!view->m_bReadOnly);
}
// --


// 연습 문제 14
void CMainFrame::OnEditUndo()
{
	// TODO: Add your command handler code here
	CEditCtrlView* view = (CEditCtrlView*)GetActiveView();
	view->m_edit.Undo();
}


void CMainFrame::OnUpdateEditUndo(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	//CEditCtrlView* view = (CEditCtrlView*)GetActiveView();
	//pCmdUI->SetCheck(!view->m_bUndo);
}

void CMainFrame::OnEditCut()
{
	// TODO: Add your command handler code here
	CEditCtrlView* view = (CEditCtrlView*)GetActiveView();
	view->m_edit.Cut();
}


void CMainFrame::OnUpdateEditCut(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
}


void CMainFrame::OnEditCopy()
{
	// TODO: Add your command handler code here
	CEditCtrlView* view = (CEditCtrlView*)GetActiveView();
	view->m_edit.Copy();
}


void CMainFrame::OnUpdateEditCopy(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
}


void CMainFrame::OnEditPaste()
{
	// TODO: Add your command handler code here
	CEditCtrlView* view = (CEditCtrlView*)GetActiveView();
	view->m_edit.Paste();
}


void CMainFrame::OnUpdateEditPaste(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
}
// --