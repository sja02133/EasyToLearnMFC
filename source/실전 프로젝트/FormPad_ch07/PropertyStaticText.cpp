// PropertyStaticText.cpp : ���� �����Դϴ�.
//

#include "pch.h"
#include "FormPad.h"
#include "PropertyStaticText.h"


// CPropertyStaticText ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPropertyStaticText, CPropertyBase)

CPropertyStaticText::CPropertyStaticText(CWnd* pParent /*=NULL*/)
	: CPropertyBase(CPropertyStaticText::IDD, pParent)
	, m_bWebLink(FALSE)
	, m_strCaption(_T(""))
{
}

CPropertyStaticText::~CPropertyStaticText()
{
}

void CPropertyStaticText::DoDataExchange(CDataExchange* pDX)
{
	CPropertyBase::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_WEBLINK, m_bWebLink);
	DDX_Text(pDX, IDC_EDIT_CAPTION, m_strCaption);
}


BEGIN_MESSAGE_MAP(CPropertyStaticText, CPropertyBase)
END_MESSAGE_MAP()


// CPropertyStaticText �޽��� ó�����Դϴ�.
