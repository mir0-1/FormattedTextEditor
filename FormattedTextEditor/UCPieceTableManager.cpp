#include "pch.h"
#include "UCPieceTableManager.h"


void UCPieceTableManager::splitAtCurrentTextPos()
{
	USPieceTableEntry oSelectedPte = m_oPieceTable.GetAt(m_oCurrentTextPos.m_pnCurrentNode);
	USPieceTableEntry oSecondSplitPartPte;

	unsigned int uiSplitLengthLeft = oSelectedPte.m_uiLength - m_oCurrentTextPos.m_uiCharOffset;
	oSelectedPte.m_uiLength = m_oCurrentTextPos.m_uiCharOffset;
	m_oPieceTable.SetAt(m_oCurrentTextPos.m_pnCurrentNode, oSelectedPte);

	oSecondSplitPartPte.m_pszContent = oSelectedPte.m_pszContent + m_oCurrentTextPos.m_uiCharOffset;
	oSecondSplitPartPte.m_uiLength = uiSplitLengthLeft;
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

			if (pnPrev != nullptr && (m_oCurrentTextPos.m_pnCurrentNode != pnPrev || m_oCurrentTextPos.m_uiCharOffset != oSelectedPte.m_uiLength))
				m_oAppendBuffer.UpdateTracker();
		}

		pszThisTracker = m_oAppendBuffer.Add(&tszString, &uiLength, false);

		// CASE 0: INSERT IN EMPTY TABLE
		if (m_oCurrentTextPos.m_pnCurrentNode == nullptr)
		{
			oAddedPte.m_pszContent = pszThisTracker;
			oAddedPte.m_uiLength = (uiPrevLength - uiLengthNotAdded);
			m_oCurrentTextPos.m_pnCurrentNode = m_oPieceTable.AddTail(oAddedPte);
			m_oCurrentTextPos.m_uiCharOffset = oAddedPte.m_uiLength;
		}

		else if (m_oCurrentTextPos.m_uiCharOffset == oSelectedPte.m_uiLength)
		{
			// case 1: insert after (update existing entry)
			if (pszThisTracker == pszPrevTracker)
			{
				oSelectedPte.m_uiLength += (uiPrevLength - uiLengthNotAdded);
				m_oCurrentTextPos.m_uiCharOffset = oSelectedPte.m_uiLength;
				m_oPieceTable.SetAt(m_oCurrentTextPos.m_pnCurrentNode, oSelectedPte);
			}

			// case 2: insert after (add new entry)
			else
			{
				oAddedPte.m_pszContent = pszThisTracker;
				oAddedPte.m_uiLength = (uiPrevLength - uiLengthNotAdded);
				m_oCurrentTextPos.m_pnCurrentNode = m_oPieceTable.InsertAfter(m_oCurrentTextPos.m_pnCurrentNode, oAddedPte);
				m_oCurrentTextPos.m_uiCharOffset = oAddedPte.m_uiLength;
			}
		}

		// case 3: insert before (add new entry)
		else if (m_oCurrentTextPos.m_uiCharOffset == 0)
		{
			oAddedPte.m_pszContent = pszThisTracker;
			oAddedPte.m_uiLength = (uiPrevLength - uiLengthNotAdded);
			m_oCurrentTextPos.m_pnCurrentNode = m_oPieceTable.InsertBefore(m_oCurrentTextPos.m_pnCurrentNode, oAddedPte);
			m_oCurrentTextPos.m_uiCharOffset = oAddedPte.m_uiLength;
		}

		// case 4: insert between (add new entry, update existing entry)
		else
		{
			splitAtCurrentTextPos();

			oAddedPte.m_pszContent = pszThisTracker;
			oAddedPte.m_uiLength = (uiPrevLength - uiLengthNotAdded);
			m_oCurrentTextPos.m_pnCurrentNode = m_oPieceTable.InsertAfter(m_oCurrentTextPos.m_pnCurrentNode, oAddedPte);
			m_oCurrentTextPos.m_uiCharOffset = oAddedPte.m_uiLength;
		}

		pszPrevTracker = pszThisTracker;
		pnPrev = m_oCurrentTextPos.m_pnCurrentNode;
	}

	return m_oCurrentTextPos.m_pnCurrentNode;
}

void UCPieceTableManager::SelectPos(NODE_PTR pnCurrentPos, unsigned int uiCharOffset)
{
	m_oCurrentTextPos.m_pnCurrentNode = pnCurrentPos;
	m_oCurrentTextPos.m_uiCharOffset = uiCharOffset;
}

void UCPieceTableManager::SelectPosByCharCount(unsigned int uiLength)
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

		if (uiLength > oEntry.m_uiLength)
		{
			uiLength -= oEntry.m_uiLength;
			continue;
		}

		SelectPos(posPrev, uiLength);
		break;
	}
}
