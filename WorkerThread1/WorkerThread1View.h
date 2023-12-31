
// WorkerThread1View.h : interface of the CWorkerThread1View class
//

#pragma once

struct thread_parameter{
	CPoint point;
	HWND hwnd;
};

class CWorkerThread1View : public CView
{
protected: // create from serialization only
	CWorkerThread1View() noexcept;
	DECLARE_DYNCREATE(CWorkerThread1View)

// Attributes
public:
	CWorkerThread1Doc* GetDocument() const;

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
	virtual ~CWorkerThread1View();
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
};

#ifndef _DEBUG  // debug version in WorkerThread1View.cpp
inline CWorkerThread1Doc* CWorkerThread1View::GetDocument() const
   { return reinterpret_cast<CWorkerThread1Doc*>(m_pDocument); }
#endif

