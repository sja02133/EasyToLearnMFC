
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "ChangeCursor.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	this->m_rectRgn.left = 10;
	this->m_rectRgn.top = 10;
	this->m_rectRgn.right = 400;
	this->m_rectRgn.bottom = 100;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	// 기존
	//dc.SelectStockObject(LTGRAY_BRUSH);
	//dc.Ellipse(this->m_rectRgn);
	// --
	// 연습 문제 13
	//dc.SelectStockObject(NULL_BRUSH);
	//dc.SetROP2(R2_NOT);
	//dc.Ellipse(this->m_rect);
	// --

	// 연습 문제 16
	CPen pen;
	if (this->m_bLBclicked && this->m_bLBClickedRgn) {
		pen.CreatePen(PS_DASHDOT, 1, RGB(255, 0, 0));
		dc.SelectObject(&pen);
		dc.SelectStockObject(LTGRAY_BRUSH);
		dc.Ellipse(this->m_rectRgn);
	}
	else {
		dc.SelectStockObject(LTGRAY_BRUSH);
		dc.Ellipse(this->m_rectRgn);
	}

	pen.DeleteObject();
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&pen);
	if (this->m_listRect.GetSize() > 0) {
		POSITION pos = this->m_listRect.GetHeadPosition();
		while (pos) {
			auto rect = this->m_listRect.GetNext(pos);
			dc.SelectStockObject(LTGRAY_BRUSH);
			dc.Ellipse(rect);
		}
	}
	// --

	// Do not call CWnd::OnPaint() for painting messages
}

int count = 0;

BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	if (nHitTest == HTCLIENT)
	{
		// 기존
		//CPoint point;
		//::GetCursorPos(&point);
		//ScreenToClient(&point);
		//CRgn rgn;
		//rgn.CreateEllipticRgn(10, 10, 400, 100);
		//if (rgn.PtInRegion(point))
		//	::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		//else
		//	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		// --

		// 연습 문제 13
		//CPoint point;
		//::GetCursorPos(&point);
		//ScreenToClient(&point);
		//this->m_point = point;
		//this->m_rect.SetRect(CPoint(point.x - 20, point.y - 20), CPoint(point.x + 20, point.y + 20));
		//this->m_bSetCursor = TRUE;
		// --

		// 연습 문제 14
		//CPoint point;
		//::GetCursorPos(&point);
		//ScreenToClient(&point);
		//CRgn rgn;
		//rgn.CreateEllipticRgn(10, 10, 400, 100);
		//if (rgn.PtInRegion(point)) {
		//	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
		//}
		//else
		//	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
		// --

		// 연습 문제 15
		//CPoint point;
		//::GetCursorPos(&point);
		//ScreenToClient(&point);
		//CRgn rgn;
		//rgn.CreateEllipticRgn(this->m_rectRgn.left,this->m_rectRgn.top,this->m_rectRgn.right,this->m_rectRgn.bottom);
		////CClientDC dc(this);
		////dc.SelectStockObject(NULL_BRUSH);
		////dc.Rectangle(this->m_rectRgn);
		//if (rgn.PtInRegion(point)) {
		//	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
		//	if (this->m_bLBclicked)
		//		this->m_bLBClickedRgn = TRUE;
		//}
		//else
		//	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
		// --

		// 연습 문제 16
		CPoint point;
		::GetCursorPos(&point);
		ScreenToClient(&point);
		CRgn rgn;
		rgn.CreateEllipticRgn(this->m_rectRgn.left, this->m_rectRgn.top, this->m_rectRgn.right, this->m_rectRgn.bottom);
		if (rgn.PtInRegion(point)) {
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
			if (this->m_bLBclicked)
				this->m_bLBClickedRgn = TRUE;
		}
		else
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(this->m_rectRgn);
		if (this->m_listRect.GetSize()) {
			POSITION pos = this->m_listRect.GetHeadPosition();
			while (pos) {
				rgn.DeleteObject();
				auto rect = this->m_listRect.GetNext(pos);
				rgn.CreateEllipticRgn(rect.left,rect.top,rect.right,rect.bottom);
				if (rgn.PtInRegion(point)) {
					::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
					if (this->m_bLBclicked)
						this->m_bLBClickedRgn = TRUE;

					break;
				}
				else
					::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
			}
			int kkk = 0;
			rgn.DeleteObject();
			rgn.CreateEllipticRgn(this->m_rectRgn.left, this->m_rectRgn.top, this->m_rectRgn.right, this->m_rectRgn.bottom);
			if (rgn.PtInRegion(point)) {
				::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND));
				if (this->m_bLBclicked)
					this->m_bLBClickedRgn = TRUE;
			}
			else if (this->m_bLBClickedRgn) {
				if(::GetCursor() != AfxGetApp()->LoadCursorW(IDC_ARROW))
					::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
			}
		}
		// --

		

		return TRUE;
	}

	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 연습 문제 13
	//if (this->m_bSetCursor) {
	//	this->m_point = point;
	//	this->m_rect.SetRect(CPoint(point.x - 20, point.y - 20), CPoint(point.x + 20, point.y + 20));
	//	Invalidate();
	//}
	// --

	// 연습 문제 15
	//if (this->m_bLBclicked && (this->m_beforePoint.x != point.x && this->m_beforePoint.y != point.y)) {
	//	count++;
	//	CPoint tempPoint = point;
	//	//TRACE("diff bX : %d,bY : %d | aX : %d, aY : %d\n", this->m_beforePoint.x, this->m_beforePoint.y, point.x, point.y);
	//	//TRACE("Move X : %d, Y : %d\n", this->m_beforePoint.x - point.x, this->m_beforePoint.y - point.y);
	//	point.x -= this->m_beforePoint.x;
	//	point.y -= this->m_beforePoint.y;
	//	this->m_beforePoint = tempPoint;
	//	OffsetRect(this->m_rectRgn, point.x, point.y);
	//	Invalidate();
	//}
	// --

	// 연습 문제 16
	if (this->m_bLBclicked && (this->m_beforePoint.x != point.x && this->m_beforePoint.y != point.y)
		) {
		CPoint tempPoint = point;
		point.x -= this->m_beforePoint.x;
		point.y -= this->m_beforePoint.y;
		this->m_beforePoint = tempPoint;
		OffsetRect(this->m_rectRgn, point.x, point.y);
		Invalidate();
	}
	// --

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// 연습 문제 14
	//CPoint point;
	//::GetCursorPos(&point);
	//ScreenToClient(&point);
	// --
	
	// 연습 문제 15
	this->m_bLBclicked = TRUE;
	this->m_beforePoint = point;
	// --

	// 연습 문제 16
	if (this->m_listRect.GetSize()) {
		POSITION pos = this->m_listRect.GetHeadPosition();
		CRgn rgn;
		while (pos) {
			auto rect = this->m_listRect.GetNext(pos);
			rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);
			if (rgn.PtInRegion(point)) {
				this->m_rectRgn = rect;
				break;
			}
			else
				rgn.DeleteObject();
		}
	}
	// --

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// 연습 문제 15
	//if (this->m_bLBclicked) {
	//	this->m_bLBclicked = FALSE;
	//}
	// --

	// 연습 문제 16
	if (this->m_bLBclicked) {
		this->m_bLBclicked = FALSE;
		this->m_bLBClickedRgn = FALSE;
		if(nFlags & MK_CONTROL)
			this->m_listRect.AddTail(this->m_rectRgn);
		Invalidate();
	}
	// --
	CWnd::OnLButtonUp(nFlags, point);
}
