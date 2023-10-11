// PropertyComboBox.cpp : ���� �����Դϴ�.
//

#include "pch.h"
#include "FormPad.h"
#include "PropertyComboBox.h"


// CPropertyComboBox ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPropertyComboBox, CPropertyBase)

CPropertyComboBox::CPropertyComboBox(CWnd* pParent /*=NULL*/)
	: CPropertyBase(CPropertyComboBox::IDD, pParent)
	, m_strName(_T(""))
{
}

CPropertyComboBox::~CPropertyComboBox()
{
}

void CPropertyComboBox::DoDataExchange(CDataExchange* pDX)
{
	CPropertyBase::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAPTION, m_strName);
}


BEGIN_MESSAGE_MAP(CPropertyComboBox, CPropertyBase)
END_MESSAGE_MAP()


// CPropertyComboBox �޽��� ó�����Դϴ�.
