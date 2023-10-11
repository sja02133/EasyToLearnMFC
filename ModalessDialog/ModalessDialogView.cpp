
// ModalessDialogView.cpp : implementation of the CModalessDialogView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ModalessDialog.h"
#endif

#include "ModalessDialogDoc.h"
#include "ModalessDialogView.h"

#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalessDialogView

IMPLEMENT_DYNCREATE(CModalessDialogView, CView)

BEGIN_MESSAGE_MAP(CModalessDialogView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalessDialogView construction/destruction

CModalessDialogView::CModalessDialogView() noexcept
{
	// TODO: add construction code here
	m_pDlg = NULL;
	m_str = _T("");
	m_font = 0;

}

CModalessDialogView::~CModalessDialogView()
{
}

BOOL CModalessDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CModalessDialogView drawing

void CModalessDialogView::OnDraw(CDC* pDC)
{
	CModalessDialogDoc* pDoc = GetDocument();
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
	//font.CreatePointFont(m_size * 40, fontname);	// 연습 문제 09
	// 연습 문제 12
	if(font_FaceName.IsEmpty())
		font.CreatePointFont(m_size * 40, fontname);
	else
		font.CreatePointFont(m_size * 40, font_FaceName);
	// --


	// 연습 문제 11
	pDC->SetTextColor(this->m_textColor);
	this->m_textColor = pDC->GetTextColor();
	// --

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);

	
}


// CModalessDialogView printing

BOOL CModalessDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CModalessDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CModalessDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CModalessDialogView diagnostics

#ifdef _DEBUG
void CModalessDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CModalessDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModalessDialogDoc* CModalessDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalessDialogDoc)));
	return (CModalessDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CModalessDialogView message handlers


void CModalessDialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_pDlg != NULL)
		m_pDlg->SetFocus();
	else {
		m_pDlg = new CMyDialog();
		m_pDlg->m_pView = this;
		m_pDlg->m_str = m_str;
		m_pDlg->m_font = m_font;
		m_pDlg->Create(IDD_DIALOG1);

		// 연습 문제 08
		//CRect rect;
		//GetClientRect(&rect);
		//m_pDlg->SetWindowPos(&wndTopMost, 0, 0, rect.right, rect.bottom, SWP_SHOWWINDOW);
		// --

		// 연습 문제 09
		m_pDlg->m_size = m_size;
		// --

		m_pDlg->ShowWindow(SW_SHOW);
	}

	CView::OnLButtonDown(nFlags, point);
}
