// CBitmapDoc.cpp : implementation file
//

#include "pch.h"
#include "MDITest.h"
#include "CBitmapDoc.h"


// CBitmapDoc

IMPLEMENT_DYNCREATE(CBitmapDoc, CDocument)

CBitmapDoc::CBitmapDoc()
{
}

BOOL CBitmapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	this->m_bitmap.LoadBitmap(IDR_MAINFRAME);

	return TRUE;
}

CBitmapDoc::~CBitmapDoc()
{
}


BEGIN_MESSAGE_MAP(CBitmapDoc, CDocument)
END_MESSAGE_MAP()


// CBitmapDoc diagnostics

#ifdef _DEBUG
void CBitmapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CBitmapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CBitmapDoc serialization

void CBitmapDoc::Serialize(CArchive& ar)
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


// CBitmapDoc commands
