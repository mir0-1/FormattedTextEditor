#pragma once
#include "UCSplitMerger.h"

class UCFormatter
{
	private:
		UCSplitMerger& m_roSplitMerger;

	public:
		UCFormatter(UCSplitMerger& roSplitMerger);

		void SetFont(USCharPosition& roStart, USCharPosition& roEnd, TCHAR* ptszStrFontName, unsigned int uiFontSize);
};

