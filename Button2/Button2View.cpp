
// Button2View.cpp : implementation of the CButton2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Button2.h"
#endif

#include "Button2Doc.h"
#include "Button2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButton2View

IMPLEMENT_DYNCREATE(CButton2View, CFormView)

BEGIN_MESSAGE_MAP(CButton2View, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CButton2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CButton2View::OnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CButton2View::OnClickedCheck2)
END_MESSAGE_MAP()

// CButton2View construction/destruction

CButton2View::CButton2View() noexcept
	: CFormView(IDD_BUTTON2_FORM)
{
	// TODO: add construction code here

}

CButton2View::~CButton2View()
{
}

void CButton2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
}

BOOL CButton2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CButton2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_checkbox.SetCheck(1);
	// 기존
	//m_3state.SetCheck(2);
	//m_radio2.SetCheck(1);
	// --

	// 연습 문제 06
	m_3state.SetCheck(2);
	int checkSet = m_3state.GetCheck();
	if (checkSet == 0) {
		// 라디오 버튼 모두 비활성화
		m_radio1.EnableWindow(FALSE);
		m_radio2.EnableWindow(FALSE);
	}
	else if (checkSet == 1) {
		// 라디오 버튼 둘 중 1만 활성화
		m_radio1.EnableWindow(TRUE);
		m_radio2.EnableWindow(FALSE);
	}
	else {
		// 라디오 버튼 모두 활성화
		m_radio1.EnableWindow(TRUE);
		m_radio2.EnableWindow(TRUE);
	}
	// --
}


// CButton2View printing

BOOL CButton2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CButton2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CButton2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CButton2View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CButton2View diagnostics

#ifdef _DEBUG
void CButton2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CButton2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CButton2Doc* CButton2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButton2Doc)));
	return (CButton2Doc*)m_pDocument;
}
#endif //_DEBUG


// CButton2View message handlers


void CButton2View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	// 기존
	//int state_checkbox = m_checkbox.GetCheck();
	//int state_3state = m_3state.GetCheck();
	//int state_radio1 = m_radio1.GetCheck();
	//int state_radio2 = m_radio2.GetCheck();

	//CString str;
	//str.Format(_T("버튼 상태: %d, %d, %d, %d"), state_checkbox, state_3state, state_radio1, state_radio2);
	//MessageBox(str, _T("Button2 예제"), MB_ICONINFORMATION);
	// --

	// 연습 문제 07
	UINT checkStyle = m_button1.GetButtonStyle();
	switch (checkStyle) {
	case BS_DEFPUSHBUTTON:
		checkStyle = BS_CHECKBOX;
		break;
	case BS_CHECKBOX:
		checkStyle = BS_RADIOBUTTON;
		break;
	case BS_RADIOBUTTON:
		checkStyle = BS_DEFPUSHBUTTON;
		break;
	}

	m_button1.SetButtonStyle(checkStyle);
	Invalidate();
	// --

}

// 연습 문제 05
void CButton2View::OnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	BOOL checkSet = m_checkbox.GetCheck();
	if (checkSet) {
		m_button1.EnableWindow(TRUE);
	}
	else
		m_button1.EnableWindow(FALSE);
}
// --

// 연습 문제 06
void CButton2View::OnClickedCheck2()
{
	// TODO: Add your control notification handler code here
	int checkSet = m_3state.GetCheck();
	if (checkSet == 0) {
		// 라디오 버튼 모두 비활성화
		m_radio1.EnableWindow(FALSE);
		m_radio2.EnableWindow(FALSE);
	}
	else if (checkSet == 1) {
		// 라디오 버튼 둘 중 1만 활성화
		m_radio1.EnableWindow(TRUE);
		m_radio2.EnableWindow(FALSE);
	}
	else {
		// 라디오 버튼 모두 활성화
		m_radio1.EnableWindow(TRUE);
		m_radio2.EnableWindow(TRUE);
	}
}
// --

