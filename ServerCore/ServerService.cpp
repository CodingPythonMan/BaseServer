#include "ServerService.h"

ServerService::ServerService() : m_handle(INVALID_HANDLE_VALUE)
{
}

ServerService::~ServerService()
{
}

bool ServerService::CreateThread()
{
	return false;
}

unsigned int WINAPI ServerService::ExecuteThread(void* arg)
{
	return 0;
}
