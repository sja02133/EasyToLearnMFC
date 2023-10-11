
// ListViewTestView.h : interface of the CListViewTestView class
//

#pragma once


class CListViewTestView : public CListView
{
protected: // create from serialization only
	CListViewTestView() noexcept;
	DECLARE_DYNCREATE(CListViewTestView)

// Attributes
public:
	CListViewTestDoc* GetDocument() const;

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
	virtual ~CListViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewLargeicon();
	afx_msg void OnViewSmallicon();
	afx_msg void OnViewList();
	afx_msg void OnViewDetails();
	afx_msg void OnListDelete();
	afx_msg void OnListAppend();
};

#ifndef _DEBUG  // debug version in ListViewTestView.cpp
inline CListViewTestDoc* CListViewTestView::GetDocument() const
   { return reinterpret_cast<CListViewTestDoc*>(m_pDocument); }
#endif

