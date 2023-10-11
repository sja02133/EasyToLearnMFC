
// TreeViewTestView.cpp : implementation of the CTreeViewTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TreeViewTest.h"
#endif

#include "TreeViewTestDoc.h"
#include "TreeViewTestView.h"

#include "CAddDialog.h"	// 연습 문제 08

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTreeViewTestView

IMPLEMENT_DYNCREATE(CTreeViewTestView, CTreeView)

BEGIN_MESSAGE_MAP(CTreeViewTestView, CTreeView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTreeView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST_DELETESELECTED, &CTreeViewTestView::OnTestDeleteselected)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CTreeViewTestView::OnTvnSelchanged)
	ON_WM_SIZE()
	ON_COMMAND(ID_STYLE_HASLINES, &CTreeViewTestView::OnStyleHaslines)
	ON_COMMAND(ID_STYLE_LINESATROOT, &CTreeViewTestView::OnStyleLinesatroot)
	ON_COMMAND(iD_TEST_APPEND, &CTreeViewTestView::OnTestAppend)
END_MESSAGE_MAP()

// CTreeViewTestView construction/destruction

CTreeViewTestView::CTreeViewTestView() noexcept
{
	// TODO: add construction code here

}

CTreeViewTestView::~CTreeViewTestView()
{
}

BOOL CTreeViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style |= TVS_HASBUTTONS;
	cs.style |= TVS_HASLINES;
	cs.style |= TVS_LINESATROOT;
	cs.style |= TVS_TRACKSELECT;


	return CTreeView::PreCreateWindow(cs);
}


void CTreeViewTestView::OnDraw(CDC* /*pDC*/)
{
	CTreeViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CTreeViewTestView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	CImageList il;
	il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));

	CTreeCtrl& tree = GetTreeCtrl();
	tree.SetImageList(&il, TVSIL_NORMAL);
	il.Detach();

	HTREEITEM hSun = tree.InsertItem(_T("태양"), 0, 0, TVI_ROOT, TVI_LAST);

	HTREEITEM hPlanet[8];
	CString planet[] = { _T("수성"),_T("금성"),_T("지구"),_T("화성") ,_T("목성") ,_T("토성") ,_T("천왕성") ,_T("해왕성") };

	for (int i = 0; i < 8; i++) {
		hPlanet[i] = tree.InsertItem(planet[i], 1, 1, hSun, TVI_LAST);
	}

	tree.InsertItem(_T("달"), 2, 2, hPlanet[2], TVI_LAST);
	tree.InsertItem(_T("포보스"), 2, 2, hPlanet[3], TVI_LAST);
	tree.InsertItem(_T("데이포스"), 2, 2, hPlanet[3], TVI_LAST);
	tree.InsertItem(_T("이오"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("에우로파"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("가니메데"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("칼리스토"), 2, 2, hPlanet[4], TVI_LAST);

	// 연습 문제 06
	tree.Expand(hSun, TVE_EXPAND);
	// --

}


// CTreeViewTestView printing

BOOL CTreeViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTreeViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTreeViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTreeViewTestView diagnostics

#ifdef _DEBUG
void CTreeViewTestView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CTreeViewTestView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CTreeViewTestDoc* CTreeViewTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeViewTestDoc)));
	return (CTreeViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTreeViewTestView message handlers


void CTreeViewTestView::OnTestDeleteselected()
{
	// TODO: Add your command handler code here
	CTreeCtrl& tree = GetTreeCtrl();

	HTREEITEM hItem = tree.GetSelectedItem();
	if (hItem != NULL) {
		tree.DeleteItem(hItem);
	}
}

// 연습 문제 06
void CTreeViewTestView::OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	TVITEM tvi = pNMTreeView->itemNew;
	CTreeCtrl& tree = GetTreeCtrl();
	CString str = tree.GetItemText(tvi.hItem);
	AfxGetMainWnd()->SetWindowText(str);

	*pResult = 0;
}
// --

// 연습 문제 05
void CTreeViewTestView::OnSize(UINT nType, int cx, int cy)
{
	CTreeView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CTreeCtrl& tree = GetTreeCtrl();
	//tree.SetWindowPos(this, 0, 0, cx, cy, SWP_NOZORDER | SWP_SHOWWINDOW);
	CRect rect;

	::GetClientRect(this->m_hWnd,rect);
	tree.MoveWindow(rect, TRUE);
}
// --

// 연습 문제 07
void CTreeViewTestView::OnStyleHaslines()
{
	// TODO: Add your command handler code here
	CTreeCtrl& pTree = GetTreeCtrl();
	DWORD style = pTree.GetStyle();
	pTree.ModifyStyle(0, TVS_HASLINES);
}


void CTreeViewTestView::OnStyleLinesatroot()
{
	// TODO: Add your command handler code here
	CTreeCtrl& pTree = GetTreeCtrl();
	DWORD style = pTree.GetStyle();
	pTree.ModifyStyle(0, TVS_LINESATROOT);
}
// --

// dus
void CTreeViewTestView::OnTestAppend()
{
	// TODO: Add your command handler code here
	CAddDialog dlg;

	if (dlg.DoModal() == IDOK) {
		if (dlg.m_name.IsEmpty())
			MessageBox(_T("이름 에러"));
		else {
			CTreeCtrl& pTree = GetTreeCtrl();
			HTREEITEM hItem = pTree.GetSelectedItem();

			CString str;
			str = pTree.GetItemText(hItem);
			if (str.Compare(_T("태양")) == 0) {
				pTree.InsertItem(dlg.m_name, 1, 1, hItem, TVI_LAST);
			}
			else {
				pTree.InsertItem(dlg.m_name, 1, 1, hItem, TVI_LAST);
			}
		}
	}
}
