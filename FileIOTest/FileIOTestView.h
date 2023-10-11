
// FileIOTestView.h : interface of the CFileIOTestView class
//

#pragma once


class CFileIOTestView : public CView
{
protected: // create from serialization only
	CFileIOTestView() noexcept;
	DECLARE_DYNCREATE(CFileIOTestView)

// Attributes
public:
	CFileIOTestDoc* GetDocument() const;

	// 연습 문제 02, 03
	CMemFile memFile;
	BOOL m_bExistData = FALSE;

	// 연습 문제 04
	CString m_str;

	// 연습 문제 05
	CStringList m_CStringListFile;

	// 연습 문제 13
	CImage image;
	BOOL m_bImage = FALSE;

	// 연습 문제 14
	CList<CPoint, POINT&> m_listPoint;
	BOOL m_bDrawMode = FALSE;
	int m_x1, m_y1, m_x2, m_y2;

	// 연습 문제 15
	CPoint m_saveMousePoint;

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
	virtual ~CFileIOTestView();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in FileIOTestView.cpp
inline CFileIOTestDoc* CFileIOTestView::GetDocument() const
   { return reinterpret_cast<CFileIOTestDoc*>(m_pDocument); }
#endif

