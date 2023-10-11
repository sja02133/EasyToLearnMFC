
// CriticalSectionDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CriticalSection.h"
#include "CriticalSectionDlg.h"
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


// CCriticalSectionDlg dialog



CCriticalSectionDlg::CCriticalSectionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CRITICALSECTION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCriticalSectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress1);
	DDX_Control(pDX, IDC_PROGRESS2, m_progress2);
}

BEGIN_MESSAGE_MAP(CCriticalSectionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CCriticalSectionDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// CCriticalSectionDlg message handlers

BOOL CCriticalSectionDlg::OnInitDialog()
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
	m_progress1.SetRange(0, 100);
	m_progress1.SetPos(0);
	m_progress2.SetRange(0, 100);
	m_progress2.SetPos(0);



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCriticalSectionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCriticalSectionDlg::OnPaint()
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
HCURSOR CCriticalSectionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CCriticalSection g_cs;

void UpdateIndex(LPCTSTR pszName, CCriticalSectionDlg* pDlg, int i)
{
	g_cs.Lock();
	{
		CString str;
		str.Format(_T("[%s] %d"), pszName, i);
		pDlg->GetDlgItem(IDC_START)->SetWindowText(str);
		::Sleep(10);
	}
	g_cs.Unlock();
}

CString Get_WindowTextToCString(CButton* but) {
	CString str;
	but->GetWindowText(str);
	return str;
}

UINT Thread1(LPVOID pParam)
{
	CCriticalSectionDlg* ptr = (CCriticalSectionDlg*)pParam;
	ptr->m_button1.SetWindowText(_T("스레드 1 시작"));
	ptr->m_progress1.SetPos(0);

	//g_cs.Lock();
	for (int i = 0; i <= 100; i++) {
		ptr->m_progress1.SetPos(i);

		UpdateIndex(Get_WindowTextToCString(&ptr->m_button1), ptr, i);	// 연습 문제 06

		::Sleep(10);
	}
	//g_cs.Unlock();

	ptr->m_button1.SetWindowText(_T(""));
	return 0;
}

UINT Thread2(LPVOID pParam)
{
	CCriticalSectionDlg* ptr = (CCriticalSectionDlg*)pParam;
	ptr->m_button2.SetWindowText(_T("스레드 2 시작"));
	ptr->m_progress2.SetPos(0);

	//g_cs.Lock();
	for (int i = 0; i <= 100; i++) {
		ptr->m_progress2.SetPos(i);

		UpdateIndex(Get_WindowTextToCString(&ptr->m_button2), ptr, i);	// 연습 문제 06

		::Sleep(10);
	}
	//g_cs.Unlock();

	ptr->m_button2.SetWindowText(_T(""));
	return 0;
}

void CCriticalSectionDlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	srand((unsigned)time(NULL));
	if (rand() % 2 == 0) {
		AfxBeginThread(Thread1, this);
		AfxBeginThread(Thread2, this);
	}
	else {
		AfxBeginThread(Thread2, this);
		AfxBeginThread(Thread1, this);
	}
}


