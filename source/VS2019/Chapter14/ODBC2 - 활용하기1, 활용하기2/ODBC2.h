
// ODBC2.h : ODBC2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CODBC2App:
// �� Ŭ������ ������ ���ؼ��� ODBC2.cpp�� �����Ͻʽÿ�.
//

class CODBC2App : public CWinApp
{
public:
	CODBC2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CODBC2App theApp;
