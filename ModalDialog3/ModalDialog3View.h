
// ModalDialog3View.h : interface of the CModalDialog3View class
//

#pragma once


class CModalDialog3View : public CView
{
protected: // create from serialization only
	CModalDialog3View() noexcept;
	DECLARE_DYNCREATE(CModalDialog3View)

// Attributes
public:
	CModalDialog3Doc* GetDocument() const;

	CString m_str = _T("");
	int m_font = 0;
	int m_size = 10; // 연습 문제 06
	CPoint point;	//연습 문제 07
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
	virtual ~CModalDialog3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClear();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in ModalDialog3View.cpp
inline CModalDialog3Doc* CModalDialog3View::GetDocument() const
   { return reinterpret_cast<CModalDialog3Doc*>(m_pDocument); }
#endif

