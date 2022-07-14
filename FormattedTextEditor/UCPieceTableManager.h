#pragma once
#include <afxtempl.h>
#include "UCPieceTableEntry.h"
#include "UCAppendBuffer.h"

class UCPieceTableManager
{
	private:
		CList<UCPieceTableEntry, UCPieceTableEntry&> oPieceTable;
		UCAppendBuffer oAppendBuffer;
	public:

};

