
// ListCtrlTest2View.cpp : implementation of the CListCtrlTest2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ListCtrlTest2.h"
#endif

#include "ListCtrlTest2Doc.h"
#include "ListCtrlTest2View.h"

#define IDC_LIST1 100
CListCtrl m_list;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListCtrlTest2View

IMPLEMENT_DYNCREATE(CListCtrlTest2View, CListView)

BEGIN_MESSAGE_MAP(CListCtrlTest2View, CListView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
	ON_WM_CREATE()
	//ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CListCtrlTest2View::OnLvnItemchanged)
	//ON_NOTIFY_REFLECT(NM_DBLCLK, &CListCtrlTest2View::OnNMDblclk)
	ON_NOTIFY(LVN_ITEMCHANGED,IDC_LIST1,&CListCtrlTest2View::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CListCtrlTest2View::OnNMDblclkList1)
	//ON_NOTIFY(WM_CONTEXTMENU, IDC_LIST1, &CListCtrlTest2View::OnContextMenu)
	ON_WM_CONTEXTMENU()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(2001, &CListCtrlTest2View::OnDeleteButtonClicked)
END_MESSAGE_MAP()

// CListCtrlTest2View construction/destruction

CListCtrlTest2View::CListCtrlTest2View() noexcept
{
	// TODO: add construction code here

}

CListCtrlTest2View::~CListCtrlTest2View()
{
}

BOOL CListCtrlTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}


void CListCtrlTest2View::OnDraw(CDC* /*pDC*/)
{
	CListCtrlTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CListCtrlTest2View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}


// CListCtrlTest2View printing

BOOL CListCtrlTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CListCtrlTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CListCtrlTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CListCtrlTest2View diagnostics

#ifdef _DEBUG
void CListCtrlTest2View::AssertValid() const
{
	CListView::AssertValid();
}

void CListCtrlTest2View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CListCtrlTest2Doc* CListCtrlTest2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListCtrlTest2Doc)));
	return (CListCtrlTest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CListCtrlTest2View message handlers


int CListCtrlTest2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SINGLESEL, CRect(10, 10, 310, 110), this, IDC_LIST1);

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
	m_list.SetItemText(2, 2, _T("B0"));// TODO:  Add your specialized creation code here

	return 0;
}


void CListCtrlTest2View::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here

	if (pNMLV->uChanged & LVIF_STATE) {
		if (pNMLV->uNewState & (LVIS_SELECTED | LVIS_FOCUSED)) {
			CString str = m_list.GetItemText(pNMLV->iItem, 0);
			AfxGetMainWnd()->SetWindowText(str);
		}
	}

	*pResult = 0;
}


void CListCtrlTest2View::OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	if (pNMItemActivate->iItem != -1) {
		CString str = m_list.GetItemText(pNMItemActivate->iItem, 0);
		MessageBox(str);
	}

	*pResult = 0;
}


void CListCtrlTest2View::OnContextMenu(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your message handler code here
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	if (pNMItemActivate->iItem != -1) {
		CString str = m_list.GetItemText(pNMItemActivate->iItem, 0);
		MessageBox(str);
	}int kkk = 0;
}


void CListCtrlTest2View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: Add your message handler code here
	UINT checkSelect = m_list.GetSelectedCount();
	if (checkSelect) {
		CMenu menu;
		menu.CreatePopupMenu();

		menu.AppendMenu(MF_STRING, 2001, _T("삭제"));
		menu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, AfxGetMainWnd());
	}
}

void CListCtrlTest2View::OnDeleteButtonClicked() {
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nItem = m_list.GetNextSelectedItem(pos);
	m_list.DeleteItem(nItem);
}