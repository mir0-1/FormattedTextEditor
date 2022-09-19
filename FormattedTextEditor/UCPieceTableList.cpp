#include "pch.h"
#include "UCPieceTable.h"
#include "UCSFontInfoManager.h"


NODE_PTR UCPieceTable::SplitAt(USCharPosition& roCharPos)
{
	USPieceTableEntry& oSelectedPte = GetAt(roCharPos.m_pnNode);
	USPieceTableEntry oSecondSplitPartPte;
	NODE_PTR pnResult = nullptr;

	if (roCharPos.m_uiCharOffset == 0 || roCharPos.m_uiCharOffset == oSelectedPte.m_uiLength)
		return roCharPos.m_pnNode;

	unsigned int uiSplitLengthLeft = oSelectedPte.m_uiLength - roCharPos.m_uiCharOffset;
	oSelectedPte.m_uiLength = roCharPos.m_uiCharOffset;

	oSecondSplitPartPte.m_ptszContent = oSelectedPte.m_ptszContent + roCharPos.m_uiCharOffset;
	oSecondSplitPartPte.m_uiLength = uiSplitLengthLeft;
	pnResult = InsertAfter(roCharPos.m_pnNode, oSecondSplitPartPte);

	return pnResult;
}

void UCPieceTable::CaseAdd_EmptyTable(USFPieceTableAdd& roAddInfo)
{
	roAddInfo.oAddedPte.m_ptszContent = roAddInfo.pszThisTracker;
	roAddInfo.oAddedPte.m_uiLength = (roAddInfo.uiPrevLength - *roAddInfo.m_puiLengthNotAdded);
	m_oCurrentTextPos.m_pnNode = AddTail(roAddInfo.oAddedPte);
	m_oCurrentTextPos.m_uiCharOffset = roAddInfo.oAddedPte.m_uiLength;
}

void UCPieceTable::CaseAdd_InsertAfter_Update(USFPieceTableAdd& roAddInfo)
{
	roAddInfo.oSelectedPte->m_uiLength += (roAddInfo.uiPrevLength - *roAddInfo.m_puiLengthNotAdded);
	m_oCurrentTextPos.m_uiCharOffset = roAddInfo.oSelectedPte->m_uiLength;
}

void UCPieceTable::CaseAdd_InsertAfter_New(USFPieceTableAdd& roAddInfo)
{
	roAddInfo.oAddedPte.m_ptszContent = roAddInfo.pszThisTracker;
	roAddInfo.oAddedPte.m_uiLength = (roAddInfo.uiPrevLength - *roAddInfo.m_puiLengthNotAdded);
	m_oCurrentTextPos.m_pnNode = InsertAfter(m_oCurrentTextPos.m_pnNode, roAddInfo.oAddedPte);
	m_oCurrentTextPos.m_uiCharOffset = roAddInfo.oAddedPte.m_uiLength;
}

void UCPieceTable::CaseAdd_InsertBefore_New(USFPieceTableAdd& roAddInfo)
{
	roAddInfo.oAddedPte.m_ptszContent = roAddInfo.pszThisTracker;
	roAddInfo.oAddedPte.m_uiLength = (roAddInfo.uiPrevLength - *roAddInfo.m_puiLengthNotAdded);
	m_oCurrentTextPos.m_pnNode = InsertBefore(m_oCurrentTextPos.m_pnNode, roAddInfo.oAddedPte);
	m_oCurrentTextPos.m_uiCharOffset = roAddInfo.oAddedPte.m_uiLength;
}

void UCPieceTable::CaseAdd_InsertBetween_Split(USFPieceTableAdd& roAddInfo)
{
	SplitAt(m_oCurrentTextPos);

	roAddInfo.oAddedPte.m_ptszContent = roAddInfo.pszThisTracker;
	roAddInfo.oAddedPte.m_uiLength = (roAddInfo.uiPrevLength - *roAddInfo.m_puiLengthNotAdded);
	m_oCurrentTextPos.m_pnNode = InsertAfter(m_oCurrentTextPos.m_pnNode, roAddInfo.oAddedPte);
	m_oCurrentTextPos.m_uiCharOffset = roAddInfo.oAddedPte.m_uiLength;
}



