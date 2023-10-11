
// SDITestView.h : interface of the CSDITestView class
//

#pragma once


class CSDITestView : public CView
{
protected: // create from serialization only
	CSDITestView() noexcept;
	DECLARE_DYNCREATE(CSDITestView)

// Attributes
public:
	CSDITestDoc* GetDocument() const;

	CString m_file = _T("");	// 연습 문제 05

	CString m_str = _T("");

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
	virtual ~CSDITestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnAppAbout();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in SDITestView.cpp
inline CSDITestDoc* CSDITestView::GetDocument() const
   { return reinterpret_cast<CSDITestDoc*>(m_pDocument); }
#endif

