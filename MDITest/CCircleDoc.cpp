// CCircleDoc.cpp : implementation file
//

#include "pch.h"
#include "MDITest.h"
#include "CCircleDoc.h"


// CCircleDoc

IMPLEMENT_DYNCREATE(CCircleDoc, CDocument)

CCircleDoc::CCircleDoc()
{
	
}

BOOL CCircleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_points.RemoveAll();


	return TRUE;
}

CCircleDoc::~CCircleDoc()
{
}


BEGIN_MESSAGE_MAP(CCircleDoc, CDocument)
END_MESSAGE_MAP()


// CCircleDoc diagnostics

#ifdef _DEBUG
void CCircleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CCircleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CCircleDoc serialization

void CCircleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}
#endif


// CCircleDoc commands
