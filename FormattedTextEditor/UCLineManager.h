#pragma once
#include "UCReadOnlyList.h"
#include "USPieceTableEntry.h"
#include "USLineEntry.h"
#include "UCNonNullList.h"
#include "UCGrowableTcharArray.h"
#include <afxwin.h>

class UCLineManager
{
	private:
		UCReadOnlyList<USPieceTableEntry, USPieceTableEntry&> m_oPieceTable;
		USCharPosition m_oDefaultPosition;
		USLineEntry m_oDefaultLine;
		UCNonNullList<USLineEntry, USLineEntry&> m_oLines;
		CDC* m_poDC;
		UCGrowableArray<int> m_oLineWidthsArray;
		UCGrowableTcharArray m_oLineAsString;

		NODE_PTR m_pnSelectedLine;
		unsigned int m_uiMaxLineWidth;

	public:
		UCLineManager(CList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable, unsigned int uiMaxLineWidth, CDC *poDC);

		void RecalcLines(NODE_PTR posStartLine, NODE_PTR posEndLine);
		int GetLineBreakStrLen();
		void GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength);
};