
// OLEDB2.h : OLEDB2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// COLEDB2App:
// �� Ŭ������ ������ ���ؼ��� OLEDB2.cpp�� �����Ͻʽÿ�.
//

class COLEDB2App : public CWinApp
{
public:
	COLEDB2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COLEDB2App theApp;
