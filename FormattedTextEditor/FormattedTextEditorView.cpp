
// FormattedTextEditorView.cpp : implementation of the CFormattedTextEditorView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FormattedTextEditor.h"
#endif

#include "FormattedTextEditorDoc.h"
#include "FormattedTextEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFormattedTextEditorView

IMPLEMENT_DYNCREATE(CFormattedTextEditorView, CView)

BEGIN_MESSAGE_MAP(CFormattedTextEditorView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFormattedTextEditorView construction/destruction

CFormattedTextEditorView::CFormattedTextEditorView() noexcept
{
	// TODO: add construction code here

}

CFormattedTextEditorView::~CFormattedTextEditorView()
{
}

BOOL CFormattedTextEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFormattedTextEditorView drawing

void CFormattedTextEditorView::OnDraw(CDC* /*pDC*/)
{
	CFormattedTextEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFormattedTextEditorView printing

BOOL CFormattedTextEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFormattedTextEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFormattedTextEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFormattedTextEditorView diagnostics

#ifdef _DEBUG
void CFormattedTextEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CFormattedTextEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFormattedTextEditorDoc* CFormattedTextEditorView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormattedTextEditorDoc)));
	return (CFormattedTextEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CFormattedTextEditorView message handlers
