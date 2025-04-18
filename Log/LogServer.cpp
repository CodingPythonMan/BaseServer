#include "LogServer.h"
#include "Packet.h"
#include "LogService.h"
#include "Server.h"
#include "LogServerEvent.h"
#include "ConfigParser.h"

bool LogServer::Initialize()
{
	ConfigParser::GetInstance().LoadConfig(L"ServerConfig.json");

	// DB ������ �� �ְԲ� �� �۾��ؾ��Ѵ�.
	return true;
}

bool LogServer::Run()
{
	Packet::ReservePool(1000);

	Server* server = new Server;
	server->BindEvent(std::make_shared<LogServerEvent>());

	if (false == LogService::GetInstance().Start())
	{
		return false;
	}

	server->Start();

	Sleep(INFINITE);

	delete server;

	return true;
}