
// ODBC2Set.cpp : CODBC2Set Ŭ������ ����
//

#include "stdafx.h"
#include "ODBC2.h"
#include "ODBC2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC2Set ����

IMPLEMENT_DYNAMIC(CODBC2Set, CRecordset)

CODBC2Set::CODBC2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ST_NUM = 0;
	m_ST_NAME = L"";
	m_ST_MAN = FALSE;
	m_ST_PHONE = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CODBC2Set::GetDefaultConnect()
{
	return _T("DSN=student;DBQ=C:\\Rust_Server\\student.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CODBC2Set::GetDefaultSQL()
{
	return _T("[���̺�1]");
}

void CODBC2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[ST_NUM]"), m_ST_NUM);
	RFX_Text(pFX, _T("[ST_NAME]"), m_ST_NAME);
	RFX_Bool(pFX, _T("[ST_MAN]"), m_ST_MAN);
	RFX_Text(pFX, _T("[ST_PHONE]"), m_ST_PHONE);
}
/////////////////////////////////////////////////////////////////////////////
// CODBC2Set ����

#ifdef _DEBUG
void CODBC2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBC2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

