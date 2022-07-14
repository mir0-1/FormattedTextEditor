#pragma once
#include <tchar.h>

class UCAppendBuffer
{
	private:
		unsigned int uiLengthPerArray;
		unsigned int uiCurrentArrayLengthLeft;
		TCHAR* pArrTszCurrentArray;
		TCHAR* pTracker;

	public:
		UCAppendBuffer();
		UCAppendBuffer(unsigned int uiLengthPerArray);

		TCHAR* add(TCHAR* tszString, unsigned int* uiLength, bool bUpdateTracker);
		TCHAR* updateTracker();
		TCHAR* getTracker();
};