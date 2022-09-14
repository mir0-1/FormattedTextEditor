#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "USCharPosition.h"

class UCPieceTableContainer : public UCRelinkList<USPieceTableEntry, USPieceTableEntry&>
{
	public:
		void GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength);
};

