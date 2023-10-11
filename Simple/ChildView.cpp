
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Simple.h"
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
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	//cs.style &= ~WS_BORDER;

	cs.style |= WS_HSCROLL | WS_VSCROLL;	// �������� 03 (�� �߰�)


	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
	//	::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);	//�⺻
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_HAND), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);	//�������� 02


	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	

	// TODO: Add your message handler code here
	//dc.TextOut(50, 50, CString(_T("�ȳ��ϼ���")));	//����
	//dc.TextOut(50, 50, AfxGetApp()->m_pszAppName);	//�������� 12
	dc.TextOut(50, 50, AfxGetApp()->m_lpCmdLine);	//�������� 13

	//�������� 14
	CString str = _T("");
	AfxGetMainWnd()->GetWindowTextW(str);
	dc.TextOut(50, 50, str);
	// --


	// Do not call CWnd::OnPaint() for painting messages
}

