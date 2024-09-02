#pragma once
#include <Windows.h>

class ServerService
{
public:
	ServerService();
	virtual ~ServerService();

	bool		CreateThread();

	static unsigned int WINAPI ExecuteThread(void* arg);

private:
	HANDLE		m_handle;
};

