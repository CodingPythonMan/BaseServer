#include "NetworkService.h"
#include <process.h>

NetworkService::NetworkService() : m_handle(INVALID_HANDLE_VALUE), m_isTerminate(false)
{
}

NetworkService::~NetworkService()
{
}

bool NetworkService::CreateThread()
{
	m_handle = (HANDLE)_beginthreadex(nullptr, 0, ExecuteThread, nullptr, 0, nullptr);
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
		case EJobType::CONNECT:
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

void NetworkService::OnConnect(NetworkJob& job)
{
	// 손님
	Session* session = nullptr;
	

}

unsigned int WINAPI NetworkService::ExecuteThread(void* arg)
{
	NetworkService& networkService = *(NetworkService*)arg;

	networkService.RunThread();
	networkService.SetTerminate();

	return 0;
}
