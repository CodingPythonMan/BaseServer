#include "SessionManager.h"
#include "NetworkJob.h"

SessionManager::SessionManager()
{
}

SessionManager::~SessionManager()
{
}

bool SessionManager::ReadyForListen(NetworkEvent* networkEvent, const std::string& address, const int port)
{
	// 굳이 풀까지 쓰지 않고, Session 하나 만들어서 해당 Session 에서 일을 도모하자.
	Session* session = new Session();
	if (session == nullptr)
	{
		// 파일 로그로 바뀌어야하는 부분들이다.
		printf("Create Failed - session\n");
		return false;
	}

	// Event 넣는 것은 virtual 함수로 OnRev 등의 함수다.
	session->SetEvent(networkEvent);
	session->SetIP(address);
	session->SetPort(port);

	NetworkJob* job = new NetworkJob();
	if (job == nullptr)
	{
		printf("Create Failed - context\n");
		return false;
	}

	// 데이터 셋팅
	job->Ready(EJobType::Listen);
	job->Write(&session, sizeof(session));

	return DispatchController(job, session);
}

bool SessionManager::DispatchController(NetworkJob* job, Session* session)
{
	if(m_controller)

	return false;
}
