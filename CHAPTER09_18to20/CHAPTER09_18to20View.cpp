
// CHAPTER09_18to20View.cpp : implementation of the CCHAPTER0918to20View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CHAPTER09_18to20.h"
#endif

#include "CHAPTER09_18to20Doc.h"
#include "CHAPTER09_18to20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCHAPTER0918to20View

// 연습 문제 18, 19, 20
// CFindReplaceDialog 를 사용시에 무조건 해야하는 절차 중 하나다.
static UINT WM_FINDDREPLACE = ::RegisterWindowMessage(FINDMSGSTRING);
// --



IMPLEMENT_DYNCREATE(CCHAPTER0918to20View, CEditView)

BEGIN_MESSAGE_MAP(CCHAPTER0918to20View, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_FIND, &CCHAPTER0918to20View::OnEditFind)
	ON_UPDATE_COMMAND_UI(ID_EDIT_FIND, &CCHAPTER0918to20View::OnUpdateEditFind)
	ON_COMMAND(ID_EDIT_REPEAT, &CCHAPTER0918to20View::OnEditRepeat)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REPEAT, &CCHAPTER0918to20View::OnUpdateEditRepeat)
	ON_COMMAND(ID_EDIT_REPLACE, &CCHAPTER0918to20View::OnEditReplace)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REPLACE, &CCHAPTER0918to20View::OnUpdateEditReplace)
	ON_REGISTERED_MESSAGE(WM_FINDDREPLACE,OnFindReplaceCmd)		// 무조건 필요.
	ON_COMMAND(ID_FORMAT_FONT, &CCHAPTER0918to20View::OnFormatFont)
	ON_WM_CTLCOLOR()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()

// CCHAPTER0918to20View construction/destruction

CCHAPTER0918to20View::CCHAPTER0918to20View() noexcept
{
	// TODO: add construction code here
	dlg = NULL;
}

CCHAPTER0918to20View::~CCHAPTER0918to20View()
{
}

BOOL CCHAPTER0918to20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CCHAPTER0918to20View printing

BOOL CCHAPTER0918to20View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CCHAPTER0918to20View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CCHAPTER0918to20View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CCHAPTER0918to20View diagnostics

#ifdef _DEBUG
void CCHAPTER0918to20View::AssertValid() const
{
	CEditView::AssertValid();
}

void CCHAPTER0918to20View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CCHAPTER0918to20Doc* CCHAPTER0918to20View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHAPTER0918to20Doc)));
	return (CCHAPTER0918to20Doc*)m_pDocument;
}
#endif //_DEBUG


// CCHAPTER0918to20View message handlers


void CCHAPTER0918to20View::OnEditFind()
{
	// TODO: Add your command handler code here
	dlg = new CFindReplaceDialog();
	dlg->Create(TRUE, _T(""), _T(""), FR_DOWN, this);
}


void CCHAPTER0918to20View::OnUpdateEditFind(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	
}


void CCHAPTER0918to20View::OnEditRepeat()
{
	// TODO: Add your command handler code here
}


void CCHAPTER0918to20View::OnUpdateEditRepeat(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	dlg = new CFindReplaceDialog();
	dlg->Create(FALSE, _T(""), _T(""), FR_DOWN, this);
}


void CCHAPTER0918to20View::OnEditReplace()
{
	// TODO: Add your command handler code here
	dlg = new CFindReplaceDialog();
	dlg->Create(FALSE, _T(""), _T(""), FR_DOWN, this);
}


void CCHAPTER0918to20View::OnUpdateEditReplace(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
}


//BOOL CCHAPTER0918to20View::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	return CEditView::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
//}

