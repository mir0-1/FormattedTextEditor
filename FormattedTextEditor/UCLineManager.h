#pragma once
#include "USPieceTableEntry.h"
#include "USLineEntry.h"
#include "UCNonNullList.h"
#include "UCGrowableTcharArray.h"
#include "UCPieceTable.h"
#include <afxwin.h>

class UCLineManager
{
	private:
		UCPieceTable& m_roPieceTable;
		USCharPosition m_oDefaultPosition;
		USLineEntry m_oDefaultLine;
		UCNonNullList<USLineEntry, USLineEntry&> m_oLines;
		CDC* m_poDC;
		UCGrowableArray<int> m_oLineWidthsArray;
		UCGrowableTcharArray m_oLineAsString;

		NODE_PTR m_pnSelectedLine;
		unsigned int m_uiMaxLineWidth;

	public:
		UCLineManager(UCPieceTable& roPieceTable, unsigned int uiMaxLineWidth, CDC *poDC);

		void RecalcLines(NODE_PTR posStartLine, NODE_PTR posEndLine);
		int GetLineBreakStrLen();
};