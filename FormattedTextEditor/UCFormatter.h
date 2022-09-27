#pragma once
#include "UCSplitMerger.h"

class UCFormatter
{
	private:
		UCSplitMerger& m_roSplitMerger;

	public:
		UCFormatter(UCSplitMerger& roSplitMerger);

		void SetFont(const USCharPosition& roStart, const USCharPosition& roEnd, TCHAR* ptszStrFontName, unsigned int uiFontSize);
};

