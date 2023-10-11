#pragma once


// CWindowList dialog

class CWindowList : public CDialog
{
	DECLARE_DYNAMIC(CWindowList)

public:
	CWindowList(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CWindowList();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_WINDOWLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	// CListCtrl m_list;	// CListCtrl m_list;
	CListBox m_list;
	CString m_selectWindowText = _T("");
	CView* FindTargetView(CDocument* pDoc, CString& findStr);

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonActive();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonCheck();
	afx_msg void OnLbnSelchangeListboxWindow();
};
