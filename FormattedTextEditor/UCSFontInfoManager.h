#pragma once
#include "USFontInfo.h"
#include <afxwin.h>

class UCSFontInfoManager
{
	private:
		static CList<USFontInfo, USFontInfo&> m_oFontInfoList;

	public:
		static USFontInfo* SetFontInfo(TCHAR* ptszStrName, long lHeight);
		static HFONT ToHFont(USFontInfo* poFontInfo, CDC* poDc);
};

