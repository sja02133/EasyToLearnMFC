// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "ModalDialog2.h"
#include "CMyDialog.h"
#include "afxdialogex.h"


// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_size(10)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FONT, m_combo);
	DDX_Text(pDX, IDC_SIZE, m_size);
	DDX_Control(pDX, IDC_COMBO_COLOR, m_color);
	DDX_Control(pDX, IDC_BOLD, m_bold);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_CLEAR, &CMyDialog::OnClickedClear)
	ON_BN_CLICKED(IDCANCEL, &CMyDialog::OnBnClickedCancel)
	ON_WM_SYSCOMMAND()
	ON_BN_CLICKED(IDC_BOLD, &CMyDialog::OnBnClickedBold)
END_MESSAGE_MAP()


// CMyDialog message handlers


void CMyDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	GetDlgItemText(IDC_STR, m_str);
	m_font = m_combo.GetCurSel();

	// 연습 문제 04
	m_selectColor = m_color.GetCurSel();
	// --

	checkBold = m_bold.GetCheck();	// 연습 문제 05

	CDialog::OnOK();
}


BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	SetDlgItemText(IDC_STR, m_str);
	m_combo.SetCurSel(m_font);

	// 연습 문제 04
	m_color.SetCurSel(m_selectColor);
	// --

	// 연습 문제 05
	m_bold.SetCheck(checkBold);
	// --

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CMyDialog::OnClickedClear()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDC_CLEAR);
}

// 연습 문제 02
void CMyDialog::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	if (this->m_clickedCancel) {
		this->m_clickedCancel = FALSE;
		CDialog::OnCancel();
	}

}

void CMyDialog::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	this->m_clickedCancel = TRUE;
	OnCancel();
}


void CMyDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: Add your message handler code here and/or call default
	if (nID == SC_CLOSE)
		EndDialog(IDCANCEL);

	CDialog::OnSysCommand(nID, lParam);
}


BOOL CMyDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}
// --

// 연습 문제 05
void CMyDialog::OnBnClickedBold()
{
	// TODO: Add your control notification handler code here
	this->checkBold = !this->checkBold;
	this->m_bold.SetCheck(this->checkBold);
}
// --
