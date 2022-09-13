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

HFONT UCSFontInfoManager::ToHFont(USFontInfo* poFontInfo, CDC* poDC)
{
	static LOGFONT oLogfont;
	static HFONT hFont;

	if (poDC)
		return nullptr;

	DeleteObject(hFont);

	oLogfont.lfCharSet = DEFAULT_CHARSET;
	oLogfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	oLogfont.lfEscapement = 0;
	_tcscpy_s(oLogfont.lfFaceName, 32, poFontInfo->m_ptszStrName);
	oLogfont.lfHeight = -MulDiv(poFontInfo->m_uiPointSize, poDC->GetDeviceCaps(LOGPIXELSY), 72);
	oLogfont.lfItalic = 0; // add support
	oLogfont.lfOrientation = 0;
	oLogfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	oLogfont.lfPitchAndFamily = DEFAULT_PITCH;
	oLogfont.lfQuality = DEFAULT_QUALITY;
	oLogfont.lfStrikeOut = 0; // add support
	oLogfont.lfUnderline = 0; // add support
	oLogfont.lfWeight = 0; // this is used for bold; add support
	oLogfont.lfWidth = 0;

	hFont = CreateFontIndirect(&oLogfont);

	return hFont;
}
