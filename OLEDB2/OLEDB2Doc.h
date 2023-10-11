
// OLEDB2Doc.h : COLEDB2Doc Ŭ������ �������̽�
//


#pragma once
#include "OLEDB2Set.h"


class COLEDB2Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	COLEDB2Doc();
	DECLARE_DYNCREATE(COLEDB2Doc)

// Ư���Դϴ�.
public:
	COLEDB2Set m_OLEDB2Set;

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
	virtual ~COLEDB2Doc();
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
