#include "Listener.h"

Listener::Listener()
{
	m_networkService = new NetworkService();
	m_serverService = new ServerService();
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



	return true;
}
