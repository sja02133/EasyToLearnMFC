
// MDITestView.h : interface of the CMDITestView class
//

#pragma once


class CMDITestView : public CView
{
protected: // create from serialization only
	CMDITestView() noexcept;
	DECLARE_DYNCREATE(CMDITestView)

// Attributes
public:
	CMDITestDoc* GetDocument() const;

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
	virtual ~CMDITestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in MDITestView.cpp
inline CMDITestDoc* CMDITestView::GetDocument() const
   { return reinterpret_cast<CMDITestDoc*>(m_pDocument); }
#endif

