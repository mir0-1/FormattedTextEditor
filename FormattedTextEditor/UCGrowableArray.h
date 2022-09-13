#pragma once
template<typename TYPE>
class UCGrowableArray
{
	protected:
		TYPE* m_pTypeBaseAddress;
		TYPE* m_pTypeAppendSource;
		unsigned int m_uiUsedLength;
		unsigned int m_uiTotalLength;
		float m_fGrowthRate;

		void Grow(unsigned int uiMinLength);

	public:
		UCGrowableArray(unsigned int uiInitialLength = 128, float fGrowthRate = 1.2f);

		void SetAppendSource(TYPE* pArrTypeSrc);
		int Append(unsigned int uiLength);
		void Clear();
		TYPE* GetBaseAddress();
		unsigned int GetUsedLength();
		unsigned int GetTotalLength();
		void SetUsedLength(unsigned int uiLength);
};

template<typename TYPE>
inline void UCGrowableArray<TYPE>::Grow(unsigned int uiMinLengthToGrow)
{
	unsigned int uiOldLength = m_uiTotalLength;
	unsigned int uiNewLength = uiOldLength * m_fGrowthRate + uiMinLengthToGrow;
	TYPE* pTypeNewBuffer = new TYPE[uiNewLength];

	for (int i = 0; i < uiOldLength; i++)
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
inline void UCGrowableArray<TYPE>::SetAppendSource(TYPE* pArrTypeSrc)
{
	m_pTypeAppendSource = pArrTypeSrc;
}

template<typename TYPE>
inline int UCGrowableArray<TYPE>::Append(unsigned int uiLength)
{
	if (m_pTypeAppendSource == nullptr || uiLength == 0)
		return -1;

	if (uiLength > m_uiTotalLength)
		Grow(uiMaxLength);

	for (int i = 0;; i < uiLength; i++)
		m_pTypeBaseAddress[m_uiUsedLength++] = *(m_pTypeAppendSource++);

	m_pTypeAppendSource += i;

	return i;
}

template<typename TYPE>
inline void UCGrowableArray<TYPE>::Clear()
{
	m_uiUsedLength = 0;
}

template<typename TYPE>
inline TYPE* UCGrowableArray<TYPE>::GetBaseAddress()
{
	return m_pTypeBaseAddress;
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
inline void UCGrowableArray<TYPE>::SetUsedLength(unsigned int uiLength)
{
	if (uiLength > m_uiTotalLength)
	{
		if (m_pTypeBaseAddress != nullptr)
		{
			delete[] m_pTypeBaseAddress;
			m_pTypeBaseAddress = nullptr;
		}
		m_uiTotalLength = uiLength;
		m_uiUsedLength = uiLength;
		m_pTypeBaseAddress = new TYPE[m_uiTotalLength];
	}
	else if (uiLength < m_uiUsedLength)
		m_uiUsedLength = uiLength;
}
