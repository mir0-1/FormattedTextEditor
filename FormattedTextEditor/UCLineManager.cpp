#include "UCLineManager.h"

UCLineManager::UCLineManager(UCRORelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable)
	: m_roPieceTable(roPieceTable)
{
}