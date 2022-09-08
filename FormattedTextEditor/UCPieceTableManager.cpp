#include "pch.h"
#include "UCPieceTableManager.h"


void UCPieceTableManager::splitSelectedEntry()
{
	USPieceTableEntry oSelectedPte = m_oPieceTable.GetAt(m_oCurrentTextPos.m_pnCurrentNode);
	USPieceTableEntry oSecondSplitPartPte;

	unsigned int uiSplitLengthLeft = oSelectedPte.uiLength - m_oCurrentTextPos.m_uiCharOffset;
	oSelectedPte.uiLength = m_oCurrentTextPos.m_uiCharOffset;
	m_oPieceTable.SetAt(m_oCurrentTextPos.m_pnCurrentNode, oSelectedPte);

	oSecondSplitPartPte.pszContent = oSelectedPte.pszContent + m_oCurrentTextPos.m_uiCharOffset;
	oSecondSplitPartPte.uiLength = uiSplitLengthLeft;
	m_oPieceTable.InsertAfter(m_oCurrentTextPos.m_pnCurrentNode, oSecondSplitPartPte);
}

UCPieceTableManager::UCPieceTableManager() 
	: m_oPieceTable(m_oHeadEntry),
	m_oLineManager((CList<USPieceTableEntry, USPieceTableEntry&>&)m_oPieceTable, 20)
{
 
}

NODE_PTR UCPieceTableManager::Add(TCHAR* tszString, unsigned int uiLength)
{
	USPieceTableEntry oAddedPte, oSelectedPte;
	TCHAR* pszThisTracker;
	static TCHAR* pszPrevTracker = nullptr;
	static NODE_PTR pnPrev = nullptr;
	unsigned int& uiLengthNotAdded = uiLength;

	while (uiLengthNotAdded != 0)
	{
		unsigned int uiPrevLength = uiLength;

		if (m_oCurrentTextPos.m_pnCurrentNode != nullptr)
		{
			oSelectedPte = m_oPieceTable.GetAt(m_oCurrentTextPos.m_pnCurrentNode);

			if (pnPrev != nullptr && (m_oCurrentTextPos.m_pnCurrentNode != pnPrev || m_oCurrentTextPos.m_uiCharOffset != oSelectedPte.uiLength))
				m_oAppendBuffer.UpdateTracker();
		}

		pszThisTracker = m_oAppendBuffer.Add(&tszString, &uiLength, false);

		// CASE 0: INSERT IN EMPTY TABLE
		if (m_oCurrentTextPos.m_pnCurrentNode == nullptr)
		{
			oAddedPte.pszContent = pszThisTracker;
			oAddedPte.uiLength = (uiPrevLength - uiLengthNotAdded);
			m_oCurrentTextPos.m_pnCurrentNode = m_oPieceTable.AddTail(oAddedPte);
			m_oCurrentTextPos.m_uiCharOffset = oAddedPte.uiLength;
		}

		else if (m_oCurrentTextPos.m_uiCharOffset == oSelectedPte.uiLength)
		{
			// case 1: insert after (update existing entry)
			if (pszThisTracker == pszPrevTracker)
			{
				oSelectedPte.uiLength += (uiPrevLength - uiLengthNotAdded);
				m_oCurrentTextPos.m_uiCharOffset = oSelectedPte.uiLength;
				m_oPieceTable.SetAt(m_oCurrentTextPos.m_pnCurrentNode, oSelectedPte);
			}

			// case 2: insert after (add new entry)
			else
			{
				oAddedPte.pszContent = pszThisTracker;
				oAddedPte.uiLength = (uiPrevLength - uiLengthNotAdded);
				m_oCurrentTextPos.m_pnCurrentNode = m_oPieceTable.InsertAfter(m_oCurrentTextPos.m_pnCurrentNode, oAddedPte);
				m_oCurrentTextPos.m_uiCharOffset = oAddedPte.uiLength;
			}
		}

		// case 3: insert before (add new entry)
		else if (m_oCurrentTextPos.m_uiCharOffset == 0)
		{
			oAddedPte.pszContent = pszThisTracker;
			oAddedPte.uiLength = (uiPrevLength - uiLengthNotAdded);
			m_oCurrentTextPos.m_pnCurrentNode = m_oPieceTable.InsertBefore(m_oCurrentTextPos.m_pnCurrentNode, oAddedPte);
			m_oCurrentTextPos.m_uiCharOffset = oAddedPte.uiLength;
		}

		// case 4: insert between (add new entry, update existing entry)
		else
		{
			splitSelectedEntry();

			oAddedPte.pszContent = pszThisTracker;
			oAddedPte.uiLength = (uiPrevLength - uiLengthNotAdded);
			m_oCurrentTextPos.m_pnCurrentNode = m_oPieceTable.InsertAfter(m_oCurrentTextPos.m_pnCurrentNode, oAddedPte);
			m_oCurrentTextPos.m_uiCharOffset = oAddedPte.uiLength;
		}

		pszPrevTracker = pszThisTracker;
		pnPrev = m_oCurrentTextPos.m_pnCurrentNode;
	}

	return m_oCurrentTextPos.m_pnCurrentNode;
}

void UCPieceTableManager::selectPos(NODE_PTR pnCurrentPos, unsigned int uiCharOffset)
{
	m_oCurrentTextPos.m_pnCurrentNode = pnCurrentPos;
	m_oCurrentTextPos.m_uiCharOffset = uiCharOffset;
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
