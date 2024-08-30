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

	// 다양한 Manager 들에 대한 코드가 들어갈 수 있다.
	// 그런데... 시작은 어떤 코드가 들어가야할까?

	// 우선 Make Shared 하는 이유에 대해선 좀 더 조사가 필요하다.
	// 왜 Make Shared 하게 되는 걸까?
	std::shared_ptr<Listener> listener = std::make_shared<Listener>();



	return true;
}

bool BaseServer::Run()
{
	// 이 때부터 스레드를 파서 로직 스레드, IOCP 스레드를 나눈다.
	// 해당 부분을 나눠서 짤 수 있는걸까?
	

	return false;
}