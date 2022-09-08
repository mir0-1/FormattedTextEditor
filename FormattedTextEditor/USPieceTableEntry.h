#pragma once

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
		TCHAR* pszContent = nullptr;
		unsigned int uiLength = 0;
};