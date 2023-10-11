
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "DrawTexts.h"
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
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	
	// ����
	//dc.SetTextColor(RGB(255, 0, 0));
	//dc.SetBkColor(RGB(255, 255, 0));
	//dc.DrawText(CString("DrawText �Լ��� �����մϴ�. [1]"), &rect, 0);
	//dc.DrawText(CString("DrawText �Լ��� �����մϴ�. [2]"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//dc.SetTextAlign(TA_CENTER);
	//dc.SetTextColor(RGB(0, 0, 255));
	//dc.SetBkColor(RGB(0, 255, 0));
	//dc.TextOut(rect.right / 2, 3 * rect.bottom / 4, CString("TextOut �Լ��� �����մϴ�."));
	// --

	// ���� ���� 14
	//LOGFONT lf;
	//dc.GetCurrentFont()->GetLogFont(&lf);
	//CFont font;
	//font.CreatePointFont(MulDiv(lf.lfHeight,720,GetDeviceCaps(dc,LOGPIXELSY)),
	//	_T("���� ���"));
	//dc.SelectObject(&font);
	//dc.SetTextColor(RGB(255, 0, 0));
	//dc.SetBkColor(RGB(255, 255, 0));
	//dc.DrawText(CString("DrawText �Լ��� �����մϴ�. [1]"), &rect, 0);
	//font.DeleteObject();
	//font.CreatePointFont(MulDiv(lf.lfHeight, 720, GetDeviceCaps(dc, LOGPIXELSY)),
	//	_T("�ü�"));
	//dc.SelectObject(&font);
	//dc.DrawText(CString("DrawText �Լ��� �����մϴ�. [2]"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//dc.SetTextAlign(TA_CENTER);
	//dc.SetTextColor(RGB(0, 0, 255));
	//dc.SetBkColor(RGB(0, 255, 0));
	//font.DeleteObject();
	//font.CreatePointFont(MulDiv(lf.lfHeight, 720, GetDeviceCaps(dc, LOGPIXELSY)),
	//	_T("����ü"));
	//dc.SelectObject(&font);
	//dc.TextOut(rect.right / 2, 3 * rect.bottom / 4, CString("TextOut �Լ��� �����մϴ�."));
	//font.Detach();
	// --
	
	// ���� ���� 15
	LOGFONT lf;
	dc.GetCurrentFont()->GetLogFont(&lf);
	CFont font;
	int height = -::MulDiv(14, GetDeviceCaps(dc, LOGPIXELSY), 72);
	font.CreateFont(height,lf.lfWidth,lf.lfEscapement,lf.lfOrientation,lf.lfWeight,FALSE,FALSE,FALSE,DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_DONTCARE,_T("Arial"));
	dc.SelectObject(&font);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(255, 255, 0));
	dc.DrawText(CString("DrawText �Լ��� �����մϴ�. [1]"), &rect, 0);
	font.DeleteObject();
	height = -::MulDiv(16, GetDeviceCaps(dc, LOGPIXELSY), 72);
	font.CreateFont(height, lf.lfWidth, lf.lfEscapement, lf.lfOrientation, lf.lfWeight, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, _T("Arial"));
	dc.SelectObject(&font);
	dc.DrawText(CString("DrawText �Լ��� �����մϴ�. [2]"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	dc.SetTextAlign(TA_CENTER);
	dc.SetTextColor(RGB(0, 0, 255));
	dc.SetBkColor(RGB(0, 255, 0));
	font.DeleteObject();
	height = -::MulDiv(18, GetDeviceCaps(dc, LOGPIXELSY), 72);
	font.CreateFont(height, lf.lfWidth, lf.lfEscapement, lf.lfOrientation, lf.lfWeight, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, _T("Arial"));
	dc.SelectObject(&font);
	dc.TextOut(rect.right / 2, 3 * rect.bottom / 4, CString("TextOut �Լ��� �����մϴ�."));
	font.Detach();
	// --

	// Do not call CWnd::OnPaint() for painting messages
}

