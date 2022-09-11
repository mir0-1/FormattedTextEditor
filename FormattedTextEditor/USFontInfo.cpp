#include "USFontInfo.h"

USFontInfo::USFontInfo(TCHAR* pszName, unsigned int uiSize)
{

}

USFontInfo::USFontInfo(CString& poStrName, unsigned int uiSize)
{
}

bool USFontInfo::operator==(USFontInfo& oFontInfoOther)
{
	if (oFontInfoOther.m_uiSize != m_uiSize)
		return false;

	if (oFontInfoOther)

	return true;
}
