
// Simple.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Simple.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimpleApp

BEGIN_MESSAGE_MAP(CSimpleApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CSimpleApp::OnAppAbout)
END_MESSAGE_MAP()


// CSimpleApp construction

CSimpleApp::CSimpleApp() noexcept
{

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Simple.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CSimpleApp object

CSimpleApp theApp;


// CSimpleApp initialization

BOOL CSimpleApp::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	//CFrameWnd* pFrame = new CMainFrame;	//기존

	//연습 문제 15
	CFrameWnd* pFrame;
	CRuntimeClass* pRuntimeClass = RUNTIME_CLASS(CMainFrame);
	pFrame = (CMainFrame*)pRuntimeClass->CreateObject();
	// --

	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);

	// The one and only window has been initialized, so show and update it
	
	int nCmdShow = 0;
	nCmdShow = SW_SHOW;	//기존
	nCmdShow = SW_MINIMIZE;	//연습문제 09
	nCmdShow = SW_MAXIMIZE;	//연습문제 10
	
	pFrame->ShowWindow(nCmdShow);
	pFrame->UpdateWindow();
	return TRUE;
}

int CSimpleApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	
	//연습문제 17, 레지스토리에 추가.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	theApp.WriteProfileInt(_T("Int"), _T("WindowSizeX"), pFrame->size.x);
	theApp.WriteProfileInt(_T("Int"), _T("WindowSizeY"), pFrame->size.y);
	theApp.WriteProfileInt(_T("Int"), _T("WindowPosX"), pFrame->position.x);
	theApp.WriteProfileInt(_T("Int"), _T("WindowPosY"), pFrame->position.y);
	// --
	
	int result = MessageBox(NULL,_T("종료"), _T("프로그램을 종료합니다."),MB_OK);	//연습문제 16

	

	return CWinApp::ExitInstance();
}

// CSimpleApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

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

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CSimpleApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CSimpleApp message handlers



