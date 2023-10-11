// CSubclassEdit.cpp : implementation file
//

#include "pch.h"
#include "ModalessDialog.h"
#include "CSubclassEdit.h"


// CSubclassEdit

IMPLEMENT_DYNAMIC(CSubclassEdit, CEdit)

CSubclassEdit::CSubclassEdit()
{

}

CSubclassEdit::~CSubclassEdit()
{
}


BEGIN_MESSAGE_MAP(CSubclassEdit, CEdit)
	ON_WM_CHAR()
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()



// CSubclassEdit message handlers

// 연습 문제 09
void CSubclassEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar >= _T('0') && nChar <= _T('9') || nChar == _T('\b'))
		CEdit::OnChar(nChar, nRepCnt, nFlags);
}
// --

void CSubclassEdit::OnKillFocus(CWnd* pNewWnd)
{
	CEdit::OnKillFocus(pNewWnd);

	

	// TODO: Add your message handler code here
}
