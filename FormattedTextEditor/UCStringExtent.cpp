#include "UCStringExtent.h"

UCStringExtent::UCStringExtent()
{
	ZeroMemory(&m_oGcp, sizeof(GCP_RESULTS));
	m_oGcp.lStructSize = sizeof(GCP_RESULTS);
}

int UCStringExtent::operator[](int iIndex)
{
	int iAcculumatedWidth = -1;
	
	if (iIndex >= 0)
	{
		for (int i = 0; i <= iIndex; i++)
			iAcculumatedWidth += m_oWidthArray[i];
	}
	else
	{
		iIndex = -iIndex;
		for (int i = 0; i <= m_oWidthArray.GetUsedLength() - iIndex; i++)
			iAcculumatedWidth += m_oWidthArray[i];
	}

	return iAcculumatedWidth;
}

void UCStringExtent::Update(CDC* poDc)
{
	if (poDc == nullptr)
		return;

	m_oWidthArray.Clear();
	m_oWidthArray.GrowToFit(m_oString.GetUsedLength());
	m_oGcp.lpDx = m_oWidthArray.GetBaseAddress();
	m_oGcp.nGlyphs = m_oWidthArray.GetTotalLength();
	
	GetCharacterPlacement(poDc->GetSafeHdc(), m_oString.GetBaseAddress(), m_oString.GetUsedLength(), m_iMaxExtent, &m_oGcp, GCP_MAXEXTENT);

	m_oString.SetUsedLength(m_oGcp.nMaxFit);
	m_oWidthArray.SetUsedLength(m_oGcp.nMaxFit);
}

void UCStringExtent::SetMaxExtent(int iMaxExtent)
{
	m_iMaxExtent = iMaxExtent;
}
