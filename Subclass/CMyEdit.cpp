// CMyEdit.cpp : implementation file
//

#include "pch.h"
#include "Subclass.h"
#include "CMyEdit.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CMyEdit message handlers




void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if ((nChar >= _T('0') && nChar <= _T('9')) || nChar == _T('-') || nChar == _T('\b'))
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
}
