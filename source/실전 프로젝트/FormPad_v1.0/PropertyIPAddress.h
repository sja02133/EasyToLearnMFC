#pragma once

#include "PropertyBase.h"

class CMyComboBox;

// CPropertyIPAddress ��ȭ �����Դϴ�.

class CPropertyIPAddress : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyIPAddress)

public:
	CPropertyIPAddress(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyIPAddress();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_IPADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	CComboBox		m_ctrlCombo;
	int				m_iAction;
	CMyComboBox	*	m_pCombo;

public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();

};
