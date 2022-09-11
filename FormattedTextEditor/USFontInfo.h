#pragma once
#include <afxtempl.h>
class USFontInfo
{
	public:
		USFontInfo();
		USFontInfo(CString& poStrName, unsigned int uiSize);
		bool operator==(const USFontInfo& oOtherFontInfo) const;

	private:
		CString m_poStrName;
		unsigned int m_uiSize;
};