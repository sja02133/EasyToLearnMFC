
// HtmlViewTestView.h : interface of the CHtmlViewTestView class
//

#pragma once

class CHtmlViewTestView : public CHtmlView
{
protected: // create from serialization only
	CHtmlViewTestView() noexcept;
	DECLARE_DYNCREATE(CHtmlViewTestView)

// Attributes
public:
	CHtmlViewTestDoc* GetDocument() const;

	
// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CHtmlViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHtmlInputhtml();
};

#ifndef _DEBUG  // debug version in HtmlViewTestView.cpp
inline CHtmlViewTestDoc* CHtmlViewTestView::GetDocument() const
   { return reinterpret_cast<CHtmlViewTestDoc*>(m_pDocument); }
#endif

