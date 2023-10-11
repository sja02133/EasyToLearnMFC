#include <afxwin.h>

class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

CHelloApp theApp;

BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	
	//m_pMainWnd->ShowWindow(m_nCmdShow);	//기본

	// 연습 문제 13
	//m_nCmdShow = SW_MAXIMIZE;
	//m_pMainWnd->ShowWindow(m_nCmdShow);
	// --

	// 연습 문제 14
	m_nCmdShow = SW_MINIMIZE;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	// --
	return TRUE;
}

CMainFrame::CMainFrame()
{
	//Create(NULL, _T("HelloMFC"));		// 기본
	//Create(NULL, _T("Hello World"));		// 연습 문제 11

	// 연습 문제 12
	CRect tempRect(0, 0, 500, 200);
	Create(NULL, _T("Hello World"),WS_POPUPWINDOW,tempRect,NULL,NULL,NULL);
	// --
	
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	const TCHAR* msg = _T("Hello, MFC");
	dc.TextOut(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	//MessageBox(_T("마우스 클릭!"), _T("마우스 메시지"));		//기본
	//MessageBox(_T("마우스 클릭!"), _T("마우스 메시지"),MB_YESNOCANCEL);		// 연습 문제 15
	//MessageBox(_T("마우스 클릭!"), _T("마우스 메시지"),MB_ICONQUESTION);		// 연습 문제 16
	
	// 연습 문제 17
	//switch (MessageBox(_T("마우스 클릭!"), _T("마우스 메시지"), MB_YESNOCANCEL))		
	//{
	//case IDYES:
	//	PostQuitMessage(0);
	//	break;
	//default:
	//	break;
	//}
	// --

	//chapter 03 3.1
	AfxMessageBox(_T("마우스 클릭!"));

	//chapter 03 3.2
	TRACE(_T("응용 프로그램 객체 주소: %p = %p\n"), AfxGetApp(), &theApp);
	//TRACE(_T("메인 윈도우 객체 주소 : %p = %p\n"), AfxGetMainWnd(), theApp.m_pMainWnd);
	TRACE(_T("메인 윈도우 객체 주소 : %p = %p\n"), AfxGetMainWnd(), this); //여기서 this 는 theApp.m_pMainWnd 와 동일
	TRACE(_T("응용 프로그램 이름: %s\n"), AfxGetAppName());

	TRACE(_T("인스턴스 핸들: %p\n"), AfxGetInstanceHandle());

}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()