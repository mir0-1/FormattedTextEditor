#pragma once
#include "USFontInfo.h"
#include "user_typedefs.h"

class USPieceTableEntry
{
	public:
		USFontInfo* m_poFontInfo = nullptr;
		TCHAR* m_ptszContent = nullptr;
		unsigned int m_uiLength = 0;
		NODE_PTR m_pnLine = nullptr;
};