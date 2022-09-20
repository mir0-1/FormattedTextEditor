#include "pch.h"
#include "UCTextEditorDataManager.h"
#include "UCSFontInfoManager.h"

UCTextEditorDataManager::UCTextEditorDataManager(CDC* poDC)
	: m_oLineManager(m_oPieceTable, 30, poDC),
	m_oDataVisualiser(m_oPieceTable, poDC, m_oLineManager.GetLineList())
{
}
