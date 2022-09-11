
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
	ON_CBN_SELCHANGE(55555, &CFormattedTextEditorView::OnFontCommand)
	ON_WM_CREATE()
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

int CFormattedTextEditorView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	RECT r = { 20, 20, 200, 100 };
	m_fcb.Create(CBS_DROPDOWNLIST | WS_VISIBLE | WS_VSCROLL, r, this, 55555);

	return 0;
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

void CFormattedTextEditorView::OnFontCommand()
{
	CMFCFontInfo* fontInfo = m_fcb.GetSelFont();
	CString name = fontInfo->m_strName;
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
