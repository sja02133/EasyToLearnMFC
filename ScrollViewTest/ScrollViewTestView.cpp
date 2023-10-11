
// ScrollViewTestView.cpp : implementation of the CScrollViewTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ScrollViewTest.h"
#endif

#include "ScrollViewTestDoc.h"
#include "ScrollViewTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CScrollViewTestView

IMPLEMENT_DYNCREATE(CScrollViewTestView, CScrollView)

BEGIN_MESSAGE_MAP(CScrollViewTestView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CScrollViewTestView construction/destruction

CScrollViewTestView::CScrollViewTestView() noexcept
{
	// TODO: add construction code here

}

CScrollViewTestView::~CScrollViewTestView()
{
}

BOOL CScrollViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CScrollViewTestView drawing

void CScrollViewTestView::OnDraw(CDC* pDC)
{
	CScrollViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	// 기존
	//pDC->TextOut(20, 20, CString(_T("스크롤 뷰를 연습합니다.")));
	//pDC->Ellipse(1930, 1930, 1980, 1980);
	// --
	
	// 연습 문제 09
	BITMAP bmp;
	pDoc->bitmap.GetObject(sizeof(BITMAP), &bmp);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CBitmap* pOldBitmap = (CBitmap*)memDC.SelectObject(&pDoc->bitmap);

	pDC->BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 0, 0, SRCCOPY);
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	// --
}

void CScrollViewTestView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 2000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CScrollViewTestView printing

BOOL CScrollViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CScrollViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CScrollViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CScrollViewTestView diagnostics

#ifdef _DEBUG
void CScrollViewTestView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CScrollViewTestView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CScrollViewTestDoc* CScrollViewTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScrollViewTestDoc)));
	return (CScrollViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CScrollViewTestView message handlers


BOOL CScrollViewTestView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	//return TRUE;
	return CScrollView::OnEraseBkgnd(pDC);
}
