
// ListCtrlTest1View.h : interface of the CListCtrlTest1View class
//

#pragma once


class CListCtrlTest1View : public CListView
{
protected: // create from serialization only
	CListCtrlTest1View() noexcept;
	DECLARE_DYNCREATE(CListCtrlTest1View)

// Attributes
public:
	CListCtrlTest1Doc* GetDocument() const;

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
	virtual ~CListCtrlTest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in ListCtrlTest1View.cpp
inline CListCtrlTest1Doc* CListCtrlTest1View::GetDocument() const
   { return reinterpret_cast<CListCtrlTest1Doc*>(m_pDocument); }
#endif

