#include "NetworkService.h"
#include <process.h>

NetworkService::NetworkService() : m_handle(INVALID_HANDLE_VALUE)
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
		return false;
	}

	// ���� ��⸦ �Ѵٸ� �� �ϴ� ���ΰ�?

	return true;
}

unsigned int WINAPI NetworkService::ExecuteThread(void* arg)
{
	return 0;
}
