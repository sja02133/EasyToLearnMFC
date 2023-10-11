
// EditCtrlView.cpp : implementation of the CEditCtrlView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "EditCtrl.h"
#endif

#include "EditCtrlDoc.h"
#include "EditCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditCtrlView

IMPLEMENT_DYNCREATE(CEditCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CEditCtrlView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_EN_CHANGE(IDC_MYEDIT, &CEditCtrlView::OnChangeMyedit)
	ON_EN_MAXTEXT(IDC_MYEDIT, &CEditCtrlView::OnMaxtextMyedit)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, &CEditCtrlView::OnClickedButtonEnter)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CEditCtrlView construction/destruction

CEditCtrlView::CEditCtrlView() noexcept
	: CFormView(this->question_15 ? IDD_EDITCTRL_FORM_15 : IDD_EDITCTRL_FORM)
{
	// TODO: add construction code here

}

CEditCtrlView::~CEditCtrlView()
{
}

void CEditCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYEDIT, m_edit);
	DDX_Control(pDX, IDC_MYSTATIC, m_static);
}

BOOL CEditCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CEditCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	this->m_edit.SetLimitText(20);

	// 연습 문제 15
	if (this->checkFirst) {
		CFile file(_T("EditCtrl.vcxproj"), CFile::modeRead, NULL);
		ULONGLONG k = file.GetLength();
		char* temp = (char*)malloc((UINT)k);
		file.Read(temp, (UINT)k);
		this->fileStr = temp;
		m_edit.SetWindowText(this->fileStr);
		this->checkFirst = FALSE;
	}
	// --

}


// CEditCtrlView printing

BOOL CEditCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEditCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEditCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CEditCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CEditCtrlView diagnostics

#ifdef _DEBUG
void CEditCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CEditCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CEditCtrlDoc* CEditCtrlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditCtrlDoc)));
	return (CEditCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CEditCtrlView message handlers


void CEditCtrlView::OnChangeMyedit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	
	// 기존
	//CString str;
	//this->m_edit.GetWindowText(str);
	//this->m_static.SetWindowText(str);
	// --

	// 연습 문제 10 
	//CString str;
	//this->m_edit.GetWindowText(str);
	//
	//CString staticStr;
	//for (int i = 0; i < str.GetLength(); i++) {
	//	staticStr += _T('*');
	//}
	//this->m_static.SetWindowText(staticStr);
	//
	//if (str.Compare(this->password) == 0) {
	//	MessageBox(_T("통과"));
	//}
	// --

	// 연습 문제 12
	//CString str;
	//this->m_edit.GetWindowText(str);
	//this->m_static.SetWindowText(str);
	//theApp.m_pMainWnd->SetWindowText(str);
	//SetTimer(IDC_MYEDIT, 3000, NULL);
	// --

}

void CEditCtrlView::OnMaxtextMyedit()
{
	// TODO: Add your control notification handler code here
	MessageBox(_T("최대 길이 도달!"), _T("오류"), MB_ICONERROR);
}

// 연습 문제 11
void CEditCtrlView::OnDraw(CDC* /*pDC*/)
{
	// TODO: Add your specialized code here and/or call the base class

	//m_edit.EnableWindow(this->m_bReadOnly);	// 연습 문제 11

}
// --

// 연습 문제 13
void CEditCtrlView::OnClickedButtonEnter()
{
	// TODO: Add your control notification handler code here
	CString str;
	this->m_edit.GetWindowText(str);

	this->m_static.SetWindowText(str);


}
// --

// 연습 문제 12
void CEditCtrlView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	switch (nIDEvent) {
	case IDC_MYEDIT:
		theApp.m_pMainWnd->SetWindowText(_T(""));
		break;
	}

	CFormView::OnTimer(nIDEvent);
}
// --