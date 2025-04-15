#include "LogService.h"
#include "NetworkManager.h"
#include "ConfigParser.h"
#include "ServerConnectInfo.h"

bool LogService::Initialize()
{
	// Listen 후에 Packet 을 받아야 한다.
	auto& connectServerInfo = ConfigParser::GetInstance().GetConnectInfo();
	ServerConnectInfo* connectInfo = new ServerConnectInfo;
	connectInfo->mHostIP = connectServerInfo.Address;
	connectInfo->mHostPort = connectServerInfo.Port;
	connectInfo->mServerID = connectServerInfo.ServerID;

	mConnectInfoList[connectInfo->mServerID] = connectInfo;

	return true;
}

bool LogService::Start()
{
	RegisterRunner(CONNECT_CHECK_TICK, std::bind(&LogService::_TryConnect, this));

	return CreateThread();
}

void LogService::_TryConnect()
{
	for (auto [serverID, connectInfo] : mConnectInfoList)
	{
		printf("Try Connect....\n");
		if (true == connectInfo->IsConnected())
		{
			continue;
		}

		if (true == connectInfo->IsConnecting())
		{
			continue;
		}

		connectInfo->SetState(EServerConnectState::Connecting);

		int hostID = 0;
		if (true == NetworkManager::GetInstance().Connect(&mEvent, connectInfo->mHostIP, connectInfo->mHostPort, OUT hostID))
		{
			connectInfo->SetHostID(hostID);
		}
	}
}