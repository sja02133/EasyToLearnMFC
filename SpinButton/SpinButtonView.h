
// SpinButtonView.h : interface of the CSpinButtonView class
//

#pragma once


class CSpinButtonView : public CFormView
{
protected: // create from serialization only
	CSpinButtonView() noexcept;
	DECLARE_DYNCREATE(CSpinButtonView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SPINBUTTON_FORM };
#endif

// Attributes
public:
	CSpinButtonDoc* GetDocument() const;

	COLORREF m_color = RGB(255, 0, 0);	// 연습 문제 03

	UINT m_comboValue = 10;

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
	virtual ~CSpinButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_spin;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnDraw(CDC* /*pDC*/);
	CEdit m_edit;
	CSpinButtonCtrl m_spin2;
	CComboBox m_combo;
};

#ifndef _DEBUG  // debug version in SpinButtonView.cpp
inline CSpinButtonDoc* CSpinButtonView::GetDocument() const
   { return reinterpret_cast<CSpinButtonDoc*>(m_pDocument); }
#endif

