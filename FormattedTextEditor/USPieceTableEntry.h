#pragma once
#include "USFontInfo.h"

enum UEPieceTableEntryType
{
	DISCRETE_ADD,
	ATOMIC_ADD,
	IMAGE_SPACING,
	TABULATION
};


class USPieceTableEntry
{
	public:
		USFontInfo* m_poFontInfo = nullptr;
		TCHAR* m_ptszContent = nullptr;
		unsigned int m_uiLength = 0;
};