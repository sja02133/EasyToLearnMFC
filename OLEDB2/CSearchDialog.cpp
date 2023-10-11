// CSearchDialog.cpp : implementation file
//

//#include "pch.h"
#include "stdafx.h"
#include "OLEDB2.h"
#include "CSearchDialog.h"
#include "afxdialogex.h"


// CSearchDialog dialog

IMPLEMENT_DYNAMIC(CSearchDialog, CDialog)

CSearchDialog::CSearchDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_name(_T(""))
{

}

CSearchDialog::~CSearchDialog()
{
}

void CSearchDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
}


BEGIN_MESSAGE_MAP(CSearchDialog, CDialog)
END_MESSAGE_MAP()


// CSearchDialog message handlers
