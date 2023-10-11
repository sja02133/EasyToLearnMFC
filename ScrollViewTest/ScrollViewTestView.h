
// ScrollViewTestView.h : interface of the CScrollViewTestView class
//

#pragma once


class CScrollViewTestView : public CScrollView
{
protected: // create from serialization only
	CScrollViewTestView() noexcept;
	DECLARE_DYNCREATE(CScrollViewTestView)

// Attributes
public:
	CScrollViewTestDoc* GetDocument() const;


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
	virtual ~CScrollViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // debug version in ScrollViewTestView.cpp
inline CScrollViewTestDoc* CScrollViewTestView::GetDocument() const
   { return reinterpret_cast<CScrollViewTestDoc*>(m_pDocument); }
#endif

