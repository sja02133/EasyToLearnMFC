
// ModalDialog2View.cpp : implementation of the CModalDialog2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ModalDialog2.h"
#endif

#include "ModalDialog2Doc.h"
#include "ModalDialog2View.h"

#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDialog2View

IMPLEMENT_DYNCREATE(CModalDialog2View, CView)

BEGIN_MESSAGE_MAP(CModalDialog2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalDialog2View construction/destruction

CModalDialog2View::CModalDialog2View() noexcept
{
	// TODO: add construction code here

}

CModalDialog2View::~CModalDialog2View()
{
}

BOOL CModalDialog2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CModalDialog2View drawing

void CModalDialog2View::OnDraw(CDC* pDC)
{
	CModalDialog2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CFont font;
	CString fontname;

	if (m_font == 0) fontname = _T("굴림");
	else if (m_font == 1) fontname = _T("궁서");
	else if (m_font == 2) fontname = _T("바탕");
	//font.CreatePointFont(400, fontname);	//기존
	//font.CreatePointFont(m_size * 40, fontname);	// 연습 문제 03
	// 연습 문제 05
	font.CreateFont(m_size * 5, 0, 0, 0, this->checkBold ? FW_BOLD : FW_NORMAL,
		FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		fontname);	
	// --
	

	// 연습 문제 04
	COLORREF color;
	if (m_selectColor == 0) color = RGB(255, 0, 0);
	else if (m_selectColor == 1) color = RGB(0, 255, 0);
	else if (m_selectColor == 2) color = RGB(0, 0, 255);
	pDC->SetTextColor(color);
	// --

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);


}


// CModalDialog2View printing

BOOL CModalDialog2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CModalDialog2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CModalDialog2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CModalDialog2View diagnostics

#ifdef _DEBUG
void CModalDialog2View::AssertValid() const
{
	CView::AssertValid();
}

void CModalDialog2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModalDialog2Doc* CModalDialog2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDialog2Doc)));
	return (CModalDialog2Doc*)m_pDocument;
}
#endif //_DEBUG


// CModalDialog2View message handlers


void CModalDialog2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_font = m_font;
	dlg.m_size = m_size;	// 연습 문제 03
	dlg.m_selectColor = m_selectColor;	// 연습 문제 04
	dlg.checkBold = checkBold;	// 연습 문제 05

	int result = dlg.DoModal();
	if (result == IDOK) {
		m_str = dlg.m_str;
		m_font = dlg.m_font;
		m_size = dlg.m_size;	// 연습 문제 03
		m_selectColor = dlg.m_selectColor;	// 연습 문제 04
		checkBold = dlg.checkBold;	// 연습 문제 05
		Invalidate();
	}
	else if (result == IDC_CLEAR) {
		m_str = _T("");
		m_size = 10;
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}
