#pragma once
#include "USFontInfo.h"
#include <afxwin.h>

class UCSFontInfoManager
{
	private:
		static CList<USFontInfo, USFontInfo&> m_oFontInfoList;

	public:
		static USFontInfo* CreateFontInfo(TCHAR* ptszStrName, long lHeight);
		static HFONT ConvertToHFont(USFontInfo* poFontInfo, CDC* poDc);
};

