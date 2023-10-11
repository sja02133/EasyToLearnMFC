
// WorkerThread2View.h : interface of the CWorkerThread2View class
//

#pragma once

struct ThreadArg
{
	CWnd* pWnd;
	int pos;
};

class CWorkerThread2View : public CView
{
protected: // create from serialization only
	CWorkerThread2View() noexcept;
	DECLARE_DYNCREATE(CWorkerThread2View)

// Attributes
public:
	CWorkerThread2Doc* GetDocument() const;

	CWinThread* pThread1, *pThread2;
	ThreadArg arg1, arg2;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CWorkerThread2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // debug version in WorkerThread2View.cpp
inline CWorkerThread2Doc* CWorkerThread2View::GetDocument() const
   { return reinterpret_cast<CWorkerThread2Doc*>(m_pDocument); }
#endif

