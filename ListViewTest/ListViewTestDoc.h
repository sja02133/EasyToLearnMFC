
// ListViewTestDoc.h : interface of the CListViewTestDoc class
//


#pragma once

struct MYITEM {
	CString name;
	int price;
	int quantity;
};

const int NUMITEM = 500;


class CListViewTestDoc : public CDocument
{
protected: // create from serialization only
	CListViewTestDoc() noexcept;
	DECLARE_DYNCREATE(CListViewTestDoc)

// Attributes
public:
	MYITEM m_item[NUMITEM];


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
	virtual ~CListViewTestDoc();
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
