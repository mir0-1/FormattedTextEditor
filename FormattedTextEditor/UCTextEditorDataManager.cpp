#include "pch.h"
#include "UCTextEditorDataManager.h"
#include "UCSFontInfoManager.h"

UCTextEditorDataManager::UCTextEditorDataManager()
	: m_oSplitMerger(m_oListForPieceTable),
	m_oFinder(m_oListForPieceTable),
	m_oFormatter(m_oSplitMerger),
	m_oInserter(m_oSplitMerger)
{
}
