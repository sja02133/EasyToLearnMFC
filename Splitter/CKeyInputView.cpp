// CKeyInputView.cpp : implementation file
//

#include "pch.h"
#include "Splitter.h"
#include "SplitterDoc.h"
#include "CKeyInputView.h"


// CKeyInputView

IMPLEMENT_DYNCREATE(CKeyInputView, CView)

CKeyInputView::CKeyInputView()
{

}

CKeyInputView::~CKeyInputView()
{
}

BEGIN_MESSAGE_MAP(CKeyInputView, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CKeyInputView drawing

void CKeyInputView::OnDraw(CDC* pDC)
{
	CSplitterDoc* pDoc = (CSplitterDoc*)GetDocument();
	// TODO: add draw code here

	CFont font;
	font.CreatePointFont(150, _T("궁서"));
	pDC->SelectObject(&font);

	// 기존
	//CRect rect;
	//GetClientRect(&rect);
	//pDC->DrawText(pDoc->m_str.GetData(), pDoc->m_str.GetSize(), &rect, DT_LEFT);
	// --

	// 연습 문제 13
	//CRect rect;
	//GetClientRect(&rect);
	//CString totalStr = _T("");
	//for (int i = 0; i < pDoc->m_points.GetSize(); i++) {
	//	CString str = _T("");
	//	str.Format(_T("%d : (%d, %d)"), i, pDoc->m_points[i].x, pDoc->m_points[i].y);
	//	this->m_drawPoints.AddTail(str);
	//	totalStr += str + _T("\n");
	//}
	//pDC->DrawText(totalStr, &rect, DT_LEFT);
	// --

	// 연습 문제 14
	BITMAP bmp;
	pDoc->bitmap.GetObject(sizeof(BITMAP), &bmp);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CBitmap* pOldBitmap = (CBitmap*)memDC.SelectObject(&pDoc->bitmap);
	CRect rect;
	GetClientRect(&rect);

	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0,0,bmp.bmWidth, bmp.bmHeight, SRCCOPY);
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	// --
}


// CKeyInputView diagnostics

#ifdef _DEBUG
void CKeyInputView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CKeyInputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CKeyInputView message handlers


void CKeyInputView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CSplitterDoc* pDoc = (CSplitterDoc*)GetDocument();

	if (nChar == _T('\b')) {
		if (pDoc->m_str.GetSize() > 0)
			pDoc->m_str.RemoveAt(pDoc->m_str.GetSize() - 1);
	}
	else
		pDoc->m_str.Add(nChar);

	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CKeyInputView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 연습 문제 12
	//CSplitterWnd* split = GetParentSplitter(this, TRUE);
	//int row = 0, col = 0;
	//split->IsChildPane(this, &row, &col);

	//CString str = _T("");
	//str.Format(_T("(%d,%d)"), row, col);
	//MessageBox(str, _T("Pane Index"), MB_ICONINFORMATION | MB_OK);
	// --

	CView::OnLButtonDown(nFlags, point);
}
