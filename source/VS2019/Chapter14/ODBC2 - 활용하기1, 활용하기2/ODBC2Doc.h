
// ODBC2Doc.h : CODBC2Doc Ŭ������ �������̽�
//


#pragma once
#include "ODBC2Set.h"


class CODBC2Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CODBC2Doc();
	DECLARE_DYNCREATE(CODBC2Doc)

// Ư���Դϴ�.
public:
	CODBC2Set m_ODBC2Set;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CODBC2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
