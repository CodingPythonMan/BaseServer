#include "LogServer.h"
#include "Packet.h"
#include "LogService.h"
#include "Server.h"
#include "LogServerEvent.h"
#include "ConfigParser.h"

bool LogServer::Initialize()
{
	ConfigParser::GetInstance().LoadConfig(L"ServerConfig.json");

	// DB 연결할 수 있게끔 좀 작업해야한다.
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