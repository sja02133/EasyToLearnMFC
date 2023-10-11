
// InputSaveLoadView.h : interface of the CInputSaveLoadView class
//

#pragma once


class CInputSaveLoadView : public CView
{
protected: // create from serialization only
	CInputSaveLoadView() noexcept;
	DECLARE_DYNCREATE(CInputSaveLoadView)

// Attributes
public:
	CInputSaveLoadDoc* GetDocument() const;

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
	virtual ~CInputSaveLoadView();
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

#ifndef _DEBUG  // debug version in InputSaveLoadView.cpp
inline CInputSaveLoadDoc* CInputSaveLoadView::GetDocument() const
   { return reinterpret_cast<CInputSaveLoadDoc*>(m_pDocument); }
#endif

