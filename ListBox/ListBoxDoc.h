
// ListBoxDoc.h : interface of the CListBoxDoc class
//

#pragma once
#include "MainFrm.h"
#include "ListBoxView.h"

class CListBoxDoc : public CDocument
{
protected: // create from serialization only
	CListBoxDoc() noexcept;
	DECLARE_DYNCREATE(CListBoxDoc)

// Attributes
public:
	CMainFrame* pFrame;
	POSITION pos;
	CListBoxView* pView;

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
	virtual ~CListBoxDoc();
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
