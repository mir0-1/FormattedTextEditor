#pragma once
#include "UCGrowableTcharArray.h"
#include <afxwin.h>

class UCStringExtent
{
	private:
		GCP_RESULTS m_oGcp;
		UCGrowableArray<int> m_oWidthArray;
		int m_iMaxExtent;

	public:
		UCGrowableTcharArray m_oString;
		UCGrowableArray<WCHAR> m_oGlyphIndexes;

		UCStringExtent();

		int operator[](int iIndex);

		void Update(CDC* poDc);
		void SetMaxExtent(int iMaxExtent);
};