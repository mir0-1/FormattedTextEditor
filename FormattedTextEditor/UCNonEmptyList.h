#pragma once
#include <afxtempl.h>

template <class TYPE, class ARG_TYPE = TYPE&>
class UCInitialNonEmptyList : public CList<TYPE, ARG_TYPE>
{
	TYPE m_typeFirstElement;

	UCNonEmptyList(int iBlockSize = 10)
		: CList(iBlockSize)
	{
		AddHead(m_typeFirstElement);
	}
};

