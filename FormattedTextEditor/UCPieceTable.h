#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"
#include "USCharPosition.h"
#include "USFPieceTableAdd.h"
#include <afxwin.h>

class UCPieceTable : public UCRelinkList<USPieceTableEntry, USPieceTableEntry&>
{
	private:
		USPieceTableEntry m_oDummyHeadEntry;

		UCAppendBuffer m_oAppendBuffer;
		USCharPosition m_oCurrentTextPos;

		NODE_PTR SplitAt(USCharPosition& roCharPos);
		void CaseAdd_EmptyTable(USFPieceTableAdd& roAddInfo);
		void CaseAdd_InsertAfter_Update(USFPieceTableAdd& roAddInfo);
		void CaseAdd_InsertAfter_New(USFPieceTableAdd& roAddInfo);
		void CaseAdd_InsertBefore_New(USFPieceTableAdd& roAddInfo);
		void CaseAdd_InsertBetween_Split(USFPieceTableAdd& roAddInfo);

	public:
		UCPieceTable();

		NODE_PTR Add(TCHAR* tszString, unsigned int uiLength);
		void GetAbsoluteCharPos(USCharPosition* poCharPos, unsigned int uiLength);
		void SetFont(USCharPosition& roStart, USCharPosition& roEnd, TCHAR* ptszStrFontName, unsigned int uiFontSize);
		void SelectCharPosByCharCount(unsigned int uiLength);
		void GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength);
};