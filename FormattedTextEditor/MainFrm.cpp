
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "FormattedTextEditor.h"

#include "MainFrm.h"
#include "UCPieceTableManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{

}

CMainFrame::~CMainFrame()
{

}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	UCPieceTableManager ptm;

	TCHAR tsz[256] = TEXT("This is");
	unsigned int uiLen1 = _tcslen(tsz);
	unsigned int uiLen2;
	unsigned int uiLen3;
	unsigned int uiLen4;
	unsigned int uiLen5;
	unsigned int uiLen6;
	unsigned int uiLen7;
	unsigned int uiLen8;

	ptm.selectPos(nullptr, 0);
	//ptm.add(tsz, uiLen1);

	_tcscpy(tsz, TEXT("This is a very very long line of text, I made it so with hopes that word wrap will correctly work. Vecherai Rado."));
	uiLen2 = _tcslen(tsz);
	ptm.add(tsz, uiLen2);
	ptm.selectPosByCharCount(10);
	ptm.add(TEXT("example"), 8);

	//UCNonEmptyList<int, int> list;

	//list.AddHead(5);

	//ptm.m_oLineManager.RecalcLines(nullptr, nullptr);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_TILEDWINDOW | FWS_ADDTOTITLE;

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

