
// TabCtrlView.cpp : implementation of the CTabCtrlView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TabCtrl.h"
#endif

#include "TabCtrlDoc.h"
#include "TabCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTabCtrlView

IMPLEMENT_DYNCREATE(CTabCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CTabCtrlView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CTabCtrlView::OnTcnSelchangeTab1)
	ON_COMMAND(ID_TAB_APPEND, &CTabCtrlView::OnTabAppend)
	ON_COMMAND(ID_TAB_DELETE, &CTabCtrlView::OnTabDelete)
END_MESSAGE_MAP()

// CTabCtrlView construction/destruction

CTabCtrlView::CTabCtrlView() noexcept
	: CFormView(IDD_TABCTRL_FORM)
{
	// TODO: add construction code here

}

CTabCtrlView::~CTabCtrlView()
{
}

void CTabCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_ANIMATE1, m_ani);
}

BOOL CTabCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTabCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();

	//CImageList m_il;	// 기존
	m_il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));
	m_tab.SetImageList(&m_il);
	m_il.Detach();

	m_tab.InsertItem(0, _T("Tab #0"), 0);
	m_tab.InsertItem(1, _T("Tab #1"), 0);
	m_tab.InsertItem(2, _T("Tab #2"), 0);

	m_tab.SetCurSel(1);
	m_edit.SetWindowText(_T("Tab #1 선택됨"));

	// 연습 문제 03
	CRect rect;
	m_ani.GetClientRect(&rect);
	//m_ani.Create(ACS_CENTER, rect, this, NULL);
	m_ani.ShowWindow(SW_HIDE);
	BOOL check = m_ani.Open(IDR_AVI1);
	m_tab.InsertItem(3, _T("AVI"), 0);
	// --
}


// CTabCtrlView printing

BOOL CTabCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTabCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTabCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTabCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CTabCtrlView diagnostics

#ifdef _DEBUG
void CTabCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTabCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTabCtrlDoc* CTabCtrlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTabCtrlDoc)));
	return (CTabCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CTabCtrlView message handlers


void CTabCtrlView::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	int nIndex = m_tab.GetCurSel();
	// 기존
	CString str;
	str.Format(_T("Tab #%d 선택됨"), nIndex);
	m_edit.SetWindowText(str);
	// --

	// 연습 문제 07
	// 임의적으로 nIndex가 3이면 animation control로 정의..
	if (nIndex == 3) {
		
		m_ani.ShowWindow(SW_SHOW);
		m_edit.ShowWindow(SW_HIDE);
		m_ani.Play(0,-1,-1);
	}
	else {
		m_ani.Stop();
		m_ani.ShowWindow(SW_HIDE);

		m_edit.ShowWindow(SW_SHOW);
		CString str;
		str.Format(_T("Tab #%d 선택됨"), nIndex);
		m_edit.SetWindowText(str);
	}
	// --
	*pResult = 0;
}

// 연습 문제 02
void CTabCtrlView::OnTabAppend()
{
	// TODO: Add your command handler code here
	int count = m_tab.GetItemCount();
	CString str;
	str.Format(_T("Tab #%d"), count);
	m_tab.InsertItem(count, str,0);
}


void CTabCtrlView::OnTabDelete()
{
	// TODO: Add your command handler code here
	int count = m_tab.GetItemCount();
	if (count > 0) {
		m_tab.DeleteItem(count - 1);
		m_tab.SetCurSel(count - 2);
		CString str;
		str.Format(_T("Tab #%d 선택됨"), count - 2);
		m_edit.SetWindowText(str);
	}
}
// --

