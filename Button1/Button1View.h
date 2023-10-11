
// Button1View.h : interface of the CButton1View class
//

#pragma once


class CButton1View : public CView
{
protected: // create from serialization only
	CButton1View() noexcept;
	DECLARE_DYNCREATE(CButton1View)

// Attributes
public:
	CButton1Doc* GetDocument() const;

	// 실습 8-1
	CButton m_pushButton;
	CButton m_checkBox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;

	// 연습 문제 04
	CButton m_radioA;
	CButton m_radioB;
	// --

	CButton m_groupbox;
	// --


// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CButton1View();
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
	void OnButtonClicked();
	void OnButtonClicked_checkBox();
	void OnButtonClicked_3state();
	void OnButtonClicked_radioButton1();
};

#ifndef _DEBUG  // debug version in Button1View.cpp
inline CButton1Doc* CButton1View::GetDocument() const
   { return reinterpret_cast<CButton1Doc*>(m_pDocument); }
#endif

