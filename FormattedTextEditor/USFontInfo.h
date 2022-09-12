#pragma once
#include <afxtempl.h>
class USFontInfo
{
	public:
		USFontInfo();
		USFontInfo(TCHAR* ptszStrName, unsigned int uiFontSize);
		bool operator==(const USFontInfo& oOtherFontInfo) const;
		bool operator!=(const USFontInfo& oOtherFontInfo) const;

	private:
		TCHAR m_ptszStrName[128];
		unsigned int m_uiSize;
};