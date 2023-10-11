
// ModalessDialogView.h : interface of the CModalessDialogView class
//

#pragma once
class CMyDialog;

class CModalessDialogView : public CView
{
protected: // create from serialization only
	CModalessDialogView() noexcept;
	DECLARE_DYNCREATE(CModalessDialogView)

// Attributes
public:
	CModalessDialogDoc* GetDocument() const;

	CMyDialog* m_pDlg;
	CString m_str;
	int m_font;

	int m_size;	// 연습 문제 09

	COLORREF m_textColor = RGB(0,0,0);	// 연습 문제 11

	CString font_FaceName = _T("");	// 연습 문제 12

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
	virtual ~CModalessDialogView();
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

#ifndef _DEBUG  // debug version in ModalessDialogView.cpp
inline CModalessDialogDoc* CModalessDialogView::GetDocument() const
   { return reinterpret_cast<CModalessDialogDoc*>(m_pDocument); }
#endif

