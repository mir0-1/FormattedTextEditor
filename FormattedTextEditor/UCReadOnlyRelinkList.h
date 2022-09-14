#pragma once
#include "user_typedefs.h"
#include "UCRelinkList.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCReadOnlyRelinkList
{
private:
	UCRelinkList<TYPE, ARG_TYPE>& m_oCompositeList;

public:
	UCReadOnlyRelinkList(CList<TYPE, ARG_TYPE>& roList) : m_oCompositeList(roList) {}


};