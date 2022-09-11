#pragma once
#include "USFontInfo.h"

class UCSFontInfoManager
{
	private:
		static CList<USFontInfo, USFontInfo&> m_oFontInfoList;

	public:
		static USFontInfo* CreateFontInfo(CString& poStrName, unsigned int uiSize);
};

