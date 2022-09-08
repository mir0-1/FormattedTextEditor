#pragma once
#include "user_typedefs.h"

template<class TYPE, class ARG_TYPE = const TYPE&>
class UCReadOnlyList
{
	private:
		CList<TYPE, ARG_TYPE> &m_oCompositeList;

	public:
		UCReadOnlyList(CList<TYPE, ARG_TYPE> &roList) : m_oCompositeList(roList) {}

		const TYPE& GetHead() const
		{
			return m_oCompositeList.GetHead();
		}

		const TYPE& GetTail() const
		{
			return m_oCompositeList.GetTail();
		}

		const TYPE& GetAt(NODE_PTR pnNode) const
		{
			return m_oCompositeList.GetAt(pnNode);
		}

		const TYPE& GetNext(NODE_PTR& pnNode) const
		{
			return m_oCompositeList.GetNext(pnNode);
		}

		const TYPE& GetPrev(NODE_PTR& pnNode) const
		{
			return m_oCompositeList.GetPrev(pnNode);
		}

		void Dump(CDumpContext& oDumpContext) const
		{
			return m_oCompositeList.Dump(oDumpContext);
		}

		NODE_PTR Find(ARG_TYPE typeSearch, NODE_PTR pnStartAfter = nullptr) const
		{
			return m_oCompositeList.Find(typeSearch, pnStartAfter);
		}

		NODE_PTR FindIndex(INT_PTR iIndex) const
		{
			return m_oCompositeList.FindIndex(iIndex);
		}

		INT_PTR GetCount() const
		{
			return m_oCompositeList.GetCount();
		}

		NODE_PTR GetHeadPosition() const
		{
			return m_oCompositeList.GetHeadPosition();
		}

		CRuntimeClass GetRuntimeClass() const
		{
			return m_oCompositeList.GetRuntimeClass();
		}

		INT_PTR GetSize() const
		{
			return m_oCompositeList.GetSize();
		}

		NODE_PTR GetTailPosition() const
		{
			return m_oCompositeList.GetTailPosition();
		}

		CRuntimeClass* GetThisClass()
		{
			return m_oCompositeList.GetThisClass();
		}

		BOOL IsEmpty() const
		{
			return m_oCompositeList.IsEmpty();
		}

		BOOL IsKindOf(CRuntimeClass* poClass) const
		{
			return m_oCompoisiteList.IsKindOf(poClass);
		}

		BOOL IsSerializable() const
		{
			return m_oCompositeList.IsSerializable();
		}
};

