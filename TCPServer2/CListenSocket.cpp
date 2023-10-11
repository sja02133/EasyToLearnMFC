// CListenSocket.cpp : implementation file
//

#include "pch.h"
#include "TCPServer2.h"
#include "CListenSocket.h"
#include "TCPServer2Doc.h"

// CListenSocket

CListenSocket::CListenSocket(CTCPServer2Doc* pDoc)
{
	m_pDoc = pDoc;
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket member functions


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	CSocket::OnAccept(nErrorCode);

	m_pDoc->ProcessAccept(nErrorCode);

}
