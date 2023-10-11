// CMyData.cpp : implementation file
//

#include "pch.h"
#include "CHAPTER09_18to20.h"
#include "CMyData.h"


// CMyData

IMPLEMENT_DYNCREATE(CMyData, CEditView)

CMyData::CMyData()
{

}

CMyData::CMyData(CString& str, LOGFONT& lf)
{
	m_str = str;
	m_lf = lf;
}

CMyData::~CMyData()
{
}

BEGIN_MESSAGE_MAP(CMyData, CEditView)
END_MESSAGE_MAP()


// CMyData diagnostics

#ifdef _DEBUG
void CMyData::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyData::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyData message handlers


void CMyData::Serialize(CArchive& ar)
{
	CEditView::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		this->WriteToArchive(ar);
	}
	else
	{	// loading code
		this->ReadFromArchive(ar);
	}
}
