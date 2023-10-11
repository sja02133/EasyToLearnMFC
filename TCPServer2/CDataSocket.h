#pragma once

// CDataSocket command target

class CTCPServer2Doc;

class CDataSocket : public CSocket
{
public:
	CDataSocket(CTCPServer2Doc* pDoc);
	virtual ~CDataSocket();
	CTCPServer2Doc* m_pDoc;
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


