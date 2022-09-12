#pragma once
#include "USPieceTableEntry.h"
#include "user_typedefs.h"

class USFPieceTableAdd
{
	public:
		USPieceTableEntry oAddedPte;
		USPieceTableEntry* oSelectedPte = nullptr;
		TCHAR* pszThisTracker = nullptr;
		TCHAR* pszPrevTracker = nullptr;
		NODE_PTR pnPrev = nullptr;
		unsigned int* m_puiLengthNotAdded;
		unsigned int uiPrevLength;

		void Reinit(unsigned int* puiLength);
};