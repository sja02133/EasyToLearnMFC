
// DialogBaseDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DialogBase.h"
#include "DialogBaseDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDialogBaseDlg dialog



CDialogBaseDlg::CDialogBaseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGBASE_DIALOG, pParent)
	, m_num1(1)
	, m_num2(45)
	, m_count(6)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDV_MinMaxInt(pDX, m_num1, 1, 99);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDV_MinMaxInt(pDX, m_num2, 1, 99);
	DDX_Text(pDX, IDC_EDIT3, m_count);
	DDV_MinMaxInt(pDX, m_count, 1, 99);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CDialogBaseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CDialogBaseDlg::OnBnClickedStart)
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// CDialogBaseDlg message handlers

BOOL CDialogBaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDialogBaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialogBaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDialogBaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDialogBaseDlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	if (UpdateData(TRUE) == 0)
		return;

	if (m_num1 >= m_num2) {
		MessageBox(_T("숫자1 >= 숫자2"), _T("오류!"), MB_ICONERROR);
		return;
	}

	m_list.ResetContent();
	srand((unsigned)time(NULL));

	// 기존
	//for (int i = 0; i < m_count; i++) {
	//	CString str;
	//	str.Format(_T("%02d"), 1 + rand() % (m_num2 - m_num1 + 1));
	//	m_list.AddString(str);
	//}
	// --
	
	// 연습 문제 14
	BOOL exactCheck = FALSE;
	int check_exit = 0;
	while (TRUE) {
		
		if (m_count == check_exit)
			break;

		int num = 1 + rand() % (m_num2 - m_num1 + 1);
		CString str;
		str.Format(_T("%02d"), num);
		while (!exactCheck) {
			int nIndex = m_list.FindStringExact(-1, str);
			if (nIndex == LB_ERR)
				exactCheck = TRUE;
			else {
				num = 1 + rand() % (m_num2 - m_num1 + 1);
				str.Format(_T("%02d"), num);
			}
		}
		m_list.AddString(str);
		exactCheck = FALSE;
		check_exit++;
	}
	// --


}


void CDialogBaseDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CColorDialog color_dlg;
	CDC* pDC = this->GetDC();

	// 설정 : 확장, 기본색(현재 배경 색상)
	color_dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	color_dlg.m_cc.rgbResult = pDC->GetBkColor();

	if (color_dlg.DoModal() == IDOK)
	{
		
		this->m_setColor = color_dlg.GetColor();
		this->SetBackgroundColor(this->m_setColor, TRUE);
		this->m_bChangeColor = TRUE;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL CDialogBaseDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	CRect rect;
	GetClientRect(&rect);
	
	if (!this->m_bChangeColor) {
		//pDC->FillSolidRect(&rect, this->default_color);
		pDC->SetBkMode(TRANSPARENT);
		return TRUE;
	}
	else {
		pDC->FillSolidRect(&rect, this->m_setColor);
	}
	return CDialogEx::OnEraseBkgnd(pDC);
}


void CDialogBaseDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//CFileDialog file_dlg;



	CDialogEx::OnLButtonDblClk(nFlags, point);
}
