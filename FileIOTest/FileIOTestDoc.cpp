
// FileIOTestDoc.cpp : implementation of the CFileIOTestDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FileIOTest.h"
#endif

#include "FileIOTestDoc.h"

#include <propkey.h>

#include "MainFrm.h"
#include "FileIOTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFileIOTestDoc

IMPLEMENT_DYNCREATE(CFileIOTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CFileIOTestDoc, CDocument)
END_MESSAGE_MAP()


// CFileIOTestDoc construction/destruction

CFileIOTestDoc::CFileIOTestDoc() noexcept
{
	// TODO: add one-time construction code here

}

CFileIOTestDoc::~CFileIOTestDoc()
{
}

BOOL CFileIOTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CFileIOTestDoc serialization

void CFileIOTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		// 연습 문제 08
		//CFile* pFile = ar.GetFile();
		//AfxMessageBox(pFile->GetFilePath());
		// --



	}
	else
	{
		// TODO: add loading code here
		// 연습 문제 07
		//CFile* pFile = ar.GetFile();
		//AfxMessageBox(pFile->GetFilePath());
		// --

		// 연습 문제 09
		//CFile* pFile = ar.GetFile();
		//CString tempStr = _T("");
		//
		//ULONGLONG k = pFile->SeekToEnd();
		//ULONGLONG pos = pFile->Seek(k,CFile::begin);
		//tempStr.Format(_T("GetLength : %d, GetPosition : %I64u"), pFile->GetLength(), pos);
		//AfxMessageBox(tempStr);
		// --

		// 연습 문제 10
		//CFile* pFile = ar.GetFile();
		//char* tempChar = (char*)malloc(sizeof(char)*pFile->GetLength());
		//pFile->Read(tempChar,pFile->GetLength());
		//CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		//CFileIOTestView* pView = (CFileIOTestView*)pFrame->GetActiveView();
		//if (tempChar[0] == _T('B') && tempChar[1] == _T('M')) {
		//	pView->m_str = _T("");
		//	pView->m_str.Format(_T("비트맵 파일입니다.\n파일 크기:%4d(바이트)"), pFile->GetLength());
		//}
		//else {
		//	pView->m_str = _T("비트맵 파일이 아닙니다.");
		//}
		//this->UpdateAllViews(pView);
		// --

		// 연습 문제 10
		//CFile* pFile = ar.GetFile();
		//char* tempChar = (char*)malloc(sizeof(char) * pFile->GetLength());
		//pFile->Read(tempChar, pFile->GetLength());
		//CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		//CFileIOTestView* pView = (CFileIOTestView*)pFrame->GetActiveView();

		//pView->m_str = _T("");
		//int i = 0;
		//BOOL check_R = FALSE, check_N = FALSE;
		//while (i < pFile->GetLength()) {
		//	if (tempChar[i] == '\r' && tempChar[i + 1] == '\n') {
		//		i++;
		//		check_R = TRUE;
		//		check_N = TRUE;
		//	}
		//	else if (tempChar[i] == '\n')
		//		check_N = TRUE;
		//	i++;
		//}

		//if(check_R && check_N)
		//	pView->m_str = _T("윈도우 텍스트 파일입니다.");
		//else if (!check_R && check_N)
		//	pView->m_str = _T("윈도우 텍스트 파일이 아닙니다.");
		//else
		//	pView->m_str = _T("개행 문자가 없어 알 수 없습니다.");

		//this->UpdateAllViews(pView);
		// --

		// 연습 문제 13
		//CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		//CFileIOTestView* pView = (CFileIOTestView*)pFrame->GetActiveView();
		//CFile* pFile = ar.GetFile();
		//pView->image.Destroy();
		//HRESULT result = pView->image.Load(pFile->GetFilePath());
		//if (SUCCEEDED(result)) {
		//	pView->m_bImage = TRUE;
		//	pView->Invalidate();
		//}
		// --

		// 연습 문제 14
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CFileIOTestView* pView = (CFileIOTestView*)pFrame->GetActiveView();
		CFile* pFile = ar.GetFile();
		CArchive temp_ar(pFile, CArchive::load);
		pView->m_listPoint.RemoveAll();
		while (TRUE) {
			CPoint temp_point;
			temp_ar >> temp_point;
			if (temp_point.x == 0 && temp_point.y == 0)
				break;
			else
				pView->m_listPoint.AddTail(temp_point);
		}
		pView->Invalidate();
		// --
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CFileIOTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CFileIOTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CFileIOTestDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CFileIOTestDoc diagnostics

#ifdef _DEBUG
void CFileIOTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFileIOTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFileIOTestDoc commands
