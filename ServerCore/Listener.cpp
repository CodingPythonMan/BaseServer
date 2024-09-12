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
	// NetworkService 스레드 생성
	m_networkService->CreateThread();

	// ServerService 스레드 생성
	m_serverService->CreateThread();

	// 주 스레드가 지나가는 자리...
	while (true == m_running)
	{

		// 해당 부분은 엄청 빨리 돌 필요 없다.
		// 아예, 나머지 스레드가 종료될 때까지 Wait 하고 있어도 된다.
		Sleep(100);
	}
	
	return true;
}
