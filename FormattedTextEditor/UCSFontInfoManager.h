#pragma once
#include <afxtempl.h>
#include "USFontInfo.h"

class UCSFontInfoManager
{
	private:
		static CList<USFontInfo, USFontInfo&> m_oFontInfoList;

		UCSFontInfoManager();

	public:
		static USFontInfo* CreateFontInfo(CString& poStrName, unsigned int uiSize);
};

