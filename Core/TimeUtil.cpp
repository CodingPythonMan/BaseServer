#include "TimeUtil.h"
#include <WS2tcpip.h>
#include <windows.h>

int64_t TimeUtil::GetTick64()
{
	FILETIME fileTime = {};
	int64_t tick = 0;

	GetSystemTimeAsFileTime(&fileTime);

	tick = (static_cast<int64_t>(fileTime.dwHighDateTime) << 32)
		+ static_cast<int64_t>(fileTime.dwLowDateTime);
	tick /= 10000;
	return tick;
}