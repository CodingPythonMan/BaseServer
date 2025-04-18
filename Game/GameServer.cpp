#include "GameServer.h"
#include "ConfigParser.h"
#include "Environment.h"
#include "Packet.h"
#include "GameService.h"
#include "LogConnectService.h"
#include "Server.h"
#include "GameServerEvent.h"

GameServer::~GameServer()
{
}

bool GameServer::Initialize()
{
	ConfigParser::GetInstance().LoadConfig(L"ServerConfig.json");

	const auto& mainInfo = ConfigParser::GetInstance().GetServerInfo();

	Environment::GetInstance().mServerID = mainInfo.ServerID;
	Environment::GetInstance().SetMaxConnection(mainInfo.MaxConnection);

	if (false == LogConnectService::GetInstance().Initialize())
	{
		return false;
	}

	return true;
}

bool GameServer::Run()
{
	Packet::ReservePool(1000);

	Server* server = new Server;
	server->BindEvent(std::make_shared<GameServerEvent>());

	if (false == LogConnectService::GetInstance().Start())
	{
		return false;
	}

	if (false == GameService::GetInstance().Start())
	{
		return false;
	}

	server->Start();

	while (1)
	{
		CSLog1Req req;
		req.set_text("hey");
		req.set_a(5);
		req.set_b(4);

		MakePacket(0, CS_Log1Req, req);
		GameService::GetInstance().Push(packet);
		Sleep(500);
	}

	// 여기서 메인 스레드는 어떤 작업을 수행하는게 좋을까?
	// 우선 무한 대기
	//Sleep(INFINITE);

	return true;
}

void GameServer::ShowPacket()
{
}

void GameServer::ShowPool()
{
}
