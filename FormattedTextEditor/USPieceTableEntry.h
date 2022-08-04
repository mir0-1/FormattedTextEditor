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
		UEPieceTableEntryType eType;
		TCHAR* pszContent;
		unsigned int uiLength;
};