#pragma once
#include <Windows.h>

class NetworkService
{
public:
	NetworkService();
	virtual ~NetworkService();

	bool		CreateThread();

	static unsigned int WINAPI ExecuteThread(void* arg);

private:
	HANDLE		m_handle;
};