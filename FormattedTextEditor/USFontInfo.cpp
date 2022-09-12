#include "USFontInfo.h"

USFontInfo::USFontInfo()
{
	m_ptszStrName[0] = '\0';
	m_uiSize = 0;
}

USFontInfo::USFontInfo(TCHAR* ptszStrName, unsigned int uiSize)
{
	_tcscpy(m_ptszStrName, ptszStrName);
	m_uiSize = uiSize;
}

bool USFontInfo::operator==(const USFontInfo& oOtherFontInfo) const
{
	if (oOtherFontInfo.m_uiSize == m_uiSize)
		return false;

	if (oOtherFontInfo.m_ptszStrName == m_ptszStrName)
		return false;

	return true;
}

bool USFontInfo::operator!=(const USFontInfo& oOtherFontInfo) const
{
	return !operator==(oOtherFontInfo);
}
