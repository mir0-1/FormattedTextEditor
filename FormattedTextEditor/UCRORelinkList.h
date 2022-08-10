#pragma once
#include "UCRelinkList.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCRORelinkList : public UCRelinkList<TYPE, ARG_TYPE>
{
	protected:
		using UCRelinkList::AddHead;
		using UCRelinkList::AddTail;
		using UCRelinkList::InsertAfter;
		using UCRelinkList::InsertBefore;
		using UCRelinkList::Relink;
		using UCRelinkList::Unlink;
};

