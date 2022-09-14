#pragma once
#include "UCPieceTableSplitMerger.h"
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"

class UCPieceTableAdder : public virtual UCPieceTableSplitMerger
{
	UCAppendBuffer m_oAppendBuffer;

	private:
		USPieceTableEntry oAddedPte;
		USPieceTableEntry* oSelectedPte = nullptr;
		TCHAR* pszThisTracker = nullptr;
		TCHAR* pszPrevTracker = nullptr;
		NODE_PTR pnPrev = nullptr;
		unsigned int* m_puiLengthNotAdded;
		unsigned int uiPrevLength;

		void CaseAdd_EmptyTable();
		void CaseAdd_InsertAfter_Update();
		void CaseAdd_InsertAfter_New();
		void CaseAdd_InsertBefore_New();
		void CaseAdd_InsertBetween_Split();

		void Reinit(unsigned int* puiLength);

	public:
		NODE_PTR Add(TCHAR* tszString, unsigned int uiLength);
};

