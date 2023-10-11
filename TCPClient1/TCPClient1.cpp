// TCPClient1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "TCPClient1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

// here is B
#define A_SERVER_PORT   7000
#define B_SERVER_PORT   8000



void ErrQuit(int err) {
    LPVOID lpMsgBuf;
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, err,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf, 0, NULL);
    MessageBox(NULL, (LPCTSTR)lpMsgBuf, _T("오류 발생"), MB_ICONERROR);
    LocalFree(lpMsgBuf);
    exit(1);
}

UINT receiveChat(LPVOID p) {
    CSocket* sock = (CSocket*)p;
    int nResult = 0;
    CSocket recv_sock;
    recv_sock.Create(B_SERVER_PORT);
    if (!recv_sock.Listen()) {
        ErrQuit(recv_sock.GetLastError());
    }

    TCHAR buf[256 + 1];
    int nbytes;

    while (1) {
        CSocket newsock;
        recv_sock.Accept(newsock);

        CString PeerAddress;
        UINT PeerPort;
        newsock.GetPeerName(PeerAddress, PeerPort);
        _tprintf(_T("### IP 주소: %s, 포트 번호: %d ###\n"), (LPCTSTR)PeerAddress, PeerPort);

        while (1) {
            nbytes = newsock.receives(buf, 256);

            if (nbytes == 0 || nbytes == SOCKET_ERROR)
                break;

            else {
                buf[nResult] = _T('\0');
                _tprintf(_T("%s"), buf);
                Sleep(10);
            }
        }
        newsock.Close();
    }
    return 0;
}

UINT sendChat(void* p) {
    CSocket* send_sock = new CSocket;
    BOOL check = FALSE;
    while (1) {
        check = send_sock->Create();
        if (check == TRUE)
            break;
    }
    while (1) {
        check = send_sock->Connect(_T("127.0.0.1"), A_SERVER_PORT);
        if (check == TRUE)
            break;
    }
    TCHAR buf[256 + 1];
    int nbytes;

    for (int i = 0; i < 5; i++) {
        wsprintf(buf, _T("%d번째 기존 클라이언트 메시지\r\n"), i);
        nbytes = send_sock->Send(buf, 256);
        if (nbytes == SOCKET_ERROR)
            ErrQuit(send_sock->GetLastError());
        else {
            //_tprintf(_T("<%d> %d바이트 전송\n"), i, nbytes);
            Sleep(1000);
        }
    }
    send_sock->Close();
    return 0;
}

CWinThread* pThread1;
CWinThread* pThread2;

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
            AfxSocketInit();

            CSocket sock;
            if (!sock.Create())
                ErrQuit(sock.GetLastError());

            CSocket send_sock, recv_sock;
            

            
             // 연습 문제 04
            pThread1 = AfxBeginThread(receiveChat, NULL, THREAD_PRIORITY_NORMAL, 0, 0, 0);
            pThread2 = AfxBeginThread(sendChat, NULL, THREAD_PRIORITY_NORMAL, 0, 0, 0);

            while (1) {
                Sleep(1000);
            }

            /*
            while (1) {
                BOOL check = sock.Connect(_T("127.0.0.1"), 8000);
                if (check)
                    break;
            }
            //if (!sock.Connect(_T("127.0.0.1"), 8000)) {
            //    ErrQuit(sock.GetLastError());
            //}

            TCHAR buf[256];
            int nbytes;

            // 기존
            //for (int i = 0; i < 5; i++) {
            //    wsprintf(buf, _T("%d번째 테스트 메시지\r\n"), i);
            //    nbytes = sock.Send(buf, 256);
            //    if (nbytes == SOCKET_ERROR)
            //        ErrQuit(sock.GetLastError());
            //    else {
            //        _tprintf(_T("<%d> %d바이트 전송\n"), i, nbytes);
            //        Sleep(1000);
            //    }
            //}
            // --
            
            // 연습 문제 02
            //int count = 0;
            //while (1) {
            //    if (count == 20)
            //        break;
            //    srand((unsigned)time(NULL));
            //    int random1 = 0, random2 = 0;
            //    random1 = rand() % 100;
            //    random2 = rand() % 100;

            //    wsprintf(buf, _T("%d + %d\r\n"), random1, random2);
            //    nbytes = sock.Send(buf, 256);
            //    _tprintf(_T("%d + %d 전송\n"), random1, random2);
            //    TCHAR rBuf[256];
            //    nbytes = sock.Receive(rBuf, 256);
            //    _tprintf(_T("수신 : %s\n"), rBuf);
            //    Sleep(1000);
            //    count++;
            //}
            // --

            CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY);
            if (dlg.DoModal() == IDOK) {
                CFile file;
                file.Open(dlg.GetPathName(), CFile::modeRead);
                TCHAR* mal_buf = (TCHAR*)malloc(file.GetLength());
                file.Read(mal_buf, file.GetLength());

                ULONGLONG totalSum = file.GetLength();
                ULONGLONG nowSum = 0;
                int nResult = 0;

                //first Send File size
                sock.Send(&totalSum, sizeof(ULONGLONG));

                while ((nResult = sock.Send(mal_buf, 256)) != SOCKET_ERROR) {
                    nowSum += (ULONGLONG)nResult;
                    if (nowSum > totalSum) {
                        nowSum = totalSum;
                    }
                    CString str1, str2;
                    //str1.Format(_T("%ld 중"), totalSum);
                    //str2.Format(_T(" %d 전송\n"), nowSum);
                    //_tprintf(_T("%s"),str1+str2);

                    double percent = ((double)nowSum / (double)totalSum) * 100;

                    str1.Format(_T("%lf%%\r"), percent);
                    _tprintf(_T("%s"), str1);
                    if (percent == 100.0)
                        break;
                    Sleep(10);
                }
                free(mal_buf);
            }
            
            sock.Close();
            */
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
