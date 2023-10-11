#pragma once


// CMyDialog dialog

class CModalDialog3View;

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
	afx_msg void OnBnClickedClear();
	CString m_str;
	int m_font;
	int m_size;
	int m_xPos;
	int m_yPos;
	CModalDialog3View* pView;
	CRect m_rectView;
};
