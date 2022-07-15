#include "pch.h"
#include "UCPieceTableManager.h"


POSITION UCPieceTableManager::addAt(POSITION posEntry, unsigned int uiAfterNChars, TCHAR* tszString, unsigned int uiLength)
{
	unsigned int uiPrevLength = uiLength;
	TCHAR* pTszTracker = nullptr;
	USPieceTableEntry oInEntry, oTemp;

	while (uiLength)
	{
		uiPrevLength = uiLength;
		pTszTracker = oAppendBuffer.add(tszString, &uiLength, false);

		oInEntry.eType = UEPieceTableEntryType::DISCRETE_ADD; // TODO: make this changeable
		oInEntry.uiLength = uiPrevLength;
		oInEntry.pszContent = pTszTracker;

		if (posEntry == nullptr)
		{
			posEntry = oPieceTable.AddTail(oInEntry);
			continue;
		}

		oTemp = oPieceTable.GetAt(posEntry);

		if (uiAfterNChars > oTemp.uiLength)
			return nullptr;

		if (uiAfterNChars == oTemp.uiLength)
		{
			oPieceTable.InsertAfter(posEntry, oInEntry);
			continue;
		}

		if (uiAfterNChars == 0)
		{
			oPieceTable.InsertBefore(posEntry, oInEntry);
			continue;
		}

		unsigned int uiOrigLength = oTemp.uiLength;

		oTemp.uiLength = uiAfterNChars;
		oPieceTable.SetAt(posEntry, oTemp);
		POSITION posFirstHalf = oPieceTable.InsertAfter(posEntry, oInEntry);

		oTemp.pszContent = oTemp.pszContent + oTemp.uiLength;
		oTemp.uiLength = uiOrigLength - uiAfterNChars;

		oPieceTable.InsertAfter(posFirstHalf, oTemp);
	
	}

	return posEntry;
}
