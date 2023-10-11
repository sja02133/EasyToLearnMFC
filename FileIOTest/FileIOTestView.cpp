
// FileIOTestView.cpp : implementation of the CFileIOTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FileIOTest.h"
#endif

#include "FileIOTestDoc.h"
#include "FileIOTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileIOTestView

IMPLEMENT_DYNCREATE(CFileIOTestView, CView)

BEGIN_MESSAGE_MAP(CFileIOTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CFileIOTestView construction/destruction

CFileIOTestView::CFileIOTestView() noexcept
{
	// TODO: add construction code here

	// 연습 문제 05
	//CFileFind finder;
	//BOOL bWorking = finder.FindFile(_T("*.cpp"));
	//while (bWorking) {
	//	bWorking = finder.FindNextFile();
	//	this->m_CStringListFile.AddTail(finder.GetFileName());
	//}
	// --

	// 연습 문제 06
	//CFileFind finder;
	//BOOL bWorking = finder.FindFile(_T("*.*"));
	//while (bWorking) {
	//	bWorking = finder.FindNextFile();
	//	this->m_CStringListFile.AddTail(finder.GetFileName());
	//}

	//try {
	//	CStdioFile stdFile;
	//	stdFile.Open(_T("FileList.txt"), CFile::modeCreate | CFile::modeWrite);
	//	POSITION pos = this->m_CStringListFile.GetHeadPosition();
	//	while (pos) {
	//		CString tempStr = this->m_CStringListFile.GetNext(pos);
	//		stdFile.WriteString(tempStr + _T("\n"));
	//	}
	//
	//}
	//catch (CFileException& e) {
	//	e.ReportError();
	//	e.Delete();
	//}
	// --
}

CFileIOTestView::~CFileIOTestView()
{
}

BOOL CFileIOTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFileIOTestView drawing

void CFileIOTestView::OnDraw(CDC* pDC)
{
	CFileIOTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	// 실습 7-1
	//pDC->SetMapMode(MM_LOMETRIC);
	//pDC->Rectangle(50, -50, 350, -350);
	//pDC->Ellipse(500, -50, 800, -350);
	// --

	// 연습 문제 12, OnDraw 호출을 위해 OnPaint 이벤트 모두 주석처리.
	//pDC->SetMapMode(MM_LOMETRIC);
	//pDC->Rectangle(0, 0, 950, -1700);
	// --

}


// CFileIOTestView printing

BOOL CFileIOTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileIOTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFileIOTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFileIOTestView diagnostics

#ifdef _DEBUG
void CFileIOTestView::AssertValid() const
{
	CView::AssertValid();
}

void CFileIOTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileIOTestDoc* CFileIOTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileIOTestDoc)));
	return (CFileIOTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileIOTestView message handlers


void CFileIOTestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 연습 문제 01
	//CFile pFile;
	//try{
	//	::CreateDirectory(_T("C:\\Temp1"),NULL);
	//	pFile.Open(_T("C:\\Temp1\\MyFile.tmp"), CFile::modeCreate);
	//}
	//catch (CFileException* e) {
	//	e->ReportError();
	//	e->Delete();
	//}
	// --

	// 연습 문제 02
	//memFile.Write(&point, sizeof(point));
	//this->m_bExistData = TRUE;
	// --

	// 연습 문제 03
	//Invalidate();
	// --

	// 연습 문제 04
	//CStdioFile stdFile;
	//stdFile.Open(_T("test1.txt"), CFile::modeRead | CFile::typeUnicode);

	//CString tempStr = _T("");

	//if (this->m_str.GetLength()) {
	//	this->m_str = _T("");
	//}

	//while (stdFile.ReadString(tempStr)) {
	//	this->m_str += tempStr + _T("\n");
	//}
	//Invalidate();
	// --

	// 연습 문제 14
	this->m_x1 = this->m_x2 = point.x;
	this->m_y1 = this->m_y2 = point.y;
	this->m_bDrawMode = TRUE;
	// --

	// 연습 문제 15
	this->m_saveMousePoint = point;
	CFile file;
	file.Open(_T("saveMousePoint.dat"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);

	ar << this->m_saveMousePoint;
	// --

	CView::OnLButtonDown(nFlags, point);
}


void CFileIOTestView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 연습 문제 02
	//if (this->m_bExistData) {
	//	this->memFile.SeekToBegin();
	//	this->memFile.Read(&point, sizeof(point));
	//	try {
	//		CFile file;
	//		file.Open(_T("MyData.dat"), CFile::modeCreate|CFile::modeWrite);
	//		file.Write(&point, sizeof(point));
	//	}
	//	catch (CFileException& e) {
	//		e.ReportError();
	//		e.Delete();
	//	}
	//
	//}
	// --

	// 연습 문제 15
	CFile file;
	file.Open(_T("saveMousePoint.dat"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);

	ar >> this->m_saveMousePoint;
	Invalidate();
	// --

	CView::OnRButtonDown(nFlags, point);
}

int count = 0;


void CFileIOTestView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	// 연습 문제 03
	//if (this->m_bExistData) {
	//	CPoint point;

	//	this->memFile.SeekToBegin();
	//	this->memFile.Read(&point, sizeof(point));

	//	CString str;
	//	str.Format(_T("(%04d,%04d)"), point.x, point.y);

	//	dc.TextOut(0, 0, str);
	//}
	// --

	// 연습 문제 04
	//CRect rect;
	//GetClientRect(&rect);
	//if (this->m_str.GetLength()) {
	//	dc.DrawText(this->m_str,&rect,DT_WORDBREAK);
	//}
	// --

	// 연습 문제 05
	//this->m_str = _T("");
	//CRect rect;
	//GetClientRect(&rect);
	//if (this->m_CStringListFile.GetCount()) {
	//	POSITION pos = this->m_CStringListFile.GetHeadPosition();
	//	while (pos) {
	//		this->m_str += this->m_CStringListFile.GetNext(pos);
	//		this->m_str += _T("\n");
	//	}
	//	dc.DrawText(this->m_str, &rect, DT_LEFT);
	//}
	//

	// 기존
	//this->m_str = _T("파일이 선택되지 않았습니다.");
	// --

	// 연습 문제 10
	//if(count == 0)
	//	this->m_str = _T("파일이 선택되지 않았습니다.");
	// --

	// 연습 문제 11
	//if (count == 0)
	//	this->m_str = _T("");
	//// --
	//CRect rect;
	//GetClientRect(&rect);
	//dc.DrawText(this->m_str, &rect, DT_LEFT);
	//count++;
	// --
	
	// 연습 문제 13
	if (this->m_bImage) {
		CRect rect;
		GetClientRect(&rect);
		//dc.StretchBlt(0, 0, this->image.GetWidth(), this->image.GetHeight(), dc.FromHandle(this->image.GetDC()), 0, 0, this->image.GetWidth(), this->image.GetHeight(), SRCCOPY);
		dc.StretchBlt(0, 0, rect.right, rect.bottom, dc.FromHandle(this->image.GetDC()), 0, 0, this->image.GetWidth(), this->image.GetHeight(), SRCCOPY);
	}
	// --

	// 연습 문제 14
	//if (this->m_listPoint.GetSize() == 0)
	//	return;
	//CPoint startPoint;
	//dc.SelectStockObject(NULL_BRUSH);
	//POSITION pos = this->m_listPoint.GetHeadPosition();
	//auto b_point = this->m_listPoint.GetHead();
	//dc.MoveTo(b_point);
	//int count = 0;
	//if (this->m_listPoint.GetSize()) {
	//	while (pos) {
	//		auto n_point = this->m_listPoint.GetNext(pos);
	//		dc.LineTo(n_point);
	//	}
	//}
	// --

	// 연습 문제 15
	if (this->m_saveMousePoint.x != 0 || this->m_saveMousePoint.y != 0) {
		CString str = _T("");
		str.Format(_T("(%03d,%03d)"), this->m_saveMousePoint.x, this->m_saveMousePoint.y);

		dc.TextOut(0, 0, str);
	}
	// --
}

// 연습 문제 14
void CFileIOTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//if (this->m_bDrawMode) {
	//	CClientDC dc(this);
	//	dc.SelectStockObject(NULL_BRUSH);
	//	dc.SetROP2(R2_NOT);
	//	dc.MoveTo(m_x2, m_y2);
	//	dc.SetROP2(R2_NOT);
	//	m_x2 = point.x;
	//	m_y2 = point.y;
	//	dc.LineTo(point.x, point.y);
	//	this->m_listPoint.AddTail(point);
	//}

	CView::OnMouseMove(nFlags, point);
}
// --

void CFileIOTestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 연습 문제 14
	this->m_bDrawMode = FALSE;
	CFileIOTestDoc* pDoc = this->GetDocument();
	CFile file;
	file.Open(_T("listPoint.dat"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file,CArchive::store);
	
	POSITION pos = this->m_listPoint.GetHeadPosition();
	while (pos) {
		auto point = this->m_listPoint.GetNext(pos);
		ar << point;
	}
	// --

	// 연습 문제 15
	
	// --

	CView::OnLButtonUp(nFlags, point);
}
