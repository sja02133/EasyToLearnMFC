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
	
	//m_pMainWnd->ShowWindow(m_nCmdShow);	//�⺻

	// ���� ���� 13
	//m_nCmdShow = SW_MAXIMIZE;
	//m_pMainWnd->ShowWindow(m_nCmdShow);
	// --

	// ���� ���� 14
	m_nCmdShow = SW_MINIMIZE;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	// --
	return TRUE;
}

CMainFrame::CMainFrame()
{
	//Create(NULL, _T("HelloMFC"));		// �⺻
	//Create(NULL, _T("Hello World"));		// ���� ���� 11

	// ���� ���� 12
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
	//MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"));		//�⺻
	//MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"),MB_YESNOCANCEL);		// ���� ���� 15
	//MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"),MB_ICONQUESTION);		// ���� ���� 16
	
	// ���� ���� 17
	//switch (MessageBox(_T("���콺 Ŭ��!"), _T("���콺 �޽���"), MB_YESNOCANCEL))		
	//{
	//case IDYES:
	//	PostQuitMessage(0);
	//	break;
	//default:
	//	break;
	//}
	// --

	//chapter 03 3.1
	AfxMessageBox(_T("���콺 Ŭ��!"));

	//chapter 03 3.2
	TRACE(_T("���� ���α׷� ��ü �ּ�: %p = %p\n"), AfxGetApp(), &theApp);
	//TRACE(_T("���� ������ ��ü �ּ� : %p = %p\n"), AfxGetMainWnd(), theApp.m_pMainWnd);
	TRACE(_T("���� ������ ��ü �ּ� : %p = %p\n"), AfxGetMainWnd(), this); //���⼭ this �� theApp.m_pMainWnd �� ����
	TRACE(_T("���� ���α׷� �̸�: %s\n"), AfxGetAppName());

	TRACE(_T("�ν��Ͻ� �ڵ�: %p\n"), AfxGetInstanceHandle());

}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()