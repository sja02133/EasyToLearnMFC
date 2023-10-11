// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "ModalDialog3.h"
#include "CMyDialog.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "ModalDialog3Doc.h"
#include "ModalDialog3View.h"

// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_str(_T(""))
	, m_font(0)
	, m_size(10)	// 연습 문제 06 (0) -> (10)
	, m_xPos(0)
	, m_yPos(0)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	pView = (CModalDialog3View*)pFrame->GetActiveView();
	pView->GetWindowRect(&this->m_rectView);
	
}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR, m_str);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
	DDX_Text(pDX, IDC_EDIT2, m_size);
	DDV_MinMaxInt(pDX, m_size, 10, 40);	// 연습 문제 06
	DDX_Text(pDX, IDC_EDIT3, m_xPos);
	DDX_Text(pDX, IDC_EDIT4, m_yPos);
	DDV_MinMaxInt(pDX, m_xPos, 0, this->m_rectView.right);
	DDV_MinMaxInt(pDX, m_yPos, 0, this->m_rectView.bottom);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_CLEAR, &CMyDialog::OnBnClickedClear)
END_MESSAGE_MAP()


// CMyDialog message handlers


void CMyDialog::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDC_CLEAR);
}
