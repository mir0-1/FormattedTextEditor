#pragma once
#include "user_typedefs.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCRelinkList : public CList<TYPE, ARG_TYPE>
{
	public:
		void UCRelinkList<TYPE, ARG_TYPE>::Unlink(NODE_PTR pnStartNode, NODE_PTR pnEndNode)
		{
			if (pnNode == nullptr || pnStartNode == nullptr || pnEndNode == nullptr)
				return;

			CNode* poStartNode = (CNode*)pnStartNode;
			CNode* poEndNode = (CNode*)pnEndNode;
			CNode* poStartNodePrev = (CNode*)poStartNode->pPrev;
			CNode* poEndNodeNext = (CNode*)poEndNode->pNext;

			if (poStartNodePrev && poEndNodeNext)
			{
				poStartNodePrev->pNext = poEndNodeNext;
				poEndNodeNext->pPrev = poStartNodePrev;
			}
		}

		void UCRelinkList<TYPE, ARG_TYPE>::Relink(NODE_PTR pnStartNode, NODE_PTR pnEndNode)
		{
			if (pnNode == nullptr || pnStartNode == nullptr || pnEndNode == nullptr)
				return;

			CNode* poStartNode = (CNode*)pnStartNode;
			CNode* poEndNode = (CNode*)pnEndNode;
			CNode* poStartNodePrev = (CNode*)poStartNode->pPrev;
			CNode* poEndNodeNext = (CNode*)poEndNode->pNext;

			if (poStartNodePrev && poEndNodeNext)
			{
				poStartNodePrev->pNext = pnStartNode;
				poEndNodeNext->pPrev = pnEndNode;
			}
		}
};