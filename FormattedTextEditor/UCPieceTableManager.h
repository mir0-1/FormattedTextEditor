#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"
#include "UCLineManager.h"
#include "USCharPosition.h"
#include "USFPieceTableAdd.h"

class UCPieceTableManager
{
	private:
		USPieceTableEntry m_oDummyHeadEntry;
		UCRelinkList<USPieceTableEntry, USPieceTableEntry&> m_oPieceTable;

		UCAppendBuffer m_oAppendBuffer;
		USCharPosition m_oCurrentTextPos;

		NODE_PTR SplitAt(USCharPosition& roCharPos);
		void CaseAdd_EmptyTable(USFPieceTableAdd& roAddInfo);
		void CaseAdd_InsertAfter_Update(USFPieceTableAdd& roAddInfo);
		void CaseAdd_InsertAfter_New(USFPieceTableAdd& roAddInfo);
		void CaseAdd_InsertBefore_New(USFPieceTableAdd& roAddInfo);
		void CaseAdd_InsertBetween_Split(USFPieceTableAdd& roAddInfo);

	public:
		UCLineManager m_oLineManager;

		UCPieceTableManager();

		NODE_PTR Add(TCHAR* tszString, unsigned int uiLength);
		void SelectCharPosByCharCount(unsigned int uiLength);
		void SetFont(USCharPosition& roStart, USCharPosition& roEnd, TCHAR* ptszStrFontName, unsigned int uiFontSize);
		void CharCountToCharPos(USCharPosition& roCharPos, unsigned int uiLength);
};

