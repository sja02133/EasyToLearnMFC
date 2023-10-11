
// OptimizeScrollView.h : interface of the COptimizeScrollView class
//

#pragma once


class COptimizeScrollView : public CScrollView
{
protected: // create from serialization only
	COptimizeScrollView() noexcept;
	DECLARE_DYNCREATE(COptimizeScrollView)

// Attributes
public:
	COptimizeScrollDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~COptimizeScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void MyDraw(CDC* pDC, int x, int y);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // debug version in OptimizeScrollView.cpp
inline COptimizeScrollDoc* COptimizeScrollView::GetDocument() const
   { return reinterpret_cast<COptimizeScrollDoc*>(m_pDocument); }
#endif

