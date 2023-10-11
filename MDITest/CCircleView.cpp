// CCircleView.cpp : implementation file
//

#include "pch.h"
#include "MDITest.h"
#include "CCircleView.h"

#include "CCircleDoc.h"

// CCircleView

IMPLEMENT_DYNCREATE(CCircleView, CView)

CCircleView::CCircleView()
{

}

CCircleView::~CCircleView()
{
}

BEGIN_MESSAGE_MAP(CCircleView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CCircleView drawing

void CCircleView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	// TODO: add draw code here

	CCircleDoc* pDoc = (CCircleDoc*)GetDocument();
	// 기존
	//pDC->SelectStockObject(LTGRAY_BRUSH);
	//for (int i = 0; i < pDoc->m_points.GetSize(); i++) {
	//	pDC->Ellipse(pDoc->m_points[i].x - 20,
	//		pDoc->m_points[i].y - 20, pDoc->m_points[i].x + 20,
	//		pDoc->m_points[i].y + 20);
	//}
	// --

	// 연습 문제 20
	CDocTemplate* pTemplate = pDoc->GetDocTemplate();
	CString str = _T(""), tempStr = _T("");
	str += _T("windowTitle : ");
	pTemplate->GetDocString(tempStr,CDocTemplate::windowTitle);
	str += tempStr + _T("\n");
	str += _T("docName : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::docName);
	str += tempStr + _T("\n");
	str += _T("fileNewName : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::fileNewName);
	str += tempStr + _T("\n");
	str += _T("filterName : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::filterName);
	str += tempStr + _T("\n");
	str += _T("filterExt : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::filterExt);
	str += tempStr + _T("\n");
	str += _T("regFileTypeId : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::regFileTypeId);
	str += tempStr + _T("\n");
	str += _T("regFileTypeName : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::regFileTypeName);
	str += tempStr + _T("\n");
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(str, &rect, DT_LEFT);
	// --
}


// CCircleView diagnostics

#ifdef _DEBUG
void CCircleView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCircleView message handlers


void CCircleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CCircleDoc* pDoc = (CCircleDoc*)GetDocument();
	pDoc->m_points.Add(point);
	pDoc->UpdateAllViews(NULL);


	CView::OnLButtonDown(nFlags, point);
}
