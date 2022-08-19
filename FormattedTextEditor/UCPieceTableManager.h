#pragma once
#include "UCRelinkList.h"
#include "USPieceTableEntry.h"
#include "UCAppendBuffer.h"
#include "UCLineManager.h"
#include "USCharPosition.h"

class UCPieceTableManager
{
	private:
		UCAppendBuffer m_oAppendBuffer;
		UCRelinkList<USPieceTableEntry, USPieceTableEntry&> m_oPieceTable;
		UCLineManager m_oLineManager;
		USCharPosition m_oTextPos;

		void splitSelectedEntry();
	public:
		UCPieceTableManager();
		NODE_PTR add(TCHAR* tszString, unsigned int uiLength);

		void selectPos(NODE_PTR pnCurrentNode, unsigned int uiCharOffset);
		void selectPosByCharCount(unsigned int uiLength);
		void test() { m_oLineManager.RecalcLines(nullptr, nullptr); }
};

