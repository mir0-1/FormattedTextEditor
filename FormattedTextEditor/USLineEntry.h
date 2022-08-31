#pragma once
#include "user_typedefs.h"
#include "USCharPosition.h"


class USLineEntry
{
	public:
		USCharPosition m_oCharPos;
		long m_uiMaxTmHeight;
		bool m_bIsValidated;

		USLineEntry();
		USLineEntry(USCharPosition& oCharPos, long uiMaxTmHeight, bool isValidated);

};