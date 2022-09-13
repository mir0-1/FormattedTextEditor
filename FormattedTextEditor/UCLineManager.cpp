#include "UCLineManager.h"
#include "USCharPosition.h"
#include "UCSFontInfoManager.h"
#include "UCGrowableArray.h"


UCLineManager::UCLineManager(CList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable, unsigned int uiMaxLineLength, CDC *poDC)
	: m_oPieceTable(roPieceTable),
	m_oDefaultPosition(m_oPieceTable.GetHeadPosition(), 0),
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
	unsigned int uiAppendedLength = 0;
	int iLineBreakLength = -1, iPrevLineBreakLength = -1;
	bool bLineWidthLimitReached = false;

	do
	{
		USLineEntry& oCurrentLine = m_oLines.GetNext(pnLineCurrent);

		pnPteCurrent = oCurrentLine.m_oCharPos.m_pnNode;
		uiAppendedLength = oCurrentLine.m_oCharPos.m_uiCharOffset;

		while (pnPteCurrent != nullptr)
		{
			pnPtePrev = pnPteCurrent;
			const USPieceTableEntry& oCurrentPte = m_oPieceTable.GetNext(pnPteCurrent);

			HFONT hFont = UCSFontInfoManager::ToHFont(oCurrentPte.m_poFontInfo, m_poDC);
			HFONT hPrevFont = (HFONT)m_poDC->SelectObject(hFont);

			m_oLineAsString.SetAppendSource(oCurrentPte.m_ptszContent + uiAppendedLength);
			while (uiAppendedLength < oCurrentPte.m_uiLength)
			{
				uiAppendedLength += m_oLineAsString.AppendUntilSpace(min(m_uiMaxLineWidth, oCurrentPte.m_uiLength - uiAppendedLength));
				iPrevLineBreakLength = iLineBreakLength;
				iLineBreakLength = GetLineBreakStrLen();

				if (iPrevLineBreakLength == iLineBreakLength)
				{
					bLineWidthLimitReached = true;
					break;
				}
			}

			if (bLineWidthLimitReached == true)
			{
				bLineWidthLimitReached = false;

				USCharPosition oEndLinePos;
				USCharPosition oCurrentPtePos(pnPteCurrent, uiAppendedLength);

				GetRelativeCharPos(&oCurrentPtePos, &oEndLinePos, uiAppendedLength);
				USLineEntry& oNextLine = m_oLines.GetNext(pnLineCurrent);
				oNextLine.m_oCharPos.m_pnNode = oEndLinePos.m_pnNode;
				oNextLine.m_oCharPos.m_uiCharOffset = oEndLinePos.m_uiCharOffset;

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

void UCLineManager::GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength)
{
	NODE_PTR pnCurrent;
	NODE_PTR pnPrev;
	USPieceTableEntry oEntry;
	unsigned int uiTotalLengthPassed;

	if (poResult == nullptr)
		return;

	if (poStart == nullptr)
		pnCurrent = m_oPieceTable.GetHeadPosition();
	else
	{
		pnCurrent = poStart->m_pnNode;
		uiLength += poStart->m_uiCharOffset;
	}

	uiTotalLengthPassed = 0;
	while (pnCurrent != nullptr)
	{
		pnPrev = pnCurrent;
		oEntry = m_oPieceTable.GetNext(pnCurrent);

		if (uiLength > oEntry.m_uiLength)
			uiLength -= oEntry.m_uiLength;
		else
			break;

	}

	poResult->m_pnNode = pnCurrent;
	poResult->m_uiCharOffset = uiLength;
}

void UCLineManager::CalcLine(USLineEntry& roLineEntry)
{

}

