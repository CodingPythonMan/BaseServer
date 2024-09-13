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

	// �� ���� �ݹ� �Լ��� ���� ������ ���� ã�� ���ߴ�.
	// �ʿ��ϸ� �ش� �κ� ������ �ȴ�.
	if (false == ReadyForListen(address, port))
	{
		printf("[Listen] ����\n");
	}

	// �� �����尡 �������� �ڸ�...
	while (true == m_running)
	{
		// Ŀ�ǵ� ���� �ų� ó���ϸ� �ȴ�.

		// �ش� �κ��� ��û ���� �� �ʿ� ����.
		// �ƿ�, ������ �����尡 ����� ������ Wait �ϰ� �־ �ȴ�.
		Sleep(100);
	}

	return true;
}

bool BaseServer::ReadyForListen(std::string address, int port)
{
	// ���� Ǯ���� ���� �ʰ�, Session �ϳ� ���� �ش� Session ���� ���� ��������.
	Session* session = new Session();
	if (session == nullptr)
	{
		printf("Create Failed - session");
		return false;
	}



	return true;
}