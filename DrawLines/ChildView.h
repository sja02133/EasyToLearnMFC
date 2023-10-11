
// ChildView.h : interface of the CChildView class
//


#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	CArray<CPoint, POINT&> m_pointArray;


// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

