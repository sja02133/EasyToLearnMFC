// CMyThread.cpp : implementation file
//

#include "pch.h"
#include "UIThread.h"
#include "CMyThread.h"

#include "CMyWnd.h"
// CMyThread

IMPLEMENT_DYNCREATE(CMyThread, CWinThread)

CMyThread::CMyThread()
{
}

CMyThread::~CMyThread()
{
}

BOOL CMyThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here

	CRuntimeClass* pRuntimeClass = RUNTIME_CLASS(CMyWnd);
	CObject* pObject = pRuntimeClass->CreateObject();
	ASSERT(pObject->IsKindOf(RUNTIME_CLASS(CMyWnd)));

	m_pMainWnd = (CWnd*)pObject;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CMyThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyThread, CWinThread)
END_MESSAGE_MAP()


// CMyThread message handlers
