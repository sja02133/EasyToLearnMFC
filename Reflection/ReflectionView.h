
// ReflectionView.h : interface of the CReflectionView class
//

#pragma once
#include "CMyListBox.h"

class CReflectionView : public CFormView
{
protected: // create from serialization only
	CReflectionView() noexcept;
	DECLARE_DYNCREATE(CReflectionView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_REFLECTION_FORM };
#endif

// Attributes
public:
	CReflectionDoc* GetDocument() const;

	// 연습 문제 21
	BOOL m_bCheck = FALSE;
	// --
	
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
	virtual ~CReflectionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CMyListBox m_list;
	afx_msg void OnBnClickedCheckMessage();
	CButton m_checkBox;
};

#ifndef _DEBUG  // debug version in ReflectionView.cpp
inline CReflectionDoc* CReflectionView::GetDocument() const
   { return reinterpret_cast<CReflectionDoc*>(m_pDocument); }
#endif

