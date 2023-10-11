
// SplitterView.cpp : implementation of the CSplitterView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Splitter.h"
#endif

#include "SplitterDoc.h"
#include "SplitterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSplitterView

IMPLEMENT_DYNCREATE(CSplitterView, CView)

BEGIN_MESSAGE_MAP(CSplitterView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_CHAR()
END_MESSAGE_MAP()

// CSplitterView construction/destruction

CSplitterView::CSplitterView() noexcept
{
	// TODO: add construction code here

}

CSplitterView::~CSplitterView()
{
}

BOOL CSplitterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSplitterView drawing

void CSplitterView::OnDraw(CDC* pDC)
{
	CSplitterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	// 기존
	//pDC->SelectStockObject(LTGRAY_BRUSH);
	//for (int i = 0; i < pDoc->m_points.GetSize(); i++) {
	//	pDC->Ellipse(pDoc->m_points[i].x - 20, pDoc->m_points[i].y - 20, pDoc->m_points[i].x + 20, pDoc->m_points[i].y + 20);
	//}
	// --

	// 연습 문제 14
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


// CSplitterView printing

BOOL CSplitterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSplitterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSplitterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSplitterView diagnostics

#ifdef _DEBUG
void CSplitterView::AssertValid() const
{
	CView::AssertValid();
}

void CSplitterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSplitterDoc* CSplitterView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitterDoc)));
	return (CSplitterDoc*)m_pDocument;
}
#endif //_DEBUG


// CSplitterView message handlers


void CSplitterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CSplitterDoc* pDoc = GetDocument();
	pDoc->m_points.Add(point);
	pDoc->UpdateAllViews(NULL);

	// 연습 문제 12
	//CSplitterWnd* split = GetParentSplitter(this, TRUE);
	//int row = 0, col = 0;
	//split->IsChildPane(this, &row, &col);

	//CString str = _T("");
	//str.Format(_T("(%d,%d)"), row, col);
	//MessageBox(str, _T("Pane Index"), MB_ICONINFORMATION | MB_OK);
	// --



	CView::OnLButtonDown(nFlags, point);
}


//void CSplitterView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: Add your message handler code here and/or call default
//	
//
//
//	CView::OnChar(nChar, nRepCnt, nFlags);
//}
