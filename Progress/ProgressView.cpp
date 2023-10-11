
// ProgressView.cpp : implementation of the CProgressView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Progress.h"
#endif

#include "ProgressDoc.h"
#include "ProgressView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgressView

IMPLEMENT_DYNCREATE(CProgressView, CFormView)

BEGIN_MESSAGE_MAP(CProgressView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CProgressView construction/destruction

CProgressView::CProgressView() noexcept
	: CFormView(IDD_PROGRESS_FORM)
{
	// TODO: add construction code here
	bNowProgress = FALSE;

}

CProgressView::~CProgressView()
{
}

void CProgressView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
}

BOOL CProgressView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CProgressView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CProgressView printing

BOOL CProgressView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProgressView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProgressView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CProgressView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CProgressView diagnostics

#ifdef _DEBUG
void CProgressView::AssertValid() const
{
	CFormView::AssertValid();
}

void CProgressView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CProgressDoc* CProgressView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProgressDoc)));
	return (CProgressDoc*)m_pDocument;
}
#endif //_DEBUG


// CProgressView message handlers


void CProgressView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (bNowProgress == FALSE) {
		bNowProgress = TRUE;
		m_progress.SetRange(0, 30);
		m_progress.SetPos(0);
		SetTimer(100, 50, NULL);
	}


	CFormView::OnLButtonDown(nFlags, point);
}


void CProgressView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 100) {
		if (m_progress.GetPos() < 30)
			m_progress.OffsetPos(1);
		else {
			KillTimer(nIDEvent);
			bNowProgress = FALSE;
		}
	}


	CFormView::OnTimer(nIDEvent);
}
