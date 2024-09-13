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
	// �׷���... ������ � �ڵ尡 �����ұ�?

	return true;
}

bool ElasticServer::Run()
{
	// �켱 Make Shared �ϴ� ������ ���ؼ� �� �� ���簡 �ʿ��ϴ�.
	// �� Make Shared �ϰ� �Ǵ� �ɱ�?
	auto server = new BaseServer();

	// �� ������ ��Ȯ�� �����ϱ� ���� new �� ���� Server �� �������.

	server->Start();

	delete server;

	return false;
}
