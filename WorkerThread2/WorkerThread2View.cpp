
// WorkerThread2View.cpp : implementation of the CWorkerThread2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WorkerThread2.h"
#endif

#include "WorkerThread2Doc.h"
#include "WorkerThread2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define LOOPCNT (200000)
#define DIVCNT (LOOPCNT/500)


// CWorkerThread2View

IMPLEMENT_DYNCREATE(CWorkerThread2View, CView)

BEGIN_MESSAGE_MAP(CWorkerThread2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CWorkerThread2View construction/destruction

BOOL check_prioirty();

CWorkerThread2View::CWorkerThread2View() noexcept
{
	// TODO: add construction code here
}

CWorkerThread2View::~CWorkerThread2View()
{
	KillTimer(1);
}

BOOL CWorkerThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CWorkerThread2View drawing

void CWorkerThread2View::OnDraw(CDC* /*pDC*/)
{
	CWorkerThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CWorkerThread2View printing

BOOL CWorkerThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWorkerThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWorkerThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CWorkerThread2View diagnostics

#ifdef _DEBUG
void CWorkerThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CWorkerThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkerThread2Doc* CWorkerThread2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkerThread2Doc)));
	return (CWorkerThread2Doc*)m_pDocument;
}
#endif //_DEBUG


// CWorkerThread2View message handlers
UINT MyDraw(LPVOID arg)
{
	ThreadArg* pArg = (ThreadArg*)arg;
	CClientDC dc(pArg->pWnd);

	int x, y, i;
	CBrush brush1(RGB(255, 0, 0));
	CBrush brush2(RGB(255, 0, 0));

	switch (pArg->pos) {
	case 1:
		dc.SelectObject(&brush1);
		x = 50; y = 50;
		for (i = 0; i < LOOPCNT; i++) {
			int inc = i / DIVCNT;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	case 2:
		dc.SelectObject(&brush2);
		x = 50; y = 100;
		for (i = 0; i < LOOPCNT; i++) {
			int inc = i / DIVCNT;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	}
	return 0;
}

void CWorkerThread2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);

	arg1.pWnd = this;
	arg1.pos = 1;
	pThread1 = AfxBeginThread(MyDraw, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	arg2.pWnd = this;
	arg2.pos = 2;
	pThread2 = AfxBeginThread(MyDraw, &arg2, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	pThread2->SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL);

	pThread1->ResumeThread();
	pThread2->ResumeThread();

	CView::OnLButtonDown(nFlags, point);
}

// 연습 문제 03
BOOL check_prioirty() {
	DWORD now_priority = ::GetPriorityClass(GetCurrentProcess());
	BOOL check = FALSE;
	if (now_priority != REALTIME_PRIORITY_CLASS) {
		::SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
		check = TRUE;
	}
	else
		check = FALSE;

	return check;
}
// --

void CWorkerThread2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if (nIDEvent == 1) {
		BOOL check = check_prioirty();
		CString str;
		str.Format(check ? _T("변경") : _T("변경없음"));
		//MessageBox(str);
	}

	CView::OnTimer(nIDEvent);
}
// --

void CWorkerThread2View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	SetTimer(1, 5000, NULL);	// 연습 문제 03
}
