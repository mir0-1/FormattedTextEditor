#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "USCharPosition.h"

class UCSplitMerger
{
	private:	
		UCRelinkList<USPieceTableEntry, USPieceTableEntry&>& m_roPieceTable;

	public:
		UCSplitMerger(UCRelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable);

		NODE_PTR SplitAfter(USCharPosition& roCharPos);

		friend class UCTextInserter;
		friend class UCFormatter;
};

