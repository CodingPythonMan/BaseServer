#include "BaseServer.h"
#include "SessionManager.h"

BaseServer::BaseServer()
{
	m_controllService = new ControllService();
	m_workService = new WorkService();
	m_running = true;
}

BaseServer::~BaseServer()
{
	delete m_controllService;
	delete m_workService;
}

bool BaseServer::Start()
{
	// NetworkService ������ ����
	m_controllService->CreateThread();

	// ServerService ������ ����
	m_workService->CreateThread();

	const std::string& name = ConfigParser::GetInstance()->GetServerInfo().Name;
	const std::string& address = ConfigParser::GetInstance()->GetServerInfo().BindAddress;
	const int& port = ConfigParser::GetInstance()->GetServerInfo().BindPort;

	// �� ���� �ݹ� �Լ��� ���� ������ ���� ã�� ���ߴ�.
	// �ʿ��ϸ� �ش� �κ� ������ �ȴ�.
	if (false == SessionManager::GetInstance()->ReadyForListen(address, port))
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