#include "LogServer.h"
#include "Packet.h"
#include "LogService.h"

bool LogServer::Initialize()
{
	// DB ������ �� �ְԲ� �� �۾��ؾ��Ѵ�.
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