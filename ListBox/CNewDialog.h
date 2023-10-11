#pragma once


// CNewDialog dialog

class CNewDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CNewDialog)

public:
	CNewDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CNewDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo1;
	CComboBox m_combo2;
};
