#pragma once

#include "PropertyBase.h"

// CPropertyAnimate ��ȭ �����Դϴ�.

class CPropertyAnimate : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyAnimate)

public:
	CPropertyAnimate(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyAnimate();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_ANIMATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	CString m_strPath;

public:
	afx_msg void OnBnClickedButtonPath();

};
