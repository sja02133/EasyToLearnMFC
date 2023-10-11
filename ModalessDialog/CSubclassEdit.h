#pragma once


// CSubclassEdit

class CSubclassEdit : public CEdit
{
	DECLARE_DYNAMIC(CSubclassEdit)

public:
	CSubclassEdit();
	virtual ~CSubclassEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
};


