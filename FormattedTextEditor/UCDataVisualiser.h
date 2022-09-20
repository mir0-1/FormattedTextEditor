#pragma once
#include "USLineEntry.h"
#include "USPieceTableEntry.h"
#include "UCPieceTable.h"
#include "UCNonNullList.h"
#include "UCGrowableTcharArray.h"
#include <afxwin.h>

class UCDataVisualiser
{
	private:
		UCPieceTable& m_roPieceTable;
		CDC* m_poDc;
		UCNonNullList<USLineEntry, USLineEntry&>& m_roLines;
		UCGrowableTcharArray m_oLineAsString;

	public:
		UCDataVisualiser(UCPieceTable& roPieceTable, CDC* poDc, UCNonNullList<USLineEntry, USLineEntry&>& roLines);

		void DisplayLine(int x, int y, NODE_PTR pnLineToDisplay);
};

