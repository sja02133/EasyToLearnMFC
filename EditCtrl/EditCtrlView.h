
// EditCtrlView.h : interface of the CEditCtrlView class
//

#pragma once

#include "EditCtrlDoc.h"

class CEditCtrlView : public CFormView
{
protected: // create from serialization only
	CEditCtrlView() noexcept;
	DECLARE_DYNCREATE(CEditCtrlView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EDITCTRL_FORM };
#endif

// Attributes
public:
	CEditCtrlDoc* GetDocument() const;

	CString password = _T("12345!@#");	// 연습 문제 10
	
	// 연습 문제 11
	BOOL m_bReadOnly = TRUE;
	CString m_beforeStr = _T("");
	// --

	// 연습 문제 14
	BOOL m_bUndo = FALSE;
	BOOL m_bCut = FALSE;
	BOOL m_bCopy = FALSE;
	BOOL m_bPaste = FALSE;
	// --
	
	// 연습 문제 15
	BOOL question_15 = TRUE;	// TRUE면 15번 문제, FALSE면 그 이외
	CString fileStr = _T("");
	BOOL checkFirst = TRUE;
	// --
	
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
	virtual ~CEditCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnChangeMyedit();
	afx_msg void OnMaxtextMyedit();
	CStatic m_static;
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnClickedButtonEnter();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version in EditCtrlView.cpp
inline CEditCtrlDoc* CEditCtrlView::GetDocument() const
   { return reinterpret_cast<CEditCtrlDoc*>(m_pDocument); }
#endif

