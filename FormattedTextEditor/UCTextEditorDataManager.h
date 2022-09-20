#pragma once
#include "UCLineManager.h"
#include "UCPieceTable.h"
#include "UCDataVisualiser.h"

class UCTextEditorDataManager
{
	public:
		UCPieceTable m_oPieceTable;
		UCLineManager m_oLineManager;
		UCDataVisualiser m_oDataVisualiser;

		UCTextEditorDataManager(CDC *poDC);
};

