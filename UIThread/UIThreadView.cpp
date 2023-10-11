
// UIThreadView.cpp : implementation of the CUIThreadView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "UIThread.h"
#endif

#include "UIThreadDoc.h"
#include "UIThreadView.h"

#include "CMyThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUIThreadView

IMPLEMENT_DYNCREATE(CUIThreadView, CView)

BEGIN_MESSAGE_MAP(CUIThreadView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_OPTION_ALWAYSUP, &CUIThreadView::OnOptionAlwaysup)
END_MESSAGE_MAP()

// CUIThreadView construction/destruction

CUIThreadView::CUIThreadView() noexcept
{
	// TODO: add construction code here

}

CUIThreadView::~CUIThreadView()
{
}

BOOL CUIThreadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CUIThreadView drawing

void CUIThreadView::OnDraw(CDC* /*pDC*/)
{
	CUIThreadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CUIThreadView printing

BOOL CUIThreadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUIThreadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUIThreadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CUIThreadView diagnostics

#ifdef _DEBUG
void CUIThreadView::AssertValid() const
{
	CView::AssertValid();
}

void CUIThreadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUIThreadDoc* CUIThreadView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUIThreadDoc)));
	return (CUIThreadDoc*)m_pDocument;
}
#endif //_DEBUG


// CUIThreadView message handlers


void CUIThreadView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	AfxBeginThread(RUNTIME_CLASS(CMyThread));

	CView::OnLButtonDown(nFlags, point);
}


void CUIThreadView::OnOptionAlwaysup()
{
	// TODO: Add your command handler code here

}
