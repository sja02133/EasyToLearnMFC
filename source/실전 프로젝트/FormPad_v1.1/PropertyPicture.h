#pragma once

#include "PropertyBase.h"

// CPropertyPicture ��ȭ �����Դϴ�.

class CPropertyPicture : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyPicture)

public:
	CPropertyPicture(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyPicture();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_PICTURE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	CString	m_strPath;
	int		m_iAction;

public:
	afx_msg void OnBnClickedButtonPath();

};
