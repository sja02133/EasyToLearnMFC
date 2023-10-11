
// ListCtrlTest1View.cpp : implementation of the CListCtrlTest1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ListCtrlTest1.h"
#endif

#include "ListCtrlTest1Doc.h"
#include "ListCtrlTest1View.h"

#define IDC_LIST1 100
CListCtrl m_list;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListCtrlTest1View

IMPLEMENT_DYNCREATE(CListCtrlTest1View, CListView)

BEGIN_MESSAGE_MAP(CListCtrlTest1View, CListView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CListCtrlTest1View construction/destruction

CListCtrlTest1View::CListCtrlTest1View() noexcept
{
	// TODO: add construction code here

}

CListCtrlTest1View::~CListCtrlTest1View()
{
}

BOOL CListCtrlTest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}


void CListCtrlTest1View::OnDraw(CDC* /*pDC*/)
{
	CListCtrlTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

}


void CListCtrlTest1View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}


// CListCtrlTest1View printing

BOOL CListCtrlTest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CListCtrlTest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CListCtrlTest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CListCtrlTest1View diagnostics

#ifdef _DEBUG
void CListCtrlTest1View::AssertValid() const
{
	CListView::AssertValid();
}

void CListCtrlTest1View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CListCtrlTest1Doc* CListCtrlTest1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListCtrlTest1Doc)));
	return (CListCtrlTest1Doc*)m_pDocument;
}
#endif //_DEBUG


// CListCtrlTest1View message handlers


int CListCtrlTest1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	
	
	
	//m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT, CRect(10, 10, 310, 110), this, IDC_LIST1);	// 기존
	
	// 연습 문제 01
	CRect rect;
	GetClientRect(&rect);
	m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT, rect, this, IDC_LIST1);
	// --
	CImageList ilLarge, ilSmall;
	ilLarge.Create(32, 32, ILC_COLOR4, 1, 1);
	ilSmall.Create(16, 16, ILC_COLOR4, 1, 1);
	ilLarge.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	ilSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON1));

	m_list.SetImageList(&ilLarge, LVSIL_NORMAL);
	m_list.SetImageList(&ilSmall, LVSIL_SMALL);
	ilLarge.Detach();
	ilSmall.Detach();

	m_list.InsertColumn(0, _T("이름"), LVCFMT_LEFT, 100, 0);
	m_list.InsertColumn(1, _T("성적"), LVCFMT_LEFT, 100, 1);
	m_list.InsertColumn(2, _T("학점"), LVCFMT_LEFT, 100, 2);

	m_list.InsertItem(0, _T("임현선"), 0);
	m_list.InsertItem(1, _T("김기태"), 0);
	m_list.InsertItem(2, _T("서유경"), 0);

	m_list.SetItemText(0, 1, _T("90"));
	m_list.SetItemText(0, 2, _T("A0"));
	m_list.SetItemText(1, 1, _T("95"));
	m_list.SetItemText(1, 2, _T("A+"));
	m_list.SetItemText(2, 1, _T("70"));
	m_list.SetItemText(2, 2, _T("B0"));

	return 0;
}

// 연습 문제 01
void CListCtrlTest1View::OnSize(UINT nType, int cx, int cy)
{
	CListView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CListCtrl* pList = &m_list;
	if (pList != NULL) {
		pList->SetWindowPos(this, 0, 0, cx, cy, SWP_NOZORDER | SWP_SHOWWINDOW);
		pList->MoveWindow(0, 0, cx, cy, TRUE);
	}
}
// --