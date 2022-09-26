#include "UCSplitMerger.h"

UCSplitMerger::UCSplitMerger(UCRelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable)
	: m_roPieceTable(roPieceTable)
{
}

NODE_PTR UCSplitMerger::SplitAfter(USCharPosition& roCharPos)
{
	USPieceTableEntry& oSelectedPte = m_roPieceTable.GetAt(roCharPos.m_pnNode);
	USPieceTableEntry oSecondSplitPartPte;
	NODE_PTR pnResult = nullptr;

	if (roCharPos.m_uiCharOffset == 0 || roCharPos.m_uiCharOffset == oSelectedPte.m_uiLength)
		return roCharPos.m_pnNode;

	unsigned int uiSplitLengthLeft = oSelectedPte.m_uiLength - roCharPos.m_uiCharOffset;
	oSelectedPte.m_uiLength = roCharPos.m_uiCharOffset;

	oSecondSplitPartPte.m_ptszContent = oSelectedPte.m_ptszContent + roCharPos.m_uiCharOffset;
	oSecondSplitPartPte.m_uiLength = uiSplitLengthLeft;
	oSecondSplitPartPte.m_poFontInfo = oSelectedPte.m_poFontInfo;
	pnResult = m_roPieceTable.InsertAfter(roCharPos.m_pnNode, oSecondSplitPartPte);

	return pnResult;
}
