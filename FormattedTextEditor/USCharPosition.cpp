#include "USCharPosition.h"

USCharPosition::USCharPosition()
{
	m_pnNode = nullptr;
	m_uiCharOffset = 0;
}

USCharPosition::USCharPosition(NODE_PTR pnCurrentNode, unsigned int uiCharOffset)
{
	m_pnNode = pnCurrentNode;
	m_uiCharOffset = uiCharOffset;
}
