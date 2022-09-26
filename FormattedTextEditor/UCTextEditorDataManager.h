#pragma once
#include "UCPieceTable.h"
#include "UCRelinkList.h"
#include "UCFormatter.h"
#include "UCCharPosFinder.h"
#include "UCTextInserter.h"

class UCTextEditorDataManager
{
	private:
		UCRelinkList<USPieceTableEntry, USPieceTableEntry&> m_oListForPieceTable;

	public:
		UCTextEditorDataManager();

		UCSplitMerger m_oSplitMerger;
		UCCharPosFinder m_oFinder;
		UCTextInserter m_oInserter;
		UCFormatter m_oFormatter;
};

