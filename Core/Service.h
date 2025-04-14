#pragma once
#include <WS2tcpip.h>
#include <windows.h>
#include "TickRunner.h"
#include "InternalPacketHandler.h"
#include "PacketHandler.h"

class Service : public TickRunner, public PacketHandler, public InternalPacketHandler
{
public:
	Service() = default;
	virtual ~Service() = default;

protected:
	bool	CreateThread();

	virtual unsigned int	Run();

private:
	static unsigned int WINAPI Work(void* self);

protected:
	bool	mIsStop = false;


private:
	HANDLE	mThreadHandle = INVALID_HANDLE_VALUE;
};