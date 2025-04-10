#pragma once
#include <WS2tcpip.h>
#include <windows.h>
#include "TickRunner.h"
#include "InternalPacketHandler.h"

class Service : public TickRunner, public InternalPacketHandler
{
public:
	Service() = default;
	virtual ~Service() = default;

protected:
	bool	CreateThread();

	virtual unsigned int	Run();

private:
	static unsigned int WINAPI ThreadProc(void* self);

protected:
	bool	mIsStop = false;


private:
	HANDLE	mThreadHandle = INVALID_HANDLE_VALUE;
};