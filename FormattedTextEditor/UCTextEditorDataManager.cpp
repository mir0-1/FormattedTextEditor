#include "pch.h"
#include "UCTextEditorDataManager.h"
#include "UCSFontInfoManager.h"

UCTextEditorDataManager::UCTextEditorDataManager(CDC* poDC)
	: m_oLineManager(m_oPieceTable, 30, poDC)
{
}
