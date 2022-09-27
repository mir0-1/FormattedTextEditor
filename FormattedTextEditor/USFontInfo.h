#pragma once
#include <afxtempl.h>
class USFontInfo
{
	public:
		USFontInfo();
		USFontInfo(TCHAR* ptszStrName, long lHeight);

		TCHAR m_ptszStrName[32];
		long m_lHeight;

		bool operator==(const USFontInfo& oOtherFontInfo) const;
		bool operator!=(const USFontInfo& oOtherFontInfo) const;

		friend class UCSFontInfoManager;
};