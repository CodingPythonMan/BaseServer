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

	// ���� ���⿡�� DB ������ ���� �ʿ� ����.
	// Log Server �� �Ѱ��ָ�, Log Server ���� DB ó���ϸ� �ȴ�.

	return true;
}

bool GameServer::Run()
{
	Packet::ReservePool(1000);

	//if (false == LogService::GetInstance().Start)
	{
		return false;
	}

	if (false == GameService::GetInstance().Start())
	{
		return false;
	}

	// ���⼭ ���� ������� � �۾��� �����ϴ°� ������?
	// �켱 ���� ���
	Sleep(INFINITE);

	return true;
}

void GameServer::ShowPacket()
{
}

void GameServer::ShowPool()
{
}
