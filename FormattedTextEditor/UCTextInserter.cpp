#include "UCTextInserter.h"

void UCTextInserter::CaseAdd_EmptyTable()
{
	m_oAddedPte.m_ptszContent = m_ptszThisTracker;
	m_oAddedPte.m_uiLength = (m_uiPrevLength - *m_puiLengthNotAdded);
	NODE_PTR pnResult = m_roSplitMerger.m_roPieceTable.AddTail(m_oAddedPte);
	UpdateOutPosition(pnResult);
}

void UCTextInserter::CaseAdd_InsertAfter_Update()
{
	m_poSelectedPte->m_uiLength += (m_uiPrevLength - *m_puiLengthNotAdded);
	m_poPositionOut->m_uiCharOffset = m_poSelectedPte->m_uiLength;
}

void UCTextInserter::CaseAdd_InsertAfter_New()
{
	m_oAddedPte.m_ptszContent = m_ptszThisTracker;
	m_oAddedPte.m_uiLength = (m_uiPrevLength - *m_puiLengthNotAdded);
	NODE_PTR pnResult = m_roSplitMerger.m_roPieceTable.InsertAfter(m_poPositionIn->m_pnNode, m_oAddedPte);
	UpdateOutPosition(pnResult);
}

void UCTextInserter::CaseAdd_InsertBefore_New()
{
	m_oAddedPte.m_ptszContent = m_ptszThisTracker;
	m_oAddedPte.m_uiLength = (m_uiPrevLength - *m_puiLengthNotAdded);
	NODE_PTR pnResult = m_roSplitMerger.m_roPieceTable.InsertBefore(m_poPositionIn->m_pnNode, m_oAddedPte);
	UpdateOutPosition(pnResult);
}

void UCTextInserter::CaseAdd_InsertBetween_Split()
{
	m_roSplitMerger.SplitAfter(*m_poPositionIn);

	m_oAddedPte.m_ptszContent = m_ptszThisTracker;
	m_oAddedPte.m_uiLength = (m_uiPrevLength - *m_puiLengthNotAdded);
	NODE_PTR pnResult = m_roSplitMerger.m_roPieceTable.InsertAfter(m_poPositionIn->m_pnNode, m_oAddedPte);
	UpdateOutPosition(pnResult);
}

UCTextInserter::UCTextInserter(UCSplitMerger& roSplitMerger)
	: m_roSplitMerger(roSplitMerger)
{
}

void UCTextInserter::Add(const USCharPosition* poPositionIn, USCharPosition* poPositionOut, TCHAR* ptszString, unsigned int uiLength)
{
	if (poPositionIn == nullptr)
		return;

	ReinitAddInfo(&uiLength);
	m_poPositionIn = poPositionIn;
	m_poPositionOut = poPositionOut;

	while (*m_puiLengthNotAdded != 0)
	{
		m_uiPrevLength = uiLength;

		if (m_poPositionIn->m_pnNode != nullptr)
		{
			m_poSelectedPte = &m_roSplitMerger.m_roPieceTable.GetAt(m_poPositionIn->m_pnNode);

			if (m_pnPrev != nullptr && (m_poPositionIn->m_pnNode != m_pnPrev || m_poPositionIn->m_uiCharOffset != m_poSelectedPte->m_uiLength))
				m_oAppendBuffer.UpdateTracker();
		}

		m_ptszThisTracker = m_oAppendBuffer.Add(&ptszString, &uiLength, false);

		// CASE 0: INSERT IN EMPTY TABLE
		if (m_poPositionIn->m_pnNode == nullptr)
			CaseAdd_EmptyTable();

		else if (m_poPositionIn->m_uiCharOffset == m_poSelectedPte->m_uiLength)
		{
			// case 1: insert after (update existing entry)
			if (m_ptszThisTracker == m_ptszPrevTracker)
				CaseAdd_InsertAfter_Update();

			// case 2: insert after (add new entry)
			else
				CaseAdd_InsertAfter_New();
		}

		// case 3: insert before (add new entry)
		else if (m_poPositionIn->m_uiCharOffset == 0)
			CaseAdd_InsertBefore_New();

		// case 4: insert between (add new entry, update existing entry)
		else
			CaseAdd_InsertBetween_Split();

		m_ptszPrevTracker = m_ptszThisTracker;
		m_pnPrev = (m_poPositionOut == nullptr ? nullptr : m_poPositionOut->m_pnNode);
	}
}

void UCTextInserter::ReinitAddInfo(unsigned int* puiLength)
{
	m_poSelectedPte = nullptr;
	m_ptszThisTracker = nullptr;
	m_puiLengthNotAdded = puiLength;
}

void UCTextInserter::UpdateOutPosition(const NODE_PTR pnResult)
{
	if (m_poPositionOut != nullptr)
	{
		m_poPositionOut->m_pnNode = pnResult;
		m_poPositionOut->m_uiCharOffset = m_oAddedPte.m_uiLength;
	}
}
