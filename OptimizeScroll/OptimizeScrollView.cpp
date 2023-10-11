
// OptimizeScrollView.cpp : implementation of the COptimizeScrollView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OptimizeScroll.h"
#endif

#include "OptimizeScrollDoc.h"
#include "OptimizeScrollView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COptimizeScrollView

IMPLEMENT_DYNCREATE(COptimizeScrollView, CScrollView)

BEGIN_MESSAGE_MAP(COptimizeScrollView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// COptimizeScrollView construction/destruction

COptimizeScrollView::COptimizeScrollView() noexcept
{
	// TODO: add construction code here

}

COptimizeScrollView::~COptimizeScrollView()
{
}

BOOL COptimizeScrollView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// COptimizeScrollView drawing

void COptimizeScrollView::OnDraw(CDC* pDC)
{
	COptimizeScrollDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rect;
	
	// 연습 문제 10
	BITMAP bmp;
	pDoc->bitmap.GetObject(sizeof(BITMAP), &bmp);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CBitmap* pOldBitmap = (CBitmap*)memDC.SelectObject(&pDoc->bitmap);

	pDC->BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 0, 0, SRCCOPY);
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	// --

	pDC->GetClipBox(&rect);
	rect.InflateRect(100, 100, 100, 100);

	CString str;
	for (int x = 0; x < 4000; x+=100) {
		for (int y = 0; y < 4000; y+=100) {
			if (!rect.PtInRect(CPoint(x, y)))
				continue;

			// 기존
			//MyDraw(pDC, x + 50, y + 50);
			// --



			str.Format(_T("(%d, %d)"), x + 50, y + 50);
			pDC->SetBkMode(TRANSPARENT);
			pDC->DrawText(str, CRect(x, y, x + 100, y + 100), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
	}

}

void COptimizeScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	/*
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
	*/
}


// COptimizeScrollView printing

BOOL COptimizeScrollView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COptimizeScrollView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COptimizeScrollView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// COptimizeScrollView diagnostics

#ifdef _DEBUG
void COptimizeScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void COptimizeScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

COptimizeScrollDoc* COptimizeScrollView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COptimizeScrollDoc)));
	return (COptimizeScrollDoc*)m_pDocument;
}
#endif //_DEBUG


// COptimizeScrollView message handlers


void COptimizeScrollView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CSize sizeTotal(4000, 4000);
	CSize sizePage(cx - 50, cy - 50);
	CSize sizeLine(50, 50);
	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
}


void COptimizeScrollView::MyDraw(CDC* pDC, int x, int y)
{
	// TODO: Add your implementation code here.
	CPen pen(PS_SOLID, 1, RGB(x % 256, y % 256, (x + y) % 128));
	pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);

	for (int i = 50; i > 0; i--) {
		pDC->Rectangle(x - i, y - i, x + i, y + i);
		pDC->Rectangle(x - i, y - i, x + i, y + i);
	}
}


BOOL COptimizeScrollView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return CScrollView::OnEraseBkgnd(pDC);
	return TRUE;

}
