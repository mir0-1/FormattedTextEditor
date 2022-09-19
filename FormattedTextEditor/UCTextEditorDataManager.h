#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"
#include "UCLineManager.h"
#include "USCharPosition.h"
#include "USFPieceTableAdd.h"
#include "UCPieceTable.h"

class UCTextEditorDataManager
{
	public:
		UCPieceTable m_oPieceTable;
		UCLineManager m_oLineManager;

		UCTextEditorDataManager(CDC *poDC);
};

