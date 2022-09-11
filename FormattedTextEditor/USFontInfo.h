#pragma once
#include <afxstr.h>
class USFontInfo
{
	public:
		USFontInfo(CString& poStrName, unsigned int uiSize);
		bool operator==(USFontInfo& oFontInfoOther);

	private:
		CString m_poStrName;
		unsigned int m_uiSize;
};