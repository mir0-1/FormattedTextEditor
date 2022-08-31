#pragma once
#include "user_typedefs.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCRelinkList : public CList<TYPE, ARG_TYPE>
{
	protected:
		using CList<TYPE, ARG_TYPE>::CNode;

	public:
		void UCRelinkList<TYPE, ARG_TYPE>::Unlink(NODE_PTR pnNode)
		{
			if (posNode == nullptr || posNode == m_pNodeHead || posNode == m_pNodeTail)
				return;

			CNode* poThisNode = (CNode*)pnNode;
			CNode* poPrev = poThisNode->pPrev;
			CNode* poNext = poThisNode->pNext;

			if (poPrev != nullptr)
				poPrev->pNext = poNext;

			if (poNext != nullptr)
				poNext->pPrev = poPrev;
		}

		void UCRelinkList<TYPE, ARG_TYPE>::Relink(NODE_PTR pnNode)
		{
			if (pnNode == nullptr || posNode == m_pNodeHead || posNode == m_pNodeTail)
				return;

			CNode* poThisNode = (CNode*)pnNode;
			CNode* poPrev = poThisNode->pPrev;
			CNode* poNext = poThisNode->pNext;

			if (poPrev != nullptr)
				poPrev->pNext = poThisNode;

			if (poNext != nullptr)
				poNext->pPrev = poThisNode;
		}
};