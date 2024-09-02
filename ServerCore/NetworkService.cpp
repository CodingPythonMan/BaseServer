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

	// 생성 대기를 한다면 왜 하는 것인가?

	return true;
}

unsigned int WINAPI NetworkService::ExecuteThread(void* arg)
{
	return 0;
}
