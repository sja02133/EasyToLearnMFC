// CHtmlCodeDialog.cpp : implementation file
//

#include "pch.h"
#include "HtmlViewTest.h"
#include "CHtmlCodeDialog.h"
#include "afxdialogex.h"


// CHtmlCodeDialog dialog

IMPLEMENT_DYNAMIC(CHtmlCodeDialog, CDialog)

CHtmlCodeDialog::CHtmlCodeDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_code(_T(""))
{

}

CHtmlCodeDialog::~CHtmlCodeDialog()
{
}

void CHtmlCodeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_code);
}


BEGIN_MESSAGE_MAP(CHtmlCodeDialog, CDialog)
END_MESSAGE_MAP()


// CHtmlCodeDialog message handlers
