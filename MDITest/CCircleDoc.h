#pragma once

// CCircleDoc document

#include <afxtempl.h>

class CCircleDoc : public CDocument
{
	DECLARE_DYNCREATE(CCircleDoc)

public:
	CCircleDoc();
	virtual ~CCircleDoc();

public:
	CArray<CPoint, CPoint&> m_points;

#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
};
