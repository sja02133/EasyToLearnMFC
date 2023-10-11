
// Button2View.h : interface of the CButton2View class
//

#pragma once


class CButton2View : public CFormView
{
protected: // create from serialization only
	CButton2View() noexcept;
	DECLARE_DYNCREATE(CButton2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_BUTTON2_FORM };
#endif

// Attributes
public:
	CButton2Doc* GetDocument() const;

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
	virtual ~CButton2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClickedCheck1();
	CButton m_button1;	// 연습 문제 05
	afx_msg void OnClickedCheck2();
};

#ifndef _DEBUG  // debug version in Button2View.cpp
inline CButton2Doc* CButton2View::GetDocument() const
   { return reinterpret_cast<CButton2Doc*>(m_pDocument); }
#endif

