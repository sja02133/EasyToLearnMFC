#pragma once

#include "PropertyBase.h"

// CPropertyStaticText ��ȭ �����Դϴ�.

class CPropertyStaticText : public CPropertyBase
{
	DECLARE_DYNAMIC(CPropertyStaticText)

public:
	CPropertyStaticText(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPropertyStaticText();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPERTY_STATICTEXT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	BOOL	m_bWebLink;
	CString	m_strCaption;

};
