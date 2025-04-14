#include "IOContext.h"

void IOContext::Ready(EContextType type)
{
	Internal = 0;
	InternalHigh = 0;
	Offset = 0;
	OffsetHigh = 0;
	hEvent = 0;

	mType = type;
}

bool IOContext::Write(void* src, int srcSize)
{
	if (src == nullptr || srcSize <= 0)
	{
		return false;
	}

	return true;
}