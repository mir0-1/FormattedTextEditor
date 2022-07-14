#include "UCAppendBuffer.h"

UCAppendBuffer::UCAppendBuffer()
{
	uiLengthPerArray = 256;
	pArrTszCurrentArray = nullptr;
	uiCurrentArrayLengthLeft = 0;
	pTracker = nullptr;
}

UCAppendBuffer::UCAppendBuffer(unsigned int uiInLengthPerArray)
{
	uiLengthPerArray = uiInLengthPerArray;
	pArrTszCurrentArray = nullptr;
	uiCurrentArrayLengthLeft = 0;
	pTracker = nullptr;
}

TCHAR* UCAppendBuffer::add(TCHAR* tszString, unsigned int* uiLength, bool bUpdateTracker)
{
	unsigned int i;

	if (bUpdateTracker)
		pTracker = &pArrTszCurrentArray[uiLengthPerArray - uiCurrentArrayLengthLeft];

	for (i = 0; i < *uiLength; ++i)
	{
		if (pArrTszCurrentArray == nullptr || uiCurrentArrayLengthLeft == 0)
		{
			pArrTszCurrentArray = new TCHAR[uiLengthPerArray];
			pTracker = pArrTszCurrentArray;
			return pArrTszCurrentArray;
		}

		uiCurrentArrayLengthLeft = uiLengthPerArray;
		pArrTszCurrentArray[uiLengthPerArray - uiCurrentArrayLengthLeft] = tszString[i];

		uiCurrentArrayLengthLeft--;
	}

	*uiLength -= i;
	return pTracker;
}

TCHAR* UCAppendBuffer::updateTracker()
{
	pTracker = &pArrTszCurrentArray[uiLengthPerArray - uiCurrentArrayLengthLeft];
	return pTracker;
}

TCHAR* UCAppendBuffer::getTracker()
{
	return pTracker;
}