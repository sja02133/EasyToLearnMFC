
// OLEDB2View.cpp : COLEDB2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "OLEDB2.h"
#endif

#include "OLEDB2Set.h"
#include "OLEDB2Doc.h"
#include "OLEDB2View.h"

#include "CSearchDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COLEDB2View

IMPLEMENT_DYNCREATE(COLEDB2View, COleDBRecordView)

BEGIN_MESSAGE_MAP(COLEDB2View, COleDBRecordView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COleDBRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_SEARCHNAME, &COLEDB2View::OnRecordSearchname)
	ON_COMMAND(ID_RECORD_APPEND, &COLEDB2View::OnRecordAppend)
END_MESSAGE_MAP()

// COLEDB2View ����/�Ҹ�

COLEDB2View::COLEDB2View()
	: COleDBRecordView(IDD_OLEDB2_FORM)
{
	m_pSet = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

COLEDB2View::~COLEDB2View()
{
}

void COLEDB2View::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	// SetDlgItem*/GetDlgItem* API ȣ��� �ƴ϶� DDX_* �Լ��� �����Ͽ� �����ͺ��̽��� �信 ������ �� �ֽ��ϴ�.
	// ex. ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// �ڼ��� ������ MSDN �� OLEDB ������ �����Ͻʽÿ�.
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ST_NUM);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_ST_NAME, 256);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_ST_MAN);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_ST_PHONE, 256);
}

BOOL COLEDB2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return COleDBRecordView::PreCreateWindow(cs);
}

void COLEDB2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_OLEDB2Set;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->OpenAll();
		if (FAILED(hr))
		{
			// ���ڵ� ������ ���� ���߽��ϴ�.  ���ڵ� ������ ����
			// ���ν����� ��� OpenAll()�� ȣ���ϱ� ���� 
			// �Է� �Ű� ������ ����� �ʱ�ȭ�ߴ���
			// Ȯ���Ͻʽÿ�.

			AfxMessageBox(_T("���ڵ� ������ ���� ���߽��ϴ�."), MB_OK);
			// ���� RowSet ���� ���� ���ڵ��� ������ �õ��ϸ�
			// �浹�� �� �ֱ� ������ ���� �� ���� ���ڵ� �����
			// ��Ȱ��ȭ�մϴ�.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if (hr == DB_S_ENDOFROWSET)
		{
			// �� ������ ��� �ֽ��ϴ�(���� ���ԵǾ� ���� ����).
			AfxMessageBox(_T("���ڵ� ������ �������� ��ȯ�� ���� �������ϴ�."), MB_OK);
			// ���� �� ���� ���ڵ� ����� ��Ȱ��ȭ�մϴ�.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
	COleDBRecordView::OnInitialUpdate();

	m_pSet->MoveFirst();
	UpdateData(FALSE);
}


// COLEDB2View �μ�

BOOL COLEDB2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void COLEDB2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void COLEDB2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// COLEDB2View ����

#ifdef _DEBUG
void COLEDB2View::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void COLEDB2View::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

COLEDB2Doc* COLEDB2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COLEDB2Doc)));
	return (COLEDB2Doc*)m_pDocument;
}
#endif //_DEBUG


// COLEDB2View �����ͺ��̽� ����
CRowset<>* COLEDB2View::OnGetRowset()
{
	return m_pSet->GetRowsetBase();
}



// COLEDB2View �޽��� ó����

// ���� ���� 05
void COLEDB2View::OnRecordSearchname()
{
	// TODO: Add your command handler code here
	CSearchDialog dlg;
	if (dlg.DoModal() == IDOK) {
		if (!dlg.m_name.IsEmpty()) {
			m_pSet->MoveFirst();
			BOOL checkFind = FALSE;
			do {
				if (m_pSet->m_ST_NAME == dlg.m_name) {
					checkFind = TRUE;
					break;
				}
			} while (m_pSet->MoveNext() == S_OK);
			if (checkFind) {
				UpdateData(FALSE);
			}
		}
	}
}
// --

// ���� ���� 06
void COLEDB2View::OnRecordAppend()
{
	// TODO: Add your command handler code here
	UpdateData(TRUE);

	CString name, phone;
	int num, man;
	name = m_pSet->m_ST_NAME;
	phone = m_pSet->m_ST_PHONE;
	num = m_pSet->m_ST_NUM;
	man = m_pSet->m_ST_MAN;

	m_pSet->MoveLast();

	m_pSet->m_dwST_NUMStatus = DBSTATUS_S_OK;
	m_pSet->m_dwST_NAMEStatus = DBSTATUS_S_OK;
	m_pSet->m_dwST_MANStatus = DBSTATUS_S_OK;
	m_pSet->m_dwST_PHONEStatus = DBSTATUS_S_OK;

	m_pSet->m_dwST_NAMELength = name.GetLength();
	m_pSet->m_dwST_PHONELength = phone.GetLength();

	m_pSet->m_ST_NUM = num;
	wsprintf(m_pSet->m_ST_NAME, name);
	m_pSet->m_ST_MAN = man;
	wsprintf(m_pSet->m_ST_PHONE, phone);

	HRESULT hr = m_pSet->Insert();
	if (FAILED(hr)) {
		AfxMessageBox(_T("���ڵ� �߰� ����!"), MB_OK);
	}

}
// --