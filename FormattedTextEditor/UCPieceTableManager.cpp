#include "pch.h"
#include "UCPieceTableManager.h"


void UCPieceTableManager::splitSelectedEntry()
{
	USPieceTableEntry oSelectedPte = m_oPieceTable.GetAt(m_posCurrent);
	USPieceTableEntry oSecondSplitPartPte;

	unsigned int uiSplitLengthLeft = oSelectedPte.uiLength - m_uiCharOffset;
	oSelectedPte.uiLength = m_uiCharOffset;
	m_oPieceTable.SetAt(m_posCurrent, oSelectedPte);

	oSecondSplitPartPte.pszContent = oSelectedPte.pszContent + m_uiCharOffset;
	oSecondSplitPartPte.uiLength = uiSplitLengthLeft;
	m_oPieceTable.InsertAfter(m_posCurrent, oSecondSplitPartPte);
}

UCPieceTableManager::UCPieceTableManager() 
	: m_oLineManager(static_cast<UCRORelinkList<USPieceTableEntry, USPieceTableEntry&>&>(m_oPieceTable))
{
}

POSITION UCPieceTableManager::add(TCHAR* tszString, unsigned int uiLength)
{
	USPieceTableEntry oAddedPte, oSelectedPte;
	TCHAR* pszThisTracker;
	static TCHAR* pszPrevTracker = nullptr;
	static POSITION posPrev = nullptr;
	unsigned int &uiLengthNotAdded = uiLength;

	while (uiLength)
	{
		unsigned int uiPrevLength = uiLength;

		if (m_posCurrent != nullptr)
		{
			oSelectedPte = m_oPieceTable.GetAt(m_posCurrent);

			if (posPrev != nullptr && (m_posCurrent != posPrev || m_uiCharOffset != oSelectedPte.uiLength))
				m_oAppendBuffer.updateTracker();
		}

		pszThisTracker = m_oAppendBuffer.add(&tszString, &uiLength, false);

		// CASE 0: INSERT IN EMPTY TABLE
		if (m_posCurrent == nullptr)
		{
			oAddedPte.pszContent = pszThisTracker;
			oAddedPte.uiLength = (uiPrevLength - uiLength);
			m_posCurrent = m_oPieceTable.AddTail(oAddedPte);
			m_uiCharOffset = oAddedPte.uiLength;
			pszPrevTracker = pszThisTracker;
			posPrev = m_posCurrent;
			continue;
		}

		if (m_uiCharOffset == oSelectedPte.uiLength)
		{
			// case 1: insert after (update existing entry)
			if (pszThisTracker == pszPrevTracker)
			{
				oSelectedPte.uiLength += (uiPrevLength - uiLengthNotAdded);
				m_uiCharOffset = oSelectedPte.uiLength;
				m_oPieceTable.SetAt(m_posCurrent, oSelectedPte);
			}

			// case 2: insert after (add new entry)
			else
			{
				oAddedPte.pszContent = pszThisTracker;
				oAddedPte.uiLength = (uiPrevLength - uiLengthNotAdded);
				m_posCurrent = m_oPieceTable.InsertAfter(m_posCurrent, oAddedPte);
				m_uiCharOffset = oAddedPte.uiLength;
			}
		}

		// case 3: insert before (add new entry)
		else if (m_uiCharOffset == 0)
		{
			oAddedPte.pszContent = pszThisTracker;
			oAddedPte.uiLength = (uiPrevLength - uiLengthNotAdded);
			m_posCurrent = m_oPieceTable.InsertBefore(m_posCurrent, oAddedPte);
			m_uiCharOffset = oAddedPte.uiLength;
		}

		// case 4: insert between (add new entry, update existing entry)
		else
		{
			splitSelectedEntry();

			oAddedPte.pszContent = pszThisTracker;
			oAddedPte.uiLength = (uiPrevLength - uiLengthNotAdded);
			m_posCurrent = m_oPieceTable.InsertAfter(m_posCurrent, oAddedPte);
			m_uiCharOffset = oAddedPte.uiLength;
		}

		pszPrevTracker = pszThisTracker;
		posPrev = m_posCurrent;
	}

	return m_posCurrent;
}

void UCPieceTableManager::selectPos(POSITION posInCurrentPos, unsigned int uiInCharOffset)
{
	m_posCurrent = posInCurrentPos;
	m_uiCharOffset = uiInCharOffset;
}

void UCPieceTableManager::selectPosByCharCount(unsigned int uiLength)
{
	POSITION posCurrent = m_oPieceTable.GetHeadPosition();
	POSITION posPrev;
	USPieceTableEntry oEntry;
	unsigned int uiTotalLengthPassed;

	uiTotalLengthPassed = 0;
	while (posCurrent != nullptr)
	{
		posPrev = posCurrent;
		oEntry = m_oPieceTable.GetNext(posCurrent);

		if (uiLength > oEntry.uiLength)
		{
			uiLength -= oEntry.uiLength;
			continue;
		}

		selectPos(posPrev, uiLength);
		break;
	}
}
