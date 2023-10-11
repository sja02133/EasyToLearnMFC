
// FindReplaceView.cpp : implementation of the CFindReplaceView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FindReplace.h"
#endif

#include "FindReplaceDoc.h"
#include "FindReplaceView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFindReplaceView

static UINT WM_FINDPLACE = ::RegisterWindowMessage(FINDMSGSTRING);

IMPLEMENT_DYNCREATE(CFindReplaceView, CView)

BEGIN_MESSAGE_MAP(CFindReplaceView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_REGISTERED_MESSAGE(WM_FINDPLACE, OnFindReplaceCmd)
END_MESSAGE_MAP()

// CFindReplaceView construction/destruction

CFindReplaceView::CFindReplaceView() noexcept
{
	// TODO: add construction code here
	pDlg = NULL;

}

CFindReplaceView::~CFindReplaceView()
{
}

BOOL CFindReplaceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFindReplaceView drawing

void CFindReplaceView::OnDraw(CDC* /*pDC*/)
{
	CFindReplaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFindReplaceView printing

BOOL CFindReplaceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFindReplaceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFindReplaceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFindReplaceView diagnostics

#ifdef _DEBUG
void CFindReplaceView::AssertValid() const
{
	CView::AssertValid();
}

void CFindReplaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFindReplaceDoc* CFindReplaceView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFindReplaceDoc)));
	return (CFindReplaceDoc*)m_pDocument;
}
#endif //_DEBUG


// CFindReplaceView message handlers


void CFindReplaceView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (pDlg != NULL)
		pDlg->SetFocus();
	else {
		pDlg = new CFindReplaceDialog();
		pDlg->Create(FALSE, _T(""), _T(""), FR_DOWN, this);
	}


	CView::OnLButtonDown(nFlags, point);
}


LRESULT CFindReplaceView::OnFindReplaceCmd(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your implementation code here.
	CString str;

	if (pDlg->IsTerminating()) {
		pDlg = NULL;
		return 0;
	}
	else if (pDlg->FindNext()) {
		str.Format(_T("찾을 문자열: %s"), pDlg->GetFindString());
		MessageBox(str);
	}
	else if (pDlg->ReplaceCurrent()) {
		str.Format(_T("찾을 문자열: %s\n\r바꿀 문자열: %s"), pDlg->GetFindString(), pDlg->GetReplaceString());
		MessageBox(str);
	}
	else if (pDlg->ReplaceAll()) {
		str.Format(_T("찾을 문자열: %s\n\r바꿀 문자열: %s"), pDlg->GetFindString(), pDlg->GetReplaceString());
		MessageBox(str);
	}
	return 0;
}
