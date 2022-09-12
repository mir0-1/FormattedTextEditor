#include "UCSFontInfoManager.h"
#include "user_typedefs.h"

CList<USFontInfo, USFontInfo&> UCSFontInfoManager::m_oFontInfoList;

USFontInfo* UCSFontInfoManager::SetFontInfo(TCHAR* ptszStrName, unsigned int uiSize)
{
	USFontInfo oTemp(ptszStrName, uiSize);
	NODE_PTR pnFindResult = m_oFontInfoList.Find(oTemp, m_oFontInfoList.GetHeadPosition());

	if (pnFindResult == nullptr)
		pnFindResult = m_oFontInfoList.AddHead(oTemp);

	return &m_oFontInfoList.GetAt(pnFindResult);
}
