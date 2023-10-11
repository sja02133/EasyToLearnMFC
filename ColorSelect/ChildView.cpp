
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "ColorSelect.h"
#include "ChildView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(255, 0, 0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_COLOR_BLUE, &CChildView::OnColorBlue)
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CChildView::OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CChildView::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CChildView::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CChildView::OnUpdateColorGreen)
	ON_WM_CONTEXTMENU()
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
	
	CFont font;
	font.CreatePointFont(300, _T("궁서"));
	dc.SelectObject(&font);
	dc.SetTextColor(m_color);

	CRect rect;
	GetClientRect(&rect);
	CString str = _T("메뉴 테스트");
	dc.DrawText(str, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnColorBlue()
{
	// TODO: Add your command handler code here
	// 기존
	//m_color = RGB(0, 0, 255);
	//Invalidate();
	// --

	// 연습 문제 06
	//theApp.OnColorBlue1();
	// --

	// 연습 문제 07
	((CMainFrame*)AfxGetMainWnd())->OnColorBlue1();
	// --

	// 연습 문제 08
	this->m_selectRed = FALSE;
	this->m_selectBlue = TRUE;
	this->m_selectGreen = FALSE;
	// --

}


void CChildView::OnColorRed()
{
	// TODO: Add your command handler code here
	// 기존
	//m_color = RGB(255, 0, 0);
	//Invalidate();
	// --

	// 연습 문제 06
	//theApp.OnColorRed1();
	// --

	// 연습 문제 07
	((CMainFrame*)AfxGetMainWnd())->OnColorRed1();
	// --

	// 연습 문제 08
	this->m_selectRed = TRUE;
	this->m_selectBlue = FALSE;
	this->m_selectGreen = FALSE;
	// --
}


void CChildView::OnColorGreen()
{
	// TODO: Add your command handler code here
	//m_color = RGB(0, 255, 0);
	//Invalidate();

	// 연습 문제 06
	//theApp.OnColorGreen1();
	// --

	// 연습 문제 07
	((CMainFrame*)AfxGetMainWnd())->OnColorGreen1();
	// --

	// 연습 문제 08
	this->m_selectRed = FALSE;
	this->m_selectBlue = FALSE;
	this->m_selectGreen = TRUE;
	// --
}


void CChildView::OnUpdateColorRed(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	//pCmdUI->SetCheck(m_color == RGB(255, 0, 0));

	// 연습 문제 06
	//theApp.OnUpdateColorRed1(pCmdUI);
	// --

	// 연습 문제 07
	((CMainFrame*)AfxGetMainWnd())->OnUpdateColorRed1(pCmdUI);
	// --

	// 연습 문제 08
	pCmdUI->SetRadio(TRUE);
	if (this->m_selectRed) {
		pCmdUI->Enable(FALSE);
	}
	else {
		pCmdUI->Enable(TRUE);
	}
	// --
}


void CChildView::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	//pCmdUI->SetCheck(m_color == RGB(0, 0, 255));

	// 연습 문제 06
	//theApp.OnUpdateColorBlue1(pCmdUI);
	// --

	// 연습 문제 07
	((CMainFrame*)AfxGetMainWnd())->OnUpdateColorBlue1(pCmdUI);
	// --

	// 연습 문제 08
	pCmdUI->SetRadio(TRUE);
	if (this->m_selectBlue) {
		pCmdUI->Enable(FALSE);
	}
	else
		pCmdUI->Enable(TRUE);
	// --
}


void CChildView::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	//pCmdUI->SetCheck(m_color == RGB(0, 255, 0));

	// 연습 문제 06
	//theApp.OnUpdateColorGreen1(pCmdUI);
	// --

	// 연습 문제 07
	((CMainFrame*)AfxGetMainWnd())->OnUpdateColorGreen1(pCmdUI);
	// --

	// 연습 문제 08
	pCmdUI->SetRadio(TRUE);
	if (this->m_selectGreen) {
		pCmdUI->Enable(FALSE);
	}
	else
		pCmdUI->Enable(TRUE);
	// --
}


void CChildView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);

	CMenu* pMenu = menu.GetSubMenu(4);

	pMenu->TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
}

// 연습 문제 09
BOOL CChildView::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	int kkk = 0;
	switch (nID) {
	case ID_COLOR_RED:
		SendMessage(ID_COLOR_RED);
		break;
	case ID_COLOR_BLUE:
		SendMessage(ID_COLOR_BLUE);
		break;
	case ID_COLOR_GREEN:
		SendMessage(ID_COLOR_GREEN);
		break;
	}

	return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
// --
