#include "BaseServer.h"

BaseServer::BaseServer()
{
	m_networkService = new NetworkService();
	m_serverService = new ServerService();
	m_running = true;
}

BaseServer::~BaseServer()
{
	delete m_networkService;
	delete m_serverService;
}

bool BaseServer::Start()
{
	// NetworkService ������ ����
	m_networkService->CreateThread();

	// ServerService ������ ����
	m_serverService->CreateThread();

	// Listen
	const std::string& name = ConfigParser::GetInstance()->GetServerInfo().Name;
	const std::string& address = ConfigParser::GetInstance()->GetServerInfo().BindAddress;
	const int& port = ConfigParser::GetInstance()->GetServerInfo().BindPort;



	// �� �����尡 �������� �ڸ�...
	while (true == m_running)
	{

		// �ش� �κ��� ��û ���� �� �ʿ� ����.
		// �ƿ�, ������ �����尡 ����� ������ Wait �ϰ� �־ �ȴ�.
		Sleep(100);
	}

	return true;
}
