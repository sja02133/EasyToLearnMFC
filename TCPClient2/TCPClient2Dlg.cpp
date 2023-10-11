
// TCPClient2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "TCPClient2.h"
#include "TCPClient2Dlg.h"
#include "afxdialogex.h"

#include "CDataSocket.h"

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


// CTCPClient2Dlg dialog



CTCPClient2Dlg::CTCPClient2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TCPCLIENT2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTCPClient2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ipaddr);
}

BEGIN_MESSAGE_MAP(CTCPClient2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, &CTCPClient2Dlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_DISCONNECT, &CTCPClient2Dlg::OnBnClickedDisconnect)
	ON_BN_CLICKED(IDC_SEND, &CTCPClient2Dlg::OnBnClickedSend)
END_MESSAGE_MAP()


// CTCPClient2Dlg message handlers

BOOL CTCPClient2Dlg::OnInitDialog()
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

	m_pDataSocket = NULL;
	m_ipaddr.SetWindowText(_T("127.0.0.1"));


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTCPClient2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTCPClient2Dlg::OnPaint()
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
HCURSOR CTCPClient2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTCPClient2Dlg::OnBnClickedConnect()
{
	// TODO: Add your control notification handler code here
	if (m_pDataSocket == NULL) {
		m_pDataSocket = new CDataSocket(this);
		m_pDataSocket->Create();
		CString addr;
		m_ipaddr.GetWindowText(addr);
		if (m_pDataSocket->Connect(addr, 8000)) {
			MessageBox(_T("서버에 접속 성공!"), _T("알림"), MB_ICONINFORMATION);
			m_edit.SetFocus();
		}
		else {
			MessageBox(_T("서버에 접속 실패!"), _T("알림"), MB_ICONERROR);
			delete m_pDataSocket;
			m_pDataSocket = NULL;
		}
	}
	else {
		MessageBox(_T("서버에 이미 접속됨!"), _T("알림"), MB_ICONINFORMATION);
		m_edit.SetFocus();
	}
}


void CTCPClient2Dlg::OnBnClickedDisconnect()
{
	// TODO: Add your control notification handler code here
	if (m_pDataSocket == NULL) {
		MessageBox(_T("서버에 접속 안 함!"), _T("알림"), MB_ICONERROR);
	}
	else {
		m_pDataSocket->Close();
		delete m_pDataSocket;
		m_pDataSocket = NULL;
	}
}


void CTCPClient2Dlg::OnBnClickedSend()
{
	// TODO: Add your control notification handler code here
	if (m_pDataSocket == NULL) {
		MessageBox(_T("서버에 접속 안 함!"), _T("알림"), MB_ICONERROR);
	}
	else {
		CString message;
		m_edit.GetWindowText(message);
		message += _T("\r\n");
		m_pDataSocket->Send((LPCTSTR)message, (message.GetLength() + 1) * sizeof(TCHAR));
		m_edit.SetWindowText(_T(""));
		m_edit.SetFocus();
	}
}
