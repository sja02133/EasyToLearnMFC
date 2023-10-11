
// OLEDB2View.h : COLEDB2View Ŭ������ �������̽�
//

#pragma once

class COLEDB2Set;

class COLEDB2View : public COleDBRecordView
{
protected: // serialization������ ��������ϴ�.
	COLEDB2View();
	DECLARE_DYNCREATE(COLEDB2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_OLEDB2_FORM };
#endif
	COLEDB2Set* m_pSet;

// Ư���Դϴ�.
public:
	COLEDB2Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual CRowset<>* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~COLEDB2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // OLEDB2View.cpp�� ����� ����
inline COLEDB2Doc* COLEDB2View::GetDocument() const
   { return reinterpret_cast<COLEDB2Doc*>(m_pDocument); }
#endif

