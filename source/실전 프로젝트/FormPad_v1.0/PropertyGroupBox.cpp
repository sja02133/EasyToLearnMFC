// PropertyGroupBox.cpp : ���� �����Դϴ�.
//

#include "pch.h"
#include "FormPad.h"
#include "PropertyGroupBox.h"


// CPropertyGroupBox ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPropertyGroupBox, CPropertyBase)

CPropertyGroupBox::CPropertyGroupBox(CWnd* pParent /*=NULL*/)
	: CPropertyBase(CPropertyGroupBox::IDD, pParent)
	, m_strCaption(_T(""))
{
}

CPropertyGroupBox::~CPropertyGroupBox()
{
}

void CPropertyGroupBox::DoDataExchange(CDataExchange* pDX)
{
	CPropertyBase::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAPTION, m_strCaption);
}


BEGIN_MESSAGE_MAP(CPropertyGroupBox, CPropertyBase)
END_MESSAGE_MAP()


// CPropertyGroupBox �޽��� ó�����Դϴ�.
