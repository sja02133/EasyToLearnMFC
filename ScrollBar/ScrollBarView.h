
// ScrollBarView.h : interface of the CScrollBarView class
//

#pragma once


class CScrollBarView : public CFormView
{
protected: // create from serialization only
	CScrollBarView() noexcept;
	DECLARE_DYNCREATE(CScrollBarView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SCROLLBAR_FORM };
#endif

// Attributes
public:
	CScrollBarDoc* GetDocument() const;

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
	virtual ~CScrollBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_status;
	CScrollBar m_hsb;
	CScrollBar m_vsb;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // debug version in ScrollBarView.cpp
inline CScrollBarDoc* CScrollBarView::GetDocument() const
   { return reinterpret_cast<CScrollBarDoc*>(m_pDocument); }
#endif

