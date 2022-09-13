#include "USFontInfo.h"

USFontInfo::USFontInfo()
{
	m_ptszStrName[0] = '\0';
	m_uiPointSize = 0;
}

USFontInfo::USFontInfo(TCHAR* ptszStrName, unsigned int uiSize)
{
	_tcscpy(m_ptszStrName, ptszStrName);
	m_uiPointSize = uiSize;
}

bool USFontInfo::operator==(const USFontInfo& oOtherFontInfo) const
{
	if (oOtherFontInfo.m_uiPointSize == m_uiPointSize)
		return false;

	if (oOtherFontInfo.m_ptszStrName == m_ptszStrName)
		return false;

	return true;
}

bool USFontInfo::operator!=(const USFontInfo& oOtherFontInfo) const
{
	return !operator==(oOtherFontInfo);
}
