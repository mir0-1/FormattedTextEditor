#pragma once
#include "user_typedefs.h"
#include "USCharPosition.h"

extern class USPieceTableEntry;

class USLineEntry
{
	public:
		USCharPosition m_oCharPos;
		long m_lMaxTmHeight;
		bool m_bIsValidated;

		USLineEntry();
		USLineEntry(USCharPosition& oCharPos, long uiMaxTmHeight, bool isValidated);
};