#pragma once
#include "UCRORelinkList.h"
#include "USPieceTableEntry.h"
#include "USLineEntry.h"

class UCLineManager
{
	private:
		UCRORelinkList<USPieceTableEntry, USPieceTableEntry&>& m_roPieceTable;
		UCRelinkList<USLineEntry, USLineEntry&> m_oMapLines;

	public:
		UCLineManager(UCRORelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable);
};