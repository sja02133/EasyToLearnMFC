#pragma once


// CKeyInputView view

class CKeyInputView : public CView
{
	DECLARE_DYNCREATE(CKeyInputView)

protected:
	CKeyInputView();           // protected constructor used by dynamic creation
	virtual ~CKeyInputView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

public:
	CList<CString, CString&> m_drawPoints;
};


