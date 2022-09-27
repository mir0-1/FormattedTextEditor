#include "UCFormatter.h"
#include "UCSFontInfoManager.h"

UCFormatter::UCFormatter(UCSplitMerger& roSplitMerger)
	: m_roSplitMerger(roSplitMerger)
{
}

void UCFormatter::SetFont(const USCharPosition& roStart, const USCharPosition& roEnd, TCHAR* ptszStrFontName, unsigned int uiFontSize)
{
	if (roStart.m_pnNode == nullptr || roEnd.m_pnNode == nullptr)
		return;

	USFontInfo* poTargetFont = UCSFontInfoManager::CreateFontInfo(ptszStrFontName, uiFontSize);
	USPieceTableEntry& roStartEntry = m_roSplitMerger.m_roPieceTable.GetAt(roStart.m_pnNode);
	USPieceTableEntry& roEndEntry = m_roSplitMerger.m_roPieceTable.GetAt(roEnd.m_pnNode);
	USPieceTableEntry* poCurrentEntry = nullptr;
	NODE_PTR pnIterator = roStart.m_pnNode;
	NODE_PTR pnNextIterator;
	bool bExitLoop = false;

	if (roStart.m_pnNode == roEnd.m_pnNode)
	{
		if (roEndEntry.m_ptszContent && (roEndEntry.m_poFontInfo != poTargetFont))
		{
			m_roSplitMerger.SplitAfter(roEnd);
			pnIterator = m_roSplitMerger.SplitAfter(roStart);
			poCurrentEntry = &m_roSplitMerger.m_roPieceTable.GetAt(pnIterator);
			poCurrentEntry->m_poFontInfo = poTargetFont;
		}

		return;
	}

	if (roStartEntry.m_ptszContent && (roStartEntry.m_poFontInfo != poTargetFont))
		pnIterator = m_roSplitMerger.SplitAfter(roStart);

	pnNextIterator = pnIterator;
	while (pnIterator != nullptr && !bExitLoop)
	{
		poCurrentEntry = &m_roSplitMerger.m_roPieceTable.GetNext(pnNextIterator);

		if (pnIterator == roEnd.m_pnNode)
		{
			m_roSplitMerger.SplitAfter(roEnd);
			bExitLoop = true;
		}

		if (poCurrentEntry->m_ptszContent && (poCurrentEntry->m_poFontInfo != poTargetFont))
			poCurrentEntry->m_poFontInfo = poTargetFont;

		pnIterator = pnNextIterator;
	}
}
