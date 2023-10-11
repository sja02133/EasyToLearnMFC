// CAddDialog.cpp : implementation file
//

#include "pch.h"
#include "ListViewTest.h"
#include "CAddDialog.h"
#include "afxdialogex.h"


// CAddDialog dialog

IMPLEMENT_DYNAMIC(CAddDialog, CDialog)

CAddDialog::CAddDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_item(_T(""))
	, m_price(0)
	, m_count(0)
{

}

CAddDialog::~CAddDialog()
{
}

void CAddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ITEM, m_item);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_price);
	DDX_Text(pDX, IDC_EDIT_COUNT, m_count);
}


BEGIN_MESSAGE_MAP(CAddDialog, CDialog)
END_MESSAGE_MAP()


// CAddDialog message handlers
