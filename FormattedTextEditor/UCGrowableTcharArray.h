#pragma once
#include "UCGrowableArray.h"
#include <tchar.h>
class UCGrowableTcharArray : public UCGrowableArray<TCHAR>
{
	public:
		int AppendUntilSpace(unsigned int uiLength);
};

