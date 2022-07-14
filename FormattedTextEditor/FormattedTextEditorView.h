
// FormattedTextEditorView.h : interface of the CFormattedTextEditorView class
//

#pragma once


class CFormattedTextEditorView : public CView
{
protected: // create from serialization only
	CFormattedTextEditorView() noexcept;
	DECLARE_DYNCREATE(CFormattedTextEditorView)

// Attributes
public:
	CFormattedTextEditorDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CFormattedTextEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FormattedTextEditorView.cpp
inline CFormattedTextEditorDoc* CFormattedTextEditorView::GetDocument() const
   { return reinterpret_cast<CFormattedTextEditorDoc*>(m_pDocument); }
#endif

