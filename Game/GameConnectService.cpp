#include "GameConnectService.h"
#include "ConfigParser.h"
#include "ServerConnectInfo.h"
#include "NetworkManager.h"

bool GameConnectService::Initialize()
{
	mServerInfo = ConfigParser::GetInstance().GetServerInfo();

	return true;
}

bool GameConnectService::Start()
{
	return CreateThread();
}

void GameConnectService::_TryConnect()
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