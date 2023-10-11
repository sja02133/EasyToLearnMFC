
// ListViewTestView.cpp : implementation of the CListViewTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ListViewTest.h"
#endif

#include "ListViewTestDoc.h"
#include "ListViewTestView.h"

// 연습 문제 04
#include "CAddDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListViewTestView

IMPLEMENT_DYNCREATE(CListViewTestView, CListView)

BEGIN_MESSAGE_MAP(CListViewTestView, CListView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
	ON_COMMAND(ID_VIEW_LARGEICON, &CListViewTestView::OnViewLargeicon)
	ON_COMMAND(ID_VIEW_SMALLICON, &CListViewTestView::OnViewSmallicon)
	ON_COMMAND(ID_VIEW_LIST, &CListViewTestView::OnViewList)
	ON_COMMAND(ID_VIEW_DETAILS, &CListViewTestView::OnViewDetails)
	ON_COMMAND(ID_LIST_DELETE, &CListViewTestView::OnListDelete)
	ON_COMMAND(ID_LIST_APPEND, &CListViewTestView::OnListAppend)
END_MESSAGE_MAP()

// CListViewTestView construction/destruction

CListViewTestView::CListViewTestView() noexcept
{
	// TODO: add construction code here

}

CListViewTestView::~CListViewTestView()
{
}

BOOL CListViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style &= ~LVS_TYPEMASK;
	cs.style |= LVS_REPORT;
	return CListView::PreCreateWindow(cs);
}


void CListViewTestView::OnDraw(CDC* /*pDC*/)
{
	CListViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CListViewTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().

	CImageList ilLarge, ilSmall;
	ilLarge.Create(32, 32, ILC_COLOR4, 1, 1);
	ilSmall.Create(16, 16, ILC_COLOR4, 1, 1);
	ilLarge.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	ilSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON1));

	CListCtrl& list = GetListCtrl();
	list.SetImageList(&ilLarge, LVSIL_NORMAL);
	list.SetImageList(&ilSmall, LVSIL_SMALL);
	ilLarge.Detach();
	ilSmall.Detach();

	list.InsertColumn(0, _T("상품명"), LVCFMT_LEFT, 100, 0);
	list.InsertColumn(1, _T("가격"), LVCFMT_LEFT, 100, 2);
	list.InsertColumn(2, _T("수량"), LVCFMT_LEFT, 100, 1);

	CListViewTestDoc* pDoc = GetDocument();
	CString str;
	for (int i = 0; i < NUMITEM; i++) {
		list.InsertItem(i, pDoc->m_item[i].name, 0);
		str.Format(_T("%d"), pDoc->m_item[i].price);
		list.SetItemText(i, 1, str);
		str.Format(_T("%d"), pDoc->m_item[i].quantity);
		list.SetItemText(i, 2, str);
	}

	// 연습 문제 03
	list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
}


// CListViewTestView printing

BOOL CListViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CListViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CListViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CListViewTestView diagnostics

#ifdef _DEBUG
void CListViewTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CListViewTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CListViewTestDoc* CListViewTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListViewTestDoc)));
	return (CListViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CListViewTestView message handlers


void CListViewTestView::OnViewLargeicon()
{
	// TODO: Add your command handler code here
	ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}


void CListViewTestView::OnViewSmallicon()
{
	// TODO: Add your command handler code here
	ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}


void CListViewTestView::OnViewList()
{
	// TODO: Add your command handler code here
	ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}


void CListViewTestView::OnViewDetails()
{
	// TODO: Add your command handler code here
	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}

// 연습 문제 03
void CListViewTestView::OnListDelete()
{
	// TODO: Add your command handler code here
	CListCtrl& pList = GetListCtrl();
	POSITION pos = pList.GetFirstSelectedItemPosition();
	while (pos) {
		int nItem = pList.GetNextSelectedItem(pos);
		pList.DeleteItem(nItem);
		pos = pList.GetFirstSelectedItemPosition();
	}
}
// --

// 연습 문제 04
void CListViewTestView::OnListAppend()
{
	// TODO: Add your command handler code here
	CAddDialog dlg;
	if (dlg.DoModal() == IDOK) {
		BOOL check_success = TRUE;
		if (dlg.m_item.IsEmpty()) {
			check_success = FALSE;
			MessageBox(_T("오류 : 상품명"),_T("추가"),MB_ICONERROR);
		}
		if (dlg.m_price == 0) {
			check_success = FALSE;
			MessageBox(_T("오류 : 가격"), _T("추가"), MB_ICONERROR);
		}
		if (dlg.m_count == 0) {
			check_success = FALSE;
			MessageBox(_T("오류 : 수량"), _T("추가"), MB_ICONERROR);
		}

		if (check_success) {
			CListCtrl& pList = GetListCtrl();
			int lastPosition = pList.GetItemCount();
			CString str;
			str.Format(_T("%d"), dlg.m_price);
			pList.InsertItem(lastPosition, dlg.m_item, 0);
			pList.SetItemText(lastPosition, 1, str);
			str.Format(_T("%d"), dlg.m_count);
			pList.SetItemText(lastPosition, 2, str);
		}
	}
}
// --