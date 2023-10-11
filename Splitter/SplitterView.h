
// SplitterView.h : interface of the CSplitterView class
//

#pragma once


class CSplitterView : public CView
{
protected: // create from serialization only
	CSplitterView() noexcept;
	DECLARE_DYNCREATE(CSplitterView)

// Attributes
public:
	CSplitterDoc* GetDocument() const;

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
	virtual ~CSplitterView();
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
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in SplitterView.cpp
inline CSplitterDoc* CSplitterView::GetDocument() const
   { return reinterpret_cast<CSplitterDoc*>(m_pDocument); }
#endif

