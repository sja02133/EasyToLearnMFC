
// TreeViewTestView.h : interface of the CTreeViewTestView class
//

#pragma once


class CTreeViewTestView : public CTreeView
{
protected: // create from serialization only
	CTreeViewTestView() noexcept;
	DECLARE_DYNCREATE(CTreeViewTestView)

// Attributes
public:
	CTreeViewTestDoc* GetDocument() const;

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
	virtual ~CTreeViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestDeleteselected();
	afx_msg void OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnStyleHaslines();
	afx_msg void OnStyleLinesatroot();
	afx_msg void OnTestAppend();
};

#ifndef _DEBUG  // debug version in TreeViewTestView.cpp
inline CTreeViewTestDoc* CTreeViewTestView::GetDocument() const
   { return reinterpret_cast<CTreeViewTestDoc*>(m_pDocument); }
#endif

