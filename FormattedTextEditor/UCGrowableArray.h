#pragma once
template<typename TYPE>
class UCGrowableArray
{
	protected:
		TYPE* m_pTypeBaseAddress;
		TYPE* m_pTypeAppendSource;
		unsigned int m_uiUsedLength;
		unsigned int m_uiTotalLength;
		unsigned int m_uiPrevUsedLength;
		unsigned int m_uiPrevTotalLength;
		unsigned int m_uiPrevAppendLength;
		float m_fGrowthRate;

		void Grow(unsigned int uiMinLength);

	public:
		UCGrowableArray(unsigned int uiInitialLength = 128, float fGrowthRate = 1.2f);

		const TYPE& operator[](int iIndex) const;

		void SetAppendSource(TYPE* pArrTypeSrc);
		int Append(unsigned int uiLength);
		void Clear();
		TYPE* GetBaseAddress();
		TYPE* GetAppendAddress();
		TYPE* GetPrevAppendAddress();
		unsigned int GetUsedLength();
		unsigned int GetTotalLength();
		unsigned int GetUnusedLength();
		unsigned int GetPrevAppendLength();
		void GrowToFit(unsigned int uiLength);
		void SetUsedLength(unsigned int uiLength);
};

template<typename TYPE>
inline void UCGrowableArray<TYPE>::Grow(unsigned int uiMinLengthToGrow)
{
	m_uiPrevTotalLength = m_uiTotalLength;
	unsigned int uiNewLength = m_uiPrevTotalLength * m_fGrowthRate + uiMinLengthToGrow;
	TYPE* pTypeNewBuffer = new TYPE[uiNewLength];

	for (int i = 0; i < m_uiPrevTotalLength; i++)
		pTypeNewBuffer[i] = m_pTypeBaseAddress[i];

	delete[] m_pTypeBaseAddress;
	m_pTypeBaseAddress = pTypeNewBuffer;
	m_uiTotalLength = uiNewLength;
}

template<typename TYPE>
inline UCGrowableArray<TYPE>::UCGrowableArray(unsigned int uiInitialLength, float fGrowthRate)
{
	m_uiTotalLength = uiInitialLength;
	m_pTypeBaseAddress = new TYPE[m_uiTotalLength];
	m_fGrowthRate = fGrowthRate;
}

template<typename TYPE>
inline const TYPE& UCGrowableArray<TYPE>::operator[](int iIndex) const
{
	return m_pTypeBaseAddress[iIndex];
}

template<typename TYPE>
inline void UCGrowableArray<TYPE>::SetAppendSource(TYPE* pArrTypeSrc)
{
	m_pTypeAppendSource = pArrTypeSrc;
}

template<typename TYPE>
inline int UCGrowableArray<TYPE>::Append(unsigned int uiLength)
{
	if (m_pTypeAppendSource == nullptr || uiLength == 0)
		return -1;

	if (uiLength >= m_uiTotalLength)
		Grow(uiLength);

	m_uiPrevUsedLength = m_uiUsedLength;

	unsigned int i;
	for (i = 0; i < uiLength; i++)
		m_pTypeBaseAddress[m_uiUsedLength++] = *(m_pTypeAppendSource++);

	m_pTypeAppendSource += i;
	m_uiPrevAppendLength = uiLength;

	return i;
}

template<typename TYPE>
inline void UCGrowableArray<TYPE>::Clear()
{
	GrowToFit(0);
}

template<typename TYPE>
inline TYPE* UCGrowableArray<TYPE>::GetBaseAddress()
{
	return m_pTypeBaseAddress;
}

template<typename TYPE>
inline TYPE* UCGrowableArray<TYPE>::GetAppendAddress()
{
	return m_pTypeBaseAddress + m_uiUsedLength;
}

template<typename TYPE>
inline TYPE* UCGrowableArray<TYPE>::GetPrevAppendAddress()
{
	return m_pTypeBaseAddress + m_uiPrevUsedLength;
}

template<typename TYPE>
inline unsigned int UCGrowableArray<TYPE>::GetUsedLength()
{
	return m_uiUsedLength;
}

template<typename TYPE>
inline unsigned int UCGrowableArray<TYPE>::GetTotalLength()
{
	return m_uiTotalLength;
}

template<typename TYPE>
inline unsigned int UCGrowableArray<TYPE>::GetUnusedLength()
{
	return m_uiTotalLength - m_uiUsedLength;
}

template<typename TYPE>
inline unsigned int UCGrowableArray<TYPE>::GetPrevAppendLength()
{
	return m_uiPrevAppendLength;
}

template<typename TYPE>
inline void UCGrowableArray<TYPE>::GrowToFit(unsigned int uiLength)
{
	if (uiLength > m_uiTotalLength)
		Grow(uiLength);
}

template<typename TYPE>
inline void UCGrowableArray<TYPE>::SetUsedLength(unsigned int uiLength)
{
	if (uiLength < m_uiTotalLength)
	{
		m_uiPrevUsedLength = m_uiUsedLength;
		m_uiUsedLength = uiLength;
	}
}
