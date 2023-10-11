
// ODBC2Doc.h : CODBC2Doc 클래스의 인터페이스
//


#pragma once
#include "ODBC2Set.h"


class CODBC2Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CODBC2Doc();
	DECLARE_DYNCREATE(CODBC2Doc)

// 특성입니다.
public:
	CODBC2Set m_ODBC2Set;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CODBC2Doc();
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
};
