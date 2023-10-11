#pragma once

// CDataSocket command target

class CTCPClient2Dlg;

class CDataSocket : public CSocket
{
public:
	CDataSocket(CTCPClient2Dlg* pDlg);
	virtual ~CDataSocket();
	CTCPClient2Dlg* m_pDlg;
};


