#include "GameServer.h"
#include "ConfigParser.h"
#include "Environment.h"
#include "Packet.h"
#include "GameService.h"

GameServer::~GameServer()
{
}

bool GameServer::Initialize()
{
	ConfigParser::GetInstance().LoadConfig(L"ServerConfig.json");

	const auto& mainInfo = ConfigParser::GetInstance().GetServerInfo();

	Environment::GetInstance().mServerID = mainInfo.ServerID;
	Environment::GetInstance().SetMaxConnection(mainInfo.MaxConnection);

	// 지금 여기에선 DB 연결은 딱히 필요 없다.
	// Log Server 로 넘겨주면, Log Server 에서 DB 처리하면 된다.

	return true;
}

bool GameServer::Run()
{
	Packet::ReservePool(1000);

	//if (false == LogService::GetInstance().Start)
	//{
	//	return false;
	//}

	if (false == GameService::GetInstance().Start())
	{
		return false;
	}

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
