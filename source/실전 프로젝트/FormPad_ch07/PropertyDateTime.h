#pragma once

#include "PropertyBase.h"

// CPropertyDateTime ��ȭ �����Դϴ�.

class CPropertyDateTime : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyDateTime)

public:
	CPropertyDateTime(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyDateTime();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_DATETIMEPICKER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	BOOL	m_bAlarm;
	CTime	m_tAlarm;

public:
	afx_msg void OnBnClickedButtonNow();

};
