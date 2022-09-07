#pragma once
#include "user_typedefs.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCROList : private CList<TYPE, ARG_TYPE>
{
	public:
		const TYPE& GetHead() const
		{
			return CList::GetHead();
		}

		const TYPE& GetTail() const
		{
			return CList::GetTail();
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

		using CList::Dump;
		using CList::Find;
		using CList::FindIndex;
		using CList::GetCount;
		using CList::GetHeadPosition;
		using CList::GetNext;
		using CList::GetPrev;
		using CList::GetRuntimeClass;
		using CList::GetSize;
		using CList::GetTailPosition;
		using CList::GetThisClass;
		using CList::IsEmpty;
		using CList::IsKindOf;
		using CList::IsSerializable;
};

