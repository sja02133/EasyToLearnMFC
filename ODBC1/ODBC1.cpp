// ODBC1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "ODBC1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: code your application's behavior here.
            _tsetlocale(LC_ALL, _T(""));

            CDatabase db;
            db.OpenEx(_T("DSN=student"),0);

            CString whereStr;

            CRecordset rs(&db);
            rs.Open(CRecordset::dynaset, _T("SELECT* FROM 테이블1"));

            // 연습 문제 01
            //FILE* pFile;
            //fopen_s(&pFile, "test.txt", "r");
            //TCHAR Tstr[64] = {};
            //::_fgetts(Tstr,64,pFile);
            //whereStr.Format(_T("SELECT* FROM 테이블1 WHERE ST_NAME = '%s'"), Tstr);
            // --

            CString str;
            while (!rs.IsEOF()) {
                rs.GetFieldValue(short(0), str);
                _tprintf(_T("%s"), (LPCTSTR)str);
                rs.GetFieldValue(short(1), str);
                _tprintf(_T("%s"), (LPCTSTR)str);
                rs.GetFieldValue(short(2), str);
                _tprintf(_T("%s"), (LPCTSTR)str);
                rs.GetFieldValue(short(3), str);
                _tprintf(_T("%s\n"), (LPCTSTR)str);
                rs.MoveNext();
            }
            
            // 연습 문제 02
            rs.Close();
            int num = 0, man = 0;
            TCHAR name[64] = {};
            TCHAR phone[64] = {};
            TCHAR allStr[1024] = {};
            ::_tscanf_s(_T("%d %s %d %s"), &num, name, _countof(name), &man, phone, _countof(phone));
            whereStr.Format(_T("INSERT INTO 테이블1 (ST_NUM,ST_NAME,ST_MAN,ST_PHONE) VALUES(%d,'%s',%d,'%s')"), num, name, man, phone);
            db.ExecuteSQL(whereStr);
            //rs.Requery();
            // --
            
            //rs.Close();
            //db.Close();
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
