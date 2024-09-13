#pragma once
// ServerCore 에 들어가야 알맞은 값이 된다.
#include "NetworkService.h"
#include "ServerService.h"
#include "Singleton.h"
#include "ConfigParser.h"

class BaseServer
{
public:
	BaseServer();
	virtual ~BaseServer();

	bool					Start();
	bool					ReadyForListen(std::string address, int port);


private:
	// Has - a 관계로 NetworkController 와 NetworkWorker 를 갖게 한다.
	// 최근 느낀건데 m_ 이렇게 멤버 함수 적는 게 변수 구분에 도움을 주는 듯 하다.
	NetworkService*			m_networkService;
	ServerService*			m_serverService;

	bool					m_running;
};