
// TCPServer2Doc.h : interface of the CTCPServer2Doc class
//


#pragma once

class CListenSocket;
class CDataSocket;

class CTCPServer2Doc : public CDocument
{
protected: // create from serialization only
	CTCPServer2Doc() noexcept;
	DECLARE_DYNCREATE(CTCPServer2Doc)

// Attributes
public:
	CListenSocket* m_pListenSocket;
	CDataSocket* m_pDataSocket;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTCPServer2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

#ifdef SHARED_HANDLERS
private:
	CString m_strSearchContent;
	CString m_strThumbnailContent;
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
	void PrintMessage(LPCTSTR message);
	void ProcessAccept(int nErrorCode);
	void ProcessReceive(CDataSocket* pSocket, int nErrorCode);
	void ProcessClose(CDataSocket* pSocket, int nErrorCode);
};
