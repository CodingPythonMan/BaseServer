#include "BaseServer.h"
#include "ConfigParser.h"
#include "Listener.h"

#include <memory>

BaseServer::BaseServer()
{
	ConfigParser::CreateInstance();
}

BaseServer::~BaseServer()
{
	ConfigParser::DeleteInstance();
}

bool BaseServer::Initialize()
{
	ConfigParser::GetInstance()->LoadConfig(L"GameConfig.json");

	// �پ��� Manager �鿡 ���� �ڵ尡 �� �� �ִ�.
	// �׷���... ������ � �ڵ尡 �����ұ�?
	Listener::CreateInstance();

	return true;
}

bool BaseServer::Run()
{
	// �켱 Make Shared �ϴ� ������ ���ؼ� �� �� ���簡 �ʿ��ϴ�.
	// �� Make Shared �ϰ� �Ǵ� �ɱ�?

	Listener::GetInstance()->Start();

	return false;
}