// 연습 문제 18
LRESULT CCHAPTER0918to20View::OnFindReplaceCmd(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your implementation code here.

	CString str;

	if (dlg->IsTerminating()) {
		dlg = NULL;
		return 0;
	}
	else if (dlg->FindNext()) {
		CString viewStr = _T("");
		GetWindowText(viewStr);
		if (this->m_rememberBeforePos != 0) {
			viewStr = viewStr.Mid(this->m_rememberBeforePos, viewStr.GetLength());
		}
		this->m_rememberStr = dlg->GetFindString();
		int pos = viewStr.Find(this->m_rememberStr);

		if (pos == 0 && this->m_rememberBeforePos == 0)
			this->m_rememberBeforePos += this->m_rememberStr.GetLength();
		else if (pos != -1) {
			pos += this->m_rememberBeforePos;
			this->m_rememberBeforePos += pos;
		}

		if (!this->m_rememberStr.IsEmpty()) {
			if (pos == -1)
				str = _T("\"") + viewStr + _T("\"를 찾을 수 없습니다.");
			else {
				CEdit* edit = &this->GetEditCtrl();
				edit->SetSel(pos, pos + this->m_rememberStr.GetLength());
			}
		}
	}
	else if (dlg->ReplaceCurrent()) {
		CString viewStr = _T("");
		GetWindowText(viewStr);
		if (this->m_rememberBeforePos != 0) {
			viewStr = viewStr.Mid(this->m_rememberBeforePos, viewStr.GetLength());
		}
		this->m_rememberStr = dlg->GetFindString();
		int pos = viewStr.Find(this->m_rememberStr);

		if (pos == 0 && this->m_rememberBeforePos == 0)
			this->m_rememberBeforePos += this->m_rememberStr.GetLength();
		else if (pos != -1) {
			pos += this->m_rememberBeforePos;
			this->m_rememberBeforePos += pos;
		}

		if (!this->m_rememberStr.IsEmpty()) {
			if (pos == -1)
				str = _T("\"") + viewStr + _T("\"를 찾을 수 없습니다.");
			else {
				CString str1, str2;
				str1 = viewStr.Mid(0, this->m_rememberBeforePos);
				str2 = viewStr.Mid(this->m_rememberBeforePos + this->m_rememberStr.GetLength(), viewStr.GetLength());
				viewStr = str1 + str2;
				SetWindowText(viewStr);
			}
		}
	}

	return LRESULT();
}
// --

// 연습 문제 19
void CCHAPTER0918to20View::OnFormatFont()
{
	// TODO: Add your command handler code here

	//memset(&this->m_saveLF, 0, sizeof(LOGFONT));
	CClientDC dc(this);
	
	CFont* font = GetFont();
	font->GetLogFont(&this->m_saveLF);

	CFontDialog dlg(&this->m_saveLF);
	if (dlg.DoModal() == IDOK)
	{
		dlg.GetCurrentFont(&this->m_saveLF);
		CFont tempFont;
		tempFont.CreateFontIndirectW(&this->m_saveLF);
		this->m_fontColor = dlg.GetColor();
		this->m_rem_font.DeleteObject();
		this->m_rem_font.CreateFontIndirectW(&this->m_saveLF);
		this->check_changeColor = TRUE;
		SetFont(&tempFont, TRUE);
	}
}
// --

void CCHAPTER0918to20View::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class
}


HBRUSH CCHAPTER0918to20View::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CEditView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}


HBRUSH CCHAPTER0918to20View::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  Change any attributes of the DC here

	// TODO:  Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}


void CCHAPTER0918to20View::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		CString str;
		GetWindowText(str);

		LOGFONT lf;
		this->m_rem_font.GetLogFont(&lf);

		CString fontStr;
		fontStr.Format(_T("%d||"), lf.lfHeight);
		fontStr += lf.lfFaceName;

		ar << str << fontStr;
	}
	else
	{	// loading code
		
		CString str;
		LOGFONT lf;

		CString fontStr;

		CFont* pFont = GetFont();
		pFont->GetLogFont(&lf);


		ar >> str >> fontStr;

		int pos = fontStr.Find(_T("||"));
		CString size = fontStr.Mid(0, pos);
		lf.lfHeight = _ttoi(size);
		CString facename = fontStr.Mid(pos + 2, fontStr.GetLength());
		memcpy(lf.lfFaceName, facename.GetBuffer(), facename.GetLength());

		CFont font;
		font.CreateFontIndirectW(&lf);

		SetWindowText(str);
		SetFont(&font, TRUE);
	}
}
