
// SplitterDoc.h : interface of the CSplitterDoc class
//


#pragma once
#include <afxtempl.h>


class CSplitterDoc : public CDocument
{
protected: // create from serialization only
	CSplitterDoc() noexcept;
	DECLARE_DYNCREATE(CSplitterDoc)

// Attributes
public:
	CArray<CPoint, CPoint&> m_points;
	CArray<TCHAR, TCHAR> m_str;

	CBitmap bitmap;	// 연습 문제 14

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
	virtual ~CSplitterDoc();
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
};
