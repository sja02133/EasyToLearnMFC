
// ListBoxView.h : interface of the CListBoxView class
//

#pragma once

class CListBoxView : public CFormView
{
protected: // create from serialization only
	CListBoxView() noexcept;
	DECLARE_DYNCREATE(CListBoxView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_LISTBOX_FORM };
#endif

// Attributes
public:
	//CListBoxDoc* GetDocument() const;

	BOOL check_18 = FALSE;	// 연습 문제 18 체크

	

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
	virtual ~CListBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list1;
	CListBox m_list2;
	CButton m_right;
	CButton m_left;
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnLbnDblclkList1();
	afx_msg void OnLbnDblclkList2();
};

#ifndef _DEBUG  // debug version in ListBoxView.cpp
inline CListBoxDoc* CListBoxView::GetDocument() const
   { return reinterpret_cast<CListBoxDoc*>(m_pDocument); }
#endif

