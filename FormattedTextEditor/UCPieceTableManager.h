#pragma once
#include <afxtempl.h>
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"

class UCPieceTableManager
{
	private:
		CList<USPieceTableEntry, USPieceTableEntry&> m_oPieceTable;
		POSITION m_posCurrent;
		unsigned int m_uiCharOffset;
	public:
		UCAppendBuffer m_oAppendBuffer;
		POSITION add(TCHAR* tszString, unsigned int uiLength);
		void selectPos(POSITION posInCurrentPos, unsigned int uiInCharOffset);
		void selectPosByCharCount(unsigned int uiLength);
};

