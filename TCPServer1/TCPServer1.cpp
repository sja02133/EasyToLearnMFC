// TCPServer1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "TCPServer1.h"

#include <list>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

// here is A
#define A_SERVER_PORT   7000
#define B_SERVER_PORT   8000

CList<CString, CString> client_Socket_list_info;
std::list<CWinThread*> list_thread;


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

BOOL checkExistSocketInList(CSocket* p) {
    CSocket tempSock;

    CString peerIp;
    UINT peerPort;

    p->GetPeerName(peerIp, peerPort);

    CString target;
    target.Format(_T("%s,%d"), peerIp, peerPort);

    POSITION pos = client_Socket_list_info.GetHeadPosition();
    while (pos) {
        CString info = client_Socket_list_info.GetNext(pos);
        if (info.Compare(target) == 0)
            return FALSE;
    }
    client_Socket_list_info.AddTail(target);
    return TRUE;
}

UINT receiveFromClient(LPVOID p) {
    CSocket* sock = (CSocket*)p;
    CSocket newsock;
    TCHAR buf[256 + 1];
    int nbytes;
    while (1) {
        nbytes = sock->receives(buf, 256);

        if (nbytes == SOCKET_ERROR)
            break;

        else if(nbytes > 0){
            buf[nbytes] = _T('\0');
            _tprintf(_T("%s"), buf);
            Sleep(10);
        }
    }
    return 0;
}

UINT receiveChat(LPVOID p) {
    int nResult = 0;
    CSocket* recv_sock = new CSocket();
    recv_sock->Create(A_SERVER_PORT);
     
    if (!recv_sock->Listen()) {
        ErrQuit(recv_sock->GetLastError());
    }

    TCHAR buf[256 + 1];
    int nbytes;

    while (1) {
        CSocket newsock;
        recv_sock->Accept(newsock);

        if (!checkExistSocketInList(&newsock))
            break;
        else {
            CString PeerAddress;
            UINT PeerPort;
            newsock.GetPeerName(PeerAddress, PeerPort);
            _tprintf(_T("### IP 주소: %s, 포트 번호: %d 서버 접속!###\n"), (LPCTSTR)PeerAddress, PeerPort);
            CWinThread* pThread = new CWinThread;
            pThread = AfxBeginThread(receiveFromClient, recv_sock, THREAD_PRIORITY_NORMAL, 0, 0, 0);
            list_thread.push_back(pThread);
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
        check = send_sock->Connect(_T("127.0.0.1"), B_SERVER_PORT);
        if (check == TRUE)
            break;
    }
    TCHAR buf[256 + 1];
    int nbytes;



    for (int i = 0; i < 5; i++) {
        wsprintf(buf, _T("%d번째 기존 서버 메시지\r\n"), i);
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

            pThread1 = AfxBeginThread(receiveChat, NULL, THREAD_PRIORITY_NORMAL, 0, 0, 0);
            //pThread2 = AfxBeginThread(sendChat, NULL, THREAD_PRIORITY_NORMAL, 0, 0, 0);
            while (1) {
                Sleep(1000);
            }
            //while (1) {
            //    CSocket* newsock = new CSocket;
            //    BOOL checkAccect = FALSE;
            //    if (!recv_sock.Accept(*newsock))
            //        ErrQuit(recv_sock.GetLastError());

            //    recv_sock.Accept(*newsock);

                // 연습 문제 04
                        
                        //pThread2 = AfxBeginThread(sendChat, &send_sock, THREAD_PRIORITY_NORMAL, 0, 0, 0);

                        //pThread1->ResumeThread();
                        //pThread2->ResumeThread();
                // --


                //CString PeerAddress;
                //UINT PeerPort;
                //newsock.GetPeerName(PeerAddress, PeerPort);
                //_tprintf(_T("### IP 주소: %s, 포트 번호: %d ###\n"), (LPCTSTR)PeerAddress, PeerPort);
                
                // 연습 문제 03
                //BOOL checkFirst = TRUE;
                //ULONGLONG totalFileSize = 0;
                //ULONGLONG nowSum = 0;
                // --
                //while (1) {
                //    nbytes = newsock.Receive(buf, 256);
                //    if (nbytes == 0 || nbytes == SOCKET_ERROR) {
                //        break;
                //    }
                //    else {
                        // 기존
                            //buf[nbytes] = _T('\0');
                            //_tprintf(_T("%s"), buf);
                        // --

                        // 연습 문제 01
                        //newsock.Send(buf, nbytes);
                        //if (nbytes == SOCKET_ERROR)
                        //    break;
                        // --

                        // 연습 문제 02
                        //buf[nbytes - 4] = _T('\0');
                        //int pos1 = 0, pos2 = 0;
                        //while (buf[pos1] != '+') {
                        //    pos1++;
                        //}
                        //while (buf[pos1 + pos2] != '\r') {
                        //    pos2++;
                        //}

                        //int number1Start = 0;
                        //int number1End = pos1 - 1;
                        //int number2Start = pos1 + 2;
                        //int number2End = pos1 + pos2;

                        //TCHAR* number1 = (TCHAR*)malloc(pos1 - 1);
                        //wmemcpy(number1, &buf[0], number1End);
                        //number1[number1End] = _T('\0');
                        //TCHAR* number2 = (TCHAR*)malloc(number2End - number2Start);
                        //wmemcpy(number2, &buf[number2Start], number2End - number2Start);
                        //number2[number2End - number2Start] = _T('\0');
                        //int num1 = _ttoi(number1);
                        //int num2 = _ttoi(number2);
                        //
                        //TCHAR sendBuf[256 + 1] = {};
                        //wsprintf(sendBuf, _T("%d\r\n"), num1 + num2);
                        //newsock.Send(sendBuf, 256);
                        // --


                        // 연습 문제 03
                        //buf[nbytes] = _T('\0');
                        //if (checkFirst) {
                        //    memcpy(&totalFileSize, buf, sizeof(ULONGLONG));
                        //    checkFirst = FALSE;
                        //}
                        //else {
                        //    nowSum += nbytes;
                        //    if (nowSum > totalFileSize)
                        //        nowSum = totalFileSize;

                        //    double percent = ((double)nowSum / (double)totalFileSize) * 100;

                        //    CString str1;
                        //    str1.Format(_T("%lf%%\r"), percent);
                        //    _tprintf(_T("%s"), str1);
                        //    if (percent == 100.0)
                        //        break;
                        //}
                        // --
                //    }

                //}
        //    }
        //    _tprintf(_T("### 접속 종료 ###\n\n"));
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
