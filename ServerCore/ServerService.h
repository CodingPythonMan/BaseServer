#pragma once
#include "Session.h"

class ServerService
{
public:
	ServerService();
	virtual ~ServerService();

	bool		CreateThread();

	static unsigned int WINAPI ExecuteThread(void* arg);

private:
	HANDLE		m_handle;
	bool		m_isTerminate;
};