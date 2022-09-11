#include "UCLineManager.h"
#include "USCharPosition.h"

UCLineManager::UCLineManager(CList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable, unsigned int uiMaxRowLength)
	: m_oPieceTable(roPieceTable),
	m_oDefaultPosition(m_oPieceTable.GetHeadPosition(), 0),
	m_oDefaultLine(m_oDefaultPosition, 0, false),
	m_oLines(m_oDefaultLine)
{
	m_uiMaxLineWidth = uiMaxRowLength;
}

void UCLineManager::RecalcLines(NODE_PTR pnStartLine, NODE_PTR pnEndLine)
{
	NODE_PTR pnLineCurrent = pnStartLine, pnPteCurrent, pnPtePrev;
	unsigned int uiAccumulatedWidth, i;
	USCharPosition oLastSpacePos;

	do
	{
		uiAccumulatedWidth = 0;

		USLineEntry& oCurrentLine = m_oLines.GetNext(pnLineCurrent);
		pnPteCurrent = oCurrentLine.m_oCharPos.m_pnCurrentNode;
		i = oCurrentLine.m_oCharPos.m_uiCharOffset;

		while (pnPteCurrent != nullptr)
		{
			pnPtePrev = pnPteCurrent;
			const USPieceTableEntry& oCurrentPte = m_oPieceTable.GetNext(pnPteCurrent);
			for (;oCurrentPte.m_pszContent && i < oCurrentPte.m_uiLength; i++)
			{
				uiAccumulatedWidth++;

				if (oCurrentPte.m_pszContent[i] == ' ')
				{
					oLastSpacePos.m_pnCurrentNode = pnPtePrev;
					oLastSpacePos.m_uiCharOffset = i;
				}

				if (uiAccumulatedWidth == m_uiMaxLineWidth)
				{
					USLineEntry& oNextLine = m_oLines.GetNext(pnLineCurrent);
					oNextLine.m_oCharPos.m_pnCurrentNode = oLastSpacePos.m_pnCurrentNode;
					oNextLine.m_oCharPos.m_uiCharOffset = oLastSpacePos.m_uiCharOffset;
					uiAccumulatedWidth = 0;
				}
			}
		}
	} while (pnPteCurrent != nullptr);
}