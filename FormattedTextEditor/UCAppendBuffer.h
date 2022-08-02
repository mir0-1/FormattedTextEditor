#pragma once
#include <tchar.h>
#include "USPieceTableEntry.h"

class UCAppendBuffer
{
	private:
		unsigned int uiLengthPerArray;
		unsigned int uiCurrentArrayLengthLeft;
		TCHAR* pArrTszCurrentArray;
		TCHAR* pTracker;
		bool isInit;

		USPieceTableEntry oEntryOut;

	public:
		UCAppendBuffer();
		UCAppendBuffer(unsigned int uiLengthPerArray);

		TCHAR* add(TCHAR** tszString, unsigned int* uiLength, bool bUpdateTracker);
		TCHAR* updateTracker();
		TCHAR* getTracker();
};