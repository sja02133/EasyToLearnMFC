#pragma once


// CAddDialog dialog

class CAddDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddDialog)

public:
	CAddDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_item;
	UINT m_price;
	UINT m_count;
};
