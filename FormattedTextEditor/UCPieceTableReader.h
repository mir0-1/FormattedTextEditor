#pragma once
#include "UCAbstractPieceTable.h"
#include "USPieceTableEntry.h"

class UCPieceTableReader : virtual public UCAbstractPieceTable
{
	public:
		void GetRelativeCharPos(USCharPosition* poStart, USCharPosition* poResult, unsigned int uiLength);
		const USPieceTableEntry& UCPieceTableReader::GetHead() const;
		const USPieceTableEntry& UCPieceTableReader::GetTail() const;
		const USPieceTableEntry& UCPieceTableReader::GetAt(NODE_PTR pnNode) const;
		const USPieceTableEntry& UCPieceTableReader::GetNext(NODE_PTR& pnNode) const;
		const USPieceTableEntry& UCPieceTableReader::GetPrev(NODE_PTR& pnNode) const;
		void UCPieceTableReader::Dump(CDumpContext& oDumpContext) const;
		NODE_PTR UCPieceTableReader::Find(USPieceTableEntry& typeSearch, NODE_PTR pnStartAfter = nullptr) const;
		NODE_PTR UCPieceTableReader::FindIndex(INT_PTR iIndex) const;
		INT_PTR UCPieceTableReader::GetCount() const;
		NODE_PTR UCPieceTableReader::GetHeadPosition() const;
		CRuntimeClass* UCPieceTableReader::GetRuntimeClass() const;
		INT_PTR UCPieceTableReader::GetSize() const;
		NODE_PTR UCPieceTableReader::GetTailPosition() const;
		CRuntimeClass* UCPieceTableReader::GetThisClass();
		BOOL UCPieceTableReader::IsEmpty() const;
		BOOL UCPieceTableReader::IsKindOf(CRuntimeClass* poClass) const;
		BOOL UCPieceTableReader::IsSerializable() const;
};

