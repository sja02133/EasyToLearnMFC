
// WebBrowserView.h : interface of the CWebBrowserView class
//

#pragma once


class CWebBrowserView : public CHtmlView
{
protected: // create from serialization only
	CWebBrowserView() noexcept;
	DECLARE_DYNCREATE(CWebBrowserView)

// Attributes
public:
	CWebBrowserDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CWebBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWebsearchOpen();
	afx_msg void OnWebsearchBack();
	afx_msg void OnWebsearchForward();
	virtual void OnNavigateComplete2(LPCTSTR strURL);
};

#ifndef _DEBUG  // debug version in WebBrowserView.cpp
inline CWebBrowserDoc* CWebBrowserView::GetDocument() const
   { return reinterpret_cast<CWebBrowserDoc*>(m_pDocument); }
#endif

