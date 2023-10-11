
// OLEDB2Set.h: COLEDB2Set Ŭ������ �������̽�
//


#pragma once


class COLEDB2SetAccessor
{
public:
	LONG m_ST_NUM;
	TCHAR m_ST_NAME[256];
	VARIANT_BOOL m_ST_MAN;
	TCHAR m_ST_PHONE[256];

	// ���� ������ ���� ������ �������  �� ���� �ش� 
	// �ʵ忡 ���� ���� ���� ��� �ֽ��ϴ�. �� ����
	// ����Ͽ� �����ͺ��̽�������ȯ�ϴ� NULL ����
	// �����ϰų� �����Ϸ����� ������ ��ȯ�� ��
	// ���� ������ ������ �� �ֽ��ϴ�. �̷��� �ʵ� ��뿡
	// ���� �ڼ��� ������ Visual C++ ������
	//  "������ ���� ������"���� "�ʵ� ���� ������ ���"�� �����Ͻʽÿ�.
	// ����: �����͸� ����/�����ϱ� ���� �̵� �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBSTATUS m_dwST_NUMStatus;
	DBSTATUS m_dwST_NAMEStatus;
	DBSTATUS m_dwST_MANStatus;
	DBSTATUS m_dwST_PHONEStatus;

	// ���� ������ ���� ������ ������� �� ���� �ش� �ʵ忡 ����
	// ���� ���� ��� �ֽ��ϴ�.
	// ����: ���� ���� ���� ��� �����͸� ����/�����ϱ� ���� 
	//       �̷��� 	 �ʵ带 �ʱ�ȭ�ؾ� �մϴ�.

	DBLENGTH m_dwST_NUMLength;
	DBLENGTH m_dwST_NAMELength;
	DBLENGTH m_dwST_MANLength;
	DBLENGTH m_dwST_PHONELength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_UPDATABILITY,
			DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
		hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Data Source=student;Extended Properties=\"DSN=student;DBQ=C:\\SOURCE\\VS2019\\CHAPTER14\\student.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;\"");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession& ()
	{
		return m_session;
	}

	CSession m_session;

	BEGIN_COLUMN_MAP(COLEDB2SetAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_ST_NUM, m_dwST_NUMLength, m_dwST_NUMStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_ST_NAME, m_dwST_NAMELength, m_dwST_NAMEStatus)
		_COLUMN_ENTRY_CODE(3, DBTYPE_BOOL, _SIZE_TYPE(m_ST_MAN), 0, 0, offsetbuf(m_ST_MAN), offsetbuf(m_dwST_MANLength), offsetbuf(m_dwST_MANStatus))
		COLUMN_ENTRY_LENGTH_STATUS(4, m_ST_PHONE, m_dwST_PHONELength, m_dwST_PHONEStatus)
	END_COLUMN_MAP()
};

class COLEDB2Set : public CTable<CAccessor<COLEDB2SetAccessor> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if (HasBookmark())
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if (HasBookmark())
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET* pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, L"���̺�1", pPropSet);
#ifdef _DEBUG
		if (FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		CloseDataSource();
	}
};

