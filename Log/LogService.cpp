#include "LogService.h"
#include "NetworkManager.h"
#include "ConfigParser.h"
#include "ServerConnectInfo.h"

bool LogService::Initialize()
{
	return true;
}

bool LogService::Start()
{
	return CreateThread();
}
