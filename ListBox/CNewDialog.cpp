// CNewDialog.cpp : implementation file
//

#include "pch.h"
#include "ListBox.h"
#include "CNewDialog.h"
#include "afxdialogex.h"


// CNewDialog dialog

IMPLEMENT_DYNAMIC(CNewDialog, CDialogEx)

CNewDialog::CNewDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CNewDialog::~CNewDialog()
{
}

void CNewDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
}


BEGIN_MESSAGE_MAP(CNewDialog, CDialogEx)
END_MESSAGE_MAP()


// CNewDialog message handlers
