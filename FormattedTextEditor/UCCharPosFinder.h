#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "USCharPosition.h"

class UCCharPosFinder
{
	private:
		UCRelinkList<USPieceTableEntry, USPieceTableEntry&>& m_roPieceTable;

	public:
		UCCharPosFinder(UCRelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable);

		void GetAbsoluteCharPos(USCharPosition* poCharPos, unsigned int uiLength);
		void GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength);
};