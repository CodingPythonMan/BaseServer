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
	// NetworkService 스레드 생성
	m_networkService->CreateThread();

	// ServerService 스레드 생성
	m_serverService->CreateThread();

	// Listen
	const std::string& name = ConfigParser::GetInstance()->GetServerInfo().Name;
	const std::string& address = ConfigParser::GetInstance()->GetServerInfo().BindAddress;
	const int& port = ConfigParser::GetInstance()->GetServerInfo().BindPort;

	// 이 곳에 콜백 함수를 넣을 이유는 아직 찾지 못했다.
	// 필요하면 해당 부분 넣으면 된다.
	if (false == ReadyForListen(address, port))
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

bool BaseServer::ReadyForListen(std::string address, int port)
{
	// 굳이 풀까지 쓰지 않고, Session 하나 만들어서 해당 Session 에서 일을 도모하자.
	Session* session = new Session();
	if (session == nullptr)
	{
		printf("Create Failed - session");
		return false;
	}



	return true;
}