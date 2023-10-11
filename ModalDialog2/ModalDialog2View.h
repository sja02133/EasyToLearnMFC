
// ModalDialog2View.h : interface of the CModalDialog2View class
//

#pragma once


class CModalDialog2View : public CView
{
protected: // create from serialization only
	CModalDialog2View() noexcept;
	DECLARE_DYNCREATE(CModalDialog2View)

// Attributes
public:
	CModalDialog2Doc* GetDocument() const;

	CString m_str = _T("");
	int m_font = 0;

	int m_size = 10;	// 연습 문제 03
	int m_selectColor = 0;	// 연습 문제 04
	BOOL checkBold = FALSE;

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
	virtual ~CModalDialog2View();
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

#ifndef _DEBUG  // debug version in ModalDialog2View.cpp
inline CModalDialog2Doc* CModalDialog2View::GetDocument() const
   { return reinterpret_cast<CModalDialog2Doc*>(m_pDocument); }
#endif

