#pragma once
#include "UCRelinkList.h"

template <class TYPE, class ARG_TYPE = TYPE&>
class UCNonNullList : public UCRelinkList<TYPE, ARG_TYPE>
{
	private:
		TYPE m_typeDefault;

	public:
		UCNonNullList() : UCRelinkList(m_typeDefault) {}

		UCNonNullList(ARG_TYPE typeEmptyListDefault)
			: UCRelinkList(typeEmptyListDefault)
		{
			m_typeDefault = typeEmptyListDefault;
		}

		TYPE& GetNext(POSITION& rpnPosition, bool& rbStartFromExistingTail)
		{
			if (rpnPosition == nullptr)
			{
				if (GetCount() > 0 && rbStartFromExistingTail)
				{
					rbStartFromExistingTail = false;
					return __super::GetTail();
				}

				rpnPosition = __super::AddTail(m_typeDefault);
			}

			return __super::GetNext(rpnPosition);
		}

		TYPE& GetPrev(POSITION& rpnPosition, bool &rbStartFromExistingHead)
		{
			if (rpnPosition == nullptr)
			{
				if (GetCount() > 0 && rbStartFromExistingHead)
				{
					rbStartFromExistingHead = false;
					return __super::GetHead();
				}

				rpnPosition = __super::AddHead(m_typeDefault);
			}

			return __super::GetPrev(rpnPosition);
		}
};
