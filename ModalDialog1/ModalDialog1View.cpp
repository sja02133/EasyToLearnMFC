
// ModalDialog1View.cpp : implementation of the CModalDialog1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ModalDialog1.h"
#endif

#include "ModalDialog1Doc.h"
#include "ModalDialog1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDialog1View

IMPLEMENT_DYNCREATE(CModalDialog1View, CView)

BEGIN_MESSAGE_MAP(CModalDialog1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalDialog1View construction/destruction

CModalDialog1View::CModalDialog1View() noexcept
{
	// TODO: add construction code here

}

CModalDialog1View::~CModalDialog1View()
{
}

BOOL CModalDialog1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CModalDialog1View drawing

void CModalDialog1View::OnDraw(CDC* /*pDC*/)
{
	CModalDialog1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CModalDialog1View printing

BOOL CModalDialog1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CModalDialog1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CModalDialog1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CModalDialog1View diagnostics

#ifdef _DEBUG
void CModalDialog1View::AssertValid() const
{
	CView::AssertValid();
}

void CModalDialog1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModalDialog1Doc* CModalDialog1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDialog1Doc)));
	return (CModalDialog1Doc*)m_pDocument;
}
#endif //_DEBUG


// CModalDialog1View message handlers


void CModalDialog1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDialog dlg(IDD_DIALOG1);
	if (dlg.DoModal() == IDOK) {
		MessageBox(_T("확인 버튼 누름"));
	}
	else
		MessageBox(_T("취소 버튼 누름"));


	CView::OnLButtonDown(nFlags, point);
}
