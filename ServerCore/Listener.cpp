#include "Listener.h"

Listener::Listener()
{
	m_networkService = new NetworkService();
	m_serverService = new ServerService();
	m_running = true;
}

Listener::~Listener()
{
	delete m_networkService;
	delete m_serverService;
}

bool Listener::Start()
{
	// NetworkService ������ ����
	m_networkService->CreateThread();

	// ServerService ������ ����
	m_serverService->CreateThread();

	// �� �����尡 �������� �ڸ�...
	while (true == m_running)
	{

		// �ش� �κ��� ��û ���� �� �ʿ� ����.
		// �ƿ�, ������ �����尡 ����� ������ Wait �ϰ� �־ �ȴ�.
		Sleep(100);
	}
	
	return true;
}
