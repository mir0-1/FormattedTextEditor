#pragma once
#include <afxtempl.h>
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"

class UCPieceTableManager
{
	private:
		CList<USPieceTableEntry, USPieceTableEntry&> oPieceTable;
	public:
		UCAppendBuffer oAppendBuffer;
		POSITION addAt(POSITION posAfter, unsigned int uiAfterNChars, TCHAR* tszString, unsigned int uiLength);
};

