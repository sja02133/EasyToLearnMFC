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


#if 0
			m_pSet->MoveLast(); // �� ������ �̵��Ѵ�.

			// ���ڵ� �߰� ���� �ݵ�� ���� ������ �ʱ�ȭ�ؾ� �Ѵ�!
			m_pSet->m_dwST_NUMStatus = DBSTATUS_S_OK;
			m_pSet->m_dwST_NAMEStatus = DBSTATUS_S_OK;
			m_pSet->m_dwST_MANStatus = DBSTATUS_S_OK;
			m_pSet->m_dwST_PHONEStatus = DBSTATUS_S_OK;

			// ���ڿ��� ���� ���� �ʵ�� ���̸� �ʱ�ȭ�ؾ� �Ѵ�!
			m_pSet->m_dwST_NAMELength = sizeof(_T("�Ǽ���"));
			m_pSet->m_dwST_PHONELength = sizeof(_T("010-1234-5678"));

			// �ʵ� ������ ���ο� ���ڵ��� �ʵ� ���� �ִ´�.
			m_pSet->m_ST_NUM = 3010;
			wsprintf(m_pSet->m_ST_NAME, _T("�Ǽ���"));
			m_pSet->m_ST_MAN = -1;
			wsprintf(m_pSet->m_ST_PHONE, _T("010-1234-5678"));

			// ���ڵ带 �߰��Ѵ�.
			hr = m_pSet->Insert();
			if (FAILED(hr)) {
				AfxMessageBox(_T("���ڵ带 �߰����� ���߽��ϴ�."), MB_OK);
			}
#endif
#if 0
			m_pSet->MoveLast(); // �� ������ �̵��Ѵ�.

			// ���ڵ� ���� ���� �ݵ�� ���� ������ �ʱ�ȭ�ؾ� �Ѵ�!
			m_pSet->m_dwST_NUMStatus = DBSTATUS_S_OK;
			m_pSet->m_dwST_NAMEStatus = DBSTATUS_S_OK;
			m_pSet->m_dwST_MANStatus = DBSTATUS_S_OK;
			m_pSet->m_dwST_PHONEStatus = DBSTATUS_S_OK;

			// ���ڿ��� ���� ���� �ʵ�� ���̸� �ʱ�ȭ�ؾ� �Ѵ�!
			m_pSet->m_dwST_PHONELength = sizeof(_T("010-5678-1234"));

			// �ʵ� ������ ������ ���ڵ��� �ʵ� ���� �ִ´�.
			wsprintf(m_pSet->m_ST_PHONE, _T("010-5678-1234"));

			// ���ڵ带 �����Ѵ�.
			hr = m_pSet->SetData();
			if (FAILED(hr)) {
				AfxMessageBox(_T("���ڵ带 �������� ���߽��ϴ�."), MB_OK);
			}
#endif
#if 0
			m_pSet->MoveLast(); // �� ������ �̵��Ѵ�.

			// ���ڵ带 �����Ѵ�.
			hr = m_pSet->Delete();
			if (FAILED(hr)) {
				AfxMessageBox(_T("���ڵ带 �������� ���߽��ϴ�."), MB_OK);
			}
#endif


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
