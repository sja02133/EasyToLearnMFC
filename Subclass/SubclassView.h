
// SubclassView.h : interface of the CSubclassView class
//

#pragma once
#include "CMyEdit.h"

class CSubclassView : public CFormView
{
protected: // create from serialization only
	CSubclassView() noexcept;
	DECLARE_DYNCREATE(CSubclassView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SUBCLASS_FORM };
#endif

// Attributes
public:
	CSubclassDoc* GetDocument() const;

	CMyEdit m_edit2;
	
	// 연습 문제 20
	BOOL m_bCheckBox = FALSE;

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
	virtual ~CSubclassView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CMyEdit m_edit1;
	CButton m_checkBox;
	afx_msg void OnBnClickedCheckNumberonly();
	afx_msg void OnEnChangeEdit2();
};

#ifndef _DEBUG  // debug version in SubclassView.cpp
inline CSubclassDoc* CSubclassView::GetDocument() const
   { return reinterpret_cast<CSubclassDoc*>(m_pDocument); }
#endif

