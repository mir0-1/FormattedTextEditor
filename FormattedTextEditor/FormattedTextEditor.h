
// FormattedTextEditor.h : main header file for the FormattedTextEditor application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFormattedTextEditorApp:
// See FormattedTextEditor.cpp for the implementation of this class
//

class CFormattedTextEditorApp : public CWinApp
{
public:
	CFormattedTextEditorApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFormattedTextEditorApp theApp;
