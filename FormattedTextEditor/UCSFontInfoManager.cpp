#include "UCSFontInfoManager.h"
#include "user_typedefs.h"

CList<USFontInfo, USFontInfo&> UCSFontInfoManager::m_oFontInfoList;

USFontInfo* UCSFontInfoManager::CreateFontInfo(CString& poStrName, unsigned int uiSize)
{
	USFontInfo oTemp(poStrName, uiSize);
	NODE_PTR pnFindResult = m_oFontInfoList.Find(oTemp, m_oFontInfoList.GetHeadPosition());

	if (pnFindResult == nullptr)
		m_oFontInfoList.AddHead(oTemp);

	return &m_oFontInfoList.GetAt(pnFindResult);
}
