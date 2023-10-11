
// TCPServer2View.cpp : implementation of the CTCPServer2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TCPServer2.h"
#endif

#include "TCPServer2Doc.h"
#include "TCPServer2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTCPServer2View

IMPLEMENT_DYNCREATE(CTCPServer2View, CEditView)

BEGIN_MESSAGE_MAP(CTCPServer2View, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTCPServer2View construction/destruction

CTCPServer2View::CTCPServer2View() noexcept
{
	// TODO: add construction code here

}

CTCPServer2View::~CTCPServer2View()
{
}

BOOL CTCPServer2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CTCPServer2View printing

BOOL CTCPServer2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CTCPServer2View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CTCPServer2View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CTCPServer2View diagnostics

#ifdef _DEBUG
void CTCPServer2View::AssertValid() const
{
	CEditView::AssertValid();
}

void CTCPServer2View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CTCPServer2Doc* CTCPServer2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTCPServer2Doc)));
	return (CTCPServer2Doc*)m_pDocument;
}
#endif //_DEBUG


// CTCPServer2View message handlers


void CTCPServer2View::AddMessage(LPCTSTR message)
{
	// TODO: Add your implementation code here.
	int len = GetWindowTextLength();
	GetEditCtrl().SetSel(len, len);
	GetEditCtrl().ReplaceSel(message);
}
