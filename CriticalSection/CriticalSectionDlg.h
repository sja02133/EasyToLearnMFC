
// CriticalSectionDlg.h : header file
//

#pragma once


// CCriticalSectionDlg dialog
class CCriticalSectionDlg : public CDialogEx
{
// Construction
public:
	CCriticalSectionDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CRITICALSECTION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_button1;
	CButton m_button2;
	CProgressCtrl m_progress1;
	CProgressCtrl m_progress2;
	afx_msg void OnBnClickedStart();
};
