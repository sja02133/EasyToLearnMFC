
// ImageListView.cpp : implementation of the CImageListView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ImageList.h"
#endif

#include "ImageListDoc.h"
#include "ImageListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IDC_COMBOEX_1 1544

// CImageListView

IMPLEMENT_DYNCREATE(CImageListView, CView)

BEGIN_MESSAGE_MAP(CImageListView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CImageListView construction/destruction

CImageListView::CImageListView() noexcept
{
	// TODO: add construction code here

}

CImageListView::~CImageListView()
{
}

BOOL CImageListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CImageListView drawing

void CImageListView::OnDraw(CDC* pDC)
{
	CImageListDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	// 기존
	//CBrush brush(HS_DIAGCROSS, RGB(255, 0, 0));
	//pDC->SelectObject(&brush);
	//pDC->SelectStockObject(NULL_PEN);
	//CRect rect;
	//GetClientRect(&rect);
	//pDC->Rectangle(&rect);

	//m_il.SetBkColor(CLR_NONE);
	//m_il.Draw(pDC, 0, CPoint(50, 50), ILD_NORMAL);
	//m_il.Draw(pDC, 0, CPoint(150, 50), ILD_TRANSPARENT);
	//m_il.Draw(pDC, 0, CPoint(250, 50), ILD_BLEND25);
	//m_il.Draw(pDC, 0, CPoint(350, 50), ILD_BLEND50);
	//m_il.Draw(pDC, 0, CPoint(450, 50), ILD_MASK);

	//m_il.SetBkColor(RGB(0, 0, 0));
	//m_il.Draw(pDC, 1, CPoint(50, 150), ILD_MASK);
	//m_il.Draw(pDC, 1, CPoint(150, 150), ILD_TRANSPARENT);
	//m_il.Draw(pDC, 1, CPoint(250, 150), ILD_BLEND25);
	//m_il.Draw(pDC, 1, CPoint(350, 150), ILD_BLEND50);
	//m_il.Draw(pDC, 1, CPoint(450, 150), ILD_MASK);
	// --

	// 연습 문제 06
	CBrush brush(HS_DIAGCROSS, RGB(255, 0, 0));
	pDC->SelectObject(&brush);
	pDC->SelectStockObject(NULL_PEN);
	CRect rect;
	GetClientRect(&rect);
	pDC->Rectangle(&rect);

	int selectImage = m_combo.GetCurSel();

	m_il.SetBkColor(CLR_NONE);
	m_il.Draw(pDC, selectImage, CPoint(250, 50), ILD_NORMAL);
	m_il.Draw(pDC, selectImage, CPoint(350, 50), ILD_TRANSPARENT);
	m_il.Draw(pDC, selectImage, CPoint(450, 50), ILD_BLEND25);
	m_il.Draw(pDC, selectImage, CPoint(550, 50), ILD_BLEND50);
	m_il.Draw(pDC, selectImage, CPoint(650, 50), ILD_MASK);
	
	// --

}


// CImageListView printing

BOOL CImageListView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageListView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageListView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CImageListView diagnostics

#ifdef _DEBUG
void CImageListView::AssertValid() const
{
	CView::AssertValid();
}

void CImageListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageListDoc* CImageListView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageListDoc)));
	return (CImageListDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageListView message handlers


int CImageListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	m_il.Create(IDB_BITMAP1, 48, 1, RGB(255, 255, 255));	// 기존

	//m_il.Create(IDR_MAINFRAME, 16, 8, RGB(192, 192, 192));	// 연습 문제 01

	CRect rect(20,50,200,250);
	m_combo.Create(WS_CHILD | CBS_DROPDOWN, rect, this, IDC_COMBOEX_1);

	
	m_combo.SetImageList(&m_il);
	COMBOBOXEXITEM comboItem;
	comboItem.mask = CBEIF_TEXT | CBEIF_IMAGE | CBEIF_INDENT | CBEIF_SELECTEDIMAGE;
	for (int i = 0; i < m_il.GetImageCount(); i++) {
		comboItem.iItem = i;
		CString str;
		str.Format(_T("항목 %d"), i);
		comboItem.pszText = str.GetBuffer();

		comboItem.cchTextMax = str.GetLength();

		comboItem.iImage = i;
		comboItem.iIndent = i;
		comboItem.iSelectedImage = i;

		m_combo.InsertItem(&comboItem);
	}
	m_combo.SetCurSel(0);
	m_combo.ShowWindow(SW_SHOW);

	return 0;
}


void CImageListView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 연습 문제 01
	//if (this->selectNum == 8)
	//	this->selectNum = 0;

	//CClientDC dc(this);
	//CRect rect;
	//GetClientRect(&rect);

	//m_il.SetBkColor(RGB(192,192,192));
	//m_il.Draw(&dc, this->selectNum, point, ILD_NORMAL);
	//this->selectNum++;
	// --
	CView::OnLButtonDown(nFlags, point);
}
