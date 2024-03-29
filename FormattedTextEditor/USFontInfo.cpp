#include "USFontInfo.h"

USFontInfo::USFontInfo()
{
	m_ptszStrName[0] = '\0';
	m_lHeight = 0;
}

USFontInfo::USFontInfo(TCHAR* ptszStrName, long lHeight)
{
	_tcscpy(m_ptszStrName, ptszStrName);
	m_lHeight = lHeight;
}

bool USFontInfo::operator==(const USFontInfo& oOtherFontInfo) const
{
	if (oOtherFontInfo.m_lHeight == m_lHeight)
		return false;

	if (oOtherFontInfo.m_ptszStrName == m_ptszStrName)
		return false;

	return true;
}

bool USFontInfo::operator!=(const USFontInfo& oOtherFontInfo) const
{
	return !operator==(oOtherFontInfo);
}
