
// FindReplaceView.h : interface of the CFindReplaceView class
//

#pragma once


class CFindReplaceView : public CView
{
protected: // create from serialization only
	CFindReplaceView() noexcept;
	DECLARE_DYNCREATE(CFindReplaceView)

// Attributes
public:
	CFindReplaceDoc* GetDocument() const;

	CFindReplaceDialog* pDlg;

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
	virtual ~CFindReplaceView();
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
protected:
	LRESULT OnFindReplaceCmd(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // debug version in FindReplaceView.cpp
inline CFindReplaceDoc* CFindReplaceView::GetDocument() const
   { return reinterpret_cast<CFindReplaceDoc*>(m_pDocument); }
#endif

