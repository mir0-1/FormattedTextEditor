#include "UCPieceTableAdder.h"

void UCPieceTableAdder::CaseAdd_EmptyTable()
{
	oAddedPte.m_ptszContent = pszThisTracker;
	oAddedPte.m_uiLength = (uiPrevLength - *m_puiLengthNotAdded);
	m_oCurrentTextPos.m_pnNode = m_oPieceTable.AddTail(oAddedPte);
	m_oCurrentTextPos.m_uiCharOffset = oAddedPte.m_uiLength;
}

void UCPieceTableAdder::CaseAdd_InsertAfter_Update()
{
	oSelectedPte->m_uiLength += (uiPrevLength - *m_puiLengthNotAdded);
	m_oCurrentTextPos.m_uiCharOffset = oSelectedPte->m_uiLength;
}

void UCPieceTableAdder::CaseAdd_InsertAfter_New()
{
	oAddedPte.m_ptszContent = pszThisTracker;
	oAddedPte.m_uiLength = (uiPrevLength - *m_puiLengthNotAdded);
	m_oCurrentTextPos.m_pnNode = m_oPieceTable.InsertAfter(m_oCurrentTextPos.m_pnNode, oAddedPte);
	m_oCurrentTextPos.m_uiCharOffset = oAddedPte.m_uiLength;
}

void UCPieceTableAdder::CaseAdd_InsertBefore_New()
{
	oAddedPte.m_ptszContent = pszThisTracker;
	oAddedPte.m_uiLength = (uiPrevLength - *m_puiLengthNotAdded);
	m_oCurrentTextPos.m_pnNode = m_oPieceTable.InsertBefore(m_oCurrentTextPos.m_pnNode, oAddedPte);
	m_oCurrentTextPos.m_uiCharOffset = oAddedPte.m_uiLength;
}

void UCPieceTableAdder::CaseAdd_InsertBetween_Split()
{
	SplitAt(m_oCurrentTextPos);

	oAddedPte.m_ptszContent = pszThisTracker;
	oAddedPte.m_uiLength = (uiPrevLength - *m_puiLengthNotAdded);
	m_oCurrentTextPos.m_pnNode = m_oPieceTable.InsertAfter(m_oCurrentTextPos.m_pnNode, oAddedPte);
	m_oCurrentTextPos.m_uiCharOffset = oAddedPte.m_uiLength;
}

void UCPieceTableAdder::Reinit(unsigned int* puiLength)
{
	oSelectedPte = nullptr;
	pszThisTracker = nullptr;
	m_puiLengthNotAdded = puiLength;
	unsigned int uiPrevLength;
}

NODE_PTR UCPieceTableAdder::Add(TCHAR* tszString, unsigned int uiLength)
{
	Reinit(&uiLength);

	while (*m_puiLengthNotAdded != 0)
	{
		uiPrevLength = uiLength;

		if (m_oCurrentTextPos.m_pnNode != nullptr)
		{
			oSelectedPte = &m_oPieceTable.GetAt(m_oCurrentTextPos.m_pnNode);

			if (pnPrev != nullptr && (m_oCurrentTextPos.m_pnNode != pnPrev || m_oCurrentTextPos.m_uiCharOffset != oSelectedPte->m_uiLength))
				m_oAppendBuffer.UpdateTracker();
		}

		pszThisTracker = m_oAppendBuffer.Add(&tszString, &uiLength, false);

		// CASE 0: INSERT IN EMPTY TABLE
		if (m_oCurrentTextPos.m_pnNode == nullptr)
			CaseAdd_EmptyTable();

		else if (m_oCurrentTextPos.m_uiCharOffset == oSelectedPte->m_uiLength)
		{
			// case 1: insert after (update existing entry)
			if (pszThisTracker == pszPrevTracker)
				CaseAdd_InsertAfter_Update();

			// case 2: insert after (add new entry)
			else
				CaseAdd_InsertAfter_New();
		}

		// case 3: insert before (add new entry)
		else if (m_oCurrentTextPos.m_uiCharOffset == 0)
			CaseAdd_InsertBefore_New();

		// case 4: insert between (add new entry, update existing entry)
		else
			CaseAdd_InsertBetween_Split();

		pszPrevTracker = pszThisTracker;
		pnPrev = m_oCurrentTextPos.m_pnNode;
	}

	return m_oCurrentTextPos.m_pnNode;
}