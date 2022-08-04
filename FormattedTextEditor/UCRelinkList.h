#pragma once
#include <afxtempl.h>

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCRelinkList : public CList<TYPE, ARG_TYPE>
{
	public:
		void UnlinkNode(POSITION posNode);
		void LinkNode(POSITION posNode, POSITION posPrev, POSITION posNext);
};

template<class TYPE, class ARG_TYPE>
void UCRelinkList<TYPE, ARG_TYPE>::UnlinkNode(POSITION posNode)
{
	if (posNode == nullptr)
		return;

	CNode* poThisNode = (CNode*)posNode;

	if (poThisNode->pPrev != nullptr)
		poThisNode->pPrev->pNext = poThisNode->pNext;

	if (poThisNode->pNext != nullptr)
		poThisNode->pNext->pPrev = poThisNode->pPrev;
}

template<class TYPE, class ARG_TYPE>
void UCRelinkList<TYPE, ARG_TYPE>::LinkNode(POSITION posNode, POSITION posPrev, POSITION posNext)
{
	if (posNode == nullptr)
		return;

	CNode* poThisNode = (CNode*)posNode;
	CNode* poPrev = (CNode*)posPrev;
	CNode* poNext = (CNode*)posNext;

	poThisNode->pPrev = poPrev;
	poThisNode->pNext = poNext;

	if (poPrev != nullptr)
		poPrev->pNext = poThisNode;

	if (poNext != nullptr)
		poNext->poPrev = poThisNode;
}