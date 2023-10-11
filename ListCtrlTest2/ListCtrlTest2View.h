
// ListCtrlTest2View.h : interface of the CListCtrlTest2View class
//

#pragma once


class CListCtrlTest2View : public CListView
{
protected: // create from serialization only
	CListCtrlTest2View() noexcept;
	DECLARE_DYNCREATE(CListCtrlTest2View)

// Attributes
public:
	CListCtrlTest2Doc* GetDocument() const;

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
	virtual ~CListCtrlTest2View();
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
	//afx_msg void OnLvnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//afx_msg void OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnContextMenu(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint point);
	afx_msg void OnDeleteButtonClicked();
};

#ifndef _DEBUG  // debug version in ListCtrlTest2View.cpp
inline CListCtrlTest2Doc* CListCtrlTest2View::GetDocument() const
   { return reinterpret_cast<CListCtrlTest2Doc*>(m_pDocument); }
#endif

