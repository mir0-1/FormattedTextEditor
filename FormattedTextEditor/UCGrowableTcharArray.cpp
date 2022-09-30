#include "UCGrowableTcharArray.h"

int UCGrowableTcharArray::AppendUntilSpace(unsigned int uiLength)
{
	if (m_pTypeAppendSource == nullptr || uiLength == 0)
		return -1;

	if (uiLength > m_uiTotalLength)
		Grow(uiLength);

	m_uiPrevUsedLength = m_uiUsedLength;

	bool bWasInSpaces = false;
	int i;
	for (i = 0; i < uiLength; i++)
	{
		if (_istspace(m_pTypeAppendSource[i]))
			bWasInSpaces = true;
		else if (bWasInSpaces)
		{
			bWasInSpaces = false;
			break;
		}

		m_pTypeBaseAddress[m_uiUsedLength++] = m_pTypeAppendSource[i];
	}

	m_pTypeAppendSource += i;
	m_uiPrevAppendLength = uiLength;

	return i;
}
