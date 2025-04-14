#include "Service.h"

bool Service::CreateThread()
{
	mThreadHandle = reinterpret_cast<HANDLE>(::_beginthreadex(nullptr, 0, Work, this, 0, nullptr));
	return false;
}

unsigned int Service::Run()
{
	while (false == mIsStop)
	{
		Update();

		_ProcessPacket();
		_ProcessInternalPacket();
	}

	return 0;
}

unsigned int __stdcall Service::Work(void* self)
{
	return static_cast<Service*>(self)->Run();
}
