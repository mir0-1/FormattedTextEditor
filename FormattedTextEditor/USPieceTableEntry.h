#pragma once

enum UEPieceTableEntryType
{
	DISCRETE_ADD,
	DISCRETE_REMOVE,
	ATOMIC_ADD,
	ATOMIC_REMOVE,
	ACTIVE_IMAGE_SPACING,
	INACTIVE_IMAGE,
	TABULATION
};


class USPieceTableEntry
{
	public:
		UEPieceTableEntryType eType;
		TCHAR* pszContent;
		unsigned int uiLength;
};