#include "UCLineManager.h"
#include "USCharPosition.h"
#include "UCSFontInfoManager.h"
#include "UCGrowableArray.h"


UCLineManager::UCLineManager(UCPieceTable& roPieceTable, unsigned int uiMaxLineLength, CDC *poDC)
	: m_roPieceTable(roPieceTable),
	m_oDefaultPosition(m_roPieceTable.GetHeadPosition(), 0),
	m_oDefaultLine(m_oDefaultPosition, 0, false),
	m_oLines(m_oDefaultLine)
{
	m_uiMaxLineWidth = uiMaxLineLength;
	m_poDC = poDC;
}

void UCLineManager::RecalcLines(NODE_PTR pnStartLine, NODE_PTR pnEndLine)
{
	NODE_PTR pnLineCurrent = pnStartLine, pnPteCurrent, pnPtePrev;
	USCharPosition oLineBreakChar;
	unsigned int uiAppendedLength = 0, uiPrevAppendedLength;
	int iLineBreakLength = -1, iPrevLineBreakLength = -1;
	bool bLineWidthLimitReached = false;
	bool bStartFromTail = true;

	do
	{
		USLineEntry& oCurrentLine = m_oLines.GetNext(pnLineCurrent, bStartFromTail);

		pnPteCurrent = oCurrentLine.m_oCharPos.m_pnNode;
		uiAppendedLength = oCurrentLine.m_oCharPos.m_uiCharOffset;

		while (pnPteCurrent != nullptr)
		{
			pnPtePrev = pnPteCurrent;
			const USPieceTableEntry& oCurrentPte = m_roPieceTable.GetNext(pnPteCurrent);

			HFONT hFont = UCSFontInfoManager::ToHFont(oCurrentPte.m_poFontInfo, m_poDC);
			HFONT hPrevFont = (HFONT)m_poDC->SelectObject(hFont);

			m_oLineAsString.SetAppendSource(oCurrentPte.m_ptszContent + uiAppendedLength);
			while (uiAppendedLength < oCurrentPte.m_uiLength)
			{
				uiAppendedLength += m_oLineAsString.AppendUntilSpace(min(m_uiMaxLineWidth, oCurrentPte.m_uiLength - uiAppendedLength));
				iPrevLineBreakLength = iLineBreakLength;
				iLineBreakLength = GetLineBreakStrLen();

				if (oCurrentPte.m_poFontInfo != nullptr && oCurrentLine.m_uiMaxTmHeight < oCurrentPte.m_poFontInfo->m_lHeight)
					oCurrentLine.m_uiMaxTmHeight = oCurrentPte.m_poFontInfo->m_lHeight;

				if (iPrevLineBreakLength == iLineBreakLength)
				{
					bLineWidthLimitReached = true;
					break;
				}
			}

			if (bLineWidthLimitReached == true)
			{
				bLineWidthLimitReached = false;

				USCharPosition oBreakLinePos;

				m_roPieceTable.GetRelativeCharPos(&oCurrentLine.m_oCharPos, &oBreakLinePos, uiAppendedLength);
				USLineEntry& oNextLine = m_oLines.GetNext(pnLineCurrent, bStartFromTail);
				oNextLine.m_oCharPos.m_pnNode = oBreakLinePos.m_pnNode;
				oNextLine.m_oCharPos.m_uiCharOffset = oBreakLinePos.m_uiCharOffset;

				m_oLineAsString.Clear();
			}

			m_poDC->SelectObject(hPrevFont);
		}
	} while (pnPteCurrent != nullptr);
}

int UCLineManager::GetLineBreakStrLen()
{
	static GCP_RESULTS oGcpResults;

	m_oLineWidthsArray.SetUsedLength(m_oLineAsString.GetUsedLength());
	oGcpResults.nGlyphs = m_oLineWidthsArray.GetTotalLength();
	oGcpResults.lpDx = m_oLineWidthsArray.GetBaseAddress();
	oGcpResults.nMaxFit = 0;

	GetCharacterPlacement(m_poDC->GetSafeHdc(), m_oLineAsString.GetBaseAddress(), m_oLineAsString.GetUsedLength(), m_uiMaxLineWidth, &oGcpResults, GCP_LIGATE | GCP_MAXEXTENT | GCP_GLYPHSHAPE);

	return oGcpResults.nMaxFit;
}