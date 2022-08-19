#pragma once
#include "UCRelinkList.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCRORelinkList : protected UCRelinkList<TYPE, ARG_TYPE>
{
	public:
		using UCRelinkList::GetHead;
		using UCRelinkList::GetHeadPosition;
		using UCRelinkList::GetTail;
		using UCRelinkList::GetTailPosition;
		using UCRelinkList::Find;
		using UCRelinkList::FindIndex;
		using UCRelinkList::GetAt;
		using UCRelinkList::GetCount;
		using UCRelinkList::GetNext;
		using UCRelinkList::GetPrev;
		using UCRelinkList::GetSize;
};

