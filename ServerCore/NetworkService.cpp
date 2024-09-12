#include "NetworkService.h"
#include <process.h>
#include "DefineMacro.h"

NetworkService::NetworkService() : m_handle(INVALID_HANDLE_VALUE), m_isTerminate(false)
{
}

NetworkService::~NetworkService()
{
}

bool NetworkService::CreateThread()
{
	m_handle = (HANDLE)_beginthreadex(nullptr, 0, ExecuteThread, this, 0, nullptr);
	if (m_handle == nullptr || m_handle == INVALID_HANDLE_VALUE)
	{
		SetTerminate();
		return false;
	}

	// ���� ��⸦ �Ѵٸ� �� �ϴ� ���ΰ�?

	if (m_isTerminate == true)
	{
		// [�α�] ����
		return false;
	}

	return true;
}

void NetworkService::RunThread()
{
	while (false == m_isTerminate)
	{
		// ��Ŷ�� �Դ°�?
		std::unordered_map<SessionID, bool> mapList;

		// ���� �Ŵµ�, ���� �Ŵ� ������ ��Ȯ�� �����ϰ� ����
		// �ٸ� �����忡�� ȣ���ϴ� �޼ҵ尡 �ִ���?
		mapList.swap(m_isPacketRecvMap);

		for (const auto& id : mapList)
		{
			Session* session = FindSession(id.first);
			if (session != nullptr)
			{
				session->m_isRecv = id.second;
			}
		}

		// ���⼭ Job ���·� �ϰ��� ���� �� �ִµ�...
		// Blocking ť => ��ť ���·� ���� ���ΰ�, �������� ���� ���ΰ�.
		NetworkJob* job = m_networkJobQueue.Pop();
		if (job == nullptr)
		{
			// Sleep �� �ʿ��Ѱ�?
			continue;
		}

		switch (job->GetType())
		{
		case EJobType::Connect:
			OnConnect(*job);
			break;
		}
	}
}

void NetworkService::SetTerminate()
{
	m_isTerminate = true;
}

Session* NetworkService::FindSession(const SessionID& sessionID)
{
	// ���⼭ ���Ƕ��� �� �� �ִ�.
	auto iter = m_sessionMap.find(sessionID);
	if (iter == m_sessionMap.end())
	{
		return nullptr;
	}

	return iter->second;
}

bool NetworkService::AddSession(Session* session)
{
	if (session == nullptr)
	{
		// �մ� �߰� ����
		return false;
	}

	// �� ���
	{
		LockGuard(m_sessionIDLock);

		auto iter = m_sessionMap.find(session->GetID());
		if (iter != m_sessionMap.end())
		{
			session->Close(ESocketClose::AddMapFail);
			// API
			// ���⼭ Listener �� �ּҸ� ��� ȣ���� �� �ִ�.
		}
	}

	return false;
}

void NetworkService::OnConnect(NetworkJob& job)
{
	// �մ�
	Session* session = nullptr;
	
	// ���⼭ ���޹��� Job �� IOCP �� ��� ���� �༮�̴�.
	job.Read(&session, sizeof(session));
	// Session ��ü�� ��� �� �������. => �̰� ������ �����?
	// ��Ŷ ��ü�� Session �� �ּҷμ� ��� ����Լ��� ������ �ִ� �Ҹ���.

	if (AddSession(session) == false)
	{
		return;
	}

	//job.ResetBuffer();

	//session->BeginBaseTask();
}

unsigned int WINAPI NetworkService::ExecuteThread(void* arg)
{
	NetworkService& networkService = *(NetworkService*)arg;

	networkService.RunThread();
	networkService.SetTerminate();

	return 0;
}
