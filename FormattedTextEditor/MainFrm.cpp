
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "FormattedTextEditor.h"

#include "MainFrm.h"
#include "UCTextEditorDataManager.h"
#include "USPieceTableEntry.h"

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

class UCDebugNode // only used for "Add watch" in debugger. Remove later.
{
	UCDebugNode* pPrev;
	UCDebugNode* pNext;
	USPieceTableEntry data;
};

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

	UCTextEditorDataManager ptm(this->GetDC());
	TCHAR tsz[256];

	//ptm.add(tsz, uiLen1);

	_tcscpy(tsz, TEXT("This is a very very , I made it so with hopes that word wrap "));
	ptm.m_oPieceTable.Add(tsz, _tcslen(tsz));
	ptm.m_oPieceTable.SelectCharPosByCharCount(20);
	_tcscpy(tsz, TEXT("long line of text"));
	ptm.m_oPieceTable.Add(tsz, _tcslen(tsz));
	ptm.m_oPieceTable.SelectCharPosByCharCount(112);
	_tcscpy(tsz, TEXT("will correctly work. Vecherai Rado."));
	ptm.m_oPieceTable.Add(tsz, _tcslen(tsz));

	UCDebugNode test; // only used for "Add watch" in debugger. Remove later.
	USCharPosition oStart, oEnd;
	ptm.m_oPieceTable.GetAbsoluteCharPos(&oStart, 0);
	ptm.m_oPieceTable.GetAbsoluteCharPos(&oEnd, INT_MAX);
	ptm.m_oPieceTable.SetFont(oStart, oEnd, TEXT("Tahoma"), 13);
	//ptm.SelectPosByCharCount(10);
	//ptm.Add(TEXT("example"), 8);
	ptm.m_oLineManager.RecalcLines(nullptr, nullptr);

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

