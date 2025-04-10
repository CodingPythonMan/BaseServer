#include "Service.h"

bool Service::CreateThread()
{
	return false;
}

unsigned int Service::Run()
{
	while (false == mIsStop)
	{
		Update();

		_ProcessInternalPacket();
	}

	return 0;
}

unsigned int __stdcall Service::ThreadProc(void* self)
{
	return 0;
}
