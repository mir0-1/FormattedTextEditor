#pragma once
#include "user_typedefs.h"

class USCharPosition
{
	public:
		NODE_PTR m_pnCurrentNode;
		unsigned int m_uiCharOffset;

		USCharPosition();
		USCharPosition(NODE_PTR pnCurrentNode, unsigned int uiCharOffset);
};