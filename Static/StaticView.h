
// StaticView.h : interface of the CStaticView class
//

#pragma once


class CStaticView : public CFormView
{
protected: // create from serialization only
	CStaticView() noexcept;
	DECLARE_DYNCREATE(CStaticView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_STATIC_FORM };
#endif

// Attributes
public:
	CStaticDoc* GetDocument() const;

	BOOL m_bMetaClick = FALSE;	// 연습 문제 08

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CStaticView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_metafile;
	CStatic m_bitmap;
	afx_msg void OnClickedMetafile();
	afx_msg void OnClickedStaticBitmap();
};

#ifndef _DEBUG  // debug version in StaticView.cpp
inline CStaticDoc* CStaticView::GetDocument() const
   { return reinterpret_cast<CStaticDoc*>(m_pDocument); }
#endif

