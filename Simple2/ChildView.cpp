
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Simple2.h"
#include "ChildView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	CRect rect(5, 5, 205, 105);
	this->m_listCRect.AddTail(rect);

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CONTEXTMENU()
	ON_WM_SETCURSOR()
	ON_WM_SYSCOMMAND()

	ON_COMMAND(IDM_SYSCOMMAND_TRAY + 1, &CChildView::OnSyscommandTray)
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
	// 연습 문제 05
	// 가로 200, 세로 100
	if (this->m_listCRect.GetSize()) {
		POSITION pos = this->m_listCRect.GetHeadPosition();
		while(pos) {
			auto rect = this->m_listCRect.GetNext(pos);
			dc.Rectangle(&rect);
		}
	}

	

	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: Add your message handler code here
	// 연습 문제 02
	//CMenu* menu = AfxGetMainWnd()->GetMenu()->GetSubMenu(0);
	////ClientToScreen(&point);
	//menu->TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
	// --

	// 연습 문제 05
	CMenu menu;

	menu.CreatePopupMenu();

	CMenu DrawMenu;
	DrawMenu.CreateMenu();

	if (this->m_cBAdd) {
		menu.AppendMenu(MF_STRING, IDM_SYSCOMMAND_TRAY + 1, this->addStr);
	}
	else {
		menu.AppendMenu(MF_STRING, IDM_SYSCOMMAND_TRAY + 1, this->delStr);
	}

	//ClientToScreen(&point);
	menu.TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
	// --
}



LRESULT CChildView::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your implementation code here.

	switch (lParam) {
	case WM_LBUTTONDOWN:
		ShowWindow(SW_SHOW);
	}


	return LRESULT();
}


BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	if (nHitTest == HTCLIENT) {
		CPoint point;
		::GetCursorPos(&point);
		ScreenToClient(&point);
		CRgn rgn;
		if (this->m_listCRect.GetSize()) {
			POSITION pos = this->m_listCRect.GetHeadPosition();
			while (pos) {
				rgn.DeleteObject();
				auto rect = this->m_listCRect.GetNext(pos);
				rgn.CreateRectRgn(rect.left, rect.top, rect.right, rect.bottom);
				if (rgn.PtInRegion(point)) {
					::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
					this->m_bPtInRect = TRUE;
					break;
				}
				else {
					this->m_bPtInRect = FALSE;
					::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
				}
			}
		}
	}

	return TRUE;
	
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


void CChildView::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: Add your message handler code here and/or call default

	if (nID == IDM_SYSCOMMAND_TRAY + 1) {
		// ADD
		this->m_cBAdd = TRUE;
	}
	else if (nID == IDM_SYSCOMMAND_TRAY + 2) {
		// DEL
		this->m_cBAdd = FALSE;
	}

	CWnd::OnSysCommand(nID, lParam);
}


void CChildView::OnSyscommandTray()
{
	// TODO: Add your command handler code here
	CPoint point;
	::GetCursorPos(&point);
	if (this->m_cBAdd) {
		
	}
	else {
		
	}
}
// 연습 문제 05
void CChildView::add_rectangle(CPoint point)
{
	CClientDC dc(this);

	CRect rect(point.x, point.y, point.x + 200, point.y + 100);
	this->m_listCRect.AddTail(rect);
}

void CChildView::del_rectangle(CPoint point)
{
	CClientDC dc(this);
	if (this->m_listCRect.GetSize()) {
		POSITION pos = this->m_listCRect.GetHeadPosition();
		CRgn rgn;
		while (pos) {
			auto rect = this->m_listCRect.GetNext(pos);
			rgn.CreateRectRgn(rect.left, rect.top, rect.right, rect.bottom);
			if (rgn.PtInRegion(point)) {
				this->m_rectRgn = rect;
				
			}
			else
				rgn.DeleteObject();
		}
	}
}
// --

// 연습 문제 15
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//(CMainFrame*)AfxGetMainWnd()->OnMouseMove(nFlags, point);
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	pFrame->OnMouseMove(nFlags, point);
	CWnd::OnMouseMove(nFlags, point);
}
// --
