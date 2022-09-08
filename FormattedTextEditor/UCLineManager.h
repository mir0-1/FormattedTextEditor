#pragma once
#include "UCReadOnlyList.h"
#include "USPieceTableEntry.h"
#include "USLineEntry.h"
#include "UCNonNullList.h"

class UCLineManager
{
	private:
		UCReadOnlyList<USPieceTableEntry, USPieceTableEntry&> m_oPieceTable;
		USCharPosition m_oDefaultPosition;
		USLineEntry m_oDefaultLine;
		UCNonNullList<USLineEntry, USLineEntry&> m_oLines;

		NODE_PTR m_nodeSelectedLine;
		unsigned int m_uiMaxLineWidth;

	public:
		UCLineManager(CList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable, unsigned int uiMaxLineWidth);

		void RecalcLines(NODE_PTR posStartLine, NODE_PTR posEndLine);
};