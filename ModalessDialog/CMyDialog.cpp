// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "ModalessDialog.h"
#include "CMyDialog.h"
#include "afxdialogex.h"

#include "ModalessDialogDoc.h"
#include "ModalessDialogView.h"

// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_str(_T(""))
	, m_font(0)
	, m_size(10)
	, m_rgbInfo(_T(""))
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR, m_str);
	DDV_MaxChars(pDX, m_str, 10);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
	DDX_Text(pDX, IDC_EDIT1, m_size);
	//DDV_MinMaxInt(pDX, m_size, 10, 40);
	DDX_Text(pDX, IDC_STATIC_COLOR, m_rgbInfo);
	DDX_Control(pDX, IDC_FONT, m_cFont);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDAPPLY, &CMyDialog::OnBnClickedApply)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CMyDialog::OnEnKillfocusEdit1)
	ON_EN_SETFOCUS(IDC_EDIT1, &CMyDialog::OnEnSetfocusEdit1)
	ON_EN_CHANGE(IDC_STR, &CMyDialog::OnEnChangeStr)
	ON_CBN_SELCHANGE(IDC_FONT, &CMyDialog::OnCbnSelchangeFont)
	ON_BN_CLICKED(IDC_BUTTON_CHOICE_COLOR, &CMyDialog::OnBnClickedButtonChoiceColor)
	ON_BN_CLICKED(IDC_BUTTON_CHOICE_FONT, &CMyDialog::OnBnClickedButtonChoiceFont)
END_MESSAGE_MAP()


// CMyDialog message handlers


void CMyDialog::OnBnClickedApply()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_pView->m_str = m_str;
	m_pView->m_font = m_font;
	m_pView->Invalidate();
}


void CMyDialog::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	DestroyWindow();
}


void CMyDialog::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	m_pView->m_pDlg = NULL;
	delete this;

	CDialog::PostNcDestroy();
}


BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	m_editSub.SubclassDlgItem(IDC_EDIT1, this);	// 연습 문제 09

	// 연습 문제 11
	this->m_rgbInfo.Format(_T(" 색상 : R(%d), G(%d), B(%d)"), GetRValue(m_pView->m_textColor),
		GetGValue(m_pView->m_textColor), GetBValue(m_pView->m_textColor));
	UpdateData(FALSE);
	// --
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

// 연습 문제 09
void CMyDialog::OnEnKillfocusEdit1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (this->m_size < 10 || this->m_size > 40) {
		m_size = m_beforeSize;
	}
	else
		m_beforeSize = m_size;

	// 연습 문제 10
	m_pView->m_size = m_size;
	m_pView->Invalidate();
	// --
	UpdateData(FALSE);
}


void CMyDialog::OnEnSetfocusEdit1()
{
	// TODO: Add your control notification handler code here
	m_beforeSize = m_size;
}
// --

// 연습 문제 10
void CMyDialog::OnEnChangeStr()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(TRUE);
	m_pView->m_str = m_str;
	m_pView->m_font = m_font;
	m_pView->m_size = m_size;
	m_pView->Invalidate();
}


void CMyDialog::OnCbnSelchangeFont()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_pView->m_str = m_str;
	m_pView->m_font = m_font;
	m_pView->m_size = m_size;
	CString str;
	this->m_cFont.GetLBText(this->m_cFont.GetCurSel(), str);
	m_pView->font_FaceName = str;
	m_pView->Invalidate();
}
// --

// 연습 문제 11
void CMyDialog::OnBnClickedButtonChoiceColor()
{
	// TODO: Add your control notification handler code here
	CColorDialog color_dlg;

	// 설정 : 확장, 기본색(현재 텍스트 색상)
	color_dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	color_dlg.m_cc.rgbResult = m_pView->m_textColor;

	if (color_dlg.DoModal() == IDOK)
	{
		COLORREF color = color_dlg.GetColor();
		m_pView->m_textColor = color;
		this->m_rgbInfo.Format(_T(" 색상 : R(%d), G(%d), B(%d)"), GetRValue(m_pView->m_textColor),
			GetGValue(m_pView->m_textColor), GetBValue(m_pView->m_textColor));
		UpdateData(FALSE);
		m_pView->Invalidate();
	}
}
// --

// 연습 문제 12
void CMyDialog::OnBnClickedButtonChoiceFont()
{
	// TODO: Add your control notification handler code here
	CFontDialog font_dlg;
	
	if (font_dlg.DoModal() == IDOK) {
		m_pView->m_textColor = font_dlg.GetColor();
		this->m_rgbInfo.Format(_T(" 색상 : R(%d), G(%d), B(%d)"), GetRValue(m_pView->m_textColor),
			GetGValue(m_pView->m_textColor), GetBValue(m_pView->m_textColor));

		
		CString fontStr = font_dlg.GetFaceName();
		BOOL check = TRUE;
		if (fontStr.IsEmpty()) {
			check = FALSE;
		}
		int count = this->m_cFont.GetCount();
		
		for (int i = 0; i < count && check == TRUE; i++) {
			CString tempStr = _T("");
			this->m_cFont.GetLBText(i, tempStr);
			if (tempStr.Compare(fontStr) == 0)
				check == FALSE;
		}

		if (check == TRUE) {
			this->m_cFont.AddString(fontStr);
			m_pView->font_FaceName = fontStr;
			this->m_cFont.SetCurSel(this->m_cFont.GetCount());
		}

		m_pView->m_size = font_dlg.GetSize() / 10;
		m_size = font_dlg.GetSize() / 10;

		UpdateData(TRUE);
		m_pView->Invalidate();
	}
}
// --