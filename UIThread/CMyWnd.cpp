// CMyWnd.cpp : implementation file
//

#include "pch.h"
#include "UIThread.h"
#include "CMyWnd.h"

#include "resource.h"

// CMyWnd

IMPLEMENT_DYNCREATE(CMyWnd, CFrameWnd)

CMyWnd::CMyWnd()
{
	Create(NULL, _T("UI 스레드로 생성한 윈도우"));
	
	// 연습 문제 04
	CMenu pMenu;
	pMenu.LoadMenu(IDR_MENU_THREAD_CWND);
	this->SetMenu(&pMenu);
	pMenu.Detach();
	// --
}

CMyWnd::~CMyWnd()
{
}


BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_WM_CHAR()
	ON_WM_PAINT()
	ON_COMMAND(ID_OPTION_UP, &CMyWnd::OnOptionUp)
	ON_UPDATE_COMMAND_UI(ID_OPTION_UP, &CMyWnd::OnUpdateOptionUp)
	ON_COMMAND(ID_SAVE, &CMyWnd::OnSave)
END_MESSAGE_MAP()


// CMyWnd message handlers


void CMyWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	if (nChar == _T('\b')) {
		if (m_str.GetSize() > 0)
			m_str.RemoveAt(m_str.GetSize() - 1);
	}
	else {
		m_str.Add(nChar);
	}

	Invalidate();

	CFrameWnd::OnChar(nChar, nRepCnt, nFlags);
}


void CMyWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CFrameWnd::OnPaint() for painting messages

	CFont font;
	font.CreatePointFont(150, _T("궁서"));
	dc.SelectObject(&font);

	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);
}

// 연습 문제 04
void CMyWnd::OnOptionUp()
{
	// TODO: Add your command handler code here
	if (this->topNoTop == HWND_NOTOPMOST)
		this->topNoTop = HWND_TOPMOST;
	else
		this->topNoTop = HWND_NOTOPMOST;
	::SetWindowPos(GetSafeHwnd(), this->topNoTop, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	check_menu = !check_menu;
}


void CMyWnd::OnUpdateOptionUp(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(check_menu);
}
// --

// 연습 문제 05
void CMyWnd::OnSave()
{
	// TODO: Add your command handler code here
	CFileDialog dlg(FALSE,_T(".txt"),_T("SAVE"), OFN_HIDEREADONLY,_T(".txt"),this);
	if (dlg.DoModal() == IDOK) {
		CFile file;
		USES_CONVERSION;
		char* temp = W2A(m_str.GetData());
		file.Open(dlg.GetFileName(), CFile::modeCreate | CFile::modeWrite, NULL);
		file.Write(temp, m_str.GetSize());
	}
}
// --