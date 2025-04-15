#include "MiniDump.h"
#include "LogServer.h"
#include <iostream>

int main()
{
	MiniDump::SetExceptionHandler();

	LogServer server;
	if (false == server.Initialize())
	{
		// 시간 될 때, Poco Log 로 수정해볼 것
		printf("Log Server initialize failed\n");
		return -1;
	}

	if (false == server.Run())
	{
		printf("Log Server run failed\n");
		return -1;
	}

	return 0;
}