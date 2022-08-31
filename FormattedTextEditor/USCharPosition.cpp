#include "USCharPosition.h"

USCharPosition::USCharPosition()
{
	m_pnCurrentNode = nullptr;
	m_uiCharOffset = 0;
}

USCharPosition::USCharPosition(NODE_PTR pnCurrentNode, unsigned int uiCharOffset)
{
	m_pnCurrentNode = pnCurrentNode;
	m_uiCharOffset = uiCharOffset;
}
