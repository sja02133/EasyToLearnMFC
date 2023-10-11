#pragma once


// CMyDialog dialog

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
	CComboBox m_combo;
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedClear();

	CString m_str = _T("");
	int m_font = 0;

	virtual void OnCancel();
	afx_msg void OnBnClickedCancel();

	// 연습 문제 02
	BOOL m_clickedCancel = FALSE;

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int m_size;
	CComboBox m_color;
	int m_selectColor = 0; 
	afx_msg void OnBnClickedBold();

	BOOL checkBold = FALSE;

	CButton m_bold;
};
