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

	// �켱 Make Shared �ϴ� ������ ���ؼ� �� �� ���簡 �ʿ��ϴ�.
	// �� Make Shared �ϰ� �Ǵ� �ɱ�?
	std::shared_ptr<Listener> listener = std::make_shared<Listener>();



	return true;
}

bool BaseServer::Run()
{
	// �� ������ �����带 �ļ� ���� ������, IOCP �����带 ������.
	// �ش� �κ��� ������ © �� �ִ°ɱ�?
	

	return false;
}