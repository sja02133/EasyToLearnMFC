#pragma once

class CModalessDialogView;
// CMyDialog dialog

#include "CSubclassEdit.h"

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMyDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	int m_font;

	CModalessDialogView* m_pView;

	afx_msg void OnBnClickedApply();
	virtual void OnCancel();
	virtual void PostNcDestroy();
	int m_size;
	int m_beforeSize = 0;

	CSubclassEdit m_editSub;

	virtual BOOL OnInitDialog();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnEnChangeStr();
	afx_msg void OnCbnSelchangeFont();
	afx_msg void OnBnClickedButtonChoiceColor();
	CString m_rgbInfo;
	afx_msg void OnBnClickedButtonChoiceFont();
	CComboBox m_cFont;
};
