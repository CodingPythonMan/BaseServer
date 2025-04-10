#include "NetworkEvent.h"

void NetworkEvent::SetTimeoutTick(int tick)
{
	if (DEFAULT_TIME_MS < tick)
	{
		mTimeoutTick = tick;
	}
}

int NetworkEvent::GetTimeoutTick()
{
	return mTimeoutTick;
}