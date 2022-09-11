#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"
#include "UCLineManager.h"
#include "USCharPosition.h"

class UCPieceTableManager
{
	private:
		USPieceTableEntry m_oHeadEntry;
		UCRelinkList<USPieceTableEntry, USPieceTableEntry&> m_oPieceTable;

		UCAppendBuffer m_oAppendBuffer;
		USCharPosition m_oCurrentTextPos;

		void splitAtCurrentTextPos();
	public:
		UCLineManager m_oLineManager;

		UCPieceTableManager();

		NODE_PTR Add(TCHAR* tszString, unsigned int uiLength);
		void SelectPos(NODE_PTR pnCurrentNode, unsigned int uiCharOffset);
		void SelectPosByCharCount(unsigned int uiLength);
};

