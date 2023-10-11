#pragma once


// CSearchDialog dialog

class CSearchDialog : public CDialog
{
	DECLARE_DYNAMIC(CSearchDialog)

public:
	CSearchDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSearchDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
};
