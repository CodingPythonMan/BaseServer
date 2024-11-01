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

	// �پ��� Manager �鿡 ���� �ڵ尡 �� �� �ִ�.
	

	return true;
}

bool ElasticServer::Run()
{
	auto server = std::make_shared<BaseServer>();

	// �� ������ ��Ȯ�� �����ϱ� ���� new �� ���� Server �� �������.

	server->Start();

	

	return false;
}
