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
	// NetworkService 스레드 생성
	m_controllService->CreateThread();

	// ServerService 스레드 생성
	m_workService->CreateThread();

	const std::string& name = ConfigParser::GetInstance()->GetServerInfo().Name;
	const std::string& address = ConfigParser::GetInstance()->GetServerInfo().BindAddress;
	const int& port = ConfigParser::GetInstance()->GetServerInfo().BindPort;

	// 이 곳에 콜백 함수를 넣을 이유는 아직 찾지 못했다.
	// 필요하면 해당 부분 넣으면 된다.
	if (false == SessionManager::GetInstance()->ReadyForListen(address, port))
	{
		printf("[Listen] 실패\n");
	}

	// 주 스레드가 지나가는 자리...
	while (true == m_running)
	{
		// 커맨드 오는 거나 처리하면 된다.

		// 해당 부분은 엄청 빨리 돌 필요 없다.
		// 아예, 나머지 스레드가 종료될 때까지 Wait 하고 있어도 된다.
		Sleep(100);
	}

	return true;
}