#include "USFontInfo.h"

USFontInfo::USFontInfo()
{
	m_poStrName = "";
	m_uiSize = 0;
}

USFontInfo::USFontInfo(CString& poStrName, unsigned int uiSize)
{
	m_poStrName = poStrName;
	m_uiSize = uiSize;
}

bool USFontInfo::operator==(const USFontInfo& oFontInfoOther) const
{
	if (oFontInfoOther.m_uiSize != m_uiSize)
		return false;

	if (oFontInfoOther.m_poStrName != m_poStrName)
		return false;

	return true;
}
