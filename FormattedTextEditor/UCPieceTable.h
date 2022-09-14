#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"

class UCPieceTableContainer : public UCRelinkList<USPieceTableEntry, USPieceTableEntry&>
{
	void GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength);
};

