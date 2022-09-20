
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
#include "UCTextEditorDataManager.h"

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

	//ptm.add(tsz, uiLen1);

	return 0;
}

// CFormattedTextEditorView drawing

void CFormattedTextEditorView::OnDraw(CDC* poDc)
{
	CFormattedTextEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	TCHAR tsz[256];
	UCTextEditorDataManager ptm(poDc);

	_tcscpy(tsz, TEXT("This is a very very , I made it so with hopes that word wrap "));
	ptm.m_oPieceTable.Add(tsz, _tcslen(tsz));
	ptm.m_oPieceTable.SelectCharPosByCharCount(20);
	_tcscpy(tsz, TEXT("long line of text"));
	ptm.m_oPieceTable.Add(tsz, _tcslen(tsz));
	ptm.m_oPieceTable.SelectCharPosByCharCount(112);
	_tcscpy(tsz, TEXT("will correctly work. Vecherai Rado."));
	ptm.m_oPieceTable.Add(tsz, _tcslen(tsz));

	//UCDebugNode test; // only used for "Add watch" in debugger. Remove later.
	USCharPosition oStart, oEnd;
	ptm.m_oPieceTable.GetAbsoluteCharPos(&oStart, 0);
	ptm.m_oPieceTable.GetAbsoluteCharPos(&oEnd, INT_MAX);
	ptm.m_oPieceTable.SetFont(oStart, oEnd, TEXT("Tahoma"), 13);
	//ptm.SelectPosByCharCount(10);
	//ptm.Add(TEXT("example"), 8);

	ptm.m_oPieceTable.GetAbsoluteCharPos(&oStart, 3);
	ptm.m_oPieceTable.GetAbsoluteCharPos(&oEnd, 8);
	ptm.m_oPieceTable.SetFont(oStart, oEnd, TEXT("Tahoma"), 18);
	ptm.m_oLineManager.RecalcLines(nullptr, nullptr);

	NODE_PTR line = ptm.m_oLineManager.GetLineList().FindIndex(1);
	poDc->SetBkMode(TRANSPARENT);
	ptm.m_oDataVisualiser.DisplayLine(100, 100, line);

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
