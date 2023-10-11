
// MDITestView.cpp : implementation of the CMDITestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MDITest.h"
#endif

#include "MDITestDoc.h"
#include "MDITestView.h"
#include "ChildFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDITestView

IMPLEMENT_DYNCREATE(CMDITestView, CView)

BEGIN_MESSAGE_MAP(CMDITestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMDITestView construction/destruction

CMDITestView::CMDITestView() noexcept
{
	// TODO: add construction code here

}

CMDITestView::~CMDITestView()
{
}

BOOL CMDITestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMDITestView drawing

void CMDITestView::OnDraw(CDC* pDC)
{
	CMDITestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	//CFont font;
	//font.CreateFont(30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("궁서"));
	//pDC->SelectObject(&font);

	
	//CRect rect;
	//GetClientRect(&rect);
	
	// 기존
	//pDC->DrawText(pDoc->m_str.GetData(), pDoc->m_str.GetSize(), &rect, DT_LEFT);
	// --

	// 연습 문제 15
	//POSITION pos = pDoc->GetFirstViewPosition();

	//CString totalStr = _T("");
	//int count = 0;
	//while (pos) {
	//	CMDITestView* pView = (CMDITestView*)pDoc->GetNextView(pos);
	//	CString str = _T("");
	//	str = pView->m_pDocument->GetTitle();
	//	str.Format(_T("[%2d] %s (%p)"), count, pView->m_pDocument->GetTitle() ,pView);
	//	totalStr += str + _T("\n");
	//	count++;
	//}

	//pDC->DrawText(totalStr, &rect, DT_LEFT);
	// --

	// 연습 문제 20
	CDocTemplate* pTemplate = pDoc->GetDocTemplate();
	CString str = _T(""), tempStr = _T("");
	str += _T("windowTitle : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::windowTitle);
	str += tempStr + _T("\n");
	str += _T("docName : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::docName);
	str += tempStr + _T("\n");
	str += _T("fileNewName : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::fileNewName);
	str += tempStr + _T("\n");
	str += _T("filterName : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::filterName);
	str += tempStr + _T("\n");
	str += _T("filterExt : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::filterExt);
	str += tempStr + _T("\n");
	str += _T("regFileTypeId : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::regFileTypeId);
	str += tempStr + _T("\n");
	str += _T("regFileTypeName : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::regFileTypeName);
	str += tempStr + _T("\n");
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(str, &rect, DT_LEFT);
	// --
}


// CMDITestView printing

BOOL CMDITestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMDITestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMDITestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMDITestView diagnostics

#ifdef _DEBUG
void CMDITestView::AssertValid() const
{
	CView::AssertValid();
}

void CMDITestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDITestDoc* CMDITestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDITestDoc)));
	return (CMDITestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDITestView message handlers


void CMDITestView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CMDITestDoc* pDoc = GetDocument();
	if (nChar == _T('\b')) {
		if (pDoc->m_str.GetSize() > 0) {
			pDoc->m_str.RemoveAt(pDoc->m_str.GetSize() - 1);
		}
	}
	else {
		pDoc->m_str.Add(nChar);
	}
	// 데이터가 수정되었음을 알린다.
	pDoc->SetModifiedFlag();

	pDoc->UpdateAllViews(NULL);


	CView::OnChar(nChar, nRepCnt, nFlags);
}
