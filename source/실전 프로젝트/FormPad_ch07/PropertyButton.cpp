// PropertyButton.cpp : ���� �����Դϴ�.
//

#include "pch.h"
#include "FormPad.h"
#include "PropertyButton.h"
#include "afxdialogex.h"


// CPropertyButton ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPropertyButton, CPropertyBase)

CPropertyButton::CPropertyButton(CWnd* pParent /*=NULL*/)
	: CPropertyBase(CPropertyButton::IDD, pParent)
	, m_strCaption(_T(""))
	, m_strPath(_T(""))
	, m_iAction(0)
{

}

CPropertyButton::~CPropertyButton()
{
}

void CPropertyButton::DoDataExchange(CDataExchange* pDX)
{
	CPropertyBase::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAPTION, m_strCaption);
	DDX_Text(pDX, IDC_EDIT_PATH, m_strPath);
	DDX_Radio(pDX, IDC_RADIO_ACTION, m_iAction);
}


BEGIN_MESSAGE_MAP(CPropertyButton, CPropertyBase)
	ON_BN_CLICKED(IDC_BUTTON_PATH, &CPropertyButton::OnBnClickedButtonPath)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO_ACTION, IDC_RADIO5, &CPropertyButton::OnRadio)
END_MESSAGE_MAP()


// CPropertyButton �޽��� ó�����Դϴ�.


BOOL CPropertyButton::OnInitDialog()
{
	CPropertyBase::OnInitDialog();

	OnRadio(m_iAction == 0 ? IDC_RADIO_ACTION : IDC_RADIO5);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CPropertyButton::OnRadio(UINT nID) 
{
	if (nID == IDC_RADIO_ACTION)
	{
		GetDlgItem(IDC_EDIT_PATH)->EnableWindow( TRUE );
		GetDlgItem(IDC_BUTTON_PATH)->EnableWindow( TRUE );
	}
	else
	{
		GetDlgItem(IDC_EDIT_PATH)->EnableWindow( FALSE );	
		GetDlgItem(IDC_BUTTON_PATH)->EnableWindow( FALSE );	
	}
}

void CPropertyButton::OnBnClickedButtonPath()
{
	UpdateData(TRUE);

	CFileDialog dlg(TRUE, NULL, m_strPath, OFN_FILEMUSTEXIST,
		_T("Excutable Files (*.exe)|*.exe|All Files (*.*)|*.*||") );
	
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		m_strPath = dlg.GetPathName();
		UpdateData(FALSE);
	}
	else if (nResponse == IDCANCEL)
	{
	}	
}
