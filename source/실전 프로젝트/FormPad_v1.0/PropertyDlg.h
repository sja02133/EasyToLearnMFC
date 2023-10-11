#pragma once

#include "PropertyBase.h"

// CPropertyDlg ��ȭ �����Դϴ�.

class CPropertyDlg : public CDialog
{
	DECLARE_DYNAMIC(CPropertyDlg)

public:
	CPropertyDlg( CPropertyBase *pDlg, CWnd* pParent = NULL );   // ǥ�� �������Դϴ�.
	virtual ~CPropertyDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CONTROL_PROPERTY };

protected:
	CPropertyBase	*	m_pChildDlg;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
};
