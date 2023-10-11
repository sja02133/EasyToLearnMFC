
// ImageListView.h : interface of the CImageListView class
//

#pragma once


class CImageListView : public CView
{
protected: // create from serialization only
	CImageListView() noexcept;
	DECLARE_DYNCREATE(CImageListView)

// Attributes
public:
	CImageListDoc* GetDocument() const;

	CImageList m_il;

	UINT selectNum = 0;	// 연습 문제 01, 최대 8까지

	CComboBoxEx m_combo;	// 연습 문제 06

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
	virtual ~CImageListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in ImageListView.cpp
inline CImageListDoc* CImageListView::GetDocument() const
   { return reinterpret_cast<CImageListDoc*>(m_pDocument); }
#endif

