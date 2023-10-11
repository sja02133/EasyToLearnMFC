
// TabCtrlView.h : interface of the CTabCtrlView class
//

#pragma once


class CTabCtrlView : public CFormView
{
protected: // create from serialization only
	CTabCtrlView() noexcept;
	DECLARE_DYNCREATE(CTabCtrlView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TABCTRL_FORM };
#endif

// Attributes
public:
	CTabCtrlDoc* GetDocument() const;

	CImageList m_il;	// 연습 문제 02

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTabCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CEdit m_edit;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTabAppend();
	afx_msg void OnTabDelete();
	CAnimateCtrl m_ani;
};

#ifndef _DEBUG  // debug version in TabCtrlView.cpp
inline CTabCtrlDoc* CTabCtrlView::GetDocument() const
   { return reinterpret_cast<CTabCtrlDoc*>(m_pDocument); }
#endif

