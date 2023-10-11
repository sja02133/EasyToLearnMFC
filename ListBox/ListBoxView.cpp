
// ListBoxView.cpp : implementation of the CListBoxView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ListBox.h"
#endif

#include "ListBoxDoc.h"
#include "ListBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListBoxView

IMPLEMENT_DYNCREATE(CListBoxView, CFormView)

BEGIN_MESSAGE_MAP(CListBoxView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_RIGHT, &CListBoxView::OnBnClickedRight)
	ON_BN_CLICKED(IDC_LEFT, &CListBoxView::OnBnClickedLeft)
	ON_LBN_DBLCLK(IDC_LIST1, &CListBoxView::OnLbnDblclkList1)
	ON_LBN_DBLCLK(IDC_LIST2, &CListBoxView::OnLbnDblclkList2)
END_MESSAGE_MAP()

// CListBoxView construction/destruction

CListBoxView::CListBoxView() noexcept
	: CFormView(IDD_LISTBOX_FORM)
	//: CFormView(IDD_DIALOG1)
{
	// TODO: add construction code here

}

CListBoxView::~CListBoxView()
{
}

void CListBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	/*DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_RIGHT, m_right);
	DDX_Control(pDX, IDC_LEFT, m_left);*/
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_RIGHT, m_right);
	DDX_Control(pDX, IDC_LEFT, m_left);
}

BOOL CListBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CListBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();


	m_list1.AddString(_T("사과"));
	m_list1.AddString(_T("딸기"));
	m_list1.AddString(_T("파인애플"));
	m_list1.AddString(_T("복숭아"));

	

}


// CListBoxView printing

BOOL CListBoxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CListBoxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CListBoxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CListBoxView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CListBoxView diagnostics

#ifdef _DEBUG
void CListBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CListBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

//CListBoxDoc* CListBoxView::GetDocument() const // non-debug version is inline
//{
//	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListBoxDoc)));
//	return (CListBoxDoc*)m_pDocument;
//}
#endif //_DEBUG


// CListBoxView message handlers


void CListBoxView::OnBnClickedRight()
{
	// TODO: Add your control notification handler code here
	int nIndex = this->m_list1.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_list1.GetText(nIndex, str);
		m_list1.DeleteString(nIndex);
		m_list1.SetCurSel(nIndex);
		m_list2.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("왼쪽에서 오른쪽으로..."));
	}
}


void CListBoxView::OnBnClickedLeft()
{
	// TODO: Add your control notification handler code here
	int nIndex = this->m_list2.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_list2.GetText(nIndex, str);
		m_list2.DeleteString(nIndex);
		m_list2.SetCurSel(nIndex);
		m_list1.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("오른쪽에서 왼쪽으로..."));
	}
}

// 연습 문제 16
void CListBoxView::OnLbnDblclkList1()
{
	// TODO: Add your control notification handler code here
	int nIndex = this->m_list1.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_list1.GetText(nIndex, str);
		m_list1.DeleteString(nIndex);
		m_list1.SetCurSel(nIndex);
		m_list2.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("왼쪽에서 오른쪽으로..."));
	}
}


void CListBoxView::OnLbnDblclkList2()
{
	// TODO: Add your control notification handler code here
	int nIndex = this->m_list2.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_list2.GetText(nIndex, str);
		m_list2.DeleteString(nIndex);
		m_list2.SetCurSel(nIndex);
		m_list1.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("오른쪽에서 왼쪽으로..."));
	}
}
// --
