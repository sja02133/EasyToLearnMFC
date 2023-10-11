﻿
// ModalDialog3View.cpp: CModalDialog3View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ModalDialog3.h"
#endif

#include "ModalDialog3Doc.h"
#include "ModalDialog3View.h"
#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDialog3View

IMPLEMENT_DYNCREATE(CModalDialog3View, CView)

BEGIN_MESSAGE_MAP(CModalDialog3View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalDialog3View 생성/소멸

CModalDialog3View::CModalDialog3View() noexcept
{
	m_str = _T("");
	m_font = 0;
}

CModalDialog3View::~CModalDialog3View()
{
}

BOOL CModalDialog3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CModalDialog3View 그리기

void CModalDialog3View::OnDraw(CDC* pDC)
{
	CModalDialog3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	CString fontname;

	if (m_font == 0) fontname = _T("굴림");
	else if (m_font == 1) fontname = _T("궁서");
	else if (m_font == 2) fontname = _T("바탕");
	font.CreatePointFont(400, fontname);

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);
}


// CModalDialog3View 인쇄

BOOL CModalDialog3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CModalDialog3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CModalDialog3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CModalDialog3View 진단

#ifdef _DEBUG
void CModalDialog3View::AssertValid() const
{
	CView::AssertValid();
}

void CModalDialog3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModalDialog3Doc* CModalDialog3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDialog3Doc)));
	return (CModalDialog3Doc*)m_pDocument;
}
#endif //_DEBUG


// CModalDialog3View 메시지 처리기


void CModalDialog3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMyDialog dlg; // C++ 대화 상자 객체를 생성한다.
	dlg.m_str = m_str; // 뷰 객체의 멤버 변숫값으로 대화 상자 객체의...
	dlg.m_font = m_font; // ...멤버 변수를 초기화한다.

	int result = dlg.DoModal(); // 모드형 대화 상자를 연다.
	if (result == IDOK) {
		m_str = dlg.m_str; // 대화 상자 객체의 멤버 변숫값을...
		m_font = dlg.m_font; // ...뷰 객체의 멤버 변수에 저장한다.
		Invalidate(); // 뷰 화면에 출력한다.
	}
	else if (result == IDC_CLEAR) {
		m_str = _T("");
		Invalidate(); // 뷰 화면에 출력한다.
	}
}
