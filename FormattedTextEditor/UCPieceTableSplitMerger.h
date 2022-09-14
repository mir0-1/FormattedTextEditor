#pragma once
#include "UCAbstractPieceTable.h"

class UCPieceTableSplitMerger : public virtual UCAbstractPieceTable
{
	public:
		NODE_PTR SplitAt(USCharPosition& roCharPos);
};

