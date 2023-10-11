// CMyListBox.cpp : implementation file
//

#include "pch.h"
#include "Reflection.h"
#include "CMyListBox.h"


// CMyListBox

IMPLEMENT_DYNAMIC(CMyListBox, CListBox)

CMyListBox::CMyListBox()
{

}

CMyListBox::~CMyListBox()
{
}


BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	ON_CONTROL_REFLECT(LBN_DBLCLK, &CMyListBox::OnLbnDblclk)
END_MESSAGE_MAP()



// CMyListBox message handlers




void CMyListBox::OnLbnDblclk()
{
	// TODO: Add your control notification handler code here
	CString str;
	int nIndex = GetCurSel();
	GetText(nIndex, str);
	MessageBox(str);
}
