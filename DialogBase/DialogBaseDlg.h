
// DialogBaseDlg.h : header file
//

#pragma once


// CDialogBaseDlg dialog
class CDialogBaseDlg : public CDialogEx
{
// Construction
public:
	CDialogBaseDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBASE_DIALOG };
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
	int m_num1;
	int m_num2;
	int m_count;
	CListBox m_list;
	afx_msg void OnBnClickedStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	BOOL m_bChangeColor = FALSE;
	//COLORREF default_color = RGB(240, 240, 240);
	COLORREF default_color = RGB(255, 255, 255);
	COLORREF m_setColor;

	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};
