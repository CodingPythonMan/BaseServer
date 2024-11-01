#pragma once
#include "Session.h"

class WorkService
{
public:
	WorkService();
	virtual ~WorkService();

	bool		CreateThread();

	static unsigned int WINAPI ExecuteThread(void* arg);

private:
	HANDLE		m_handle;
	bool		m_isTerminate;
};