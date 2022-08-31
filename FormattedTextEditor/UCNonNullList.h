#pragma once
#include "UCRelinkList.h"

template <class TYPE, class ARG_TYPE = TYPE&>
class UCNonNullList : public UCRelinkList<TYPE, ARG_TYPE>
{
	private:
		TYPE m_typeEmptyListDefault;
		TYPE m_typeNextDefault;
		TYPE m_typePrevDefault;

	public:
		UCNonNullList() {}

		UCNonNullList(ARG_TYPE typeEmptyListDefault)
		{
			m_typeEmptyListDefault = typeEmptyListDefault;
		}

		UCNonNullList(ARG_TYPE typeEmptyListDefault, ARG_TYPE typeNextDefault, ARG_TYPE typePrevDefault)
			: UCNonNullList(typeEmptyListDefault)
		{
			m_typeNextDefault = typeNextDefault;
			m_typePrevDefault = typePrevDefault;
		}

		TYPE& GetNext(POSITION& pnPosition)
		{
			if (GetCount() == 0)
				pnPosition = UCRelinkList<TYPE, ARG_TYPE>::AddTail(m_typeEmptyListDefault);

			else if (pnPosition == nullptr)
			{
				pnPosition = UCRelinkList<TYPE, ARG_TYPE>::AddTail(m_typeNextDefault);
			}

			return UCRelinkList<TYPE, ARG_TYPE>::GetNext(pnPosition);
		}

		TYPE& GetPrev(POSITION& pnPosition)
		{
			if (GetCount() == 0)
				pnPosition = UCRelinkList<TYPE, ARG_TYPE>::AddHead(m_typeEmptyListDefault);

			if (pnPosition == nullptr)
			{
				pnPosition = UCRelinkList<TYPE, ARG_TYPE>::AddHead(m_typePrevDefault);
			}

			return UCRelinkList<TYPE, ARG_TYPE>::GetPrev(pnPosition);
		}
		
		TYPE& getEmptyListDefault()
		{
			return m_typeEmptyListDefault;
		}

		TYPE& getNextDefault()
		{
			return m_typeNextDefault;
		}

		TYPE& getPrevDefault()
		{
			return m_typePrevDefault;
		}
};
