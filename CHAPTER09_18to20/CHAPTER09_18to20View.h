
// CHAPTER09_18to20View.h : interface of the CCHAPTER0918to20View class
//

#pragma once


class CCHAPTER0918to20View : public CEditView
{
protected: // create from serialization only
	CCHAPTER0918to20View() noexcept;
	DECLARE_DYNCREATE(CCHAPTER0918to20View)

// Attributes
public:
	CCHAPTER0918to20Doc* GetDocument() const;

	CFindReplaceDialog* dlg;
	CString m_rememberStr = _T("");
	int m_rememberBeforePos = 0;

	LOGFONT m_saveLF;
	COLORREF m_fontColor;
	CFont m_rem_font;
	BOOL check_changeColor = FALSE;
// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCHAPTER0918to20View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEditFind();
	afx_msg void OnUpdateEditFind(CCmdUI* pCmdUI);
	afx_msg void OnEditRepeat();
	afx_msg void OnUpdateEditRepeat(CCmdUI* pCmdUI);
	afx_msg void OnEditReplace();
	afx_msg void OnUpdateEditReplace(CCmdUI* pCmdUI);
//	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
protected:
	LRESULT OnFindReplaceCmd(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnFormatFont();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
	virtual void Serialize(CArchive& ar);
};

#ifndef _DEBUG  // debug version in CHAPTER09_18to20View.cpp
inline CCHAPTER0918to20Doc* CCHAPTER0918to20View::GetDocument() const
   { return reinterpret_cast<CCHAPTER0918to20Doc*>(m_pDocument); }
#endif

