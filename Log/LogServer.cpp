#include "LogServer.h"
#include "Packet.h"
#include "LogService.h"

bool LogServer::Initialize()
{
	// DB 연결할 수 있게끔 좀 작업해야한다.
	return true;
}

bool LogServer::Run()
{
	Packet::ReservePool(1000);

	if (false == LogService::GetInstance().Start())
	{
		return false;
	}

	Sleep(INFINITE);

	return true;
}