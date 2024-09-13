#include "ElasticServer.h"
#include "BaseServer.h"

#include <memory>

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

	// 다양한 Manager 들에 대한 코드가 들어갈 수 있다.
	// 그런데... 시작은 어떤 코드가 들어가야할까?

	return true;
}

bool ElasticServer::Run()
{
	// 우선 Make Shared 하는 이유에 대해선 좀 더 조사가 필요하다.
	// 왜 Make Shared 하게 되는 걸까?
	auto server = new BaseServer();

	// 그 이유를 정확히 조사하기 위해 new 를 통해 Server 를 만들었다.

	server->Start();

	delete server;

	return false;
}
