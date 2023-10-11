
// EventDlg.h : header file
//

#pragma once


// CEventDlg dialog
class CEventDlg : public CDialogEx
{
// Construction
public:
	CEventDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EVENT_DIALOG };
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
	CProgressCtrl m_progress1;
	CProgressCtrl m_progress2;
	CProgressCtrl m_progress3;
	CProgressCtrl m_progress4;
	afx_msg void OnBnClickedStart();
};
