
// TCPServer2View.h : interface of the CTCPServer2View class
//

#pragma once


class CTCPServer2View : public CEditView
{
protected: // create from serialization only
	CTCPServer2View() noexcept;
	DECLARE_DYNCREATE(CTCPServer2View)

// Attributes
public:
	CTCPServer2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTCPServer2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void AddMessage(LPCTSTR message);
};

#ifndef _DEBUG  // debug version in TCPServer2View.cpp
inline CTCPServer2Doc* CTCPServer2View::GetDocument() const
   { return reinterpret_cast<CTCPServer2Doc*>(m_pDocument); }
#endif

