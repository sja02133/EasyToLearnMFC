// CBitmapView.cpp : implementation file
//

#include "pch.h"
#include "MDITest.h"
#include "CBitmapView.h"

#include "CBitmapDoc.h"

// CBitmapView

IMPLEMENT_DYNCREATE(CBitmapView, CView)

CBitmapView::CBitmapView()
{

}

CBitmapView::~CBitmapView()
{
}

BEGIN_MESSAGE_MAP(CBitmapView, CView)
END_MESSAGE_MAP()


// CBitmapView drawing

void CBitmapView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	// TODO: add draw code here

	CBitmapDoc* pDoc = (CBitmapDoc*)GetDocument();

	//BITMAP bmp;
	//pDoc->m_bitmap.GetObject(sizeof(BITMAP), &bmp);

	//CDC memDC;
	//memDC.CreateCompatibleDC(pDC);

	//CBitmap* pOldBitmap = (CBitmap*)memDC.SelectObject(&pDoc->m_bitmap);

	//pDC->BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 0, 0, SRCCOPY);
	//memDC.SelectObject(pOldBitmap);
	//memDC.DeleteDC();

	// 연습 문제 20
	CDocTemplate* pTemplate = pDoc->GetDocTemplate();
	CString str = _T(""), tempStr = _T("");
	str += _T("windowTitle : ");
	pTemplate->GetDocString(tempStr, CDocTemplate::windowTitle);
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


// CBitmapView diagnostics

#ifdef _DEBUG
void CBitmapView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CBitmapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBitmapView message handlers
