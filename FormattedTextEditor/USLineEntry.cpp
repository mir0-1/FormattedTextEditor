#include "USLineEntry.h"

USLineEntry::USLineEntry()
{
	m_uiMaxTmHeight = 0;
	m_bIsValidated = false;
}

USLineEntry::USLineEntry(USCharPosition& oCharPos, long uiMaxTmHeight, bool bIsValidated)
{
	m_oCharPos = oCharPos;
	m_uiMaxTmHeight = uiMaxTmHeight;
	m_bIsValidated = bIsValidated;
}
