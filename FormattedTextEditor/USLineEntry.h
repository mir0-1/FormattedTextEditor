#pragma once
#include <afxtempl.h>

struct USLineEntry
{
	POSITION posNode;
	unsigned int uiCharOffset;
	long uiMaxTmHeight;
	bool bIsValidated;
};