#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "USCharPosition.h"

class UCCharPosFinder
{
	private:
		const UCRelinkList<USPieceTableEntry, USPieceTableEntry&>& m_roPieceTable;

	public:
		UCCharPosFinder(UCRelinkList<USPieceTableEntry, USPieceTableEntry&>& roPieceTable);

		void GetAbsoluteCharPos(USCharPosition* poResult, unsigned int uiLength) const;
		void GetRelativeCharPos(const USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength) const;
};