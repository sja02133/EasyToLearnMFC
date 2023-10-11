#pragma once

#include <afxtempl.h>

// CMyWnd frame

class CMyWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMyWnd)
protected:
	CMyWnd();           // protected constructor used by dynamic creation
	virtual ~CMyWnd();

protected:
	DECLARE_MESSAGE_MAP()


protected:
	CArray<TCHAR, TCHAR> m_str;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
	afx_msg void OnOptionUp();

public:
	HWND topNoTop = HWND_NOTOPMOST;
	BOOL check_menu = FALSE;
	afx_msg void OnUpdateOptionUp(CCmdUI* pCmdUI);
	afx_msg void OnSave();
};


