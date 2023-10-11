#pragma once


// CHtmlCodeDialog dialog

class CHtmlCodeDialog : public CDialog
{
	DECLARE_DYNAMIC(CHtmlCodeDialog)

public:
	CHtmlCodeDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CHtmlCodeDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_code;
};
