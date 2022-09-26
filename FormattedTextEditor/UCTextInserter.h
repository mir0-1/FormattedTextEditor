#pragma once
#include "UCSplitMerger.h"
#include "UCAppendBuffer.h"

class UCTextInserter
{
	private:
		UCSplitMerger& m_roSplitMerger;

		UCAppendBuffer m_oAppendBuffer;
		USCharPosition *m_poPositionIn;
		USCharPosition *m_poPositionOut;
		USPieceTableEntry m_oAddedPte;
		USPieceTableEntry* m_poSelectedPte = nullptr;
		TCHAR* m_ptszThisTracker = nullptr;
		TCHAR* m_ptszPrevTracker = nullptr;
		NODE_PTR m_pnPrev = nullptr;
		unsigned int* m_puiLengthNotAdded;
		unsigned int m_uiPrevLength;

		void CaseAdd_EmptyTable();
		void CaseAdd_InsertAfter_Update();
		void CaseAdd_InsertAfter_New();
		void CaseAdd_InsertBefore_New();
		void CaseAdd_InsertBetween_Split();
		void ReinitAddInfo(unsigned int* puiLength);
		void UpdateOutPosition(NODE_PTR pnResult);

	public:
		UCTextInserter(UCSplitMerger& roSplitMerger);

		void Add(USCharPosition* poPositionIn, USCharPosition* poPositionOut, TCHAR* tszString, unsigned int uiLength);
};

