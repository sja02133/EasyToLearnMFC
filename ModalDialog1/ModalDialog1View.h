
// ModalDialog1View.h : interface of the CModalDialog1View class
//

#pragma once


class CModalDialog1View : public CView
{
protected: // create from serialization only
	CModalDialog1View() noexcept;
	DECLARE_DYNCREATE(CModalDialog1View)

// Attributes
public:
	CModalDialog1Doc* GetDocument() const;

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
	virtual ~CModalDialog1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in ModalDialog1View.cpp
inline CModalDialog1Doc* CModalDialog1View::GetDocument() const
   { return reinterpret_cast<CModalDialog1Doc*>(m_pDocument); }
#endif

