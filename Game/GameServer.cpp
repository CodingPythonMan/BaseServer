#include "GameServer.h"
#include "ConfigParser.h"

GameServer::~GameServer()
{
}

bool GameServer::Initialize()
{
	ConfigParser::GetInstance().LoadConfig(L"ServerConfig.json");

	return true;
}

bool GameServer::Run()
{


	return true;
}

void GameServer::ShowPacket()
{
}

void GameServer::ShowPool()
{
}
