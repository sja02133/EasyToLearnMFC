// PropertyMonthCal.cpp : ���� �����Դϴ�.
//

#include "pch.h"
#include "FormPad.h"
#include "PropertyMonthCal.h"


// CPropertyMonthCal ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPropertyMonthCal, CPropertyBase)

CPropertyMonthCal::CPropertyMonthCal(CWnd* pParent /*=NULL*/)
	: CPropertyBase(CPropertyMonthCal::IDD, pParent)
	, m_bNoToday(FALSE)
{
}

CPropertyMonthCal::~CPropertyMonthCal()
{
}

void CPropertyMonthCal::DoDataExchange(CDataExchange* pDX)
{
	CPropertyBase::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_NOTODAY, m_bNoToday);
}


BEGIN_MESSAGE_MAP(CPropertyMonthCal, CPropertyBase)
END_MESSAGE_MAP()


// CPropertyMonthCal �޽��� ó�����Դϴ�.
