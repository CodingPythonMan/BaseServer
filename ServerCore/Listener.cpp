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
	// NetworkService 스레드 생성
	m_networkService->CreateThread();

	// ServerService 스레드 생성
	m_serverService->CreateThread();



	return true;
}