UCPieceTable::UCPieceTable(CDC* poDC)
{

}

NODE_PTR UCPieceTable::Add(TCHAR* tszString, unsigned int uiLength)
{
	static USFPieceTableAdd oAddInfo;
	oAddInfo.Reinit(&uiLength);

	while (*oAddInfo.m_puiLengthNotAdded != 0)
	{
		oAddInfo.uiPrevLength = uiLength;

		if (m_oCurrentTextPos.m_pnNode != nullptr)
		{
			oAddInfo.oSelectedPte = &GetAt(m_oCurrentTextPos.m_pnNode);

			if (oAddInfo.pnPrev != nullptr && (m_oCurrentTextPos.m_pnNode != oAddInfo.pnPrev || m_oCurrentTextPos.m_uiCharOffset != oAddInfo.oSelectedPte->m_uiLength))
				m_oAppendBuffer.UpdateTracker();
		}

		oAddInfo.pszThisTracker = m_oAppendBuffer.Add(&tszString, &uiLength, false);

		// CASE 0: INSERT IN EMPTY TABLE
		if (m_oCurrentTextPos.m_pnNode == nullptr)
			CaseAdd_EmptyTable(oAddInfo);

		else if (m_oCurrentTextPos.m_uiCharOffset == oAddInfo.oSelectedPte->m_uiLength)
		{
			// case 1: insert after (update existing entry)
			if (oAddInfo.pszThisTracker == oAddInfo.pszPrevTracker)
				CaseAdd_InsertAfter_Update(oAddInfo);

			// case 2: insert after (add new entry)
			else
				CaseAdd_InsertAfter_New(oAddInfo);
		}

		// case 3: insert before (add new entry)
		else if (m_oCurrentTextPos.m_uiCharOffset == 0)
			CaseAdd_InsertBefore_New(oAddInfo);

		// case 4: insert between (add new entry, update existing entry)
		else
			CaseAdd_InsertBetween_Split(oAddInfo);

		oAddInfo.pszPrevTracker = oAddInfo.pszThisTracker;
		oAddInfo.pnPrev = m_oCurrentTextPos.m_pnNode;
	}

	return m_oCurrentTextPos.m_pnNode;
}

void UCPieceTable::SetFont(USCharPosition& roStart, USCharPosition& roEnd, TCHAR* ptszStrFontName, unsigned int uiFontSize)
{
	if (roStart.m_pnNode == nullptr || roEnd.m_pnNode == nullptr)
		return;

	USFontInfo* poTargetFont = UCSFontInfoManager::SetFontInfo(ptszStrFontName, uiFontSize);
	USPieceTableEntry& roStartEntry = GetAt(roStart.m_pnNode);
	USPieceTableEntry& roEndEntry = GetAt(roEnd.m_pnNode);

	if (roStartEntry.m_poFontInfo == nullptr || *poTargetFont != *roStartEntry.m_poFontInfo)
	{
		NODE_PTR pnSplitEntry = SplitAt(roStart);
		USPieceTableEntry& roSplitEntry = GetAt(pnSplitEntry);
		roSplitEntry.m_poFontInfo = UCSFontInfoManager::SetFontInfo(ptszStrFontName, uiFontSize);
	}

	if (roEndEntry.m_poFontInfo == nullptr || *poTargetFont != *roEndEntry.m_poFontInfo)
		SplitAt(roEnd);

	roEndEntry.m_poFontInfo = UCSFontInfoManager::SetFontInfo(ptszStrFontName, uiFontSize);
}

void UCPieceTable::SelectCharPosByCharCount(unsigned int uiLength)
{
	
}

void UCPieceTable::GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength)
{
	NODE_PTR pnCurrent;
	NODE_PTR pnPrev = nullptr;
	const USPieceTableEntry* poEntry = nullptr;
	unsigned int uiInitialCharOffset;

	if (poResult == nullptr)
		return;

	if (poStart == nullptr)
	{
		pnCurrent = GetHeadPosition();
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
		poEntry = &GetNext(pnCurrent);

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

void UCPieceTable::GetAbsoluteCharPos(USCharPosition* poCharPosResult, unsigned int uiLength)
{
	GetRelativeCharPos(nullptr, poCharPosResult, uiLength);
}
