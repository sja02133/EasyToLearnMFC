
// EventDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Event.h"
#include "EventDlg.h"
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


// CEventDlg dialog



CEventDlg::CEventDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EVENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEventDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress1);
	DDX_Control(pDX, IDC_PROGRESS2, m_progress2);
	DDX_Control(pDX, IDC_PROGRESS3, m_progress3);
	DDX_Control(pDX, IDC_PROGRESS4, m_progress4);
}

BEGIN_MESSAGE_MAP(CEventDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CEventDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// CEventDlg message handlers

BOOL CEventDlg::OnInitDialog()
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

void CEventDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEventDlg::OnPaint()
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
HCURSOR CEventDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//CEvent g_event(FALSE, TRUE);
const TCHAR* lpsz = _T("Global\\KDY_EVENT");
CEvent g_event(FALSE, TRUE, lpsz,0);


UINT InitThread(LPVOID pParam)
{
	CProgressCtrl* ptr = (CProgressCtrl*)pParam;
	ptr->SetPos(0);

	for (int i = 0; i < 100; i++) {
		ptr->SetPos(i);
		::Sleep(10);
	}
	g_event.PulseEvent();

	return 0;
}

int th = 0;

UINT WorkThread(LPVOID pParam)
{
	CProgressCtrl* ptr = (CProgressCtrl*)pParam;
	ptr->SetPos(0);
	g_event.Lock();

	//WaitForSingleObject(g_event.m_hObject, INFINITE);
	CMutex mutex;
	mutex.Lock();
	th++;
	TRACE(_T("%dth thread is working..\n"),th);
	mutex.Unlock();
	for (int i = 0; i < 100; i++) {
		ptr->SetPos(i);
		::Sleep(10);
	}
	return 0;
}

void CEventDlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	AfxBeginThread(InitThread, &m_progress1);
	AfxBeginThread(WorkThread, &m_progress2);
	AfxBeginThread(WorkThread, &m_progress3);
	AfxBeginThread(WorkThread, &m_progress4);
}
