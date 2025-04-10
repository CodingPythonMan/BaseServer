#include "Environment.h"

bool Environment::SetMaxConnection(const int count)
{
	if (count <= 0
		|| count >= 0x10000)
	{
		return false;
	}

	mMaxConnectionCount = count;
	return true;
}