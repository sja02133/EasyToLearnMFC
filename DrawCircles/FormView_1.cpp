// FormView_1.cpp : implementation file
//

#include "pch.h"
#include "DrawCircles.h"
#include "FormView_1.h"


// FormView_1

IMPLEMENT_DYNCREATE(FormView_1, CFormView)


FormView_1::FormView_1()
	: CFormView(FormView_1::IDD)
{

	m_button = 0;
}

FormView_1::~FormView_1()
{
}

void FormView_1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FormView_1, CFormView)
END_MESSAGE_MAP()


// FormView_1 diagnostics

#ifdef _DEBUG
void FormView_1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormView_1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormView_1 message handlers
