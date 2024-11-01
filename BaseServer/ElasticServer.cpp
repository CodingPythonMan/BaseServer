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
	

	return true;
}

bool ElasticServer::Run()
{
	auto server = std::make_shared<BaseServer>();

	// 그 이유를 정확히 조사하기 위해 new 를 통해 Server 를 만들었다.

	server->Start();

	

	return false;
}
