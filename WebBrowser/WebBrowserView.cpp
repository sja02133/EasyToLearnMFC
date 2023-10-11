
// WebBrowserView.cpp : implementation of the CWebBrowserView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WebBrowser.h"
#endif

#include "WebBrowserDoc.h"
#include "WebBrowserView.h"

#include "CMyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWebBrowserView

IMPLEMENT_DYNCREATE(CWebBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CWebBrowserView, CHtmlView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_WEBSEARCH_OPEN, &CWebBrowserView::OnWebsearchOpen)
	ON_COMMAND(ID_WEBSEARCH_BACK, &CWebBrowserView::OnWebsearchBack)
	ON_COMMAND(ID_WEBSEARCH_FORWARD, &CWebBrowserView::OnWebsearchForward)
END_MESSAGE_MAP()

// CWebBrowserView construction/destruction

CWebBrowserView::CWebBrowserView() noexcept
{
	// TODO: add construction code here

}

CWebBrowserView::~CWebBrowserView()
{
}

BOOL CWebBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CWebBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	m_pBrowserApp->put_Silent(VARIANT_TRUE);
	GoHome();
}


// CWebBrowserView printing



// CWebBrowserView diagnostics

#ifdef _DEBUG
void CWebBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CWebBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CWebBrowserDoc* CWebBrowserView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWebBrowserDoc)));
	return (CWebBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CWebBrowserView message handlers


void CWebBrowserView::OnWebsearchOpen()
{
	// TODO: Add your command handler code here
	CMyDialog dlg;
	if (dlg.DoModal() == IDOK)
		Navigate(dlg.m_url);
}


void CWebBrowserView::OnWebsearchBack()
{
	// TODO: Add your command handler code here
	GoBack();
}


void CWebBrowserView::OnWebsearchForward()
{
	// TODO: Add your command handler code here
	GoForward();
}

// 연습 문제 12
void CWebBrowserView::OnNavigateComplete2(LPCTSTR strURL)
{
	// TODO: Add your specialized code here and/or call the base class

	AfxGetMainWnd()->SetWindowText(strURL);

	CHtmlView::OnNavigateComplete2(strURL);
}
// --