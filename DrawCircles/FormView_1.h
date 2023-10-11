#pragma once



// FormView_1 form view

class FormView_1 : public CFormView
{
	DECLARE_DYNCREATE(FormView_1)
public:
	enum { IDD = IDD_DIALOG1};
protected:

	FormView_1();           // protected constructor used by dynamic creation
	virtual ~FormView_1();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD =  };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//virtual void OnInitialUpdate();
	int m_button;
};


