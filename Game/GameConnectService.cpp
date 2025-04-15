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
	_TryListen();

	return CreateThread();
}

void GameConnectService::_TryListen()
{
	if (true == mIsStarted)
	{
		return;
	}

	//if (true == NetworkManager::GetInstance().IsInitialized())
	//{
	//	mIsStarted = NetworkManager::GetInstance().Listen(&mEventSync, mServerInfo.BindAddress, mServerInfo.BindPort);
	//}
}