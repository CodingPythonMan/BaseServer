#include "ServerService.h"
#include <process.h>

ServerService::ServerService() : m_handle(INVALID_HANDLE_VALUE), m_isTerminate(false)
{
}

ServerService::~ServerService()
{
}

bool ServerService::CreateThread()
{
	m_handle = (HANDLE)_beginthreadex(nullptr, 0, ExecuteThread, nullptr, 0, nullptr);
	if (m_handle == nullptr || m_handle == INVALID_HANDLE_VALUE)
	{
		m_isTerminate = true;
		return false;
	}

	// ���� ��⸦ �Ѵٸ� �� �ϴ� ���ΰ�?

	return true;
}

unsigned int WINAPI ServerService::ExecuteThread(void* arg)
{
	return 0;
}
