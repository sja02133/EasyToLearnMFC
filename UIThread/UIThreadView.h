
// UIThreadView.h : interface of the CUIThreadView class
//

#pragma once


class CUIThreadView : public CView
{
protected: // create from serialization only
	CUIThreadView() noexcept;
	DECLARE_DYNCREATE(CUIThreadView)

// Attributes
public:
	CUIThreadDoc* GetDocument() const;

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
	virtual ~CUIThreadView();
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
	afx_msg void OnOptionAlwaysup();
};

#ifndef _DEBUG  // debug version in UIThreadView.cpp
inline CUIThreadDoc* CUIThreadView::GetDocument() const
   { return reinterpret_cast<CUIThreadDoc*>(m_pDocument); }
#endif

