#pragma once
#include "UCROList.h"
#include "USPieceTableEntry.h"
#include "USLineEntry.h"
#include "UCNonNullList.h"

class UCLineManager
{
	private:
		UCNonNullList<USLineEntry, USLineEntry&> m_oLines;
		UCROList<USPieceTableEntry, USPieceTableEntry&>& m_roPieceTable;
		NODE_PTR m_nodeSelectedLine;
		unsigned int m_uiMaxLineWidth;

	public:
		UCLineManager(UCROList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable, unsigned int uiMaxLineWidth);

		void RecalcLines(NODE_PTR posStartLine, NODE_PTR posEndLine);
};