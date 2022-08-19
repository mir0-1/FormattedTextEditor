#pragma once
#include "UCRORelinkList.h"
#include "USPieceTableEntry.h"
#include "USLineEntry.h"

class UCLineManager
{
	private:
		UCRORelinkList<USPieceTableEntry, USPieceTableEntry&>& m_roPieceTable;
		UCRelinkList<USLineEntry, USLineEntry&> m_oLines;
		NODE_PTR m_nodeSelectedLine;
		unsigned int m_uiSelectedOffset;
		unsigned int m_uiMaxLineWidth;

	public:
		UCLineManager(UCRORelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable, unsigned int uiMaxLineWidth);

		void RecalcLines(NODE_PTR posStartLine, NODE_PTR posEndLine);
};