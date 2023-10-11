// CWindowList.cpp : implementation file
//

#include "pch.h"
#include "MDITest.h"
#include "CWindowList.h"
#include "afxdialogex.h"


// CWindowList dialog

IMPLEMENT_DYNAMIC(CWindowList, CDialog)

CWindowList::CWindowList(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_WINDOWLIST, pParent)
{
}

CWindowList::~CWindowList()
{
}

void CWindowList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST_WINDOW, m_list);
	DDX_Control(pDX, IDC_LISTBOX_WINDOW, m_list);
}


BEGIN_MESSAGE_MAP(CWindowList, CDialog)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_ACTIVE, &CWindowList::OnBnClickedButtonActive)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CWindowList::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CWindowList::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_CHECK, &CWindowList::OnBnClickedButtonCheck)
	ON_LBN_SELCHANGE(IDC_LISTBOX_WINDOW, &CWindowList::OnLbnSelchangeListboxWindow)
END_MESSAGE_MAP()


// CWindowList message handlers


int CWindowList::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	this->m_selectWindowText = _T("");

	// TODO:  Add your specialized creation code here
	return 0;
}


BOOL CWindowList::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	
	// 연습 문제 16
	POSITION pos = theApp.GetFirstDocTemplatePosition();
	int listCount = 0;
	while (pos) {
		CDocTemplate* pDocTemplate = theApp.GetNextDocTemplate(pos);
		POSITION docPos = pDocTemplate->GetFirstDocPosition();
		while (docPos) {
			CDocument* pDoc = pDocTemplate->GetNextDoc(docPos);
			POSITION viewPos = pDoc->GetFirstViewPosition();
			while (viewPos) {
				CView* pView = pDoc->GetNextView(viewPos);
				CString str = _T("");
				CFrameWnd* pFrame = pView->GetParentFrame();
				pFrame->GetWindowText(str);
				this->m_list.AddString(str);
				listCount++;
			}
		}
	}
	// --

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

CView* CWindowList::FindTargetView(CDocument* pDoc,CString& findStr)
{
	//CView* pView = nullptr;

	POSITION viewPos = pDoc->GetFirstViewPosition();
	while (viewPos) {
		CView* pView = pDoc->GetNextView(viewPos);
		CString str = _T("");
		CFrameWnd* pFrame = pView->GetParentFrame();
		pFrame->GetWindowText(str);
		if (str.Compare(findStr) == 0)
			return pView;
	}
	return nullptr;
}

void CWindowList::OnBnClickedButtonActive()
{
	// TODO: Add your control notification handler code here

	if (!this->m_selectWindowText.IsEmpty()) {
		POSITION pos = theApp.GetFirstDocTemplatePosition();
		int listCount = 0;
		while (pos) {
			CDocTemplate* pDocTemplate = theApp.GetNextDocTemplate(pos);
			POSITION docPos = pDocTemplate->GetFirstDocPosition();
			while (docPos) {
				CDocument* pDoc = pDocTemplate->GetNextDoc(docPos);
				CView* pView = FindTargetView(pDoc, this->m_selectWindowText);
				if (pView != nullptr) {
					CFrameWnd* pFrame = pView->GetParentFrame();
					pFrame->ActivateFrame();
				}
			}
		}
	}
}


void CWindowList::OnBnClickedButtonSave()
{
	// TODO: Add your control notification handler code here
	POSITION pos = theApp.GetFirstDocTemplatePosition();
	int listCount = 0;
	while (pos) {
		CDocTemplate* pDocTemplate = theApp.GetNextDocTemplate(pos);
		POSITION docPos = pDocTemplate->GetFirstDocPosition();
		while (docPos) {
			CDocument* pDoc = pDocTemplate->GetNextDoc(docPos);
			CView* pView = FindTargetView(pDoc, this->m_selectWindowText);
			pDoc->OnSaveDocument(_T("abc"));
		}
	}
}


void CWindowList::OnBnClickedButtonClose()
{
	// TODO: Add your control notification handler code here
	if (!this->m_selectWindowText.IsEmpty()) {
		POSITION pos = theApp.GetFirstDocTemplatePosition();
		int listCount = 0;
		while (pos) {
			CDocTemplate* pDocTemplate = theApp.GetNextDocTemplate(pos);
			POSITION docPos = pDocTemplate->GetFirstDocPosition();
			while (docPos) {
				CDocument* pDoc = pDocTemplate->GetNextDoc(docPos);
				CView* pView = FindTargetView(pDoc, this->m_selectWindowText);
				if (pView != nullptr) {
					CMDIChildWnd* pMDIChild = (CMDIChildWnd*)pView->GetParentFrame();
					pMDIChild->MDIDestroy();
				}
				for (int i = 0; i < this->m_list.GetCount(); i++) {
					CString findStr = _T("");
					this->m_list.GetText(i, findStr);
					if (findStr.Compare(this->m_selectWindowText) == 0)
					{
						this->m_list.DeleteString(i);
						this->m_selectWindowText = _T("");
					}
				}
			}
		}
	}
}


void CWindowList::OnBnClickedButtonCheck()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDC_BUTTON_CHECK);
}


void CWindowList::OnLbnSelchangeListboxWindow()
{
	// TODO: Add your control notification handler code here
	int index = this->m_list.GetCurSel();
	this->m_list.GetText(index, this->m_selectWindowText);
}
