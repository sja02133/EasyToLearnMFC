#pragma once

#include "PropertyBase.h"

// CPropertyButton ��ȭ �����Դϴ�.

class CPropertyButton : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyButton)

public:
	CPropertyButton(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyButton();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_BUTTON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	CString m_strCaption;
	CString m_strPath;
	int m_iAction;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonPath();
	afx_msg void OnRadio(UINT nID);

};
