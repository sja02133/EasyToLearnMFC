
// ODBC2View.cpp : CODBC2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ODBC2.h"
#endif

#include "ODBC2Set.h"
#include "ODBC2Doc.h"
#include "ODBC2View.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CODBC2View

IMPLEMENT_DYNCREATE(CODBC2View, CRecordView)

BEGIN_MESSAGE_MAP(CODBC2View, CRecordView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_TEST_MANONLY, &CODBC2View::OnTestManonly)
	ON_COMMAND(ID_TEST_WOMANONLY, &CODBC2View::OnTestWomanonly)
	ON_COMMAND(ID_TEST_ADDRECORD, &CODBC2View::OnTestAddrecord)
END_MESSAGE_MAP()

// CODBC2View ����/�Ҹ�

CODBC2View::CODBC2View()
	: CRecordView(IDD_ODBC2_FORM)
{
	m_pSet = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CODBC2View::~CODBC2View()
{
}

void CODBC2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// ��Ʈ���� �����ͺ��̽� �ʵ忡 '����'�ϱ� ���� ���⿡ DDX_Field* �Լ��� ������ �� �ֽ��ϴ�. ��:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �ڼ��� ������ MSDN �� ODBC ������ �����Ͻʽÿ�.


	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_ST_NUM, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_ST_NAME, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_ST_MAN, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_ST_PHONE, m_pSet);

}

BOOL CODBC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CRecordView::PreCreateWindow(cs);
}

void CODBC2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBC2Set;
	CRecordView::OnInitialUpdate();
}


// CODBC2View �μ�

BOOL CODBC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CODBC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CODBC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CODBC2View ����

#ifdef _DEBUG
void CODBC2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBC2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBC2Doc* CODBC2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC2Doc)));
	return (CODBC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CODBC2View �����ͺ��̽� ����
CRecordset* CODBC2View::OnGetRecordset()
{
	return m_pSet;
}


// CODBC2View �޽��� ó����


void CODBC2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CString str;
	str.Format(_T("��ȣ : %d, �̸� : %s, ���� : %s, ��ȭ : %s"), m_pSet->m_ST_NUM,
		m_pSet->m_ST_NAME, m_pSet->m_ST_MAN == 1 ? _T("��") : _T("��"), m_pSet->m_ST_PHONE);
	MessageBox(str);

	CRecordView::OnLButtonDblClk(nFlags, point);
}


void CODBC2View::OnTestManonly()
{
	// TODO: Add your command handler code here
	m_pSet->m_strFilter = _T("ST_MAN = TRUE");
	m_pSet->Requery();
	UpdateData(FALSE);
}


void CODBC2View::OnTestWomanonly()
{
	// TODO: Add your command handler code here
	m_pSet->m_strFilter = _T("ST_MAN = FALSE");
	m_pSet->Requery();
	UpdateData(FALSE);
}

// ���� ���� 04
void CODBC2View::OnTestAddrecord()
{
	// TODO: Add your command handler code here
	m_pSet->AddNew();
	UpdateData(TRUE);
	m_pSet->Update();
}
// --