#include "UCPieceTableSplitMerger.h"

NODE_PTR UCPieceTableSplitMerger::SplitAt(USCharPosition& roCharPos)
{
	USPieceTableEntry& oSelectedPte = m_oPieceTable.GetAt(roCharPos.m_pnNode);
	USPieceTableEntry oSecondSplitPartPte;
	NODE_PTR pnResult = nullptr;

	if (roCharPos.m_uiCharOffset == 0 || roCharPos.m_uiCharOffset == oSelectedPte.m_uiLength)
		return roCharPos.m_pnNode;

	unsigned int uiSplitLengthLeft = oSelectedPte.m_uiLength - roCharPos.m_uiCharOffset;
	oSelectedPte.m_uiLength = roCharPos.m_uiCharOffset;

	oSecondSplitPartPte.m_ptszContent = oSelectedPte.m_ptszContent + roCharPos.m_uiCharOffset;
	oSecondSplitPartPte.m_uiLength = uiSplitLengthLeft;
	pnResult = m_oPieceTable.InsertAfter(roCharPos.m_pnNode, oSecondSplitPartPte);

	return pnResult;
}