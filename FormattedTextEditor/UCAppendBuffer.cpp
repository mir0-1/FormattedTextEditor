#include "UCAppendBuffer.h"

UCAppendBuffer::UCAppendBuffer()
{
	uiLengthPerArray = 256;
	pArrTszCurrentArray = new TCHAR[uiLengthPerArray];
	uiCurrentArrayLengthLeft = 0;
}

UCAppendBuffer::UCAppendBuffer(unsigned int uiInLengthPerArray)
{
	uiLengthPerArray = uiInLengthPerArray;
	pArrTszCurrentArray = new TCHAR[uiLengthPerArray];
	uiCurrentArrayLengthLeft = 0;
}

TCHAR* UCAppendBuffer::add(TCHAR** tszString, unsigned int* uiLength, bool bUpdateTracker)
{
	unsigned int i;

	if (bUpdateTracker)
		pTracker = &pArrTszCurrentArray[uiLengthPerArray - uiCurrentArrayLengthLeft];

	for (i = 0; i < *uiLength; ++i)
	{
		if (uiCurrentArrayLengthLeft == 0)
		{
			pArrTszCurrentArray = new TCHAR[uiLengthPerArray];
			pTracker = pArrTszCurrentArray;
			uiCurrentArrayLengthLeft = uiLengthPerArray;
			break;
		}

		pArrTszCurrentArray[uiLengthPerArray - uiCurrentArrayLengthLeft] = (*tszString)[i];
		uiCurrentArrayLengthLeft--;
	}


	*uiLength -= i;
	*tszString += i;

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