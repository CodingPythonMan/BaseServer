#include "WorkService.h"
#include <process.h>

WorkService::WorkService() : m_handle(INVALID_HANDLE_VALUE), m_isTerminate(false)
{
}

WorkService::~WorkService()
{
}

bool WorkService::CreateThread()
{
	m_handle = (HANDLE)_beginthreadex(nullptr, 0, ExecuteThread, this, 0, nullptr);
	if (m_handle == nullptr || m_handle == INVALID_HANDLE_VALUE)
	{
		m_isTerminate = true;
		return false;
	}

	// ���� ��⸦ �Ѵٸ� �� �ϴ� ���ΰ�?

	return true;
}

unsigned int WINAPI WorkService::ExecuteThread(void* arg)
{
	return 0;
}
