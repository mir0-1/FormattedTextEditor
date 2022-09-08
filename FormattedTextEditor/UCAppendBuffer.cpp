#include "UCAppendBuffer.h"

UCAppendBuffer::UCAppendBuffer()
{
	m_uiLengthPerArray = 256;
	m_pArrTszCurrentArray = new TCHAR[m_uiLengthPerArray];
	m_uiCurrentArrayLengthLeft = 0;
	m_pTracker = nullptr;
}

UCAppendBuffer::UCAppendBuffer(unsigned int uiInLengthPerArray)
{
	m_uiLengthPerArray = uiInLengthPerArray;
	m_pArrTszCurrentArray = new TCHAR[m_uiLengthPerArray];
	m_uiCurrentArrayLengthLeft = 0;
	m_pTracker = nullptr;
}

TCHAR* UCAppendBuffer::Add(TCHAR** tszString, unsigned int* uiLength, bool bUpdateTracker)
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

TCHAR* UCAppendBuffer::UpdateTracker()
{
	m_pTracker = &m_pArrTszCurrentArray[m_uiLengthPerArray - m_uiCurrentArrayLengthLeft];
	return m_pTracker;
}

TCHAR* UCAppendBuffer::GetTracker()
{
	return m_pTracker;
}