
// ModalDialog3View.cpp : implementation of the CModalDialog3View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ModalDialog3.h"
#endif

#include "ModalDialog3Doc.h"
#include "ModalDialog3View.h"

#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDialog3View

IMPLEMENT_DYNCREATE(CModalDialog3View, CView)

BEGIN_MESSAGE_MAP(CModalDialog3View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalDialog3View construction/destruction

CModalDialog3View::CModalDialog3View() noexcept
{
	// TODO: add construction code here

}

CModalDialog3View::~CModalDialog3View()
{
}

BOOL CModalDialog3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CModalDialog3View drawing

void CModalDialog3View::OnDraw(CDC* pDC)
{
	CModalDialog3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CFont font;
	CString fontname;

	if (m_font == 0) fontname = _T("굴림");
	else if (m_font == 1) fontname = _T("궁서");
	else if (m_font == 2) fontname = _T("바탕");
	//font.CreatePointFont(400, fontname);	// 기존
	font.CreatePointFont(m_size * 40, fontname);	// 연습 문제 06
	pDC->SelectObject(&font);
	//pDC->TextOut(10, 10, m_str);	// 기존
	pDC->TextOut(point.x, point.y, m_str);	// 연습 문제 07

}


// CModalDialog3View printing

BOOL CModalDialog3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CModalDialog3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CModalDialog3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CModalDialog3View diagnostics

#ifdef _DEBUG
void CModalDialog3View::AssertValid() const
{
	CView::AssertValid();
}

void CModalDialog3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModalDialog3Doc* CModalDialog3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDialog3Doc)));
	return (CModalDialog3Doc*)m_pDocument;
}
#endif //_DEBUG


// CModalDialog3View message handlers



void CModalDialog3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_font = m_font;
	dlg.m_size = m_size;	// 연습 문제 06
	// 연습 문제 07
	dlg.m_xPos = point.x;
	dlg.m_yPos = point.y;
	// --

	int result = dlg.DoModal();
	if (result == IDOK) {
		m_str = dlg.m_str;
		m_font = dlg.m_font;
		m_size = dlg.m_size;	// 연습 문제 06
		// 연습 문제 07
		this->point.x = dlg.m_xPos;
		this->point.y = dlg.m_yPos;
		// --
		Invalidate();
	}
	else if (result == IDC_CLEAR) {
		m_str = _T("");
		Invalidate();
	}


	CView::OnLButtonDown(nFlags, point);
}
