#include "UCLineManager.h"
#include "USCharPosition.h"

UCLineManager::UCLineManager(UCROList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable, unsigned int uiMaxRowLength)
	: m_roPieceTable(roPieceTable)
{
	m_uiMaxLineWidth = uiMaxRowLength;
}

void UCLineManager::RecalcLines(NODE_PTR pnStartLine, NODE_PTR pnEndLine)
{
	NODE_PTR pnLineIterator = pnStartLine, pnPteIterator;
	unsigned int uiAccumulatedWidth, i;

	while (pnLineIterator != pnEndLine)
	{
		uiAccumulatedWidth = 0;

		USLineEntry& oCurrentLine = m_oLines.GetNext(pnLineIterator);
		pnPteIterator = oCurrentLine.m_oCharPos.m_pnCurrentNode;
		i = oCurrentLine.m_oCharPos.m_uiCharOffset;

		if (pnPteIterator != nullptr)
		{
			const USPieceTableEntry& oCurrentPte = m_roPieceTable.GetNext(pnPteIterator);
			for (;i < oCurrentPte.uiLength; i++)
			{
				uiAccumulatedWidth++;

			}
		}
	}
}