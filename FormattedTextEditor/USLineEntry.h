#pragma once
#include <afxtempl.h>

typedef POSITION NODE_PTR;

struct USLineEntry
{
	NODE_PTR pnNode;
	unsigned int uiCharOffset;
	long uiMaxTmHeight;
	bool bIsValidated;
};