#pragma once

#include "PropertyBase.h"

// CPropertyMonthCal ��ȭ �����Դϴ�.

class CPropertyMonthCal : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyMonthCal)

public:
	CPropertyMonthCal(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyMonthCal();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_MONTHCALENDAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	BOOL	m_bNoToday;

};
