#pragma once

#include "PropertyBase.h"

// CPropertyComboBox ��ȭ �����Դϴ�.

class CPropertyComboBox : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyComboBox)

public:
	CPropertyComboBox(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyComboBox();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_COMBOBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	CString	m_strName;

};
