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
	// ���� Ǯ���� ���� �ʰ�, Session �ϳ� ���� �ش� Session ���� ���� ��������.
	Session* session = new Session();
	if (session == nullptr)
	{
		// ���� �α׷� �ٲ����ϴ� �κе��̴�.
		printf("Create Failed - session\n");
		return false;
	}

	// Event �ִ� ���� virtual �Լ��� OnRev ���� �Լ���.
	session->SetEvent(networkEvent);
	session->SetIP(address);
	session->SetPort(port);

	NetworkJob* job = new NetworkJob();
	if (job == nullptr)
	{
		printf("Create Failed - context\n");
		return false;
	}

	// ������ ����
	job->Ready(EJobType::Listen);
	job->Write(&session, sizeof(session));

	return DispatchController(job, session);
}

bool SessionManager::DispatchController(NetworkJob* job, Session* session)
{
	if(m_controller)

	return false;
}
