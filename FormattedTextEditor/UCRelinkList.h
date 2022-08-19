#pragma once
#include "user_typedefs.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCRelinkList : public CList<TYPE, ARG_TYPE>
{
	typename CList<TYPE, ARG_TYPE>::CNode;

	public:
		void Unlink(NODE_PTR pnNode);
		void Relink(NODE_PTR pnNode);
};

template<class TYPE, class ARG_TYPE>
void UCRelinkList<TYPE, ARG_TYPE>::Unlink(NODE_PTR pnNode)
{
	if (posNode == nullptr)
		return;

	CNode* poThisNode = (CNode*)pnNode;
	CNode* poPrev = poThisNode->pPrev;
	CNode* poNext = poThisNode->pNext;

	if (poPrev != nullptr)
		poPrev->pNext = poNext;
	else
		m_pNodeHead = poNext;

	if (poNext != nullptr)
		poNext->pPrev = poPrev;
	else
		m_pNodeTail = poPrev;
}

template<class TYPE, class ARG_TYPE>
void UCRelinkList<TYPE, ARG_TYPE>::Relink(NODE_PTR pnNode)
{
	if (pnNode == nullptr)
		return;

	CNode* poThisNode = (CNode*)pnNode;
	CNode* poPrev = poThisNode->pPrev;
	CNode* poNext = poThisNode->pNext;

	if (poPrev != nullptr)
		poPrev->pNext = poThisNode;
	else
		m_pNodeHead = poThisNode;

	if (poNext != nullptr)
		poNext->pPrev = poThisNode;
	else
		m_pNodeTail = poThisNode;
}