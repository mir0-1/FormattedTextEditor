#include "UCDataVisualiser.h"
#include "UCSFontInfoManager.h"

UCDataVisualiser::UCDataVisualiser(UCPieceTable& roPieceTable, CDC* poDc, UCNonNullList<USLineEntry, USLineEntry&>& roLines)
	: m_roPieceTable(roPieceTable),
	m_roLines(roLines)
{
	m_poDc = poDc;
}

void UCDataVisualiser::DisplayLine(LONG x, LONG y, NODE_PTR pnLineToDisplay)
{
	if (pnLineToDisplay == nullptr)
		return;

	USPieceTableEntry* poPte = nullptr;
	USLineEntry& roLineToDisplay = m_roLines.UCRelinkList::GetNext(pnLineToDisplay);
	NODE_PTR pnIterator = roLineToDisplay.m_oCharPos.m_pnNode;
	NODE_PTR pnNextIterator = pnIterator;
	NODE_PTR pnNextLine = pnLineToDisplay;
	USLineEntry* poNextLine = &m_roLines.GetAt(pnNextLine);
	bool bExitLoop = false;
	unsigned int uiLengthToDisplay;
	CSize oTextExtent;

	while (pnIterator != nullptr && !bExitLoop)
	{
		poPte = &m_roPieceTable.GetNext(pnNextIterator);

		if (pnNextLine != nullptr && pnIterator == poNextLine->m_oCharPos.m_pnNode)
		{
			uiLengthToDisplay = poNextLine->m_oCharPos.m_uiCharOffset;
			bExitLoop = true;
		}
		else
			uiLengthToDisplay = poPte->m_uiLength;

		HFONT hDisplayFont = UCSFontInfoManager::ToHFont(poPte->m_poFontInfo, m_poDc);
		HFONT hPrev = (HFONT)m_poDc->SelectObject(hDisplayFont);

		m_poDc->TextOutW(x, y, poPte->m_ptszContent, uiLengthToDisplay);
		oTextExtent = m_poDc->GetTextExtent(poPte->m_ptszContent, uiLengthToDisplay);
		x += oTextExtent.cx;

		m_poDc->SelectObject(hPrev);
		pnIterator = pnNextIterator;
	}
	
}
