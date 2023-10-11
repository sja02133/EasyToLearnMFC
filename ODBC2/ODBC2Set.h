
// ODBC2Set.h: CODBC2Set Ŭ������ �������̽�
//


#pragma once

// �ڵ� ���� ��ġ 2020�� 2�� 2�� �Ͽ���, ���� 2:33

class CODBC2Set : public CRecordset
{
public:
	CODBC2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CODBC2Set)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA: ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_ST_NUM;
	CStringW	m_ST_NAME;
	BOOL	m_ST_MAN;
	CStringW	m_ST_PHONE;

// ������
	// �����翡�� ������ ���� �Լ� ������
public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

