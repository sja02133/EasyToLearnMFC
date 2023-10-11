﻿
// TCPServer2Doc.h: CTCPServer2Doc 클래스의 인터페이스
//


#pragma once

class CListenSocket;
class CDataSocket;

class CTCPServer2Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CTCPServer2Doc() noexcept;
	DECLARE_DYNCREATE(CTCPServer2Doc)

// 특성입니다.
public:
	CListenSocket* m_pListenSocket;
	CDataSocket* m_pDataSocket;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CTCPServer2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
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
