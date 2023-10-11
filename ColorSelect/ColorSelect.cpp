
// ColorSelect.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "ColorSelect.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CColorSelectApp

BEGIN_MESSAGE_MAP(CColorSelectApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CColorSelectApp::OnAppAbout)
	//ON_COMMAND(ID_COLOR_BLUE, &CColorSelectApp::OnColorBlue)
	//ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CColorSelectApp::OnUpdateColorBlue)
	//ON_COMMAND(ID_COLOR_GREEN, &CColorSelectApp::OnColorGreen)
	//ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CColorSelectApp::OnUpdateColorGreen)
	//ON_COMMAND(ID_COLOR_RED, &CColorSelectApp::OnColorRed)
	//ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CColorSelectApp::OnUpdateColorRed)
END_MESSAGE_MAP()


// CColorSelectApp construction

CColorSelectApp::CColorSelectApp() noexcept
{

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("ColorSelect.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	//CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	//CChildView* view = (CChildView*)pFrame->GetActiveView();
}

// The one and only CColorSelectApp object

CColorSelectApp theApp;


// CColorSelectApp initialization

BOOL CColorSelectApp::InitInstance()
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
	CFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);





	// The one and only window has been initialized, so show and update it
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CColorSelectApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	return CWinApp::ExitInstance();
}

// CColorSelectApp message handlers


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
void CColorSelectApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
	
}

// CColorSelectApp message handlers

void CColorSelectApp::OnColorBlue1()
{
	// TODO: Add your command handler code here
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	//CChildView* view = (CChildView*)pFrame->GetActiveView();
	CChildView& view = ((CMainFrame*)m_pMainWnd)->m_wndView;
	if (&view != nullptr) {
		view.m_color = RGB(0, 0, 255);
		view.Invalidate();
	}
}


void CColorSelectApp::OnUpdateColorBlue1(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView& view = ((CMainFrame*)m_pMainWnd)->m_wndView;
	if (&view != nullptr) {
		pCmdUI->SetCheck(view.m_color == RGB(0, 0, 255));
	}
}


void CColorSelectApp::OnColorGreen1()
{
	// TODO: Add your command handler code here
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView& view = ((CMainFrame*)m_pMainWnd)->m_wndView;
	if (&view != nullptr) {
		view.m_color = RGB(0, 255, 0);
		view.Invalidate();
	}
}


void CColorSelectApp::OnUpdateColorGreen1(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView& view = ((CMainFrame*)m_pMainWnd)->m_wndView;
	if (&view != nullptr) {
		pCmdUI->SetCheck(view.m_color == RGB(0, 255, 0));
	}
}


void CColorSelectApp::OnColorRed1()
{
	// TODO: Add your command handler code here
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView& view = ((CMainFrame*)m_pMainWnd)->m_wndView;
	if (&view != nullptr) {
		view.m_color = RGB(255, 0, 0);
		view.Invalidate();
	}
}


void CColorSelectApp::OnUpdateColorRed1(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView& view = ((CMainFrame*)m_pMainWnd)->m_wndView;
	if (&view != nullptr) {
		pCmdUI->SetCheck(view.m_color == RGB(255, 0, 0));
	}
}
