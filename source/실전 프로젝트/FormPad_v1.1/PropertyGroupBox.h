#pragma once

#include "PropertyBase.h"

// CPropertyGroupBox ��ȭ �����Դϴ�.

class CPropertyGroupBox : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyGroupBox)

public:
	CPropertyGroupBox(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyGroupBox();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_GROUPBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()
public:
	CString	m_strCaption;

};
