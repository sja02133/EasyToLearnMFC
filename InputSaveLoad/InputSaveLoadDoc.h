
// InputSaveLoadDoc.h : interface of the CInputSaveLoadDoc class
//


#pragma once

#include <afxtempl.h>


class CInputSaveLoadDoc : public CDocument
{
protected: // create from serialization only
	CInputSaveLoadDoc() noexcept;
	DECLARE_DYNCREATE(CInputSaveLoadDoc)

// Attributes
public:
	CArray<TCHAR, TCHAR> m_str;
	BOOL m_bItalic, m_bUnderline;

	// 연습 문제 18
	BOOL m_bBold = FALSE;

	// 연습 문제 19
	COLORREF m_selectColor = RGB(255,0,0);
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CInputSaveLoadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnUpdateStyleItalic(CCmdUI* pCmdUI);
	afx_msg void OnUpdateStyleUnderline(CCmdUI* pCmdUI);
	afx_msg void OnStyleItalic();
	afx_msg void OnStyleUnderline();
	afx_msg void OnStyleBold();
	afx_msg void OnUpdateStyleBold(CCmdUI* pCmdUI);
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
};
