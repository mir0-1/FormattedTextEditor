#include "UCPieceTableReader.h"

void UCPieceTableReader::GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength)
{
	NODE_PTR pnCurrent;
	NODE_PTR pnPrev = nullptr;
	const USPieceTableEntry* poEntry = nullptr;
	unsigned int uiInitialCharOffset;

	if (poResult == nullptr)
		return;

	if (poStart == nullptr)
	{
		pnCurrent = m_oPieceTable.GetHeadPosition();
		uiInitialCharOffset = 0;
	}
	else
	{
		pnCurrent = poStart->m_pnNode;
		uiInitialCharOffset = poStart->m_uiCharOffset;
	}

	while (pnCurrent != nullptr)
	{
		if (pnPrev != nullptr)
			uiLength -= poEntry->m_uiLength;

		pnPrev = pnCurrent;
		poEntry = &m_oPieceTable.GetNext(pnCurrent);

		if (uiLength <= poEntry->m_uiLength - uiInitialCharOffset)
			break;

		if (uiInitialCharOffset)
			uiInitialCharOffset = 0;
	}

	if (uiLength > poEntry->m_uiLength)
		uiLength = poEntry->m_uiLength;

	poResult->m_pnNode = pnPrev;
	poResult->m_uiCharOffset = uiLength;
}

const USPieceTableEntry& UCPieceTableReader::GetHead() const
{
	return m_oPieceTable.GetHead();
}

const USPieceTableEntry& UCPieceTableReader::GetTail() const
{
	return m_oPieceTable.GetTail();
}

const USPieceTableEntry& UCPieceTableReader::GetAt(NODE_PTR pnNode) const
{
	return m_oPieceTable.GetAt(pnNode);
}

const USPieceTableEntry& UCPieceTableReader::GetNext(NODE_PTR& pnNode) const
{
	return m_oPieceTable.GetNext(pnNode);
}

const USPieceTableEntry& UCPieceTableReader::GetPrev(NODE_PTR& pnNode) const
{
	return m_oPieceTable.GetPrev(pnNode);
}

void UCPieceTableReader::Dump(CDumpContext& oDumpContext) const
{
	return m_oPieceTable.Dump(oDumpContext);
}

NODE_PTR UCPieceTableReader::Find(USPieceTableEntry& typeSearch, NODE_PTR pnStartAfter = nullptr) const
{
	return m_oPieceTable.Find(typeSearch, pnStartAfter);
}

NODE_PTR UCPieceTableReader::FindIndex(INT_PTR iIndex) const
{
	return m_oPieceTable.FindIndex(iIndex);
}

INT_PTR UCPieceTableReader::GetCount() const
{
	return m_oPieceTable.GetCount();
}

NODE_PTR UCPieceTableReader::GetHeadPosition() const
{
	return m_oPieceTable.GetHeadPosition();
}

CRuntimeClass* UCPieceTableReader::GetRuntimeClass() const
{
	return m_oPieceTable.GetRuntimeClass();
}

INT_PTR UCPieceTableReader::GetSize() const
{
	return m_oPieceTable.GetSize();
}

NODE_PTR UCPieceTableReader::GetTailPosition() const
{
	return m_oPieceTable.GetTailPosition();
}

CRuntimeClass* UCPieceTableReader::GetThisClass()
{
	return m_oPieceTable.GetThisClass();
}

BOOL UCPieceTableReader::IsEmpty() const
{
	return m_oPieceTable.IsEmpty();
}

BOOL UCPieceTableReader::IsKindOf(CRuntimeClass* poClass) const
{
	return m_oPieceTable.IsKindOf(poClass);
}

BOOL UCPieceTableReader::IsSerializable() const
{
	return m_oPieceTable.IsSerializable();
}
