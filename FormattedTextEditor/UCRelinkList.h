#pragma once
#include <afxtempl.h>

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCRelinkList : public CList<TYPE, ARG_TYPE>
{
	typename CList<TYPE, ARG_TYPE>::CNode;

	public:
		void Unlink(POSITION posNode);
		void Relink(POSITION posNode);
};

template<class TYPE, class ARG_TYPE>
void UCRelinkList<TYPE, ARG_TYPE>::Unlink(POSITION posNode)
{
	if (posNode == nullptr)
		return;

	CNode* poThisNode = (CNode*)posNode;
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
void UCRelinkList<TYPE, ARG_TYPE>::Relink(POSITION posNode)
{
	if (posNode == nullptr)
		return;

	CNode* poThisNode = (CNode*)posNode;
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