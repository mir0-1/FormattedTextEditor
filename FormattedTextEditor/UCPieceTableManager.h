#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"

class UCPieceTableManager
{
	private:
		UCRelinkList<USPieceTableEntry, USPieceTableEntry&> m_oPieceTable;
		UCAppendBuffer m_oAppendBuffer;
		POSITION m_posCurrent;
		unsigned int m_uiCharOffset;
	public:
		POSITION add(TCHAR* tszString, unsigned int uiLength);
		void selectPos(POSITION posInCurrentPos, unsigned int uiInCharOffset);
		void selectPosByCharCount(unsigned int uiLength);
};

