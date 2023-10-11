
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "ShowCaret.h"
#include "ChildView.h"

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
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_KEYDOWN()
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



void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CreateSolidCaret(20, 70);
	SetCaretPos(CPoint(50, 50));
	ShowCaret();
}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	HideCaret();
	::DestroyCaret();
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CPoint caretPoint = GetCaretPos();
	CRect rect;
	GetClientRect(&rect);
	int value = 20;

	if (value != 0) {
		switch (nChar) {
		case VK_DOWN:
			if (rect.bottom > caretPoint.y + value)
				SetCaretPos(CPoint(caretPoint.x, caretPoint.y + value));
			break;
		case VK_UP:
			if (rect.top < caretPoint.y - value)
				SetCaretPos(CPoint(caretPoint.x, caretPoint.y - value));
			break;
		case VK_LEFT:
			if (rect.left < caretPoint.x - value)
				SetCaretPos(CPoint(caretPoint.x - value, caretPoint.y));
			break;
		case VK_RIGHT:
			if (rect.right > caretPoint.x + value)
				SetCaretPos(CPoint(caretPoint.x + value, caretPoint.y));
			break;
		}
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
