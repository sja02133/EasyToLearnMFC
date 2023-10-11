
// WorkerThread1View.cpp : implementation of the CWorkerThread1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WorkerThread1.h"
#endif

#include "MainFrm.h"

#include "WorkerThread1Doc.h"
#include "WorkerThread1View.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkerThread1View

IMPLEMENT_DYNCREATE(CWorkerThread1View, CView)

BEGIN_MESSAGE_MAP(CWorkerThread1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CWorkerThread1View construction/destruction

CWorkerThread1View::CWorkerThread1View() noexcept
{
	// TODO: add construction code here

}

CWorkerThread1View::~CWorkerThread1View()
{
}

BOOL CWorkerThread1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CWorkerThread1View drawing

void CWorkerThread1View::OnDraw(CDC* /*pDC*/)
{
	CWorkerThread1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CWorkerThread1View printing

BOOL CWorkerThread1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWorkerThread1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWorkerThread1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CWorkerThread1View diagnostics

#ifdef _DEBUG
void CWorkerThread1View::AssertValid() const
{
	CView::AssertValid();
}

void CWorkerThread1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkerThread1Doc* CWorkerThread1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkerThread1Doc)));
	return (CWorkerThread1Doc*)m_pDocument;
}
#endif //_DEBUG


// CWorkerThread1View message handlers

UINT CalcIt(LPVOID arg) {
	int val = (int)arg;

	int result = 0;
	for (int i = 0; i < val; i++) {
		result += i;
		Sleep(10);
	}

	CString str;
	str.Format(_T("계산 결과 = %d"), result);
	AfxMessageBox(str);

	return 0;
}

// 연습 문제 01
UINT CalcIt2(LPVOID arg) {
	
	thread_parameter* param = (thread_parameter*)arg;

	int val = 600;
	int result = 0;
	for (int i = 0; i < val; i++) {
		result += i;
		Sleep(10);
	}

	CString str;
	str.Format(_T("계산 결과 = %d"), result);
	
	CDC dc;
	HDC hdc = ::GetDC(param->hwnd);
	dc.Attach(hdc);
	//CClientDC dc(pView);

	dc.TextOut(param->point.x,param->point.y, str);
	dc.Detach();
	::ReleaseDC(param->hwnd, hdc);
	return 0;
}
// --

void CWorkerThread1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	int val = 600;

	// 기존
	// 스레드를 사용하지 않은 경우
	//CalcIt((LPVOID)val);

	// 스레드를 사용한 경우
	//AfxBeginThread(CalcIt, (LPVOID)val);
	// --
	
	CClientDC dc(this);
	thread_parameter* param = new thread_parameter;
	param->point = point;
	param->hwnd = this->m_hWnd;

	AfxBeginThread(CalcIt2, (LPVOID)param); // 연습 문제 01

	CView::OnLButtonDown(nFlags, point);
}
