
// CHAPTER09_18to20Doc.cpp : implementation of the CCHAPTER0918to20Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CHAPTER09_18to20.h"
#endif

#include "CHAPTER09_18to20Doc.h"

#include <propkey.h>

#include "MainFrm.h"
#include "CHAPTER09_18to20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCHAPTER0918to20Doc

IMPLEMENT_DYNCREATE(CCHAPTER0918to20Doc, CDocument)

BEGIN_MESSAGE_MAP(CCHAPTER0918to20Doc, CDocument)
END_MESSAGE_MAP()


// CCHAPTER0918to20Doc construction/destruction

CCHAPTER0918to20Doc::CCHAPTER0918to20Doc() noexcept
{
	// TODO: add one-time construction code here

}

CCHAPTER0918to20Doc::~CCHAPTER0918to20Doc()
{
}

BOOL CCHAPTER0918to20Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(nullptr);
	}

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CCHAPTER0918to20Doc serialization

void CCHAPTER0918to20Doc::Serialize(CArchive& ar)
{
	// 연습 문제 20
	// 저장
	if (ar.IsStoring()) {

	}
	else if (ar.IsLoading()) {

	}

	// CEditView contains an edit control which handles all serialization
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
	}
#ifdef SHARED_HANDLERS

	if (m_viewList.IsEmpty() && ar.IsLoading())
	{
		CFile* pFile = ar.GetFile();
		pFile->Seek(0, FILE_BEGIN);
		ULONGLONG nFileSizeBytes = pFile->GetLength();
		ULONGLONG nFileSizeChars = nFileSizeBytes/sizeof(TCHAR);
		LPTSTR lpszText = (LPTSTR)malloc(((size_t)nFileSizeChars + 1) * sizeof(TCHAR));
		if (lpszText != nullptr)
		{
			ar.Read(lpszText, (UINT)nFileSizeBytes);
			lpszText[nFileSizeChars] = '\0';
			m_strThumbnailContent = lpszText;
			m_strSearchContent = lpszText;
		}
	}
#endif
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CCHAPTER0918to20Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(m_strThumbnailContent, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CCHAPTER0918to20Doc::InitializeSearchContent()
{
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// Use the entire text file content as the search content.
	SetSearchContent(m_strSearchContent);
}

void CCHAPTER0918to20Doc::SetSearchContent(const CString& value)
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

// CCHAPTER0918to20Doc diagnostics

#ifdef _DEBUG
void CCHAPTER0918to20Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCHAPTER0918to20Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCHAPTER0918to20Doc commands
