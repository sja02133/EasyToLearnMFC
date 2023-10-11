
// ProgressView.h : interface of the CProgressView class
//

#pragma once


class CProgressView : public CFormView
{
protected: // create from serialization only
	CProgressView() noexcept;
	DECLARE_DYNCREATE(CProgressView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PROGRESS_FORM };
#endif

// Attributes
public:
	CProgressDoc* GetDocument() const;

	BOOL bNowProgress;

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
	virtual ~CProgressView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_progress;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version in ProgressView.cpp
inline CProgressDoc* CProgressView::GetDocument() const
   { return reinterpret_cast<CProgressDoc*>(m_pDocument); }
#endif

