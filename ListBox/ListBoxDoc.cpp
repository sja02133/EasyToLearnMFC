
// ListBoxDoc.cpp : implementation of the CListBoxDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ListBox.h"
#endif

#include "ListBoxDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CListBoxDoc

IMPLEMENT_DYNCREATE(CListBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CListBoxDoc, CDocument)
END_MESSAGE_MAP()


// CListBoxDoc construction/destruction

CListBoxDoc::CListBoxDoc() noexcept
{
	// TODO: add one-time construction code here
}

CListBoxDoc::~CListBoxDoc()
{
}

BOOL CListBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// CListBoxDoc serialization

void CListBoxDoc::Serialize(CArchive& ar)
{
	pFrame = (CMainFrame*)AfxGetMainWnd();
	pos = GetFirstViewPosition();
	pView = (CListBoxView*)GetNextView(pos);
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		// 연습 문제 17
		
		//CListBoxView* pView = (CListBoxView*)pFrame->GetActiveView();
		
		CFile file;
		file.Open(_T("saveListBoxData.dat"), CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);

		// 왼쪽 리스트만 저장
		int count = pView->m_list1.GetCount();
		for (int i = 0; i < count; i++) {
			CString str = _T("");
			pView->m_list1.GetText(i, str);
			ar << str;
		}
		// --
	}
	else
	{
		// TODO: add loading code here
		// 연습 문제 17
		//CListBoxView* pView = (CListBoxView*)pFrame->GetActiveView();
		CFile file;
		file.Open(_T("saveListBoxData.dat"),CFile::modeRead);
		CArchive ar(&file, CArchive::load);

		// 왼쪽 리스트만 불러온다. 먼저 리스트 제거
		int count = pView->m_list1.GetCount();
		for (int i = 0; i < count; i++) {
			pView->m_list1.DeleteString(i);
		}
		CString str = _T("");
		while (TRUE) {
			ar >> str;
			if (str.GetLength() == 0)
				break;
			else
				pView->m_list1.AddString(str);
		}
		// --
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CListBoxDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CListBoxDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CListBoxDoc::SetSearchContent(const CString& value)
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

// CListBoxDoc diagnostics

#ifdef _DEBUG
void CListBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CListBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CListBoxDoc commands
