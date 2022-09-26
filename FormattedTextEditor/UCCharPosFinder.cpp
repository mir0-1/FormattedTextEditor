#include "UCCharPosFinder.h"

UCCharPosFinder::UCCharPosFinder(UCRelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable)
	: m_roPieceTable(roPieceTable)
{
}

void UCCharPosFinder::GetAbsoluteCharPos(USCharPosition* poCharPos, unsigned int uiLength)
{
	GetRelativeCharPos(nullptr, poCharPos, uiLength);
}

void UCCharPosFinder::GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength)
{
	NODE_PTR pnCurrent;
	NODE_PTR pnPrev = nullptr;
	const USPieceTableEntry* poEntry = nullptr;
	unsigned int uiInitialCharOffset;

	if (poResult == nullptr)
		return;

	if (poStart == nullptr)
	{
		pnCurrent = m_roPieceTable.GetHeadPosition();
		uiInitialCharOffset = 0;
	}
	else
	{
		pnCurrent = poStart->m_pnNode;
		uiInitialCharOffset = poStart->m_uiCharOffset;
	}

	while (pnCurrent != nullptr)
	{
		if (pnPrev != nullptr)
			uiLength -= poEntry->m_uiLength;

		pnPrev = pnCurrent;
		poEntry = &m_roPieceTable.GetNext(pnCurrent);

		if (uiLength <= poEntry->m_uiLength - uiInitialCharOffset)
			break;

		if (uiInitialCharOffset)
			uiInitialCharOffset = 0;
	}

	if (uiLength > poEntry->m_uiLength)
		uiLength = poEntry->m_uiLength;

	poResult->m_pnNode = pnPrev;
	poResult->m_uiCharOffset = uiLength;
}