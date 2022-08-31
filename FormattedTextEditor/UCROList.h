#pragma once
#include "user_typedefs.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCROList : public CList<TYPE, ARG_TYPE>
{
	public:
		const TYPE& GetHead(NODE_PTR pnNode) const
		{
			return CList::GetHead(pnNode);
		}

		const TYPE& GetTail(NODE_PTR pnNode) const
		{
			return CList::GetTail(pnNode);
		}

		const TYPE& GetAt(NODE_PTR pnNode) const
		{
			return CList::GetAt(pnNode);
		}

		const TYPE& GetNext(NODE_PTR pnNode) const
		{
			return CList::GetNext(pnNode);
		}

		const TYPE& GetPrev(NODE_PTR pnNode) const
		{
			return CList::GetPrev(pnNode);
		}

};

