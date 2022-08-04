#include "UCAppendBuffer.h"

UCAppendBuffer::UCAppendBuffer()
{
	m_uiLengthPerArray = 256;
	m_pArrTszCurrentArray = new TCHAR[m_uiLengthPerArray];
	m_uiCurrentArrayLengthLeft = 0;
}

UCAppendBuffer::UCAppendBuffer(unsigned int uiInLengthPerArray)
{
	m_uiLengthPerArray = uiInLengthPerArray;
	m_pArrTszCurrentArray = new TCHAR[m_uiLengthPerArray];
	m_uiCurrentArrayLengthLeft = 0;
}

TCHAR* UCAppendBuffer::add(TCHAR** tszString, unsigned int* uiLength, bool bUpdateTracker)
{
	unsigned int i;

	if (bUpdateTracker)
		m_pTracker = &m_pArrTszCurrentArray[m_uiLengthPerArray - m_uiCurrentArrayLengthLeft];

	for (i = 0; i < *uiLength; ++i)
	{
		if (m_uiCurrentArrayLengthLeft == 0)
		{
			m_pArrTszCurrentArray = new TCHAR[m_uiLengthPerArray];
			m_pTracker = m_pArrTszCurrentArray;
			m_uiCurrentArrayLengthLeft = m_uiLengthPerArray;
			break;
		}

		m_pArrTszCurrentArray[m_uiLengthPerArray - m_uiCurrentArrayLengthLeft] = (*tszString)[i];
		m_uiCurrentArrayLengthLeft--;
	}


	*uiLength -= i;
	*tszString += i;

	return m_pTracker;
}

TCHAR* UCAppendBuffer::updateTracker()
{
	m_pTracker = &m_pArrTszCurrentArray[m_uiLengthPerArray - m_uiCurrentArrayLengthLeft];
	return m_pTracker;
}

TCHAR* UCAppendBuffer::getTracker()
{
	return m_pTracker;
}