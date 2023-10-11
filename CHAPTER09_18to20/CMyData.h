#pragma once


// CMyData view

class CMyData : public CEditView
{
	DECLARE_DYNCREATE(CMyData)

protected:
	CMyData();
	CMyData(CString& str, LOGFONT& lf);           // protected constructor used by dynamic creation
	virtual ~CMyData();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()


public:
	CString m_str;
	LOGFONT m_lf;
	
	virtual void Serialize(CArchive& ar);
};


