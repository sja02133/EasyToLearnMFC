
// SDITestView.cpp : implementation of the CSDITestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDITest.h"
#endif

#include "SDITestDoc.h"
#include "SDITestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDITestView

IMPLEMENT_DYNCREATE(CSDITestView, CView)

BEGIN_MESSAGE_MAP(CSDITestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DROPFILES()
//	ON_COMMAND(ID_APP_ABOUT, &CSDITestView::OnAppAbout)
//ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSDITestView construction/destruction

CSDITestView::CSDITestView() noexcept
{
	// TODO: add construction code here

}

CSDITestView::~CSDITestView()
{
}

BOOL CSDITestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSDITestView drawing

void CSDITestView::OnDraw(CDC* pDC)
{
	CSDITestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	// 연습 문제 04
	//CString str(MAKEINTRESOURCE(IDR_MAINFRAME));
	//CRect rect;
	//GetClientRect(&rect);
	//pDC->DrawText(str, &rect, DT_LEFT);
	// --

	// 연습 문제 06
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_str, &rect, DT_LEFT);
	// --
	

}


// CSDITestView printing

BOOL CSDITestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDITestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDITestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSDITestView diagnostics

#ifdef _DEBUG
void CSDITestView::AssertValid() const
{
	CView::AssertValid();
}

void CSDITestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDITestDoc* CSDITestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDITestDoc)));
	return (CSDITestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDITestView message handlers


void CSDITestView::OnDropFiles(HDROP hDropInfo)
{
	// TODO: Add your message handler code here and/or call default
	int uCount = DragQueryFile(hDropInfo, 0xffffffff, nullptr, 0);

#ifdef _UNICODE
	LPWSTR buffer;
#else
	char* buffer;
#endif
	buffer = nullptr;

	int nLength = DragQueryFile(hDropInfo, 0, nullptr, 0);

#ifdef _UNICODE
	buffer = (LPWSTR)malloc(2 * (nLength + 1));
#else
	buffer = (char*)malloc(nLength + 1);
#endif
	DragQueryFile(hDropInfo, 0, buffer, nLength + 1);

	this->m_file.Format(_T("%s"),buffer);

	//SetWindowText(this->m_file);

	if (buffer != nullptr)
		free(buffer);

	CView::OnDropFiles(hDropInfo);
}

// 연습 문제 07
//void CSDITestView::OnAppAbout()
//{
//	// TODO: Add your command handler code here
//	//MessageBox(_T("도움말입니다."), _T("도움말입니다."), MB_ICONINFORMATION | MB_OK);
//}
// --

//void CSDITestView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CView::OnLButtonDown(nFlags, point);
//}
