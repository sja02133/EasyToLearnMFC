
// SubclassView.cpp : implementation of the CSubclassView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Subclass.h"
#endif

#include "SubclassDoc.h"
#include "SubclassView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSubclassView

IMPLEMENT_DYNCREATE(CSubclassView, CFormView)

BEGIN_MESSAGE_MAP(CSubclassView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_CHECK_NUMBERONLY, &CSubclassView::OnBnClickedCheckNumberonly)
	ON_EN_CHANGE(IDC_EDIT2, &CSubclassView::OnEnChangeEdit2)
END_MESSAGE_MAP()

// CSubclassView construction/destruction

CSubclassView::CSubclassView() noexcept
	: CFormView(IDD_SUBCLASS_FORM)
{
	// TODO: add construction code here

}

CSubclassView::~CSubclassView()
{
}

void CSubclassView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_CHECK_NUMBERONLY, m_checkBox);
}

BOOL CSubclassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSubclassView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//m_edit2.SubclassDlgItem(IDC_EDIT2, this);	//기존
	// 추가 설명 : m_edit1 같은 경우는 이미 CMyEdit 클래스 변수로 만들었기에 해당 동작대로 작동하는 것이 정상이다.
	// 허나, m_edit2는 DDX_Control() 함수로 연결 시키지 않은 컨트롤 변수이므로 SubclassDlgItem() 함수를 사용하여 이 것도 연결 시켜줘야 한다.
	// SubclassDlgItem() 함수 인자에 대한 설명은 다음과 같다..
	// 첫번째 인자 : 연결 시킬 Resource ID를 입력
	// 두번째 인자 : 연결할 창의 핸들
}


// CSubclassView printing

BOOL CSubclassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSubclassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSubclassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSubclassView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CSubclassView diagnostics

#ifdef _DEBUG
void CSubclassView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSubclassView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSubclassDoc* CSubclassView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSubclassDoc)));
	return (CSubclassDoc*)m_pDocument;
}
#endif //_DEBUG


// CSubclassView message handlers

// 연습 문제 20
void CSubclassView::OnBnClickedCheckNumberonly()
{
	// TODO: Add your control notification handler code here
	this->m_bCheckBox = !this->m_bCheckBox;
	this->m_checkBox.SetCheck(this->m_bCheckBox);
	
	::SetWindowText(m_edit2.m_hWnd,_T(""));

	if (this->m_checkBox.GetCheck())
		m_edit2.SubclassDlgItem(IDC_EDIT2, this);
	else
		m_edit2.UnsubclassWindow();
}
// --

void CSubclassView::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
