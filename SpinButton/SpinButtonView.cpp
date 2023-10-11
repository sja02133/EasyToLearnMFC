
// SpinButtonView.cpp : implementation of the CSpinButtonView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SpinButton.h"
#endif

#include "SpinButtonDoc.h"
#include "SpinButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSpinButtonView

IMPLEMENT_DYNCREATE(CSpinButtonView, CFormView)

BEGIN_MESSAGE_MAP(CSpinButtonView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

// CSpinButtonView construction/destruction

CSpinButtonView::CSpinButtonView() noexcept
	: CFormView(IDD_SPINBUTTON_FORM)
{
	// TODO: add construction code here

}

CSpinButtonView::~CSpinButtonView()
{
}

void CSpinButtonView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_spin);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_SPIN2, m_spin2);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}

BOOL CSpinButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSpinButtonView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_spin.SetRange(0, 100);
	m_spin.SetPos(0);

	// 연습 문제 04
	m_spin2.SetRange(1, 10);
	m_spin2.SetPos(1);
	// --
}


// CSpinButtonView printing

BOOL CSpinButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSpinButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSpinButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSpinButtonView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CSpinButtonView diagnostics

#ifdef _DEBUG
void CSpinButtonView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSpinButtonView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSpinButtonDoc* CSpinButtonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSpinButtonDoc)));
	return (CSpinButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CSpinButtonView message handlers


void CSpinButtonView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	if (pScrollBar->GetSafeHwnd() == m_spin.GetSafeHwnd()) {
		// 기존
		//CString str;
		//str.Format(_T("%d"), nPos);
		//AfxGetMainWnd()->SetWindowText(str);
		// --

		// 연습 문제 03
		//int redValue = GetRValue(this->m_color);
		if(255 - (nPos * 3) < 0)
			this->m_color = RGB(0, 0, 0);
		else
			this->m_color = RGB(255 - (nPos * 3), 0, 0);
		int redValue = GetRValue(this->m_color);
		CString str;
		str.Format(_T("%d"), redValue);
		m_edit.SetWindowText(str);
		Invalidate();
		// --
		return;
	}
	else if (pScrollBar->GetSafeHwnd() == m_spin2.GetSafeHwnd()) {
		// 연습 문제 04
		CString str;
		str.Format(_T("%d"), this->m_comboValue * nPos);
		m_combo.SetWindowText(str);
		Invalidate();
		return;
		// --
	}


	CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CSpinButtonView::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class

	// 연습 문제 03
	CRect rect;
	GetClientRect(&rect);

	pDC->FillSolidRect(rect.right / 2, rect.bottom / 4, 100, 100, this->m_color);
	// --

}
