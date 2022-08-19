#include "UCLineManager.h"
#include "USTextPosition.h"

UCLineManager::UCLineManager(UCRORelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable, unsigned int uiMaxRowLength)
	: m_roPieceTable(roPieceTable)
{
}

void UCLineManager::RecalcLines(NODE_PTR pnStartLine, NODE_PTR pnEndLine)
{
	NODE_PTR pnCurrentPte;
	USPieceTableEntry oCurrentPte;
	USCharPosition oSpacePos;
	unsigned int i;
	unsigned int uiAccumulatedWidth;

	if (m_oLines.GetCount() == 0)
	{
		pnCurrentPte = m_roPieceTable.GetHeadPosition();
		uiAccumulatedWidth = 0;

		while (pnCurrentPte != nullptr)
		{
			oCurrentPte = m_roPieceTable.GetNext(pnCurrentPte);
			for (i = 0; i < oCurrentPte.uiLength; i++)
			{
				uiAccumulatedWidth++;


			}
		}
	}
}