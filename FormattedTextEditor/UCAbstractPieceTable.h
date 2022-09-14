#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "USCharPosition.h"

class UCAbstractPieceTable
{
	protected:
		UCRelinkList<USPieceTableEntry, USPieceTableEntry&> m_oPieceTable;
		USCharPosition m_oCurrentTextPos;
};

