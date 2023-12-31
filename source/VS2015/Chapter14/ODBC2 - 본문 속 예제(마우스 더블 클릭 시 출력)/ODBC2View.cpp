
// ODBC2View.cpp : CODBC2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CODBC2View 생성/소멸

CODBC2View::CODBC2View()
	: CRecordView(IDD_ODBC2_FORM)
{
	m_pSet = NULL;
	// TODO: 여기에 생성 코드를 추가합니다.

}

CODBC2View::~CODBC2View()
{
}

void CODBC2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 컨트롤을 데이터베이스 필드에 '연결'하기 위해 여기에 DDX_Field* 함수를 삽입할 수 있습니다. 예:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 자세한 내용은 MSDN 및 ODBC 샘플을 참조하십시오.
}

BOOL CODBC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CRecordView::PreCreateWindow(cs);
}

void CODBC2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBC2Set;
	CRecordView::OnInitialUpdate();
}


// CODBC2View 인쇄

BOOL CODBC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CODBC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CODBC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CODBC2View 진단

#ifdef _DEBUG
void CODBC2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBC2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBC2Doc* CODBC2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC2Doc)));
	return (CODBC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CODBC2View 데이터베이스 지원
CRecordset* CODBC2View::OnGetRecordset()
{
	return m_pSet;
}


// CODBC2View 메시지 처리기


void CODBC2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CString str;
	str.Format(_T("번호: %d, 이름: %s, 성별: %s, 전화: %s"),
		m_pSet->m_ST_NUM,
		m_pSet->m_ST_NAME,
		m_pSet->m_ST_MAN == 1 ? _T("남") : _T("여"),
		m_pSet->m_ST_PHONE);
	MessageBox(str);
}
