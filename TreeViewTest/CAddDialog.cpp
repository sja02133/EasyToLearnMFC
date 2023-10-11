// CAddDialog.cpp : implementation file
//

#include "pch.h"
#include "TreeViewTest.h"
#include "CAddDialog.h"
#include "afxdialogex.h"


// CAddDialog dialog

IMPLEMENT_DYNAMIC(CAddDialog, CDialog)

CAddDialog::CAddDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_name(_T(""))
{

}

CAddDialog::~CAddDialog()
{
}

void CAddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
}


BEGIN_MESSAGE_MAP(CAddDialog, CDialog)
END_MESSAGE_MAP()


// CAddDialog message handlers
