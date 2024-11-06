#include "ControllService.h"
#include <process.h>
#include "DefineMacro.h"

ControllService::ControllService() : m_handle(INVALID_HANDLE_VALUE), m_isTerminate(false)
{
}

ControllService::~ControllService()
{
}

bool ControllService::CreateThread()
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

void ControllService::RunThread()
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

void ControllService::SetTerminate()
{
	m_isTerminate = true;
}

Session* ControllService::FindSession(unsigned int sessionID)
{
	// ���⼭ ���Ƕ��� �� �� �ִ�.
	auto iter = m_sessionMap.find(sessionID);
	if (iter == m_sessionMap.end())
	{
		return nullptr;
	}

	return iter->second;
}

bool ControllService::AddSession(Session* session)
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

void ControllService::OnConnect(NetworkJob& job)
{
	// �մ�
	Session* session = nullptr;
	
	// ���⼭ ���޹��� Job �� IOCP �� ��� ���� �༮�̴�.
	job.Read(&session, sizeof(session));
	// Session ��ü�� ��� �� �������. => �̰� ������ �����?
	// ��Ŷ ��ü�� Session �� �ּҷμ� ��� ����Լ��� ������ �ִ� �Ҹ���.
	// �̰�... �ѹ� ������ ���߰ڴ�.

	if (AddSession(session) == false)
	{
		return;
	}

	job.ResetBuffer();

	//session->BeginBaseTask();

	// ��ǥ) ������� �����ؾ��Ѵ�.
	//session->Connect(job);
}

unsigned int WINAPI ControllService::ExecuteThread(void* arg)
{
	ControllService& controllService = *(ControllService*)arg;

	controllService.RunThread();
	controllService.SetTerminate();

	return 0;
}
