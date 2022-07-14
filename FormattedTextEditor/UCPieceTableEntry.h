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


class UCPieceTableEntry
{
	private:
		UEPieceTableEntryType eType;
		void* pvContent;
		unsigned int iLength;

	friend class UCPieceTableManager;
};