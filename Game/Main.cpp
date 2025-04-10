#include "MiniDump.h"
#include "GameServer.h"
#include <iostream>

int main()
{
	MiniDump::SetExceptionHandler();

	GameServer server;
	if (false == server.Initialize())
	{
		// 시간 될 때, Poco Log 로 수정해볼 것
		printf("Game Server initialize failed\n");
		return -1;
	}

	if (false == server.Run())
	{
		printf("Game Server run failed\n");
		return -1;
	}

	return 0;
}