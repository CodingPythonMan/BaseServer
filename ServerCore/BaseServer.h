#pragma once
// ServerCore �� ���� �˸��� ���� �ȴ�.
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
	// Has - a ����� NetworkController �� NetworkWorker �� ���� �Ѵ�.
	// �ֱ� �����ǵ� m_ �̷��� ��� �Լ� ���� �� ���� ���п� ������ �ִ� �� �ϴ�.
	NetworkService*			m_networkService;
	ServerService*			m_serverService;

	bool					m_running;
};