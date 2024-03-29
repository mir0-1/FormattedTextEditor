#pragma once
#include <tchar.h>
#include "USPieceTableEntry.h"

class UCAppendBuffer
{
	private:
		unsigned int m_uiLengthPerArray;
		unsigned int m_uiCurrentArrayLengthLeft;
		TCHAR* m_pArrTszCurrentArray;
		TCHAR* m_pTracker;

	public:
		UCAppendBuffer();
		UCAppendBuffer(unsigned int uiLengthPerArray);

		TCHAR* Add(TCHAR** tszString, unsigned int* uiLength, bool bUpdateTracker);
		TCHAR* UpdateTracker();
		TCHAR* GetTracker();
};