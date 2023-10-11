
// SDITestDoc.cpp : implementation of the CSDITestDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDITest.h"
#endif

#include "SDITestDoc.h"

#include "SDITestView.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSDITestDoc

IMPLEMENT_DYNCREATE(CSDITestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDITestDoc, CDocument)
	ON_COMMAND(ID_APP_ABOUT, &CSDITestDoc::OnAppAbout)
END_MESSAGE_MAP()


// CSDITestDoc construction/destruction

CSDITestDoc::CSDITestDoc() noexcept
{
	// TODO: add one-time construction code here

}

CSDITestDoc::~CSDITestDoc()
{
}

BOOL CSDITestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}




// CSDITestDoc serialization

void CSDITestDoc::Serialize(CArchive& ar)
{
	
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		
	}
	else
	{
		// TODO: add loading code here
		// 연습 문제 06
		CFile* pFile = ar.GetFile();

		CString checkExtension = _T("txt");

		CString fileExtension;
		::AfxExtractSubString(fileExtension, pFile->GetFileName(), 1,'.');

		if (fileExtension.Compare(checkExtension) == 0) {
			int checkSize = 0;
			checkSize = pFile->Seek(0, SEEK_END);
			pFile->SeekToBegin();

			CString str;
			if (pFile->GetLength() != checkSize) {
				TCHAR* tempUni = (TCHAR*)malloc(checkSize);
				pFile->Read(tempUni, checkSize);
				str = tempUni;
			}
			else {
				char* tempChar = (char*)malloc(pFile->GetLength());
				memset(tempChar, 0, pFile->GetLength());
				pFile->Read(tempChar, pFile->GetLength());
				tempChar[pFile->GetLength()] = '\0';
				str = tempChar;
			}
			POSITION pos = GetFirstViewPosition();
			CSDITestView* pView = (CSDITestView*)GetNextView(pos);
			pView->m_str = str;
			pView->Invalidate();
		}
		// --
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSDITestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CSDITestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSDITestDoc::SetSearchContent(const CString& value)
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

// CSDITestDoc diagnostics

#ifdef _DEBUG
void CSDITestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDITestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSDITestDoc commands

// 연습 문제 08
void CSDITestDoc::OnAppAbout()
{
	// TODO: Add your command handler code here
	CString str;
	str = ::PathFindFileName(this->GetPathName());

	AfxMessageBox(str, MB_OK);

}
// --


