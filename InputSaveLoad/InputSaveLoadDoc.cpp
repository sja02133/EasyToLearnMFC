
// InputSaveLoadDoc.cpp : implementation of the CInputSaveLoadDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "InputSaveLoad.h"
#endif

#include "InputSaveLoadDoc.h"

#include <propkey.h>

#include "MainFrm.h"
#include "InputSaveLoadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CInputSaveLoadDoc

IMPLEMENT_DYNCREATE(CInputSaveLoadDoc, CDocument)

BEGIN_MESSAGE_MAP(CInputSaveLoadDoc, CDocument)
	ON_UPDATE_COMMAND_UI(ID_STYLE_ITALIC, &CInputSaveLoadDoc::OnUpdateStyleItalic)
	ON_UPDATE_COMMAND_UI(ID_STYLE_UNDERLINE, &CInputSaveLoadDoc::OnUpdateStyleUnderline)
	ON_COMMAND(ID_STYLE_ITALIC, &CInputSaveLoadDoc::OnStyleItalic)
	ON_COMMAND(ID_STYLE_UNDERLINE, &CInputSaveLoadDoc::OnStyleUnderline)
	ON_COMMAND(ID_STYLE_BOLD, &CInputSaveLoadDoc::OnStyleBold)
	ON_UPDATE_COMMAND_UI(ID_STYLE_BOLD, &CInputSaveLoadDoc::OnUpdateStyleBold)
	ON_COMMAND(ID_COLOR_RED, &CInputSaveLoadDoc::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CInputSaveLoadDoc::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CInputSaveLoadDoc::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CInputSaveLoadDoc::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CInputSaveLoadDoc::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CInputSaveLoadDoc::OnUpdateColorRed)
END_MESSAGE_MAP()


// CInputSaveLoadDoc construction/destruction

CInputSaveLoadDoc::CInputSaveLoadDoc() noexcept
{
	// TODO: add one-time construction code here



}

CInputSaveLoadDoc::~CInputSaveLoadDoc()
{
}

BOOL CInputSaveLoadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	this->m_str.RemoveAll();
	this->m_bItalic = this->m_bUnderline = FALSE;


	return TRUE;
}


// CInputSaveLoadDoc serialization

void CInputSaveLoadDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		//ar << m_bItalic << m_bUnderline;	//기존

		ar.Write(&m_bItalic, sizeof(BOOL));
		ar.Write(&m_bUnderline, sizeof(BOOL));

		//ar.Write(m_bItalic,sizeof(BOOL));
		
		CFile* pFile = ar.GetFile();

		CImage image;
		
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CInputSaveLoadView* pView = (CInputSaveLoadView*)pFrame->GetActiveView();
		
		CClientDC dc(pView);
		CRect rect;
		
		CDC* pDC = pView->GetDC();
		::GetClientRect(pView->m_hWnd, &rect);

		CDC memDC;
		memDC.CreateCompatibleDC(pDC);

		int color_depth = ::GetDeviceCaps(pView->GetDC()->m_hDC, BITSPIXEL);
		image.Create(rect.right, rect.bottom, color_depth,0);

		memDC.StretchBlt(0, 0, rect.right, rect.bottom,CDC::FromHandle(image.GetDC()), 0, 0, 1024, 1024, SRCCOPY);
		
		image.Save(pFile->GetFilePath(), GUID_NULL);
		image.ReleaseDC();

		m_str.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		//ar >> m_bItalic >> m_bUnderline;

		m_bItalic = FALSE;
		m_bUnderline = FALSE;

		ar.Read(&m_bItalic, sizeof(BOOL));
		ar.Read(&m_bUnderline, sizeof(BOOL));

		m_str.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CInputSaveLoadDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CInputSaveLoadDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CInputSaveLoadDoc::SetSearchContent(const CString& value)
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

// CInputSaveLoadDoc diagnostics

#ifdef _DEBUG
void CInputSaveLoadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInputSaveLoadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CInputSaveLoadDoc commands


void CInputSaveLoadDoc::OnUpdateStyleItalic(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bItalic == TRUE);
}


void CInputSaveLoadDoc::OnUpdateStyleUnderline(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bUnderline == TRUE);
}


void CInputSaveLoadDoc::OnStyleItalic()
{
	// TODO: Add your command handler code here
	this->m_bItalic = !this->m_bItalic;
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CInputSaveLoadDoc::OnStyleUnderline()
{
	// TODO: Add your command handler code here
	this->m_bUnderline = !this->m_bUnderline;
	SetModifiedFlag();
	UpdateAllViews(NULL);
}

// 연습 문제 18
void CInputSaveLoadDoc::OnStyleBold()
{
	// TODO: Add your command handler code here
	this->m_bBold = !this->m_bBold;
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CInputSaveLoadDoc::OnUpdateStyleBold(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bBold == TRUE);
}
// --


// 연습 문제 19
void CInputSaveLoadDoc::OnColorRed()
{
	// TODO: Add your command handler code here
	this->m_selectColor = RGB(255, 0, 0);
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CInputSaveLoadDoc::OnColorGreen()
{
	// TODO: Add your command handler code here
	this->m_selectColor = RGB(0, 255, 0);
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CInputSaveLoadDoc::OnColorBlue()
{
	// TODO: Add your command handler code here
	this->m_selectColor = RGB(0, 0, 255);
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CInputSaveLoadDoc::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(this->m_selectColor == RGB(0,0,255));
}


void CInputSaveLoadDoc::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(this->m_selectColor == RGB(0, 255, 0));
}


void CInputSaveLoadDoc::OnUpdateColorRed(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(this->m_selectColor == RGB(255, 0, 0));
}
// --