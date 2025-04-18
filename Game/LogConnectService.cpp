#include "LogConnectService.h"
#include "ConfigParser.h"
#include "ServerConnectInfo.h"
#include "NetworkManager.h"

bool LogConnectService::Initialize()
{
	auto serverInfo = ConfigParser::GetInstance().GetServerInfo();

	mServerConnectInfo = new ServerConnectInfo();
	mServerConnectInfo->mHostIP = serverInfo.BindAddress;
	mServerConnectInfo->mHostPort = serverInfo.BindPort;
	mServerConnectInfo->mServerID = serverInfo.ServerID;

	return true;
}

bool LogConnectService::Start()
{
	RegisterRunner(CHECK_RECONNECT_TICK, std::bind(&LogConnectService::_TryConnect, this));

	return CreateThread();
}

void LogConnectService::_TryConnect()
{
	printf("Try Connect....\n");
	if (true == mServerConnectInfo->IsConnected())
	{
		return;
	}

	if (true == mServerConnectInfo->IsConnecting())
	{
		return;
	}

	mServerConnectInfo->SetState(EServerConnectState::Connecting);

	int hostID = 0;
	if (true == NetworkManager::GetInstance().Connect(&mEvent, mServerConnectInfo->mHostIP, mServerConnectInfo->mHostPort, OUT hostID))
	{
		mServerConnectInfo->SetHostID(hostID);
	}
}