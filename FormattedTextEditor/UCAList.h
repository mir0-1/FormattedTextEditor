#pragma once
#include <afxwin.h>
#include "user_typedefs.h"
template<class TYPE, class ARG_TYPE = TYPE&>
class UCAList
{
	protected:
		CList<TYPE, ARG_TYPE>& m_roCompositeList;

	public:
		void Dump(CDumpContext& oDumpContext) const
		{
			return m_roCompositeList.Dump(oDumpContext);
		}

		NODE_PTR Find(ARG_TYPE typeSearch, NODE_PTR pnStartAfter = nullptr) const
		{
			return m_roCompositeList.Find(typeSearch, pnStartAfter);
		}

		NODE_PTR FindIndex(INT_PTR iIndex) const
		{
			return m_roCompositeList.FindIndex(iIndex);
		}

		INT_PTR GetCount() const
		{
			return m_roCompositeList.GetCount();
		}

		NODE_PTR GetHeadPosition() const
		{
			return m_roCompositeList.GetHeadPosition();
		}

		CRuntimeClass GetRuntimeClass() const
		{
			return m_roCompositeList.GetRuntimeClass();
		}

		INT_PTR GetSize() const
		{
			return m_roCompositeList.GetSize();
		}

		NODE_PTR GetTailPosition() const
		{
			return m_roCompositeList.GetTailPosition();
		}

		CRuntimeClass* GetThisClass()
		{
			return m_roCompositeList.GetThisClass();
		}

		BOOL IsEmpty() const
		{
			return m_roCompositeList.IsEmpty();
		}

		BOOL IsKindOf(CRuntimeClass* poClass) const
		{
			return m_oCompoisiteList.IsKindOf(poClass);
		}

		BOOL IsSerializable() const
		{
			return m_roCompositeList.IsSerializable();
		}
			
};

