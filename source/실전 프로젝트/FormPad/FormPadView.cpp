﻿
// FormPadView.cpp: CFormPadView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "FormPad.h"
#endif

#include "FormPadDoc.h"
#include "FormPadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFormPadView

IMPLEMENT_DYNCREATE(CFormPadView, CFormView)

BEGIN_MESSAGE_MAP(CFormPadView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFormPadView 생성/소멸

CFormPadView::CFormPadView() noexcept
	: CFormView(IDD_FORMPAD_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFormPadView::~CFormPadView()
{
}

void CFormPadView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CFormPadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CFormPadView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CFormPadView 인쇄

BOOL CFormPadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFormPadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFormPadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CFormPadView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CFormPadView 진단

#ifdef _DEBUG
void CFormPadView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormPadView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFormPadDoc* CFormPadView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormPadDoc)));
	return (CFormPadDoc*)m_pDocument;
}
#endif //_DEBUG


// CFormPadView 메시지 처리기
