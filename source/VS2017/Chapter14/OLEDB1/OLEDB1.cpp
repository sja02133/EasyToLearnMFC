// OLEDB1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "OLEDB1.h"
#include "CStudent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

int main()
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// MFC�� �ʱ�ȭ�մϴ�. �ʱ�ȭ���� ���� ��� ������ �μ��մϴ�.
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
			wprintf(L"�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n");
			nRetCode = 1;
		}
		else
		{
			CoInitialize(NULL); // COM �ʱ�ȭ
			_tsetlocale(LC_ALL, _T(""));

			HRESULT hr; // COM ���� ����
			CStudent* m_pSet = new CStudent();

			hr = m_pSet->OpenAll();
			if (FAILED(hr)) {
				AfxMessageBox(_T("���ڵ� ������ ���� ���߽��ϴ�."), MB_OK);
			}

			m_pSet->MoveFirst();
			do {
				_tprintf(_T("%d %s %2d %s\n"),
					m_pSet->m_ST_NUM,
					m_pSet->m_ST_NAME,
					m_pSet->m_ST_MAN,
					m_pSet->m_ST_PHONE);
			} while (m_pSet->MoveNext() == S_OK);

			m_pSet->CloseAll();

			delete m_pSet;
			CoUninitialize(); // COM ����
		}
	}
	else
	{
		// TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
		wprintf(L"�ɰ��� ����: GetModuleHandle ����\n");
		nRetCode = 1;
	}

	return nRetCode;
}
