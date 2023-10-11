
// HtmlViewTestView.cpp : implementation of the CHtmlViewTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HtmlViewTest.h"
#endif

#include "HtmlViewTestDoc.h"
#include "HtmlViewTestView.h"

#include "CHtmlCodeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHtmlViewTestView

IMPLEMENT_DYNCREATE(CHtmlViewTestView, CHtmlView)

BEGIN_MESSAGE_MAP(CHtmlViewTestView, CHtmlView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_HTML_INPUTHTML, &CHtmlViewTestView::OnHtmlInputhtml)
END_MESSAGE_MAP()

// CHtmlViewTestView construction/destruction

CHtmlViewTestView::CHtmlViewTestView() noexcept
{
	// TODO: add construction code here

}

CHtmlViewTestView::~CHtmlViewTestView()
{
}

BOOL CHtmlViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CHtmlViewTestView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	m_pBrowserApp->put_Silent(VARIANT_TRUE);
	//Navigate2(_T("http://www.hanbit.co.kr"));
}


// CHtmlViewTestView printing



// CHtmlViewTestView diagnostics

#ifdef _DEBUG
void CHtmlViewTestView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CHtmlViewTestView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CHtmlViewTestDoc* CHtmlViewTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHtmlViewTestDoc)));
	return (CHtmlViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CHtmlViewTestView message handlers

// 연습 문제 11
void CHtmlViewTestView::OnHtmlInputhtml()
{
	// TODO: Add your command handler code here
	CHtmlCodeDialog dlg;

	if (dlg.DoModal() == IDOK) {
		if (!dlg.m_code.IsEmpty()) {
			Navigate(dlg.m_code,NULL,NULL);
		}
	}
}
// --