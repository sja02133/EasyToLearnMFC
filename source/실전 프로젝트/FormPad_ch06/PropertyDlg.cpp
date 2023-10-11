// PropertyDlg.cpp : ���� �����Դϴ�.
//

#include "pch.h"
#include "FormPad.h"
#include "PropertyDlg.h"
#include "afxdialogex.h"


// CPropertyDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPropertyDlg, CDialog)

CPropertyDlg::CPropertyDlg( CPropertyBase *pDlg, CWnd* pParent /*=NULL*/)
	: CDialog(CPropertyDlg::IDD, pParent)
	, m_pChildDlg( pDlg )
{
}

CPropertyDlg::~CPropertyDlg()
{
}

void CPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPropertyDlg, CDialog)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CPropertyDlg �޽��� ó�����Դϴ�.

int CPropertyDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pChildDlg->Create( this );
	m_pChildDlg->ShowWindow( SW_SHOW );

	return 0;
}


BOOL CPropertyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CRect rect;
	GetClientRect( rect );
	m_pChildDlg->SetWindowPos( NULL, rect.left, rect.top,
		rect.Width(), rect.Height(),
		SWP_NOZORDER | SWP_SHOWWINDOW );

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
