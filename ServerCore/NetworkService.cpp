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

	// 생성 대기를 한다면 왜 하는 것인가?

	if (m_isTerminate == true)
	{
		// [로그] 실패
		return false;
	}

	return true;
}

void NetworkService::RunThread()
{
	while (false == m_isTerminate)
	{
		// 패킷이 왔는감?
		std::unordered_map<SessionID, bool> mapList;

		// 락을 거는데, 락을 거는 이유를 정확히 생각하고 걸자
		// 다른 스레드에서 호출하는 메소드가 있는지?
		mapList.swap(m_isPacketRecvMap);

		for (const auto& id : mapList)
		{
			Session* session = FindSession(id.first);
			if (session != nullptr)
			{
				session->m_isRecv = id.second;
			}
		}

		// 여기서 Job 형태로 일감을 받을 수 있는데...
		// Blocking 큐 => 락큐 형태로 받을 것인가, 락프리로 받을 것인가.
		NetworkJob* job = m_networkJobQueue.Pop();
		if (job == nullptr)
		{
			// Sleep 이 필요한가?
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
	// 여기서 세션락을 걸 수 있다.
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
		// 손님 추가 실패
		return false;
	}

	// 맵 등록
	{
		LockGuard(m_sessionIDLock);

		auto iter = m_sessionMap.find(session->GetID());
		if (iter != m_sessionMap.end())
		{
			session->Close(ESocketClose::AddMapFail);
			// API
			// 여기서 Listener 의 주소를 담아 호출할 수 있다.
		}
	}

	return false;
}

void NetworkService::OnConnect(NetworkJob& job)
{
	// 손님
	Session* session = nullptr;
	
	// 여기서 전달받은 Job 은 IOCP 를 상속 받은 녀석이다.
	job.Read(&session, sizeof(session));
	// Session 자체로 모든 걸 써버린다. => 이게 가능한 까닭은?
	// 패킷 자체가 Session 의 주소로서 모든 멤버함수를 가지고 있단 소리다.

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
