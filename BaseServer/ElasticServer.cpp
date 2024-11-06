#include <memory>
#include "ElasticServer.h"
#include "BaseServer.h"
#include "SessionManager.h"
#include "GameServerEvent.h"

ElasticServer::ElasticServer()
{
	ConfigParser::CreateInstance();
}

ElasticServer::~ElasticServer()
{
	ConfigParser::DeleteInstance();
}

bool ElasticServer::Initialize()
{
	ConfigParser::GetInstance()->LoadConfig(L"GameConfig.json");

	// �پ��� Manager �鿡 ���� �ڵ尡 �� �� �ִ�.
	SessionManager::CreateInstance();

	return true;
}

bool ElasticServer::Run()
{
	auto server = std::make_shared<BaseServer>();
	auto serverEvent = std::make_shared<GameServerEvent>();

	server->BindEventSync(serverEvent);

	server->Start();


	return false;
}
