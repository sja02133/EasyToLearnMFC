
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "InputCharacter.h"
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
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
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
	
	int kk = m_str.GetSize();
	TRACE("SIZE : %d\n", kk);

	// TODO: Add your message handler code here
	CFont font;
	font.CreatePointFont(150, _T("궁서"));
	dc.SelectObject(&font);

	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);

	// Do not call CWnd::OnPaint() for painting messages
}

void CChildView::setCaretXYPos() {
	CPoint point;
	if (delCheck == TRUE) {
		delCheck = FALSE;
		point.x = (this->caretPosX + 1) * 13;
	}
	else if (this->caretPosY > 0) {
		point.x = 0;
		if (this->before_caretPosX != this->caretPosX) {
			// 엔터 직후 추가적인 입력 발생
			point.x = (this->caretPosX- this->before_caretPosX) * 13;
		}
	}
	else {
		point.x = this->caretPosX * 13;
		if (this->m_listTabPos.GetSize()) {
			point.x -= (this->m_listTabPos.GetSize() * 20);
		}
	}
	point.y = this->caretPosY * 25;
	SetCaretPos(point);
}

void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	// 기존
	//if (nChar == _T('\b')) {
	//	if (m_str.GetSize() > 0)
	//		m_str.RemoveAt(m_str.GetSize() - 1);
	//}
	//else
	//	m_str.Add(nChar);
	// --

	// 연습 문제 23
	//if (nChar == _T('\b')) {
	//	if (m_str.GetSize() > 0) {
	//		if (this->m_listTabPos.GetSize()) {
	//			POSITION pos = this->m_listTabPos.GetTailPosition();
	//			auto tabPos = this->m_listTabPos.GetPrev(pos);
	//			if (tabPos == m_str.GetSize()) {
	//				for(int i = 0;i<4;i++) m_str.RemoveAt(m_str.GetSize() - 1);

	//				this->m_listTabPos.RemoveTail();
	//			}
	//			else
	//				m_str.RemoveAt(m_str.GetSize() - 1);
	//		}
	//		else {
	//			m_str.RemoveAt(m_str.GetSize() - 1);
	//		}
	//	}
	//}
	//else if (nChar == _T('\t')) {
	//	for (int i = 0; i < 4; i++)
	//		m_str.Add(_T(' '));
	//	this->m_listTabPos.AddTail(m_str.GetSize());
	//}
	//else {
	//	m_str.Add(nChar);
	//}
	// --

	// 연습 문제 24
	if (nChar == _T('\b')) {
		if (m_str.GetSize() > 0) {
			if (this->m_listTabPos.GetSize()) {
				POSITION pos = this->m_listTabPos.GetTailPosition();
				auto tabPos = this->m_listTabPos.GetPrev(pos);
				if (tabPos == m_str.GetSize()) {
					for (int i = 0; i < 4; i++) m_str.RemoveAt(m_str.GetSize() - 1);
					this->m_listTabPos.RemoveTail();
					this->caretPosX -= 4;
				}
				else {
					if (m_str.GetAt(m_str.GetSize() - 1) == '\r\n') {
						caretPosY--;
					}
					else if (caretPosX != 0)
						caretPosX--;

					m_str.RemoveAt(m_str.GetSize() - 1);
					

				}
			}
			else {
				TRACE("DEL : %c\n", m_str.GetAt(m_str.GetSize() - 1));
				if (this->before_caretPosX == this->caretPosX) {
					caretPosY--;
					this->delCheck = TRUE;
				}
				if (m_str.GetAt(m_str.GetSize() - 1) == '\r\n') {
					this->m_listEnterPos.RemoveTail();
					caretPosY--;
				}
				else if (caretPosX != 0)
					caretPosX--;
				m_str.RemoveAt(m_str.GetSize() - 1);
			}
		}
	}
	else if (nChar == _T('\t')) {
		for (int i = 0; i < 4; i++)
			m_str.Add(_T(' '));
		this->m_listTabPos.AddTail(m_str.GetSize());
		caretPosX += 4;
	}
	else if (nChar == _T('\r\n')) {
		m_str.Add(nChar);
		this->m_listEnterPos.AddTail(m_str.GetSize());
		caretPosY++;
		this->before_caretPosX = this->caretPosX;
	}
	else {
		m_str.Add(nChar);
		caretPosX++;
	}

	setCaretXYPos();

	// --
	Invalidate();

	CWnd::OnChar(nChar, nRepCnt, nFlags);
}


void CChildView::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);

	// TODO: Add your message handler code here
	CreateSolidCaret(5, 25);
	SetCaretPos(CPoint(0, 0));
	ShowCaret();

}


void CChildView::OnKillFocus(CWnd* pNewWnd)
{
	CWnd::OnKillFocus(pNewWnd);

	// TODO: Add your message handler code here
	HideCaret();
	::DestroyCaret();
}
