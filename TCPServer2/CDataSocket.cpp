// CDataSocket.cpp : implementation file
//

#include "pch.h"
#include "TCPServer2.h"
#include "CDataSocket.h"

#include "TCPServer2Doc.h"

// CDataSocket

CDataSocket::CDataSocket(CTCPServer2Doc* pDoc)
{
	m_pDoc = pDoc;
}

CDataSocket::~CDataSocket()
{
}


// CDataSocket member functions


void CDataSocket::OnReceive(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class

	CSocket::OnReceive(nErrorCode);
	m_pDoc->ProcessReceive(this, nErrorCode);
}


void CDataSocket::OnClose(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class

	CSocket::OnClose(nErrorCode);
	m_pDoc->ProcessClose(this, nErrorCode);
}
